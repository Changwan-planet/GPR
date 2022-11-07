PROGRAM BSCAN_GPR

USE MD_BASIC
USE MD_BACKGROUND
USE MD_STACKING
USE MD_MEAN_ASCAN
USE MD_MVMEAN
!USE MD_FFT_IFFT
!USE MD_FFT_HILBERT

USE MD_DFT_IDFT
USE MD_DFT_HILBERT
!USE MD_CROSS_CORRELATION
USE MD_FILTER

IMPLICIT NONE

INCLUDE "IN_OUT_PATH.h"
INCLUDE "VARIABLES_BSCAN.h"
INCLUDE "READ_FILES_BSCAN.h"
INCLUDE "OPEN_WRITE.h"

!======INITIALIZATION======
!===========================
DO X = 1, DIS
!CALCUATE THE BACKGROUND
!      CALL background(B_SCAN_IMAGE3(X,1,:),ROWS,2001,4000,BGR) !KOERA
      CALL background(B_SCAN_IMAGE3(X,1,:),ROWS,959,999,BGR)  !MOGOD
!REMOVE THE BACKGROUND
      B_SCAN_IMAGE4(X,1,:) = B_SCAN_IMAGE3(X,1,:) - BGR
END DO

PRINT *, "B_SCAN_IMAGE3(X,1,1)=", B_SCAN_IMAGE3(1,1,1),"BGR=", BGR

!REMOVE MEAN_ASCAN 
!!   CALL mean_ascanx(B_SCAN_IMAGE4(:,1,:), DIS, ROWS, MEAN_A_SCOPE) 
!!DO X = 1, DIS
!!   DO Z = 1, ROWS
!!  B_SCAN_IMAGE5(X, 1, Z) = B_SCAN_IMAGE4(X, 1, Z) - MEAN_A_SCOPE(1,1,Z)
!!   END DO 
!!END DO


!FFT
imag = 0.0   
DO X = 1, DIS
!   CALL fft(B_SCAN_IMAGE4(X,1,:), imag, ROWS, f_real(X,1,:), f_imag(X,1,:))
   CALL dft(B_SCAN_IMAGE4(X,1,:), imag, ROWS, f_real(X,1,:), f_imag(X,1,:))
!    CALL ifft(f_real(1,Y,:), f_imag(1,Y,:), ROWS, ifft_real(1,Y,:), ifft_imag(1,Y,:))l
END DO

!HIGH PASS FILTER
f_c = 465
k = 40

!BAND = 30
!PRINT *, "BAND=",BAND

DO X = 1, DIS
   CALL hpf_butter(f_real(X,1,:), f_imag(X,1,:), ROWS, f_c, k, filter, hpf_real(X,1,:), hpf_imag(X,1,:))
!   CALL hpf(f_real(X,1,:), f_imag(X,1,:), ROWS, BAND, TW, hpf_real(X,1,:), hpf_imag(X,1,:))
END DO

!IFFT
DO X = 1, DIS
!   CALL ifft(hpf_real(X,1,:), hpf_imag(X,1,:), ROWS, ifft_real(X,1,:), ifft_imag(X,1,:))
   CALL idft(hpf_real(X,1,:), hpf_imag(X,1,:), ROWS, ifft_real(X,1,:), ifft_imag(X,1,:))
END DO

!DO Y = 1, TRA
!    CALL dft(STACKED_A_SCOPE(1,Y,:), imag, ROWS, dft_real(1,Y,:), dft_imag(1,Y,:))
!    CALL idft(dft_real(1,Y,:), dft_imag(1,Y,:), ROWS, idft_real(1,Y,:), idft_imag(1,Y,:)) 
!END DO


!HILBERT TRANSFORMATION
!FIRST SCAN
DO X = 1, DIS
!!      CALL fft_hilbert(B_SCAN_IMAGE4(X,1,:), ROWS, HILBERT_SIGNAL)
!     CALL fft_hilbert(ifft_real(X,1,:), ROWS, HILBERT_SIGNAL)
      CALL dft_hilbert(ifft_real(X,1,:), ROWS, HILBERT_SIGNAL)
      HILBERT_B_SCAN(X,1,:) = HILBERT_SIGNAL(1,1,:) 
END DO

!STACKED SCAN WITH THE AMOUNT OF THE DIS
!!DO X = 1, DIS
!!      CALL fft_hilbert(B_SCAN_IMAGE4(X,1,:), ROWS, HILBERT_SIGNAL)
!!      HILBERT_B_SCAN(X,1,:) = HILBERT_SIGNAL(1,1,:) 
!!END DO


!GAIN CONTROL BASED ON INSTANTENOUS POWER
DO X = 1, DIS
DO Z = 1, ROWS
!!   HILBERT_power(X,1,Z) = SQRT(HILBERT_B_SCAN(X,1,Z)**2 + B_SCAN_IMAGE4(X,1,Z)**2)
    HILBERT_power(X,1,Z) = SQRT(HILBERT_B_SCAN(X,1,Z)**2 + ifft_real(X,1,Z)**2)
END DO
END DO  
  
  CALL mv_meany( HILBERT_power, MV_WIN, DIS, ROWS, ROWS2, HILBERT_power2) 
  PRINT *, "MV_WIN=",MV_WIN 

!CROSS CORRELATION
!! crrl = 0.0 
!!    CALL cross_corl(B_SCAN_IMAGE4(1,1,:), &
!!                    B_SCAN_IMAGE4(1,1,:), ROWS,crrl)   

!    CALL cross_corl(HILBERT_STACKED_SIGNAL(1,1,:), &
!                    HILBERT_STACKED_SIGNAL(1,1,:), ROWS,crrl)

INCLUDE "OUTPUT_A_SCAN.h"                   !20,21,22,23
INCLUDE "OUTPUT_B_SCAN.h"                   !30,31,32,33 
INCLUDE "OUTPUT_FFT.h"                      !40  
!!INCLUDE "OUTPUT_HILBERT.h"                !50,51
!!INCLUDE "OUTPUT_PHASE.h"                  !60,61
INCLUDE "OUTPUT_FILTER.h"                   !70

END PROGRAM
