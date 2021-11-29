!=================================
INTEGER, DIMENSION(32768) :: HEADER   !32768 * 4 BYTES!
INTEGER, PARAMETER :: DIS = 500      !X
!INTEGER, PARAMETER :: DIS = 140       !X
!INTEGER, PARAMETER :: DIS = 695       !X


INTEGER, PARAMETER :: TRA = 23       !Y
!INTEGER, PARAMETER :: TRA = 23         !Y
!INTEGER, PARAMETER :: TRA = 30         !Y
!INTEGER, PARAMETER :: TRA = 67         !Y
INTEGER, PARAMETER :: ROWS = 4096     !Z


!PLEASE CALCULATE TRA
!DIS2 = DIS/N_STACK
INTEGER, PARAMETER :: N_STACK = 1
INTEGER, PARAMETER :: DIS2 = DIS
!==================================

!=====================================================
INTEGER, DIMENSION( ROWS, DIS, TRA ) :: B_SCAN_IMAGE
REAL*8, DIMENSION ( ROWS, DIS, TRA )  :: B_SCAN_IMAGE2
REAL*8, DIMENSION ( DIS , TRA, ROWS)  :: B_SCAN_IMAGE3
REAL*8, DIMENSION ( DIS , TRA, ROWS)  :: B_SCAN_IMAGE4
REAL*8, DIMENSION ( DIS , TRA, ROWS)  :: B_SCAN_IMAGE5
!=====================================================


!=====================================================
REAL*8, DIMENSION (    1,   1, ROWS) :: STACKED_A_SCOPE
REAL*8, DIMENSION (  DIS2,  1, ROWS) :: STACKED_B_SCAN
!=====================================================

!======================================================
!REAL*8, DIMENSION ( DIS2, TRA, ROWS) :: LAYER
REAL*8, DIMENSION ( DIS2, TRA, 1) :: LAYER
!======================================================

!======================================================
REAL*8, DIMENSION (1, 1, 1:ROWS) :: imag

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
REAL*8, DIMENSION (1, TRA, 1:ROWS) :: HILBERT_B_SCAN
REAL*8, DIMENSION (1, TRA, 1:ROWS) :: HILBERT_STACKED_B_SCAN
!=====================================================      

!=====================================================
INTEGER :: G,L,I,J,K,T,P
INTEGER :: X, Y, Z, S, E
REAL*8 ::  BGR
!=========!============================================







