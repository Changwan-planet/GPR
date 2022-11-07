!===========MALA-MONGOLIA==========
!INTEGER, PARAMETER :: DIS = 1547    !X
!INTEGER, PARAMETER :: TRA = 1       !Y
!INTEGER, PARAMETER :: ROWS = 616   !Z 
!INTEGER, PARAMETER :: MV_WIN = 10  !GAIN_CONTROL
!INTEGER, PARAMETER :: ROWS2 =ROWS - (MV_WIN-1) !GAIN_CONTROL
!==================================

!===========MALA-HIGH===================
!INTEGER, PARAMETER :: DIS = 1055    !X
!INTEGER, PARAMETER :: TRA = 1       !Y
!INTEGER, PARAMETER :: ROWS = 1013   !Z   HDR_HIGH 
!INTEGER, PARAMETER :: MV_WIN = 10  !GAIN_CONTROL
!INTEGER, PARAMETER :: ROWS2 =ROWS - (MV_WIN-1) !GAIN_CONTROL
!==================================

!===========MALA-LOW===================
!INTEGER, PARAMETER :: DIS = 1055    !X
!INTEGER, PARAMETER :: TRA = 1       !Y
!INTEGER, PARAMETER :: ROWS = 999    !Z   HDR_LOW 
!INTEGER, PARAMETER :: MV_WIN = 10  !GAIN_CONTROL
!INTEGER, PARAMETER :: ROWS2 =ROWS - (MV_WIN-1) !GAIN_CONTROL
!==================================


!============GSSI=================
INTEGER, PARAMETER :: DIS = 1901   !X
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
REAL*8, DIMENSION(  1,  1,  ROWS) :: MEAN_A_SCOPE
!============================================================

!============================================================
REAL*8, DIMENSION(1,1,ROWS) :: imag


REAL*8, DIMENSION (1, TRA, 1:ROWS) :: f_real
REAL*8, DIMENSION (1, TRA, 1:ROWS) :: f_imag
REAL*8, DIMENSION (1, 1, 1:ROWS) :: ifft_real
REAL*8, DIMENSION (1, 1, 1:ROWS) :: ifft_imag

REAL*8, DIMENSION (1, TRA, 1:ROWS) :: psd
REAL*8, DIMENSION (1, TRA, 1:ROWS) :: psd2

REAL*8, DIMENSION (1, 1, 1:2*ROWS+1):: crrl

REAL*8, DIMENSION (1, 1, 1:ROWS) :: dft_real
REAL*8, DIMENSION (1, 1, 1:ROWS) :: dft_imag
REAL*8, DIMENSION (1, 1, 1:ROWS) :: idft_real
REAL*8, DIMENSION (1, 1, 1:ROWS) :: idft_imag

REAL*8, DIMENSION (1, 1, 1:ROWS) :: a_idft_imag
REAL*8, DIMENSION (1, 1, 1:ROWS) :: HILBERT_SIGNAL

REAL*8, DIMENSION (DIS, 1, 1:ROWS) :: HILBERT_B_SCAN


REAL*8, DIMENSION (DIS, 1, 1:ROWS) :: HILBERT_power
REAL*8, DIMENSION (DIS, 1, 1:ROWS2) :: HILBERT_power2

REAL*8, DIMENSION (DIS, 1, 1:ROWS) :: HILBERT_powerdB

REAL*8, DIMENSION (DIS, 1, 1:ROWS) :: INST_PHASE
REAL*8, DIMENSION (DIS, 1, 1:ROWS) :: INST_PHASE2
REAL*8, DIMENSION (DIS, 1, 1:ROWS) :: INST_FREQUENCY

INTEGER             :: I,J,K,G,N,P,R, SAMPLE
INTEGER             :: X, Y, Z
REAL*8              :: BGR
REAL*8              :: MEAN
REAL*8              :: MAX_ASCAN
REAL*8              :: NORM_MEAN, NORM_STDV
REAL*8              :: PI = ACOS(-1.0)
REAL*8              :: C = 3*10**8
REAL*8              :: DEPTH, PER, TIME_WIN, SAMPLE_TIME 
!=============================================================

