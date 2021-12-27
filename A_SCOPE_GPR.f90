Program OPEN_GSSI
USE MD_BACKGROUND

IMPLICIT NONE

INCLUDE "IN_OUT_PATH.h"
INCLUDE "VARIABLES.h"
INCLUDE "PATH_NAME_OPEN.h"

!======INITIALIZATION=======
DIS = 0
!B_SCAN_IMAGE = 0
!B_SCAN_IMAGE2 = 0.0
!B_SCAN_IMAGE3 = 0.0
!INTENSITY = 0.0
!===========================

PRINT *, "PLEASE TYPE THE  DISTANCE"
READ *, DIS

INCLUDE "ALLOCATE.h"

READ(10) HEADER,B_SCAN_IMAGE

!INTEGER => REAL*8
B_SCAN_IMAGE2=B_SCAN_IMAGE

!CALCUATE THE BACKGROUND
CALL background(B_SCAN_IMAGE2,ROWS,2001,4000,BGR)

!REMOVE THE BACKGROUND
B_SCAN_IMAGE3 = B_SCAN_IMAGE2 - BGR

INCLUDE "OUTPUT_A_SCOPE.h"

END PROGRAM