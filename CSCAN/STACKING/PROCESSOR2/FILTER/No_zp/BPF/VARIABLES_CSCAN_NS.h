!===============MALA=================
!INTEGER, PARAMETER :: DIS=1498         !X
!INTEGER, PARAMETER :: TRA = 110        !Y
!INTEGER, PARAMETER :: ROWS3 = 512      !Z 512
!INTEGER, PARAMETER :: MV_WIN = 10      !GAIN_CONTROL
!INTEGER, PARAMETER :: ROWS4 = ROWS3 - (MV_WIN-1) !GAIN_CONTROL
!==================================


!===============GSSI=================
INTEGER, PARAMETER :: LINE = 1       !X FOR STACKING
!INTEGER, PARAMETER :: DIS =          !X
INTEGER, PARAMETER :: TRA = 73        !Y
INTEGER, PARAMETER :: ROWS = 4096     !Z 4096
INTEGER, PARAMETER :: MV_WIN = 100      !GAIN_CONTROL
INTEGER, PARAMETER :: ROWS2 = ROWS - (MV_WIN-1) !GAIN_CONTROL
!==================================


!===========================================================
REAL*8, DIMENSION(ROWS,TRA,LINE) ::  B_SCAN_IMAGE6
REAL*8, DIMENSION(LINE,TRA,ROWS) ::  B_SCAN_IMAGE7

REAL*8, DIMENSION(TRA,LINE,ROWS) :: B_SCAN_IMAGE8
!REAL*8, DIMENSION(TRA,LINE,ROWS2) :: B_SCAN_IMAGE8_GC
!REAL*8, DIMENSION(TRA,LINE,ROWS):: B_SCAN_IMAGE9
!REAL*8, DIMENSION(TRA,LINE,ROWS2):: B_SCAN_IMAGE9_GC
!============================================================

REAL*8, DIMENSION(1,1,ROWS) :: imag

!=====FAST FOURIER TRANSFORM===================
REAL*8, DIMENSION (TRA,LINE,ROWS) :: f_real
REAL*8, DIMENSION (TRA,LINE,ROWS) :: f_imag
REAL*8, DIMENSION (TRA,LINE,ROWS) :: f_real2
REAL*8, DIMENSION (TRA,LINE,ROWS) :: f_imag2
REAL*8, DIMENSION (TRA,LINE,ROWS) :: ifft_real
REAL*8, DIMENSION (TRA,LINE,ROWS) :: ifft_imag
!==============================================


!=====FILTER=====
!=====HIGH-PASS FILTER=====
INTEGER :: k, f_c                                !ORDER, cutoff_frequency
REAL*8, DIMENSION (ROWS)         :: TW          !TIME WINDOW
REAL*8, DIMENSION (ROWS)         :: filter      !FILTER
REAL*8, DIMENSION (TRA,LINE,ROWS) :: hpf_real
REAL*8, DIMENSION (TRA,LINE,ROWS) :: hpf_imag
REAL*8, DIMENSION (TRA,LINE,ROWS) :: hpf_power
REAL*8, DIMENSION (TRA,LINE,ROWS) :: hpf_powerdB
REAL*8, DIMENSION (TRA,LINE,ROWS) :: hpf_real2
REAL*8, DIMENSION (TRA,LINE,ROWS) :: hpf_imag2
REAL*8, DIMENSION (TRA,LINE,ROWS) :: hpf_powerdB2
!REAL*8, DIMENSION (TRA,LINE,ROWS) :: hpf_GC 
!REAL*8, DIMENSION (TRA,LINE,ROWS) :: hpf_GC2 = 0.0 

!REAL*8, DIMENSION (TRA,LINE,ROWS) :: hpf_GC_RMV 
!REAL*8, DIMENSION (TRA,LINE,ROWS) :: hpf_GC_RMV2 
!==============================================

!=====FILTER=====
!=====BAND-PASS FILTER=====
INTEGER :: f_l,f_h                           !ORDER, cutoff_frequency
REAL*8, DIMENSION (TRA,LINE,ROWS) :: bpf_real
REAL*8, DIMENSION (TRA,LINE,ROWS) :: bpf_imag
REAL*8, DIMENSION (TRA,LINE,ROWS) :: bpf_power
REAL*8, DIMENSION (TRA,LINE,ROWS) :: bpf_powerdB
REAL*8, DIMENSION (TRA,LINE,ROWS) :: bpf_real2b
REAL*8, DIMENSION (TRA,LINE,ROWS) :: bpf_imag2
REAL*8, DIMENSION (TRA,LINE,ROWS) :: bpf_powerdB2
!REAL*8, DIMENSION (TRA,LINE,ROWS) :: bpf_GC = 0.0 
!REAL*8, DIMENSION (TRA,LINE,ROWS) :: bpf_GC_RMV = 0.0 
!============================================



!=====POWER SPECTRAL DENSITY=====
REAL*8, DIMENSION (TRA,LINE,ROWS) :: psd
REAL*8, DIMENSION (TRA,LINE,ROWS) :: psd2
REAL*8, DIMENSION (TRA,LINE,ROWS) :: psd3
!==========================================

!=====CROSS CORRELATION=====
!REAL*8, DIMENSION (1, 1, 2*ROWS+1):: crrl
!============================================

!=====HILBERT TRANSFORM=====
REAL*8, DIMENSION (1, 1, ROWS) :: HILBERT_SIGNAL
REAL*8, DIMENSION (TRA,LINE,ROWS) :: HILBERT_B_SCAN
REAL*8, DIMENSION (TRA,LINE,ROWS) :: HILBERT_power
REAL*8, DIMENSION (TRA,LINE,ROWS) :: HILBERT_powerlog


!REAL*8, DIMENSION (TRA,LINE,ROWS) :: HILBERT_power2


REAL*8, DIMENSION (TRA,LINE,ROWS) :: HILBERT_powerdB
!REAL*8, DIMENSION (TRA,LINE,ROWS) :: HILBERT_powerdB2
!====================================================

!=====ATTRIBUTE ANALYSIS=====
REAL*8, DIMENSION (TRA,LINE,ROWS) :: INST_PHASE
REAL*8, DIMENSION (TRA,LINE,ROWS) :: INST_PHASE2
REAL*8, DIMENSION (TRA,LINE,ROWS) :: INST_FREQUENCY
!====================================================



INTEGER             :: I,J,G,N,P,R, SAMPLE
INTEGER             :: X, Y, Z
REAL*8              :: BGR
REAL*8              :: MEAN
REAL*8, DIMENSION(LINE, ROWS) :: MEAN2
REAL*8              :: SLICE_MEAN, SLICE_MEAN2
REAL*8              :: PI = ACOS(-1.0)
!=============================================================
