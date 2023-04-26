PROGRAM CSCAN_GPR_EW

USE MD_BASIC
USE MD_CROSS_CORRELATION

IMPLICIT NONE

!USE GSSI_PROGRAM
INCLUDE "IN_OUT_PATH_CSCAN.h"
INCLUDE "VARIABLES_CSCAN_EW.h"
INCLUDE "READ_FILES_CSCAN.h"
INCLUDE "OPEN_WRITE_CSCAN.h"

DO X = 1, DIS
   DO Y = 1, TRA
!CALCULATE THE BACKGROUND
! CALL background(B_SCAN_IMAGE3(X,Y,:),ROWS,2001,4000,BGR)
  CALL background(B_SCAN_IMAGE3(X,Y,:),ROWS,501,600,BGR)
 
!REMOVE THE BACKGROUND
     B_SCAN_IMAGE4(X,Y,:) = B_SCAN_IMAGE3(X,Y,:) - BGR
   END DO 
END DO
PRINT*, "BACKGROUND END"

!THE FIRST DATA FROM AN A-SCOPE OF GPR HAS ZERO VALUE.
!SO THAT I WRITE THE DATA FROM 2 TO REMOVE IT.
DO Z = 2, ROWS  
   B_SCAN_IMAGE5(:,:,Z-1) = B_SCAN_IMAGE4(:,:,Z) 
END DO 


!TOTAL SUM SIGNAL
DO Z = 1, ROWS2
   T_SUM_ASCOPE(1,1,Z) = SUM( B_SCAN_IMAGE5(:,:,Z) ) / SIZE( B_SCAN_IMAGE5(:,:,Z) )
END DO
PRINT *, "TOTAL_SCAN END"

!CROSS-CORRELATION
!DO Y = 1, TRA
!   DO X = 1, DIS
!      CALL cross_corl(T_SUM_ASCOPE(1,1,:), B_SCAN_IMAGE5(X,Y,:), ROWS2, crrl)
      !PRINT *, "CRRL_N=",CRRL_N
      !PRINT*, "X=",X,"Y=",Y,"MAXLOC=",MAXLOC(crrl)
!     SHIFT(X,Y) = ROWS2 - MAXLOC(crrl,1)  
!    END DO
!     PRINT *,  "TRA=",Y
!END DO
!PRINT *, "CROSS CORRELATION END"

! CALL cross_corl(T_SUM_ASCOPE(1,1,:), B_SCAN_IMAGE5(X,Y,:), ROWS2, crrl)

!ZERO_PADDING
DO X = 1, DIS
   DO Y = 1,  TRA
      CALL zero_padding(B_SCAN_IMAGE5(X,Y,:), ROWS2, ROWS3, B_SCAN_IMAGE6(X,Y,:))
   END DO 
END DO 
PRINT*, "ZERO PADDING END"


!INCLUDE "OUTPUT_A_SCAN.h"      !20
!INCLUDE "OUTPUT_B_SCAN.h"      !30
INCLUDE "OUTPUT_C_SCAN.h"     !40

!INCLUDE "OUTPUT_CRRL.h"        !50

END PROGRAM