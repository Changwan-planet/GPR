PROGRAM CSCAN_MOGOD_GPR

!USE MD_BACKGROUND
USE MD_TWMVMEAN
!USE MD_FFT_IFFT
!USE MD_FFT_HILBERT

IMPLICIT NONE

!USE GSSI_PROGRAM
INCLUDE "IN_OUT_PATH_CSCAN.h"
INCLUDE "VARIABLES_CSCAN_EW.h"
INCLUDE "READ_FILES_CSCAN.h"
INCLUDE "OPEN_WRITE_CSCAN.h"

PRINT *, "REMOVE BACKGROUND"
DO X = 1, DIS
   DO Y = 1, TRA
!CALCULATE THE BACKGROUND
 CALL background(B_SCAN_IMAGE3(X,Y,:),ROWS,401,512,BGR)
 
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
 
!INTEGRTATE THE AMP WITH 2D MV_MEAN
CALL twmvmean(B_SCAN_IMAGE4, DIS, TRA, ROWS, 2, B_SCAN_IMAGE5)



!TO MAKE THE GRAPH STABLE
!IF MADE IT 1, IT COULD MAKE AN ERROR WHEN CALCULATING LOG
!THEN, I ASSIGNED 1.
B_SCAN_IMAGE3(:,:,1) = 1
B_SCAN_IMAGE3(:,:,2) = 1

!HILBERT TRANSFORM
PRINT *, "HILBERT_TRASFORM"
!HILBERT_A_SCOPE
!!DO X = 1, DIS
!!   DO Y = 1, TRA
!      CALL fft_hilbert(b_scan_image4(x,y,:),rows,hilbert_signal,hilbert_signal_imag) 
      CALL fft_hilbert(b_scan_image4(x,y,:),rows,hilbert_signal) 
!     B_SCAN_IMAGE3(1,Y,:) = HILBERT_SIGNAL(1,1,:)
      HILBERT_B_SCAN(X,Y,:) = HILBERT_SIGNAL(1,1,:)
!      HILBERT_B_SCAN_imag(X,Y,:) = HILBERT_SIGNAL_imag(1,1,:)
!!   END DO
!!END DO

PRINT *, "HILBERT_TRASFORM END"


!!DO Z = 1, ROWS
!!CALCULATE THE MEAN
!!      SLICE_MEAN = SUM(HILBERT_B_SCAN(:,:,ROWS))/ SIZE(HILBERT_B_SCAN(:,:,ROWS))
 
!!REMOVE THE BACKGROUND
!!     HILBERT_B_SCAN(:,:,ROWS) = HILBERT_B_SCAN(:,:,ROWS) - SLICE_MEAN
!!END DO


!!INCLUDE "OUTPUT_A_SCAN.h"  !20
!!INCLUDE "OUTPUT_B_SCAN.h"  !30
!!INCLUDE "OUTPUT_C_SCAN.h"  !40
!!INCLUDE "OUTPUT_HILBERT.h" !50


END PROGRAM
