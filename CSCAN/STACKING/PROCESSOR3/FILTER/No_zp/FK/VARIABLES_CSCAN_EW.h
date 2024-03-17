!===============MALA=================
!INTEGER, PARAMETER :: DIS=1498         !X
!INTEGER, PARAMETER :: TRA = 110        !Y
!INTEGER, PARAMETER :: ROWS3 = 512      !Z 512
!INTEGER, PARAMETER :: MV_WIN = 10      !GAIN_CONTROL
!INTEGER, PARAMETER :: ROWS4 = ROWS3 - (MV_WIN-1) !GAIN_CONTROL
!==================================


!===============GSSI=================
INTEGER, PARAMETER :: DIS = 41        !X NUMBER OF POINT
INTEGER, PARAMETER :: TRA = 21        !Y NUMBER OF TRACK
INTEGER, PARAMETER :: ROWS = 4096     !Z 4096
INTEGER, PARAMETER :: MV_WIN = 100      !GAIN_CONTROL
INTEGER, PARAMETER :: ROWS2 = ROWS - (MV_WIN-1) !GAIN_CONTROL
!==================================


!===========================================================
REAL*8, DIMENSION(DIS,TRA,ROWS) ::  B_SCAN_IMAGE
REAL*8, DIMENSION(DIS,TRA,ROWS) ::  B_SCAN_IMAGE2
REAL*8, DIMENSION(DIS,TRA,ROWS) ::  B_SCAN_IMAGE2_rmavrg


REAL*8, DIMENSION(DIS,TRA,ROWS2) ::  B_SCAN_IMAGE2_GC




!REAL*8, DIMENSION(DIS,TRA,ROWS) :: B_SCAN_IMAGE7_E
!REAL*8, DIMENSION(DIS,TRA,ROWS) :: B_SCAN_IMAGE8
!REAL*8, DIMENSION(DIS,TRA,ROWS2) :: B_SCAN_IMAGE8_GC
!REAL*8, DIMENSION(DIS,TRA,ROWS):: B_SCAN_IMAGE9
!REAL*8, DIMENSION(DIS,TRA,ROWS2):: B_SCAN_IMAGE9_GC
!============================================================

REAL*8, DIMENSION(1,1,ROWS) :: imag

!=====FAST FOURIER TRANSFORM===================
REAL*8, DIMENSION (DIS,TRA,ROWS) :: f_real
REAL*8, DIMENSION (DIS,TRA,ROWS) :: f_imag
REAL*8, DIMENSION (DIS,TRA,ROWS) :: f_real2
REAL*8, DIMENSION (DIS,TRA,ROWS) :: f_imag2
REAL*8, DIMENSION (DIS,TRA,ROWS) :: ifft_real
REAL*8, DIMENSION (DIS,TRA,ROWS) :: ifft_imag
REAL*8, DIMENSION (DIS,TRA,ROWS) :: f_power
REAL*8, DIMENSION (DIS,TRA,ROWS) :: f_pdB

!==============================================


!=====FILTER=====
!=====HIGH-PASS FILTER=====
INTEGER :: k, f_c                                !ORDER, cutoff_frequency
REAL*8, DIMENSION (ROWS)         :: TW          !TIME WINDOW
REAL*8, DIMENSION (ROWS)         :: filter      !FILTER
REAL*8, DIMENSION (DIS,TRA,ROWS) :: hpf_real
REAL*8, DIMENSION (DIS,TRA,ROWS) :: hpf_imag
REAL*8, DIMENSION (DIS,TRA,ROWS) :: hpf_real2
REAL*8, DIMENSION (DIS,TRA,ROWS) :: hpf_imag2
REAL*8, DIMENSION (DIS,TRA,ROWS) :: hpf_powerdB2
REAL*8, DIMENSION (DIS,TRA,ROWS) :: hpf_GC 
REAL*8, DIMENSION (DIS,TRA,ROWS) :: hpf_GC2 = 0.0 

REAL*8, DIMENSION (DIS,TRA,ROWS) :: hpf_GC_RMV 
REAL*8, DIMENSION (DIS,TRA,ROWS) :: hpf_GC_RMV2
REAL*8, DIMENSION (DIS,TRA,ROWS) :: hpf_power
REAL*8, DIMENSION (DIS,TRA,ROWS) :: hpf_pdB
 
!==============================================

!=====FILTER=====
!=====BAND-PASS FILTER=====
INTEGER :: f_l,f_h                           !ORDER, cutoff_frequency
REAL*8, DIMENSION (DIS,TRA,ROWS) :: bpf_real
REAL*8, DIMENSION (DIS,TRA,ROWS) :: bpf_imag
REAL*8, DIMENSION (DIS,TRA,ROWS) :: bpf_power
REAL*8, DIMENSION (DIS,TRA,ROWS) :: bpf_powerdB
REAL*8, DIMENSION (DIS,TRA,ROWS) :: bpf_real2b
REAL*8, DIMENSION (DIS,TRA,ROWS) :: bpf_imag2
REAL*8, DIMENSION (DIS,TRA,ROWS) :: bpf_powerdB2
REAL*8, DIMENSION (DIS,TRA,ROWS) :: bpf_GC = 0.0 
REAL*8, DIMENSION (DIS,TRA,ROWS) :: bpf_GC_RMV = 0.0 
!============================================



!=====FILTER=====
!=====FK FILTER=====
REAL*8, DIMENSION (DIS, TRA, ROWS) :: fk_real
REAL*8, DIMENSION (DIS, TRA, ROWS) :: fk_imag

!============================================




!=====POWER SPECTRAL DENSITY=====
REAL*8, DIMENSION (DIS,TRA,ROWS) :: psd_val
REAL*8, DIMENSION (DIS,TRA,ROWS) :: psd2
REAL*8, DIMENSION (DIS,TRA,ROWS) :: psd3
REAL*8, DIMENSION (DIS,TRA,ROWS) :: psd_test

!==========================================

!=====CROSS CORRELATION=====
REAL*8, DIMENSION (1, 1, 2*ROWS+1):: crrl
!============================================

!=====HILBERT TRANSFORM=====
REAL*8, DIMENSION (1, 1, ROWS) :: HILBERT_SIGNAL
REAL*8, DIMENSION (DIS,TRA,ROWS) :: HILBERT_B_SCAN
REAL*8, DIMENSION (DIS,TRA,ROWS) :: HILBERT_power
REAL*8, DIMENSION (DIS,TRA,ROWS) :: HILBERT_powerlog

REAL*8, DIMENSION (DIS,TRA,ROWS) :: HILBERT_power2


REAL*8, DIMENSION (DIS,TRA,ROWS) :: HILBERT_powerdB
REAL*8, DIMENSION (DIS,TRA,ROWS) :: HILBERT_powerdB2
!====================================================

!=====ATTRIBUTE ANALYSIS=====
REAL*8, DIMENSION (DIS,TRA,ROWS) :: INST_PHASE
REAL*8, DIMENSION (DIS,TRA,ROWS) :: INST_PHASE2
REAL*8, DIMENSION (DIS,TRA,ROWS) :: INST_FREQUENCY
!====================================================



INTEGER             :: I,J,G,N,P,R, SAMPLE
INTEGER             :: X, Y, Z
INTEGER             :: XX, YY, ZZ
INTEGER             :: EDIT, EDIT2
REAL*8              :: BGR
REAL*8              :: MEAN
REAL*8, DIMENSION(TRA, ROWS) :: MEAN2
REAL*8              :: SLICE_MEAN, SLICE_MEAN2
REAL*8              :: PI = ACOS(-1.0)
!=============================================================
