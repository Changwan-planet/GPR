PROGRAM BSCAN_GPR

USE MD_BASIC
USE MD_BACKGROUND
USE MD_STACKING
USE MD_MEAN_ASCAN
USE MD_MVMEAN
USE MD_FFT_IFFT
USE MD_FFT_HILBERT

USE MD_DFT_IDFT
USE MD_DFT_HILBERT
!USE MD_CROSS_CORRELATION
USE MD_FILTER

IMPLICIT NONE

INCLUDE "IN_OUT_PATH.h"
INCLUDE "VARIABLES_CSCAN.h"
INCLUDE "READ_FILES_CSCAN.h"
INCLUDE "OPEN_WRITE.h"

!======INITIALIZATION======
!===========================

DO Y = 1, TRA
DO X = 1, DIS
!CALCUATE THE BACKGROUND
!      CALL background(B_SCAN_IMAGE3(X,1,:),ROWS,2001,4000,BGR) !KOERA
      CALL background(B_SCAN_IMAGE3(X,Y,:),ROWS,500,600,BGR)  !MOGOD
!REMOVE THE BACKGROUND
      B_SCAN_IMAGE4(X,Y,:) = B_SCAN_IMAGE3(X,Y,:) - BGR
END DO
END DO 

PRINT *, "B_SCAN_IMAGE3(X,1,1)=", B_SCAN_IMAGE3(1,1,1),"BGR=", BGR

!REMOVE MEAN_ASCAN 
!!   CALL mean_ascanx(B_SCAN_IMAGE4(:,1,:), DIS, ROWS, MEAN_A_SCOPE) 
!!DO X = 1, DIS
!!   DO Z = 1, ROWS
!!  B_SCAN_IMAGE5(X, 1, Z) = B_SCAN_IMAGE4(X, 1, Z) - MEAN_A_SCOPE(1,1,Z)
!!   END DO 
!!END DO


!FFT, DFT
imag = 0.0   
DO Y = 1, TRA
DO X = 1, DIS
!   CALL fft(B_SCAN_IMAGE4(X,1,:), imag, ROWS, f_real(X,1,:), f_imag(X,1,:))
   CALL dft(B_SCAN_IMAGE4(X,Y,:), imag, ROWS, f_real(X,Y,:), f_imag(X,Y,:))
!    CALL ifft(f_real(1,Y,:), f_imag(1,Y,:), ROWS, ifft_real(1,Y,:), ifft_imag(1,Y,:))l
END DO
END DO 

!250MHz HIGH PASS FILTER
!f_c = 465
!k = 40

!50MHz HIGH PASS FILTER
!f_c = 490
!k = 40

!500MHz HIGH PASS FILTER
f_c = 80
k = 3

!BAND = 30
!PRINT *, "BAND=",BAND

DO Y = 1, TRA
DO X = 1, DIS
   CALL hpf_butter(f_real(X,Y,:), f_imag(X,Y,:), ROWS, f_c, k, filter, hpf_real(X,Y,:), hpf_imag(X,Y,:))
!   CALL hpf(f_real(X,1,:), f_imag(X,1,:), ROWS, BAND, TW, hpf_real(X,1,:), hpf_imag(X,1,:))
END DO
END DO

!IFFT, IDFT
DO Y = 1, TRA
DO X = 1, DIS
   !CALL ifft(hpf_real(X,1,:), hpf_imag(X,1,:), ROWS, ifft_real(X,1,:), ifft_imag(X,1,:))
   CALL idft(hpf_real(X,Y,:), hpf_imag(X,Y,:), ROWS, ifft_real(X,Y,:), ifft_imag(X,Y,:))
END DO
END DO
!DO Y = 1, TRA
!    CALL dft(STACKED_A_SCOPE(1,Y,:), imag, ROWS, dft_real(1,Y,:), dft_imag(1,Y,:))
!    CALL idft(dft_real(1,Y,:), dft_imag(1,Y,:), ROWS, idft_real(1,Y,:), idft_imag(1,Y,:)) 
!END DO


!HILBERT TRANSFORMATION
!FIRST SCAN
DO Y = 1, TRA
DO X = 1, DIS
!!      CALL fft_hilbert(B_SCAN_IMAGE4(X,1,:), ROWS, HILBERT_SIGNAL)
!!     CALL fft_hilbert(ifft_real(X,1,:), ROWS, HILBERT_SIGNAL)
      CALL dft_hilbert(ifft_real(X,Y,:), ROWS, HILBERT_SIGNAL)
      HILBERT_B_SCAN(X,Y,:) = HILBERT_SIGNAL(1,Y,:) 
END DO
END DO 

!STACKED SCAN WITH THE AMOUNT OF THE DIS
!!DO X = 1, DIS
!!      CALL fft_hilbert(B_SCAN_IMAGE4(X,1,:), ROWS, HILBERT_SIGNAL)
!!      HILBERT_B_SCAN(X,1,:) = HILBERT_SIGNAL(1,1,:) 
!!END DO


!GAIN CONTROL BASED ON INSTANTENOUS POWER
DO Y = 1, TRA
DO X = 1, DIS
DO Z = 1, ROWS
!!   HILBERT_power(X,1,Z) = SQRT(HILBERT_B_SCAN(X,1,Z)**2 + B_SCAN_IMAGE4(X,1,Z)**2)
!!    HILBERT_power(X,1,Z) = SQRT(HILBERT_B_SCAN(X,1,Z)**2 + ifft_real(X,1,Z)**2)
    HILBERT_power(X,Y,Z) = SQRT(HILBERT_B_SCAN(X,Y,Z)**2 + idft_real(X,Y,Z)**2)


END DO
END DO  
END DO

DO Y = 1, TRA  

  CALL mv_meany( HILBERT_power(:,Y,:), MV_WIN, DIS, ROWS, ROWS2, HILBERT_power2(:,Y,:) ) 
  PRINT *, "MV_WIN=",MV_WIN 

END DO 

!CROSS CORRELATION
!! crrl = 0.0 
!!    CALL cross_corl(B_SCAN_IMAGE4(1,1,:), &
!!                    B_SCAN_IMAGE4(1,1,:), ROWS,crrl)   

!    CALL cross_corl(HILBERT_STACKED_SIGNAL(1,1,:), &
!                    HILBERT_STACKED_SIGNAL(1,1,:), ROWS,crrl)

!INCLUDE "OUTPUT_A_SCAN.h"                !20,21,22,23
!INCLUDE "OUTPUT_B_SCAN.h"                !30,31,32,33 
INCLUDE "OUTPUT_C_SCAN.h"                 !80,81
INCLUDE "OUTPUT_HILBERT.h"                !50,51
!INCLUDE "OUTPUT_FFT.h"                   !40  
!INCLUDE "OUTPUT_PHASE.h"                 !60,61
INCLUDE "OUTPUT_FILTER.h"                 !70
INCLUDE "OUTPUT_FILTER_HILBERT.h"         !90,91


END PROGRAM
