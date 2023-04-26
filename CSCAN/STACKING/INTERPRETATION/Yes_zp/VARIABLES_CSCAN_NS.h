
!===============NS=================
INTEGER, PARAMETER :: DIS=41      !X
INTEGER, PARAMETER :: TRA=21        !Y
INTEGER, PARAMETER :: ROWS=4096     !Z 4096
!==================================

!===============MOGOD=================
!INTEGER, PARAMETER :: DIS=2300      !X
!INTEGER, PARAMETER :: TRA=100        !Y
!INTEGER, PARAMETER :: ROWS=512       !Z 512
!==================================


!===========================================================
REAL*8, DIMENSION(ROWS,TRA,DIS) :: B_SCAN_IMAGE33
REAL*8, DIMENSION(DIS,TRA,ROWS) :: B_SCAN_IMAGE3
REAL*8, DIMENSION(DIS,TRA,ROWS) :: B_SCAN_IMAGE4
!============================================================

!===========================================================
REAL*8, DIMENSION(1,1,1:ROWS) :: HILBERT_SIGNAL
!REAL*8, DIMENSION(1,1,1:ROWS) :: HILBERT_SIGNAL_imag
REAL*8, DIMENSION(DIS,TRA,ROWS) :: HILBERT_B_SCAN
!REAL*8, DIMENSION(DIS,TRA,ROWS) :: HILBERT_B_SCAN_imag


REAL*8, DIMENSION(DIS,TRA,ROWS) :: HILBERT_power
REAL*8, DIMENSION(DIS,TRA,ROWS) :: HILBERT_powerdB
!============================================================      


!============================================================
REAL*8, DIMENSION(1:ROWS,1) :: f_real
REAL*8, DIMENSION(1:ROWS,1) :: f_imag


INTEGER             :: I,J,K,G,N,P,R, SAMPLE
INTEGER             :: X, Y, Z
REAL*8              :: BGR
REAL*8              :: MEAN
REAL*8              :: SLICE_MEAN, SLICE_MEAN2
REAL*8              :: PI = ACOS(-1.0)
!=============================================================


