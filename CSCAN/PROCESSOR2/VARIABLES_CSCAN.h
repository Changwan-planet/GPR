!===============NS=================================
!INTEGER, PARAMETER :: DIS=1900      !X
!INTEGER, PARAMETER :: TRA=17        !Y
!INTEGER, PARAMETER :: ROWS=4096     !Z 4096
!==================================================


!===============MOGOD==============================
INTEGER, PARAMETER :: DIS=2300      !X
INTEGER, PARAMETER :: TRA=100        !Y
INTEGER, PARAMETER :: ROWS=512       !Z 512
!==================================================


!==================================================
REAL*8, DIMENSION(ROWS,TRA,DIS) :: HdB
REAL*8, DIMENSION(DIS,TRA,ROWS) :: HdB2
!==================================================      


!=============BSCAN_MVMEAN_PROCESSING==============
INTEGER, PARAMETER :: W = 2
INTEGER, PARAMETER :: MV_DIS = (DIS - W) + 1
INTEGER, PARAMETER :: MV_TRA = (TRA - W) + 1
INTEGER :: MV_X, MV_Y
REAL*8, DIMENSION(MV_DIS,MV_TRA,ROWS) :: amp_2D_mvmean
!REAL*8 :: SUM_2DW_amp
!==================================================      



!==================================================
REAL*8, DIMENSION(1:ROWS,1) :: f_real
REAL*8, DIMENSION(1:ROWS,1) :: f_imag


INTEGER             :: I,J,K,G,N,P,R, SAMPLE
INTEGER             :: X, Y, Z
REAL*8              :: BGR
REAL*8              :: MEAN
REAL*8              :: SLICE_MEAN, SLICE_MEAN2
REAL*8              :: PI = ACOS(-1.0)
!==================================================
