!===========MALA===================
!INTEGER, PARAMETER :: DIS = 1555    !X
!INTEGER, PARAMETER :: TRA = 1       !Y
!INTEGER, PARAMETER :: ROWS = 616   !Z 
!INTEGER, PARAMETER :: MV_WIN = 10  !GAIN_CONTROL
!INTEGER, PARAMETER :: ROWS2 =ROWS - (MV_WIN-1) !GAIN_CONTROL
!==================================

!============GSSI=================
INTEGER, PARAMETER :: DIS = 400   !X
INTEGER, PARAMETER :: TRA = 1       !Y
INTEGER, PARAMETER :: ROWS = 4096   !Z 
INTEGER, PARAMETER :: MV_WIN = 100  !GAIN_CONTROL
INTEGER, PARAMETER :: ROWS2 =ROWS - (MV_WIN-1) !GAIN_CONTROL
!==================================

!===========================================================
REAL*8, DIMENSION(DIS,TRA,ROWS) :: B_SCAN_IMAGE3
REAL*8, DIMENSION(DIS,TRA,ROWS) :: B_SCAN_IMAGE4
REAL*8, DIMENSION(DIS,TRA,ROWS2) :: B_SCAN_IMAGE4_GC
REAL*8, DIMENSION(DIS,TRA,ROWS) :: B_SCAN_IMAGE5
REAL*8, DIMENSION(DIS,TRA,ROWS2) :: B_SCAN_IMAGE5_GC
!============================================================      

!============================================================
REAL*8, DIMENSION(  1,  1, ROWS) :: INST_A_SCOPE

!============================================================
REAL*8, DIMENSION(  1,  1,  ROWS2) :: MEAN_A_SCOPE
!============================================================

!============================================================
REAL*8, DIMENSION(1,1,ROWS) :: imag

!=====FAST FOURIER TRANSFORM=====
REAL*8, DIMENSION (DIS, TRA, ROWS) :: f_real
REAL*8, DIMENSION (DIS, TRA, ROWS) :: f_imag
REAL*8, DIMENSION (DIS, TRA, ROWS) :: f_real2
REAL*8, DIMENSION (DIS, TRA, ROWS) :: f_imag2
REAL*8, DIMENSION (DIS, 1, ROWS) :: ifft_real
REAL*8, DIMENSION (DIS, 1, ROWS) :: ifft_imag
!==============================================

!=====FILTER=====
!=====HIGH-PASS FILTER=====
INTEGER :: k, f_c                               !ORDER, cutoff_frequency
REAL*8, DIMENSION (ROWS)         :: TW          !TIME WINDOW
REAL*8, DIMENSION (ROWS)         :: filter      !FILTER
REAL*8, DIMENSION (DIS,TRA,ROWS) :: hpf_real
REAL*8, DIMENSION (DIS,TRA,ROWS) :: hpf_imag
REAL*8, DIMENSION (DIS,TRA,ROWS) :: hpf_power
REAL*8, DIMENSION (DIS,TRA,ROWS) :: hpf_powerdB
REAL*8, DIMENSION (DIS,TRA,ROWS) :: hpf_real2
REAL*8, DIMENSION (DIS,TRA,ROWS) :: hpf_imag2
REAL*8, DIMENSION (DIS,TRA,ROWS) :: hpf_powerdB2
REAL*8, DIMENSION (DIS,TRA,ROWS2) :: hpf_GC 
REAL*8, DIMENSION (DIS,TRA,ROWS) :: hpf_GC2 = 0.0


REAL*8, DIMENSION (DIS,TRA,ROWS2) :: hpf_GC_RMV 
REAL*8, DIMENSION (DIS,TRA,ROWS2) :: hpf_GC_RMV2 


!==============================================


!=====POWER SPECTRAL DENSITY=====
REAL*8, DIMENSION (DIS, TRA, 1:ROWS) :: psd
REAL*8, DIMENSION (DIS, TRA, 1:ROWS) :: psd2
REAL*8, DIMENSION (DIS, TRA, 1:ROWS) :: psd3
!===========================================

!=====CROSS CORRELATION=====
REAL*8, DIMENSION (1, 1, 1:2*ROWS+1):: crrl
!============================================

!=====DISCRETE FOURIER TRANSFORM=====
REAL*8, DIMENSION (1, 1, 1:ROWS) :: dft_real
REAL*8, DIMENSION (1, 1, 1:ROWS) :: dft_imag
REAL*8, DIMENSION (1, 1, 1:ROWS) :: idft_real
REAL*8, DIMENSION (1, 1, 1:ROWS) :: idft_imag
REAL*8, DIMENSION (1, 1, 1:ROWS) :: a_idft_imag
!=============================================

!=====HILBERT TRANSFORM=====
REAL*8, DIMENSION (1, 1, 1:ROWS) :: HILBERT_SIGNAL
REAL*8, DIMENSION (DIS, 1, 1:ROWS) :: HILBERT_B_SCAN
REAL*8, DIMENSION (DIS, 1, 1:ROWS) :: HILBERT_power
REAL*8, DIMENSION (DIS, 1, 1:ROWS2) :: HILBERT_power2 
REAL*8, DIMENSION (DIS, 1, 1:ROWS) :: HILBERT_powerdB
REAL*8, DIMENSION (DIS, 1, 1:ROWS) :: HILBERT_powerdB2
!====================================================

!=====ATTRIBUTE ANALYSIS=====
REAL*8, DIMENSION (DIS, 1, 1:ROWS) :: INST_PHASE
REAL*8, DIMENSION (DIS, 1, 1:ROWS) :: INST_PHASE2
REAL*8, DIMENSION (DIS, 1, 1:ROWS) :: INST_FREQUENCY
!====================================================


INTEGER             :: f,I,J,G,N,P,R, SAMPLE
INTEGER             :: X, Y, Z
INTEGER             :: BAND
INTEGER             :: DIS2
REAL*8              :: BGR
REAL*8              :: MEAN
REAL*8              :: MAX_ASCAN
REAL*8              :: NORM_MEAN, NORM_STDV
REAL*8              :: PI = ACOS(-1.0)
REAL*8              :: C = 3*10**8
REAL*8              :: DEPTH, PER, TIME_WIN, SAMPLE_TIME 
!=============================================================

