!==================================
INTEGER, PARAMETER :: DIS=20    !X
INTEGER, PARAMETER :: TRA=77       !Y
INTEGER, PARAMETER :: ROWS=4096     !Z 4096
!==================================

!===========================================================
INTEGER, DIMENSION(32768) :: HEADER !32768 * 4 BYTES!
REAL*8, DIMENSION(ROWS,TRA,DIS) :: B_SCAN_IMAGE33
REAL*8, DIMENSION(DIS,TRA,ROWS) :: B_SCAN_IMAGE3
REAL*8, DIMENSION(DIS,TRA,ROWS) :: B_SCAN_IMAGE4
!============================================================      

!============================================================
REAL*8, DIMENSION(  1,  1, ROWS) :: INST_A_SCOPE

!============================================================
REAL*8, DIMENSION(  1,  1, ROWS) :: STACKED_A_SCOPE
REAL*8, DIMENSION(  1,  TRA, ROWS) :: STACKED_B_SCAN
REAL*8, DIMENSION(  1,  TRA, ROWS) :: STACKED_B_SCAN2
!============================================================

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
REAL*8, DIMENSION (1, 1, 1:ROWS) :: HILBERT_STACKED_SIGNAL
REAL*8, DIMENSION (1, 1, 1:ROWS) :: HILBERT_STACKED_SIGNAL_imag


REAL*8, DIMENSION (1, TRA, 1:ROWS) :: HILBERT_B_SCAN
REAL*8, DIMENSION (1, TRA, 1:ROWS) :: HILBERT_STACKED_B_SCAN
REAL*8, DIMENSION (1, TRA, 1:ROWS) :: HILBERT_STACKED_B_SCAN_imag

REAL*8, DIMENSION (1, TRA, 1:ROWS) :: HILBERT_STACKED_power
REAL*8, DIMENSION (1, TRA, 1:ROWS) :: HILBERT_STACKED_powerdB


INTEGER             :: I,J,K,G,N,P,R, SAMPLE
INTEGER             :: X, Y, Z
REAL*8              :: BGR
REAL*8              :: MEAN
REAL*8              :: MAX_ASCAN
!=============================================================
