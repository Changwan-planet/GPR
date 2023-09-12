PROGRAM CSCAN_GPR_EW

USE MD_BASIC
USE MD_FFT_IFFT
USE MD_FFT_HILBERT
USE MD_FILTER
USE MD_MVMEAN
USE MD_INTERPRE
USE MD_MEAN_ASCAN

IMPLICIT NONE

!USE GSSI_PROGRAM
INCLUDE "IN_OUT_PATH_CSCAN.h"
INCLUDE "VARIABLES_CSCAN_EW.h"
INCLUDE "READ_FILES_CSCAN_EW.h"
INCLUDE "OPEN_WRITE_CSCAN.h"

!MANUAL EDIT OF THE POSITIN OF SIGNAL
B_SCAN_IMAGE2 = B_SCAN_IMAGE
!INCLUDE "MANUAL_EDIT_SIGNAL_EW_2022.h"
!INCLUDE "MANUAL_EDIT_SIGNAL_EW_2023.h"


!REMOVE AVERAGE
!DO Y = 1, LINE 
!   CALL mean_ascanx(B_SCAN_IMAGE2(:,Y,:), TRA, ROWS,MEAN2(Y,:))
!END DO 

!DO Y = 1, LINE
!DO Z =1 , ROWS
!      B_SCAN_IMAGE2_rmavrg(:,Y,Z) = B_SCAN_IMAGE2(:,Y,Z) - MEAN2(Y,Z)
!END DO 
!END DO 
 
!PRINT*, "REMOVED AVERAGE OF EACH LINE OF SAMPLES IN THE BSCAN_IMAGE"


!FFT
imag = 0.0   
DO X = 1, DIS
   DO Y = 1, TRA
   CALL fft(B_SCAN_IMAGE2(X,Y,:), imag, ROWS, f_real(X,Y,:), f_imag(X,Y,:))
!    CALL ifft(f_real(1,Y,:), f_imag(1,Y,:), ROWS, ifft_real(1,Y,:), ifft_imag(1,Y,:))l
   END DO 
END DO
PRINT *, "FFT END"


!500MHz HIGH PASS FILTER
!f_c = 80
!k = 3

!DO X = 1, TRA
!   DO Y = 1, LINE
!      CALL hpf_butter(f_real(X,Y,:), f_imag(X,Y,:), ROWS, f_c, k, filter, hpf_real(X,Y,:), hpf_imag(X,Y,:))
!!     !CALL hpf(f_real(X,Y,:), f_imag(X,Y,:), ROWS, BAND, TW, hpf_real(X,Y,:), hpf_imag(X,Y,:))
!   END DO 
!END DO

!IFFT
!DO X = 1, TRA
!   DO Y = 1, LINE
!      CALL ifft(hpf_real(X,Y,:), hpf_imag(X,Y,:), ROWS, ifft_real(X,Y,:), ifft_imag(X,Y,:))
!   END DO
!END DO

!PRINT *, "HPF END"


!40MHz BAND PASS FILTER
f_l = 30
f_h = 115 
k = 2 
!BAND = 30
!PRINT *, "BAND=",BAND


!500MHz BAND PASS FILTER
!f_l = 30
!f_h = 115 
!k = 2 
!BAND = 30
!PRINT *, "BAND=",BAND

DO X = 1, DIS
DO Y = 1, TRA
   CALL bpf_butter(f_real(X,Y,:), f_imag(X,Y,:), ROWS, f_l, f_h, k, filter, bpf_real(X,Y,:), bpf_imag(X,Y,:))
END DO
END DO

!IFFT
DO X = 1, DIS 
DO Y = 1, TRA
  CALL ifft(bpf_real(X,Y,:), bpf_imag(X,Y,:), ROWS, ifft_real(X,Y,:), ifft_imag(X,Y,:))
END DO
END DO 

!PRINT *, "BPF END"

!HILBERT TRANSFORM
!HILBERT_A_SCOPE
!!DO X = 1, DIS
!!  DO Y = 1, TRA
!!      CALL fft_hilbert(B_SCAN_IMAGE2(X,Y,:),ROWS,HILBERT_SIGNAL) 
!      CALL fft_hilbert(ifft_real(X,Y,:), ROWS, HILBERT_SIGNAL)
!!      HILBERT_B_SCAN(X,Y,:) = HILBERT_SIGNAL(1,1,:)
!!   END DO
!!END DO

!GAIN CONTROL BASED ON INSTANTENOUS POWER
!DO X = 1, DIS
!DO Y = 1, TRA
!DO Z = 1, ROWS3
!!   HILBERT_power(X,Y,Z) = SQRT(HILBERT_B_SCAN(X,Y,Z)**2 + B_SCAN_IMAGE6(X,Y,Z)**2)
!    HILBERT_power(X,Y,Z) = SQRT(HILBERT_B_SCAN(X,Y,Z)**2 + ifft_real(X,Y,Z)**2)
!END DO
!END DO
!END DO 

!DO Y = 1, TRA
!   CALL mv_meanz( HILBERT_power(:,Y,:), MV_WIN, DIS, ROWS3, ROWS4, HILBERT_power2(:,Y,:))
! PRINT *, "MV_WIN=",MV_WIN
!END DO
!PRINT*, "GAIN CONTROL END"


!!DO Z = 1, ROWS
!CALCULATE THE MEAN
!!      SLICE_MEAN = SUM(HILBERT_B_SCAN(:,:,ROWS))/ SIZE(HILBERT_B_SCAN(:,:,ROWS))
 
!REMOVE THE BACKGROUND
!!     HILBERT_B_SCAN(:,:,ROWS) = HILBERT_B_SCAN(:,:,ROWS) - SLICE_MEAN
!!END DO

!INCLUDE "OUTPUT_A_SCAN.h"      !20
!INCLUDE "OUTPUT_B_SCAN.h"      !30
INCLUDE "OUTPUT_C_SCAN.h"      !40
!INCLUDE "OUTPUT_FFT.h"        !50
!INCLUDE "OUTPUT_HILBERT.h"    !60
!INCLUDE "OUTPUT_PHASE.h"      !70
!INCLUDE "OUTPUT_FILTER.h"     !80


END PROGRAM
