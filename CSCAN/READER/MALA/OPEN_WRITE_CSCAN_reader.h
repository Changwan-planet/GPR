!BINARY
!OPEN(UNIT=20, FILE=OUTPUT_PATH20, ACCESS = 'STREAM', STATUS='REPLACE', ACTION='WRITE')   !A_SCOPE
!OPEN(UNIT=30, FILE=OUTPUT_PATH30, ACCESS = 'STREAM', STATUS='REPLACE', ACTION='WRITE')   !B_SCAN_IMAGE

OPEN(UNIT=40, FILE=OUTPUT_PATH40, ACCESS = 'STREAM', STATUS='REPLACE', ACTION='WRITE')   !3D_CUBE_IMAGE

!ASCII
OPEN(UNIT=20, FILE=OUTPUT_PATH20, STATUS='REPLACE', ACTION='WRITE')   !A_SCOPE
OPEN(UNIT=30, FILE=OUTPUT_PATH30, STATUS='REPLACE', ACTION='WRITE')   !B_SCAN_IMAGE
OPEN(UNIT=41, FILE=OUTPUT_PATH41, STATUS='REPLACE', ACTION='WRITE')   !3D_CUBE_IMAGE
OPEN(UNIT=50, FILE=OUTPUT_PATH50, STATUS='REPLACE', ACTION='WRITE')   !GNSS
OPEN(UNIT=51, FILE=OUTPUT_PATH51, STATUS='REPLACE', ACTION='WRITE')   !GNSS



PRINT*, "COMMON_PATH1=", COMMON_PATH1
PRINT*, "OUTPUT_NAME20=",OUTPUT_NAME20
PRINT*, "OUTPUT_NAME30=",OUTPUT_NAME30
PRINT*, "OUTPUT_NAME40=",OUTPUT_NAME40
PRINT*, "OUTPUT_NAME41=",OUTPUT_NAME41
PRINT*, "OUTPUT_NAME50=",OUTPUT_NAME50
PRINT*, "OUTPUT_NAME51=",OUTPUT_NAME51







