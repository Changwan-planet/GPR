PROGRAM CSCAN_MOGOD_GPR

USE MD_BASIC
USE MD_MEAN_ASCAN
!USE MD_REMOVE_MEAN
USE MD_FFT_IFFT
USE MD_FFT_HILBERT

IMPLICIT NONE

!USE GSSI_PROGRAM
INCLUDE "IN_OUT_PATH_CSCAN.h"
INCLUDE "VARIABLES_CSCAN_EW.h"
INCLUDE "READ_FILES_CSCAN.h"


!REMOVE THE MEAN
!DO Y=1,TRA
!DO Z=1,ROWS
! CALL remove_mean(B_SCAN_IMAGE3(:,Y,Z),ROWS,DIS,MEAN)
!     B_SCAN_IMAGE3(:,Y,Z) = B_SCAN_IMAGE3(:,Y,Z) - MEAN
!END DO 
!END DO 
 
!HILBERT TRANSFORM
!HILBERT_A_SCOPE
DO F = 1, LINE
   DO Y = 1, TRA
      CALL fft_hilbert(STACKED_B_SCAN(F,Y,:),ROWS,HILBERT_STACKED_SIGNAL) 
     HILBERT_STACKED_B_SCAN(F,Y,:) = HILBERT_STACKED_SIGNAL(1,1,:)
!     HILBERT_STACKED_B_SCAN_imag(F,Y,:) = HILBERT_STACKED_SIGNAL_imag(1,1,:)
   END DO
END DO


!DO F = 1, LINE
!CALCULATE THE MEAN
!      SLICE_MEAN = SUM(HILBERT_STACKED_B_SCAN(:,:,ROWS))/ SIZE(HILBERT_STACKED_B_SCAN(:,:,ROWS))
 
!REMOVE THE BACKGROUND
!     HILBERT_STACKED_B_SCAN(:,:,ROWS) = HILBERT_STACKED_B_SCAN(:,:,ROWS) - SLICE_MEAN
!END DO

INCLUDE "OPEN_WRITE_CSCAN.h"
INCLUDE "OUTPUT_A_SCOPE.h" ! 20
INCLUDE "OUTPUT_B_SCAN.h"  !30, 31, 32,33
INCLUDE "OUTPUT_C_SCAN.h"  !40
INCLUDE "OUTPUT_HILBERT.h" !50

END PROGRAM
