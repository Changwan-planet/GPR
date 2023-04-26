!===============MALA=================
INTEGER, PARAMETER :: DIS=1498         !X
INTEGER, PARAMETER :: TRA = 110        !Y
INTEGER, PARAMETER :: ROWS3 = 512      !Z 512
INTEGER, PARAMETER :: MV_WIN = 10      !GAIN_CONTROL
INTEGER, PARAMETER :: ROWS4 = ROWS3 - (MV_WIN-1) !GAIN_CONTROL

!==================================

!===============GSSI=================
!INTEGER, PARAMETER :: DIS=1900      !X
!INTEGER, PARAMETER :: TRA=17        !Y
!INTEGER, PARAMETER :: ROWS=4096     !Z 4096
!==================================

!===========================================================
REAL*8, DIMENSION(ROWS3,TRA,DIS) ::  B_SCAN_IMAGE66
REAL*8, DIMENSION(DIS,TRA,ROWS3) ::  B_SCAN_IMAGE6
REAL*8, DIMENSION(DIS,TRA,ROWS4) ::  B_SCAN_IMAGE6_GC
REAL*8, DIMENSION(DIS,TRA,ROWS3) ::  B_SCAN_IMAGE7
REAL*8, DIMENSION(DIS,TRA,ROWS3) :: B_SCAN_IMAGE8
REAL*8, DIMENSION(DIS,TRA,ROWS4) :: B_SCAN_IMAGE8_GC
REAL*8, DIMENSION(DIS,TRA,ROWS4):: B_SCAN_IMAGE9
REAL*8, DIMENSION(DIS,TRA,ROWS4):: B_SCAN_IMAGE9_GC
!============================================================

REAL*8, DIMENSION(1,1,ROWS3) :: imag

!=====FAST FOURIER TRANSFORM===================
REAL*8, DIMENSION (DIS, TRA, ROWS3) :: f_real
REAL*8, DIMENSION (DIS, TRA, ROWS3) :: f_imag
REAL*8, DIMENSION (DIS, TRA, ROWS3) :: f_real2
REAL*8, DIMENSION (DIS, TRA, ROWS3) :: f_imag2
REAL*8, DIMENSION (DIS, TRA, ROWS3) :: ifft_real
REAL*8, DIMENSION (DIS, TRA, ROWS3) :: ifft_imag
!==============================================


!=====FILTER=====
!=====HIGH-PASS FILTER=====
INTEGER :: k, f_c                                !ORDER, cutoff_frequency
REAL*8, DIMENSION (ROWS3)         :: TW          !TIME WINDOW
REAL*8, DIMENSION (ROWS3)         :: filter      !FILTER
REAL*8, DIMENSION (DIS,TRA,ROWS3) :: hpf_real
REAL*8, DIMENSION (DIS,TRA,ROWS3) :: hpf_imag
REAL*8, DIMENSION (DIS,TRA,ROWS3) :: hpf_power
REAL*8, DIMENSION (DIS,TRA,ROWS3) :: hpf_powerdB
REAL*8, DIMENSION (DIS,TRA,ROWS3) :: hpf_real2
REAL*8, DIMENSION (DIS,TRA,ROWS3) :: hpf_imag2
REAL*8, DIMENSION (DIS,TRA,ROWS3) :: hpf_powerdB2
REAL*8, DIMENSION (DIS,TRA,ROWS4) :: hpf_GC 
REAL*8, DIMENSION (DIS,TRA,ROWS3) :: hpf_GC2 = 0.0 

REAL*8, DIMENSION (DIS,TRA,ROWS3) :: hpf_GC_RMV 
REAL*8, DIMENSION (DIS,TRA,ROWS3) :: hpf_GC_RMV2 
!==============================================

!=====FILTER=====
!=====BAND-PASS FILTER=====
INTEGER :: f_l,f_h                           !ORDER, cutoff_frequency
REAL*8, DIMENSION (DIS,TRA,ROWS3) :: bpf_real
REAL*8, DIMENSION (DIS,TRA,ROWS3) :: bpf_imag
REAL*8, DIMENSION (DIS,TRA,ROWS3) :: bpf_power
REAL*8, DIMENSION (DIS,TRA,ROWS3) :: bpf_powerdB
REAL*8, DIMENSION (DIS,TRA,ROWS3) :: bpf_real2b
REAL*8, DIMENSION (DIS,TRA,ROWS3) :: bpf_imag2
REAL*8, DIMENSION (DIS,TRA,ROWS3) :: bpf_powerdB2
REAL*8, DIMENSION (DIS,TRA,ROWS4) :: bpf_GC = 0.0 
REAL*8, DIMENSION (DIS,TRA,ROWS4) :: bpf_GC_RMV = 0.0 
!==============================================



!=====POWER SPECTRAL DENSITY=====
REAL*8, DIMENSION (DIS, TRA, ROWS3) :: psd
REAL*8, DIMENSION (DIS, TRA, ROWS3) :: psd2
REAL*8, DIMENSION (DIS, TRA, ROWS3) :: psd3
!===========================================

!=====CROSS CORRELATION=====
REAL*8, DIMENSION (1, 1, 2*ROWS3+1):: crrl
!============================================

!=====HILBERT TRANSFORM=====
REAL*8, DIMENSION (1, 1, ROWS3) :: HILBERT_SIGNAL
REAL*8, DIMENSION (DIS, TRA, ROWS3) :: HILBERT_B_SCAN
REAL*8, DIMENSION (DIS, TRA, ROWS3) :: HILBERT_power
REAL*8, DIMENSION (DIS, TRA, ROWS4) :: HILBERT_power2


REAL*8, DIMENSION (DIS, TRA, ROWS3) :: HILBERT_powerdB
REAL*8, DIMENSION (DIS, TRA, ROWS3) :: HILBERT_powerdB2
!====================================================

!=====ATTRIBUTE ANALYSIS=====
REAL*8, DIMENSION (DIS, TRA, ROWS3) :: INST_PHASE
REAL*8, DIMENSION (DIS, TRA, ROWS3) :: INST_PHASE2
REAL*8, DIMENSION (DIS, TRA, ROWS3) :: INST_FREQUENCY
!====================================================

!=====INTERPETATION=====
INTEGER :: S1, S2
INTEGER, DIMENSION(DIS) :: H_1          !HORIZON
!====================================================

INTEGER             :: I,J,G,N,P,R, SAMPLE
INTEGER             :: X, Y, Z
REAL*8              :: BGR
REAL*8              :: MEAN
REAL*8              :: SLICE_MEAN, SLICE_MEAN2
REAL*8              :: PI = ACOS(-1.0)
!=============================================================
