!===============MALA=================
INTEGER, PARAMETER :: DIS=1498         !X
INTEGER, PARAMETER :: TRA = 110        !Y
INTEGER, PARAMETER :: ROWS = 616       !Z 616
INTEGER, PARAMETER :: ROWS2 = ROWS -1  !Z 615
INTEGER, PARAMETER :: ROWS3 = 512      !Z 512
!==================================

!===============GSSI=================
!INTEGER, PARAMETER :: DIS=1900      !X
!INTEGER, PARAMETER :: TRA=17        !Y
!INTEGER, PARAMETER :: ROWS=4096     !Z 4096
!==================================

!=======A_SCOPE=============================================
REAL*8, DIMENSION(DIS,TRA,ROWS) :: T_SUM_ASCOPE
!===========================================================

!===========================================================
REAL*8, DIMENSION(ROWS,TRA,DIS) ::  B_SCAN_IMAGE33
REAL*8, DIMENSION(DIS,TRA,ROWS) ::  B_SCAN_IMAGE3
REAL*8, DIMENSION(DIS,TRA,ROWS) ::  B_SCAN_IMAGE4
REAL*8, DIMENSION(DIS,TRA,ROWS2) ::  B_SCAN_IMAGE5
REAL*8, DIMENSION(DIS,TRA,ROWS3)::  B_SCAN_IMAGE6
REAL*8, DIMENSION(DIS,TRA,ROWS2)::  B_SCAN_IMAGE7
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

!=====POWER SPECTRAL DENSITY=====
REAL*8, DIMENSION (DIS, TRA, ROWS2) :: psd
REAL*8, DIMENSION (DIS, TRA, ROWS2) :: psd2
REAL*8, DIMENSION (DIS, TRA, ROWS2) :: psd3
!===========================================

!=====CROSS CORRELATION=====
INTEGER, PARAMETER :: CRRL_N = (2*ROWS2)+1
REAL*8, DIMENSION (CRRL_N):: crrl
INTEGER, DIMENSION (DIS,TRA) :: SHIFT 
!============================================

!=====HILBERT TRANSFORM=====
REAL*8, DIMENSION (1, 1, ROWS2) :: HILBERT_SIGNAL
REAL*8, DIMENSION (DIS, 1, ROWS2) :: HILBERT_B_SCAN
REAL*8, DIMENSION (DIS, 1, ROWS2) :: HILBERT_power
REAL*8, DIMENSION (DIS, 1, ROWS3) :: HILBERT_power2
REAL*8, DIMENSION (DIS, 1, ROWS2) :: HILBERT_powerdB
REAL*8, DIMENSION (DIS, 1, ROWS2) :: HILBERT_powerdB2
!====================================================

!=====ATTRIBUTE ANALYSIS=====
REAL*8, DIMENSION (DIS, 1, ROWS2) :: INST_PHASE
REAL*8, DIMENSION (DIS, 1, ROWS2) :: INST_PHASE2
REAL*8, DIMENSION (DIS, 1, ROWS2) :: INST_FREQUENCY
!====================================================


INTEGER             :: I,J,G,N,P,R, SAMPLE
INTEGER             :: X, Y, Z
REAL*8              :: BGR
REAL*8              :: MEAN
REAL*8              :: SLICE_MEAN, SLICE_MEAN2
REAL*8              :: PI = ACOS(-1.0)
!=============================================================
