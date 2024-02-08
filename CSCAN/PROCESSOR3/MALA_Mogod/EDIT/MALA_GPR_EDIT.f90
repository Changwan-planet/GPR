PROGRAM CSCAN_GPR_EW
USE MD_BASIC
USE MD_FFT_HILBERT

IMPLICIT NONE
INCLUDE "IN_OUT_PATH_CSCAN.h"
INCLUDE "VARIABLES_CSCAN.h"
INCLUDE "READ_FILES_CSCAN.h"
INCLUDE "OPEN_WRITE_CSCAN.h"

DO X = 0, DIS 
   DO Y = 0, TRA 
!CALCULATE THE BACKGROUND
 CALL background(B_SCAN_IMAGE_H(X,Y,:),ROWS,401,500,BGR)
 
!REMOVE THE BACKGROUND
     B_SCAN_IMAGE_H2(X,Y,:) = B_SCAN_IMAGE_H(X,Y,:) - BGR 
   END DO 
END DO

DO X = 0, DIS 
   DO Y = 0, TRA 
!CALCULATE THE BACKGROUND
 CALL background(B_SCAN_IMAGE_V(X,Y,:),ROWS,401,500,BGR)
 
!REMOVE THE BACKGROUND
     B_SCAN_IMAGE_V2(X,Y,:) = B_SCAN_IMAGE_V(X,Y,:) - BGR 
   END DO 
END DO

B_SCAN_IMAGE2 = (B_SCAN_IMAGE_H2 + B_SCAN_IMAGE_V2) / 2.0

!DATA AUGMENTATION
!ROW-DIRECTION
B_SCAN_IMAGE3 = B_SCAN_IMAGE2
DO DE = 0, INT(TRA/10.0) -1
B_SCAN_IMAGE3(:,5+10*DE,:) = (B_SCAN_IMAGE2(:,0+10*DE,:) + B_SCAN_IMAGE2(:,10+10*DE,:) ) / 2.0
END DO 

!COL-DIRECTION
B_SCAN_IMAGE4 = B_SCAN_IMAGE3
!B_SCAN_IMAGE4 = B_SCAN_IMAGE_V


DO DE2 = 0 , INT(DIS/10.0) -1
B_SCAN_IMAGE4(5+10*DE2,:,:) = (B_SCAN_IMAGE3(0+10*DE2,:,:) + B_SCAN_IMAGE3(10+10*DE2,:,:)) / 2.0
END DO 


!AVERAGE AND STACKING
DO Z = 0, ROWS-1 
DO J = 0, TRA2
DO I = 0, DIS2                      
B_SCAN_IMAGE5(I,J,Z)=&
SUM(                                           &
      B_SCAN_IMAGE4(5*I:5*(I+1),        5*J,Z) &!R_xr
     +B_SCAN_IMAGE4(5*I:5*(I+1),    5*(J+1),Z) &             
     +B_SCAN_IMAGE4(5*I        ,5*J:5*(J+1),Z) &!C_yr
     +B_SCAN_IMAGE4(5*(I+1)    ,5*J:5*(J+1),Z) &
   )                                           &                                                                     
/  (                                           &                                               
 SIZE(B_SCAN_IMAGE4(5*I:5*(I+1),        5*J,Z))&
+SIZE(B_SCAN_IMAGE4(5*I:5*(I+1),    5*(J+1),Z))&
+SIZE(B_SCAN_IMAGE4(5*I        ,5*J:5*(J+1),Z))&
+SIZE(B_SCAN_IMAGE4(5*(I+1)    ,5*J:5*(J+1),Z))& 
   )                     
END DO 
END DO 
END DO 

INCLUDE "OUTPUT_A_SCAN.h"      !20
!INCLUDE "OUTPUT_B_SCAN.h"     !30
INCLUDE "OUTPUT_C_SCAN.h"     !40
INCLUDE "OUTPUT_3DCUBE.h"     !50
END PROGRAM
