!===============MALA=================
INTEGER, PARAMETER :: DIS=1498         !X
INTEGER, PARAMETER :: TRA = 110        !Y
INTEGER, PARAMETER :: ROWS = 616       !Z 616
INTEGER, PARAMETER :: ROWS2 = 512      !Z 512
INTEGER, PARAMETER :: MV_WIN = 10      !GAIN_CONTROL
INTEGER, PARAMETER :: ROWS3 = ROWS2 - (MV_WIN-1) !GAIN_CONTROL

!==================================

!===============GSSI=================
!INTEGER, PARAMETER :: DIS=1900      !X
!INTEGER, PARAMETER :: TRA=17        !Y
!INTEGER, PARAMETER :: ROWS=4096     !Z 4096
!==================================

!===========================================================
REAL*8, DIMENSION(ROWS,TRA,DIS) ::  B_SCAN_IMAGE33
REAL*8, DIMENSION(DIS,TRA,ROWS) ::  B_SCAN_IMAGE3
REAL*8, DIMENSION(DIS,TRA,ROWS) ::  B_SCAN_IMAGE4
REAL*8, DIMENSION(DIS,TRA,ROWS2) :: B_SCAN_IMAGE5
REAL*8, DIMENSION(DIS,TRA,ROWS3) :: B_SCAN_IMAGE5_GC
REAL*8, DIMENSION(DIS,TRA,ROWS3):: B_SCAN_IMAGE6
REAL*8, DIMENSION(DIS,TRA,ROWS3):: B_SCAN_IMAGE6_GC
!============================================================

REAL*8, DIMENSION(1,1,ROWS) :: imag

!=====FAST FOURIER TRANSFORM===================
REAL*8, DIMENSION (DIS, TRA, ROWS2) :: f_real
REAL*8, DIMENSION (DIS, TRA, ROWS2) :: f_imag
REAL*8, DIMENSION (DIS, TRA, ROWS2) :: f_real2
REAL*8, DIMENSION (DIS, TRA, ROWS2) :: f_imag2
REAL*8, DIMENSION (DIS, TRA, ROWS2) :: ifft_real
REAL*8, DIMENSION (DIS, TRA, ROWS2) :: ifft_imag
!==============================================


!=====FILTER=====
!=====HIGH-PASS FILTER=====
INTEGER :: k, f_c                                !ORDER, cutoff_frequency
REAL*8, DIMENSION (ROWS2)         :: TW          !TIME WINDOW
REAL*8, DIMENSION (ROWS2)         :: filter      !FILTER
REAL*8, DIMENSION (DIS,TRA,ROWS2) :: hpf_real
REAL*8, DIMENSION (DIS,TRA,ROWS2) :: hpf_imag
REAL*8, DIMENSION (DIS,TRA,ROWS2) :: hpf_power
REAL*8, DIMENSION (DIS,TRA,ROWS2) :: hpf_powerdB
REAL*8, DIMENSION (DIS,TRA,ROWS2) :: hpf_real2
REAL*8, DIMENSION (DIS,TRA,ROWS2) :: hpf_imag2
REAL*8, DIMENSION (DIS,TRA,ROWS2) :: hpf_powerdB2
REAL*8, DIMENSION (DIS,TRA,ROWS3) :: hpf_GC 
REAL*8, DIMENSION (DIS,TRA,ROWS2) :: hpf_GC2 = 0.0 

REAL*8, DIMENSION (DIS,TRA,ROWS2) :: hpf_GC_RMV 
REAL*8, DIMENSION (DIS,TRA,ROWS2) :: hpf_GC_RMV2 
!==============================================

!=====FILTER=====
!=====BAND-PASS FILTER=====
INTEGER :: f_l,f_h                           !ORDER, cutoff_frequency
REAL*8, DIMENSION (DIS,TRA,ROWS2) :: bpf_real
REAL*8, DIMENSION (DIS,TRA,ROWS2) :: bpf_imag
REAL*8, DIMENSION (DIS,TRA,ROWS2) :: bpf_power
REAL*8, DIMENSION (DIS,TRA,ROWS2) :: bpf_powerdB
REAL*8, DIMENSION (DIS,TRA,ROWS2) :: bpf_real2b
REAL*8, DIMENSION (DIS,TRA,ROWS2) :: bpf_imag2
REAL*8, DIMENSION (DIS,TRA,ROWS2) :: bpf_powerdB2
REAL*8, DIMENSION (DIS,TRA,ROWS3) :: bpf_GC = 0.0 
REAL*8, DIMENSION (DIS,TRA,ROWS3) :: bpf_GC_RMV = 0.0 
!==============================================



!=====POWER SPECTRAL DENSITY=====
REAL*8, DIMENSION (DIS, TRA, ROWS2) :: psd
REAL*8, DIMENSION (DIS, TRA, ROWS2) :: psd2
REAL*8, DIMENSION (DIS, TRA, ROWS2) :: psd3
!===========================================

!=====CROSS CORRELATION=====
REAL*8, DIMENSION (1, 1, 2*ROWS+1):: crrl
!============================================

!=====HILBERT TRANSFORM=====
REAL*8, DIMENSION (1, 1, ROWS2) :: HILBERT_SIGNAL
REAL*8, DIMENSION (DIS, TRA, ROWS2) :: HILBERT_B_SCAN
REAL*8, DIMENSION (DIS, TRA, ROWS2) :: HILBERT_power
REAL*8, DIMENSION (DIS, TRA, ROWS3) :: HILBERT_power2


REAL*8, DIMENSION (DIS, TRA, ROWS2) :: HILBERT_powerdB
REAL*8, DIMENSION (DIS, TRA, ROWS2) :: HILBERT_powerdB2
!====================================================

!=====ATTRIBUTE ANALYSIS=====
REAL*8, DIMENSION (DIS, TRA, ROWS2) :: INST_PHASE
REAL*8, DIMENSION (DIS, TRA, ROWS2) :: INST_PHASE2
REAL*8, DIMENSION (DIS, TRA, ROWS2) :: INST_FREQUENCY
!====================================================


INTEGER             :: I,J,G,N,P,R, SAMPLE
INTEGER             :: X, Y, Z
REAL*8              :: BGR
REAL*8              :: MEAN
REAL*8              :: SLICE_MEAN, SLICE_MEAN2
REAL*8              :: PI = ACOS(-1.0)
!=============================================================
