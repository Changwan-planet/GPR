PROGRAM CSCAN_MOGOD_GPR

USE MD_BACKGROUND
!USE MD_REMOVE_MEAN
USE MD_FFT_IFFT
USE MD_FFT_HILBERT

IMPLICIT NONE

!USE GSSI_PROGRAM
INCLUDE "IN_OUT_PATH_CSCAN.h"

INCLUDE "VARIABLES_CSCAN_NS.h"
INCLUDE "AUTO_READ_FILES_CSCAN.h"
INCLUDE "OPEN_WRITE_CSCAN.h"

DO X = 1, DIS
   DO Y = 1, TRA
!CALCULATE THE BACKGROUND
 CALL background(B_SCAN_IMAGE3(X,Y,:),ROWS,2001,4000,BGR)
 
!REMOVE THE BACKGROUND
     B_SCAN_IMAGE4(X,Y,:) = B_SCAN_IMAGE3(X,Y,:) - BGR
   END DO 
END DO

!REMOVE THE MEAN
!DO Y=1,TRA
!DO Z=1,ROWS
! CALL remove_mean(B_SCAN_IMAGE3(:,Y,Z),ROWS,DIS,MEAN)
!     B_SCAN_IMAGE3(:,Y,Z) = B_SCAN_IMAGE3(:,Y,Z) - MEAN
!END DO 
!END DO 
 


!TO MAKE THE GRAPH STABLE
!IF MADE IT 1, IT COULD MAKE AN ERROR WHEN CALCULATING LOG
!THEN, I ASSIGNED 1.
B_SCAN_IMAGE3(:,:,1) = 1
B_SCAN_IMAGE3(:,:,2) = 1


!HILBERT TRANSFORM
!HILBERT_A_SCOPE
DO X = 1, DIS
   DO Y = 1, TRA
      CALL fft_hilbert(B_SCAN_IMAGE4(X,Y,:),ROWS,HILBERT_SIGNAL,HILBERT_SIGNAL_imag) 
!     B_SCAN_IMAGE3(1,Y,:) = HILBERT_SIGNAL(1,1,:)
      HILBERT_B_SCAN(X,Y,:) = HILBERT_SIGNAL(1,1,:)
      HILBERT_B_SCAN_imag(X,Y,:) = HILBERT_SIGNAL_imag(1,1,:)
   END DO
END DO


DO Z = 1, ROWS
!CALCULATE THE MEAN
      SLICE_MEAN = SUM(HILBERT_B_SCAN(:,:,ROWS))/ SIZE(HILBERT_B_SCAN(:,:,ROWS))
 
!REMOVE THE BACKGROUND
     HILBERT_B_SCAN(:,:,ROWS) = HILBERT_B_SCAN(:,:,ROWS) - SLICE_MEAN
END DO


INCLUDE "OUTPUT_A_SCOPE.h" !20
INCLUDE "OUTPUT_B_SCAN.h"  !30, 31
INCLUDE "OUTPUT_C_SCAN.h"  !40
INCLUDE "OUTPUT_HILBERT.h" !50


END PROGRAM
