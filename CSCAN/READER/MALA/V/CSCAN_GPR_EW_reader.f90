PROGRAM CSCAN_GPR_EW

USE MD_BASIC 

IMPLICIT NONE

INCLUDE "IN_OUT_PATH_CSCAN_reader.h"
INCLUDE "VARIABLES_CSCAN_EW_reader.h"
INCLUDE "AUTO_READ_FILES_CSCAN_reader.h"
INCLUDE "OPEN_WRITE_CSCAN_reader.h"

B_SCAN_IMAGE3F = B_SCAN_IMAGE3

!==============================================
!         X1  X2  X3        X1089  X1090  X1091
! Y_n     |   |   |         |      |      | 
! Y_n-1   |   |   |         |      |      |
! Y_n-2   |   |   |  . . .  |      |      |
!         |   |   |         |      |      |
!         |   |   |         |      |      |
! Y_3     |   |   |  . . .  |      |      |
! Y_2     |   |   |         |      |      |
! Y1      |   |   |         |      |      |
!         X1  X2  X3        X1089  X1090  X1091
!==============================================

!INCLUDE "MIHO11_V_edit.h"
!INCLUDE "MIHO12_V_edit.h"

!PRINT*, "CCD=",COL_COR_DIS
DO X = 1, DIS2
   COL_COR_PIXEL(X) = INT(COL_COR_DIS(X)/0.05)  !5 cm = 0.05 m
END DO  
!PRINT*, "CCP=", COL_COR_PIXEL

DO X = 1, DIS2
   COL_COR_PIXEL2(X) = (TRA+1) - COL_COR_PIXEL(X) - TRACE(X)
!PRINT*, "CCP2=",X, COL_COR_PIXEL2(X), (TRA+1), COL_COR_PIXEL(X), TRACE(X)
END DO  

!INCLUDE "MIHO11_V_edit.h"
!INCLUDE "MIHO12_V_edit.h"


DO X = 1, DIS2

!PRINT*, X, "CCP=", COL_COR_PIXEL2(Y)

DO Y = 0, TRA-COL_COR_PIXEL2(X)
   B_SCAN_IMAGE4(X-1,Y+COL_COR_PIXEL2(X),:) = B_SCAN_IMAGE3F(X-1,Y,:)
END DO 
END DO 


DO X  = 1, DIS2
   B_SCAN_IMAGE5(10 * (X-1),:, :) = B_SCAN_IMAGE4((X-1),:, :)
END DO 



INCLUDE "ZERO_PADDING.h"

INCLUDE "OUTPUT_A_SCAN_reader.h"        !20
!INCLUDE "OUTPUT_B_SCAN_reader.h"        !30 
!INCLUDE "OUTPUT_C_SCAN_reader.h"        !40
INCLUDE "OUTPUT_3DCUBE_reader.h"         !50


!INCLUDE "OUTPUT_GNSS.h"                !50


END PROGRAM
