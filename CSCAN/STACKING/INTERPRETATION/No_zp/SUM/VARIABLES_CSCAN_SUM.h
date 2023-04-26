
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
REAL*8, DIMENSION(ROWS,TRA,DIS) :: B_SCAN_IMAGE66
REAL*8, DIMENSION(DIS,TRA,ROWS) :: B_SCAN_IMAGE6
REAL*8, DIMENSION(DIS,TRA,ROWS) :: B_SCAN_IMAGE6F


REAL*8, DIMENSION(ROWS,TRA,DIS) :: B_SCAN_IMAGE77
REAL*8, DIMENSION(DIS,TRA,ROWS) :: B_SCAN_IMAGE7
REAL*8, DIMENSION(DIS,TRA,ROWS) :: B_SCAN_IMAGE7F

REAL*8, DIMENSION(ROWS,TRA,DIS) :: B_SCAN_IMAGE88
REAL*8, DIMENSION(DIS,TRA,ROWS) :: B_SCAN_IMAGE8

REAL*8, DIMENSION(ROWS,TRA,DIS) :: B_SCAN_IMAGE99
REAL*8, DIMENSION(DIS,TRA,ROWS) :: B_SCAN_IMAGE9
!============================================================



!============================================================
REAL*8, DIMENSION(1 ,1, ROWS) :: ASCAN_SUM
!============================================================


!===========================================================
REAL*8, DIMENSION(1,1,1:ROWS) :: HILBERT_SIGNAL

!===========================================================


!===========================================================

REAL*8, DIMENSION(DIS,TRA,ROWS) :: POWER_SUM
REAL*8, DIMENSION(DIS,TRA,ROWS) :: AMP_SUM
REAL*8, DIMENSION(DIS,TRA,ROWS) :: HILBERT_AMP_SUM



REAL*8, DIMENSION(DIS,TRA,ROWS) :: HILBERT_AS_power
REAL*8, DIMENSION(DIS,TRA,ROWS) :: HILBERT_AS_powerdB
!============================================================      

!============================================================      
INTEGER, DIMENSION(:),ALLOCATABLE :: H_X, H_Z
INTEGER, DIMENSION(DIS) :: H_1, H_2
!============================================================      


!============================================================
REAL*8, DIMENSION(1:ROWS,1) :: f_real
REAL*8, DIMENSION(1:ROWS,1) :: f_imag


INTEGER             :: I,J,K,G,N,P,R, SAMPLE
INTEGER             :: i_h, H
INTEGER             :: X, Y, Z, YY
INTEGER             :: S1, S2
REAL*8              :: BGR
REAL*8              :: MEAN
REAL*8              :: SLICE_MEAN, SLICE_MEAN2
REAL*8              :: PI = ACOS(-1.0)
!=============================================================


