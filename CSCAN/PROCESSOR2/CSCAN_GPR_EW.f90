PROGRAM CSCAN_GPR_EW

USE MD_BASIC
USE MD_FFT_IFFT
USE MD_FFT_HILBERT
USE MD_FILTER

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


!ZERO_PADDING
DO X = 1, DIS
   DO Y = 1,  TRA
      CALL zero_padding(B_SCAN_IMAGE4(X,Y,:), ROWS, ROWS2, B_SCAN_IMAGE5(X,Y,:))
   END DO 
END DO 


!FFT
imag = 0.0   
DO X = 1, DIS 
   DO Y = 1, TRA
   CALL fft(B_SCAN_IMAGE5(X,Y,:), imag, ROWS2, f_real(X,1,:), f_imag(X,1,:))
!    CALL ifft(f_real(1,Y,:), f_imag(1,Y,:), ROWS, ifft_real(1,Y,:), ifft_imag(1,Y,:))l
   END DO 
END DO

!500MHz HIGH PASS FILTER
!f_c = 80
!k = 3

DO X = 1, DIS
   DO Y = 1, TRA
      CALL hpf_butter(f_real(X,Y,:), f_imag(X,Y,:), ROWS2, f_c, k, filter, hpf_real(X,Y,:), hpf_imag(X,Y,:))
     !CALL hpf(f_real(X,Y,:), f_imag(X,Y,:), ROWS2, BAND, TW, hpf_real(X,Y,:), hpf_imag(X,Y,:))
   END DO 
END DO


!100MHz BAND PASS FILTER
!f_l = 55
!f_h = 115 
!k = 3 
!BAND = 30
!PRINT *, "BAND=",BAND

!DO X = 1, DIS 
!   CALL bpf_butter(f_real(X,1,:), f_imag(X,1,:), ROWS, f_l, f_h, k, filter, bpf_real(X,1,:), bpf_imag(X,1,:))
!END DO


!IFFT
DO X = 1, DIS
   DO Y = 1, TRA
      CALL ifft(hpf_real(X,Y,:), hpf_imag(X,Y,:), ROWS2, ifft_real(X,Y,:), ifft_imag(X,Y,:))
   END DO
END DO


!HILBERT TRANSFORM
!HILBERT_A_SCOPE
DO X = 1, DIS
  DO Y = 1, TRA
      !CALL fft_hilbert(B_SCAN_IMAGE5(X,Y,:),ROWS2,HILBERT_SIGNAL) 
      CALL fft_hilbert(ifft_real(X,Y,:), ROWS2, HILBERT_SIGNAL)
      HILBERT_B_SCAN(X,Y,:) = HILBERT_SIGNAL(1,Y,:)
   END DO
END DO

!GAIN CONTROL BASED ON INSTANTENOUS POWER
!!DO X = 1, DIS
!!DO Y = 1, TRA
!!DO Z = 1, ROWS2
!   HILBERT_power(X,1,Z) = SQRT(HILBERT_B_SCAN(X,1,Z)**2 + B_SCAN_IMAGE4(X,1,Z)**2)
!!    HILBERT_power(X,Y,Z) = SQRT(HILBERT_B_SCAN(X,Y,Z)**2 + ifft_real(X,Y,Z)**2)
!!END DO
!!END DO
!!END DO 

!!  CALL mv_meany( HILBERT_power, MV_WIN, DIS, ROWS, ROWS2, HILBERT_power2)
!!  PRINT *, "MV_WIN=",MV_WIN


!!DO Z = 1, ROWS
!CALCULATE THE MEAN
!!      SLICE_MEAN = SUM(HILBERT_B_SCAN(:,:,ROWS))/ SIZE(HILBERT_B_SCAN(:,:,ROWS))
 
!REMOVE THE BACKGROUND
!!     HILBERT_B_SCAN(:,:,ROWS) = HILBERT_B_SCAN(:,:,ROWS) - SLICE_MEAN
!!END DO


INCLUDE "OUTPUT_A_SCAN.h"      !20
!INCLUDE "OUTPUT_B_SCAN.h"     !30
!INCLUDE "OUTPUT_C_SCAN.h"     !40
INCLUDE  "OUTPUT_FFT.h"        !50
!INCLUDE "OUTPUT_HILBERT.h"    !60
!INCLUDE "OUTPUT_PHASE.h"      !70
!INCLUDE "OUTPUT_FILTER.h"     !80


END PROGRAM
