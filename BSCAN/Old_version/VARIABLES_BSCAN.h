
!==================================
INTEGER, PARAMETER :: DIS=20    !X
INTEGER, PARAMETER :: TRA=77       !Y
INTEGER, PARAMETER :: ROWS=4096     !Z 4096
!==================================

!===========================================================
INTEGER, DIMENSION(32768) :: HEADER !32768 * 4 BYTES!
INTEGER, DIMENSION(ROWS,DIS,TRA) :: B_SCAN_IMAGE
REAL*8, DIMENSION(ROWS,DIS,TRA) :: B_SCAN_IMAGE2
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
!CHARACTER (LEN=11)  :: FH1='201223__0'
!CHARACTER (LEN=11)  :: FH1='210201__0'
!CHARACTER (LEN=11)  :: FH1='201223__0'
!CHARACTER (LEN=18)  :: FH1='f1-500-profile-'
!CHARACTER (LEN=4)  :: FT='.rd3'


!CHARACTER (LEN=11) :: FH1='200430__'
!CHARACTER (LEN=11) :: FH1='220519__'
!CHARACTER (LEN=13)  :: FH1='220525_9__'
CHARACTER (LEN=14)  :: FH1='220525_14__'


!CHARACTER (LEN=13) :: FH1='20211022__'

CHARACTER (LEN=4)  :: FT='.DZT'

CHARACTER (LEN=22) :: ITEM_NUMBER

!PRINT *, FH1

