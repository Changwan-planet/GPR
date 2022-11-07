PROGRAM CSCAN_GPR_EW

USE MD_BACKGROUND
USE MD_FFT_IFFT
USE MD_FFT_HILBERT
USE MD_DFT_IDFT
USE MD_DFT_HILBERT

IMPLICIT NONE

!USE GSSI_PROGRAM
INCLUDE "IN_OUT_PATH_CSCAN.h"
INCLUDE "VARIABLES_CSCAN_EW.h"
INCLUDE "READ_FILES_CSCAN.h"
INCLUDE "OPEN_WRITE_CSCAN.h"

DO X = 1, DIS
   DO Y = 1, TRA
!CALCULATE THE BACKGROUND
! CALL background(B_SCAN_IMAGE3(X,Y,:),ROWS,2001,4000,BGR)
  CALL background(B_SCAN_IMAGE3(X,Y,:),ROWS,501,600,BGR)
 
!REMOVE THE BACKGROUND
     B_SCAN_IMAGE4(X,Y,:) = B_SCAN_IMAGE3(X,Y,:) - BGR
   END DO 
END DO


!HILBERT TRANSFORM
!HILBERT_A_SCOPE
DO X = 1, DIS
   DO Y = 1, TRA
      CALL dft_hilbert(B_SCAN_IMAGE4(X,Y,:),ROWS,HILBERT_SIGNAL) 
!      CALL fft_hilbert(B_SCAN_IMAGE3(X,Y,:),ROWS,HILBERT_SIGNAL) 

      HILBERT_B_SCAN(X,Y,:) = HILBERT_SIGNAL(1,1,:)
   END DO
END DO

!!DO Z = 1, ROWS
!CALCULATE THE MEAN
!!      SLICE_MEAN = SUM(HILBERT_B_SCAN(:,:,ROWS))/ SIZE(HILBERT_B_SCAN(:,:,ROWS))
 
!REMOVE THE BACKGROUND
!!     HILBERT_B_SCAN(:,:,ROWS) = HILBERT_B_SCAN(:,:,ROWS) - SLICE_MEAN
!!END DO



INCLUDE "OUTPUT_A_SCAN.h"    !20
INCLUDE "OUTPUT_B_SCAN.h"     !30
INCLUDE "OUTPUT_C_SCAN.h"     !40
INCLUDE "OUTPUT_HILBERT.h"   !50
END PROGRAM
