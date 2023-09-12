PROGRAM CSCAN_GPR_EW

IMPLICIT NONE

INCLUDE "IN_OUT_PATH_CSCAN_reader.h"
INCLUDE "VARIABLES_CSCAN_EW_reader.h"
INCLUDE "AUTO_READ_FILES_CSCAN_reader.h"

INCLUDE "OPEN_WRITE_CSCAN_reader.h"

!                    MIN                                       MAX
PRINT*, START_END_XY(4,3), START_END_XY(4,4), START_END_XY(15,1), START_END_XY(15,2)

!                                  DEL_X**2                                         DEL_Y**2 
MAX_D =  SQRT( ( START_END_XY(4,3) -  START_END_XY(15,1) )**2 + ( START_END_XY(4,4) -  START_END_XY(15,2) )**2 )

MAX_D_PIXEL = MAX_D/DISTANCE_INTERVAL
H = 0.5 * (15-4)-1
MAX_X = SQRT(MAX_D**2-H**2)
MAX_X_PIXEL = MAX_X/DISTANCE_INTERVAL

PRINT *, MAX_D, MAX_X
PRINT *, MAX_D_PIXEL,MAX_X_PIXEL



INCLUDE "OUTPUT_A_SCAN_reader.h"        !20
INCLUDE "OUTPUT_B_SCAN_reader.h"        !30 
INCLUDE "OUTPUT_C_SCAN_reader.h"        !40

END PROGRAM
