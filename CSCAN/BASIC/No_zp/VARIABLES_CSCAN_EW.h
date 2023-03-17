!===============MALA-BOMIN-160MHz====
INTEGER, PARAMETER :: DIS=1126          !X
INTEGER, PARAMETER :: TRA = 1        !Y
INTEGER, PARAMETER :: ROWS = 1013       !Z 103
!INTEGER, PARAMETER :: ROWS2 = ROWS -1  !Z 528
!INTEGER, PARAMETER :: ROWS3 = 512      !Z 512
!====================================


!===============MALA-BOMIN-450MHz====
!INTEGER, PARAMETER :: DIS=808          !X
!INTEGER, PARAMETER :: TRA = 1        !Y
!INTEGER, PARAMETER :: ROWS = 529       !Z 529
!INTEGER, PARAMETER :: ROWS2 = ROWS -1  !Z 528
!INTEGER, PARAMETER :: ROWS3 = 512      !Z 512
!====================================


!===============MALA-MOGOD-500MHz====
!INTEGER, PARAMETER :: DIS=1498         !X
!INTEGER, PARAMETER :: TRA = 110        !Y
!INTEGER, PARAMETER :: ROWS = 616       !Z 616
!INTEGER, PARAMETER :: ROWS2 = ROWS -1  !Z 615
!INTEGER, PARAMETER :: ROWS3 = 512      !Z 512
!====================================


!===============GSSI=================
!INTEGER, PARAMETER :: DIS = 400       !X
!INTEGER, PARAMETER :: TRA = 4         !Y
!INTEGER, PARAMETER :: ROWS = 4096     !Z 4096
!INTEGER, PARAMETER :: ROWS2 = ROWS -1  !Z 4095
!====================================

!=======A_SCOPE=============================================
REAL*8, DIMENSION(DIS,TRA,ROWS) :: T_SUM_ASCOPE
!===========================================================

!===========================================================
REAL*8, DIMENSION(ROWS,TRA,DIS) ::  B_SCAN_IMAGE33
REAL*8, DIMENSION(DIS,TRA,ROWS) ::  B_SCAN_IMAGE3
REAL*8, DIMENSION(DIS,TRA,ROWS) ::  B_SCAN_IMAGE4
!REAL*8, DIMENSION(DIS,TRA,ROWS2) ::  B_SCAN_IMAGE5
!REAL*8, DIMENSION(DIS,TRA,ROWS3)::  B_SCAN_IMAGE6
!============================================================

REAL*8, DIMENSION(1,1,ROWS) :: imag

!=====CROSS CORRELATION=====
!INTEGER, PARAMETER :: CRRL_N = (2*ROWS2)+1
!REAL*8, DIMENSION (CRRL_N):: crrl
!INTEGER, DIMENSION (DIS,TRA) :: SHIFT 
!============================================
!=====INTERPETATION=====
INTEGER :: S1, S2
INTEGER, DIMENSION(DIS) :: H_1          !HORIZON
!====================================================



INTEGER             :: I,J,G,N,P,R, SAMPLE
INTEGER             :: X, Y, Z


!REAL*8, DIMENSION(ROWS2)   :: TEMP
REAL*8              :: BGR, BGR2, BGR3
REAL*8              :: MEAN
REAL*8              :: SLICE_MEAN, SLICE_MEAN2
REAL*8              :: PI = ACOS(-1.0)
!=============================================================
