PROGRAM CSCAN_GPR

USE MD_INTERPRE

IMPLICIT NONE

!USE GSSI_PROGRAM
INCLUDE "IN_OUT_PATH_CSCAN.h"
INCLUDE "VARIABLES_CSCAN.h"
INCLUDE "READ_FILES_CSCAN.h"
INCLUDE "OPEN_WRITE_CSCAN.h"

!HORIZON PICKING

HS1 = 1050
HS2 = 1090

!DO Y = 1, TRA
Y = 3

   CALL horizon_pick_max(HILBERT_powerdB(:,Y,:), DIS, TRA, ROWS, HS1, HS2, H_S)
!   CALL horizon_pick_max(B_SCAN_IMAGE(:,Y,:), DIS, TRA, ROWS, HS1, HS2, H_S)

S1 = 1180
S2 = 1300

ALLOCATE(H_Z2(DIS))
ALLOCATE(H_Z4(DIS))


!HORIZON PICKING START FROM X=0
X = 1
 CALL non_ssd_pick(HILBERT_powerdB(X,Y,:), DIS, ROWS, S1, S2, H_Z2, H_Z_Max)

 H_Z(X) = H_Z_Max
 H_Z_MATRIX(:,X) =  H_Z2


W = 20


DO X = 2, DIS
  PRINT *, "==========="
  PRINT *, "X=", X
  PRINT *, "i_h, Z, H_Z(Z), B_SCAN_IMAGE(1,1,Z)"

!  CALL non_ssd_pick(HILBERT_powerdB(X,Y,:), DIS, ROWS, S1, S2, H_Z2, H_Z_Max)
!  CALL non_ssd_pick(B_SCAN_IMAGE(X,Y,:), DIS, ROWS, S1, S2, H_Z2, H_Z_Max)
!  CALL non_ssd_pick(B_SCAN_IMAGE(X,Y,:), DIS, ROWS, S1, S2, H_Z_Max)

 CALL non_ssd_pick(HILBERT_powerdB(X,Y,:), DIS, ROWS&
                   , H_Z_MATRIX(1,X-1)-W, H_Z_MATRIX(1,X-1)+W&
                   , H_Z2, H_Z_Max)

  !PRINT *, "H_Z_Max=",H_Z_Max
  H_Z(X) = H_Z_Max
  H_Z_MATRIX(:,X) =  H_Z2

END DO 

!HORIZON PICKING START FROM X=FINAL
S1 = 1150
S2 = 1250

 X = DIS
 CALL non_ssd_pick(HILBERT_powerdB(X,Y,:), DIS, ROWS, S1, S2, H_Z4, H_Z_Max2)

 H_Z3(X) = H_Z_Max2
 H_Z_MATRIX2(:,X) =  H_Z4


W = 20


DO X = DIS-1,1,-1
  PRINT *, "==========="
  PRINT *, "X=", X
  PRINT *, "i_h, Z, H_Z(Z), B_SCAN_IMAGE(1,1,Z)"

!  CALL non_ssd_pick(HILBERT_powerdB(X,Y,:), DIS, ROWS, S1, S2, H_Z2, H_Z_Max)
!  CALL non_ssd_pick(B_SCAN_IMAGE(X,Y,:), DIS, ROWS, S1, S2, H_Z2, H_Z_Max)
!  CALL non_ssd_pick(B_SCAN_IMAGE(X,Y,:), DIS, ROWS, S1, S2, H_Z_Max)

 CALL non_ssd_pick(HILBERT_powerdB(X,Y,:), DIS, ROWS&
                   , H_Z_MATRIX2(1,X+1)-W, H_Z_MATRIX2(1,X+1)+W&
                   , H_Z4, H_Z_Max2)

  !PRINT *, "H_Z_Max=",H_Z_Max
  H_Z3(X) = H_Z_Max2
  H_Z_MATRIX2(:,X) =  H_Z4

END DO 


DO X = 1, DIS
   PRINT *, X, H_Z_MATRIX(:,X)
!   WRITE(1,*) X, H_Z_MATRIX(:,X)
   WRITE(1,*) X, H_S(X), H_Z_MATRIX(:,X)

END DO
 
DO X = 1, DIS
!   PRINT *, X, H_Z_MATRIX2(:,X)
!   WRITE(2,*) X, H_Z_MATRIX2(:,X)
   WRITE(2,*) X, H_S(X), H_Z_MATRIX2(:,X)


END DO
 
PRINT*,  "COMPLETED TO PICK HOROZIN_1"
PRINT*, "WRITE OUT THE RESULTS"
PRINT*, "WAITING..."

INCLUDE "OUTPUT_A_SCAN.h"      !20
INCLUDE "OUTPUT_B_SCAN.h"     !30
!INCLUDE "OUTPUT_C_SCAN.h"     !40
INCLUDE "OUTPUT_INTERPRE.h"   !90

DEALLOCATE(H_Z2)
DEALLOCATE(H_Z4)


END PROGRAM
