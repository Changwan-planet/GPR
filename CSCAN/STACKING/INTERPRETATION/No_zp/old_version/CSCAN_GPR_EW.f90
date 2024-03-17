PROGRAM CSCAN_GPR_EW

USE MD_INTERPRE

IMPLICIT NONE

!USE GSSI_PROGRAM
INCLUDE "IN_OUT_PATH_CSCAN.h"
INCLUDE "VARIABLES_CSCAN_EW.h"
INCLUDE "READ_FILES_CSCAN.h"
INCLUDE "OPEN_WRITE_CSCAN.h"

!HORIZON PICKING
S1 = 70
S2 = 100

!DO Y = 1, TRA
Y = 21 
 CALL power_pick(   B_SCAN_IMAGE(:,Y,:), DIS, TRA, ROWS3, S1, S2, H_1)
 CALL power_pick(HILBERT_powerdB(:,Y,:), DIS, TRA, ROWS3, S1, S2, H_1)


!END DO 

PRINT*,  "COMPLETED TO PICK HOROZIN_1"
PRINT*, "WRITE OUT THE RESULTS"
PRINT*, "WAITING..."

!INCLUDE "OUTPUT_A_SCAN.h"      !20
!INCLUDE "OUTPUT_B_SCAN.h"     !30
!INCLUDE "OUTPUT_C_SCAN.h"     !40
INCLUDE "OUTPUT_INTERPRE.h"   !90

END PROGRAM
