!=================================
INTEGER, DIMENSION(32768) :: HEADER   !32768 * 4 BYTES!
INTEGER, PARAMETER :: ROWS=4096
INTEGER            :: DIS 
!==================================

!=====================================================
INTEGER, DIMENSION(:,:), ALLOCATABLE :: B_SCAN_IMAGE
!REAL*8, DIMENSION(:,:), ALLOCATABLE :: B_SCAN_IMAGE
REAL*8, DIMENSION(:,:), ALLOCATABLE :: B_SCAN_IMAGE2
REAL*8, DIMENSION(:,:), ALLOCATABLE :: B_SCAN_IMAGE3
REAL*8, DIMENSION(1:ROWS,1) :: STACKED_A_SCOPE

REAL*8, DIMENSION(1:ROWS,1) :: imag

REAL*8, DIMENSION(1:ROWS,1) :: f_real
REAL*8, DIMENSION(1:ROWS,1) :: f_imag
REAL*8, DIMENSION(1:ROWS,1) :: ifft_real
REAL*8, DIMENSION(1:ROWS,1) :: ifft_imag
REAL*8, DIMENSION(1:ROWS,1) :: psd



REAL*8, DIMENSION(1:ROWS,1) :: dft_real
REAL*8, DIMENSION(1:ROWS,1) :: dft_imag
REAL*8, DIMENSION(1:ROWS,1) :: idft_real
REAL*8, DIMENSION(1:ROWS,1) :: idft_imag

REAL*8, DIMENSION(1:ROWS,1) :: a_idft_imag
REAL*8, DIMENSION(1:ROWS,1) :: HILBERT_SIGNAL
REAL*8, DIMENSION(1:ROWS,1) :: HILBERT_STACKED_SIGNAL
!=====================================================      

INTEGER :: L,I,J,K,T, ALLOCATESTATUS
REAL*8 ::  BGR

