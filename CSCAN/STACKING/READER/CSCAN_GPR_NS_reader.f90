PROGRAM CSCAN_MOGOD_GPR

USE MD_BACKGROUND
USE MD_STACKING
USE MD_BASIC

IMPLICIT NONE

!USE GSSI_PROGRAM
INCLUDE "IN_OUT_PATH_CSCAN_reader.h"
INCLUDE "VARIABLES_CSCAN_NS_reader.h"
INCLUDE "AUTO_READ_FILES_CSCAN_NS_reader.h"


DO X = 1, DIS
   DO Y = 1, TRA
!CALCULATE THE BACKGROUND
 CALL background(B_SCAN_IMAGE3(X,Y,:),ROWS,2001,4000,BGR)
 
!REMOVE THE BACKGROUND
     B_SCAN_IMAGE4(X,Y,:) = B_SCAN_IMAGE3(X,Y,:) - BGR
   END DO 
END DO

!TO MAKE THE GRAPH STABLE
!IF MADE IT 1, IT COULD MAKE AN ERROR WHEN CALCULATING LOG
!THEN, I ASSIGNED 1.
B_SCAN_IMAGE4(:,:,1) = 1
B_SCAN_IMAGE4(:,:,2) = 1


!STACKING THE A_SCOPE TO SUPPRESS THE NOISEa
DO Y = 1, TRA
   CALL static_stacking(B_SCAN_IMAGE4(:,Y,:), ROWS, DIS, STACKED_A_SCOPE)
   STACKED_B_SCAN(F, Y, :) = STACKED_A_SCOPE(1,1,:)
END DO  

END DO    !THE END DO OF F LOOP  

PRINT *, "COMPLETE TO READ"

INCLUDE "OPEN_WRITE_CSCAN_reader.h"
INCLUDE "OUTPUT_A_SCAN_reader.h" ! 20
INCLUDE "OUTPUT_B_SCAN_reader.h"  !30

CALL flip_3d(STACKED_B_SCAN, LINE, TRA, ROWS, STACKED_B_SCAN2)

INCLUDE "OUTPUT_C_SCAN_NS_reader.h"  !40

END PROGRAM
