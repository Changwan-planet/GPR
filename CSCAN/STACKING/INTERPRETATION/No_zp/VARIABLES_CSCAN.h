
!===============NS=================
INTEGER, PARAMETER :: DIS = 41        !X
INTEGER, PARAMETER :: TRA = 21        !Y
INTEGER, PARAMETER :: ROWS = 4096     !Z 
INTEGER, PARAMETER :: ROWS2 = 3997     !Z 


!==================================

!===============MOGOD=================
!INTEGER, PARAMETER :: DIS=2300      !X
!INTEGER, PARAMETER :: TRA=100        !Y
!INTEGER, PARAMETER :: ROWS=512       !Z 512
!==================================


!===========================================================
REAL*8, DIMENSION(DIS,TRA,ROWS) :: B_SCAN_IMAGE
REAL*8, DIMENSION(DIS,TRA,ROWS2) :: B_SCAN_IMAGE_GC

REAL*8, DIMENSION(DIS,TRA,ROWS) :: B_SCAN_IMAGE2
!============================================================

!===========================================================
REAL*8, DIMENSION(1,1,1:ROWS) :: HILBERT_SIGNAL
!REAL*8, DIMENSION(1,1,1:ROWS) :: HILBERT_SIGNAL_imag
REAL*8, DIMENSION(DIS,TRA,ROWS) :: HILBERT_B_SCAN
!REAL*8, DIMENSION(DIS,TRA,ROWS) :: HILBERT_B_SCAN_imag


REAL*8, DIMENSION(DIS,TRA,ROWS) :: HILBERT_power
REAL*8, DIMENSION(DIS,TRA,ROWS) :: HILBERT_powerdB

!============================================================      


!=====HORIZON=====
INTEGER, DIMENSION(DIS) :: H_1
INTEGER, DIMENSION(DIS) :: H_S

!=================




!============================================================
REAL*8, DIMENSION(1:ROWS,1) :: f_real
REAL*8, DIMENSION(1:ROWS,1) :: f_imag


INTEGER             :: I,J,K,G,N,P,R, SAMPLE
INTEGER             :: X, Y, Z
INTEGER             :: XX, YY, ZZ
INTEGER             :: S1, S2
INTEGER             :: HS1, HS2
INTEGER             :: W

!INTEGER                       :: i_h
!INTEGER, DIMENSION(DIS)       :: i_h2
INTEGER                        :: H_Z_Max
INTEGER                        :: H_Z_Max2
INTEGER, DIMENSION(DIS)        :: H_Z
INTEGER, DIMENSION(DIS)        :: H_Z3
INTEGER, DIMENSION(:), ALLOCATABLE        :: H_Z2
INTEGER, DIMENSION(:), ALLOCATABLE        :: H_Z4
INTEGER, DIMENSION(5, DIS) :: H_Z_MATRIX
INTEGER, DIMENSION(5, DIS) :: H_Z_MATRIX2





REAL*8              :: BGR
REAL*8              :: MEAN
REAL*8              :: SLICE_MEAN, SLICE_MEAN2
REAL*8              :: PI = ACOS(-1.0)
!=============================================================


