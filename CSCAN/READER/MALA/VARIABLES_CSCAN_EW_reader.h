!===========MALA-160MHz==================
!INTEGER, PARAMETER :: DIS=1126      !X
!INTEGER, PARAMETER :: TRA=1        !Y
!INTEGER, PARAMETER :: ROWS=999     !Z 
!========================================

!===========MALA-450MHz==================
!INTEGER, PARAMETER :: DIS=808      !X
INTEGER, PARAMETER :: DIS=1195     !X
INTEGER, PARAMETER :: TRA=29        !Y
INTEGER, PARAMETER :: ROWS=542     !Z 
!========================================

!===========MOGOD-MALA-EW-500MHz===============
!INTEGER, PARAMETER :: DIS=1498     !X
!INTEGER, PARAMETER :: TRA=110      !Y
!INTEGER, PARAMETER :: ROWS=616     !Z 
!========================================

!===========GSSI-EW======================
!INTEGER, PARAMETER :: DIS=496       !X
!INTEGER, PARAMETER :: TRA=1         !Y
!INTEGER, PARAMETER :: ROWS=4096     !Z 4096
!========================================

!===========================================================
!INTEGER, DIMENSION(32768) :: HEADER !32768 * 4 BYTES!
!INTEGER, DIMENSION(ROWS,DIS,TRA) :: B_SCAN_IMAGE           !GSSI  
!INTEGER*2, DIMENSION(ROWS,DIS,TRA) :: B_SCAN_IMAGE       !MOGOD-MALA-500MHz
INTEGER, DIMENSION(ROWS,DIS,TRA) :: B_SCAN_IMAGE          !MALA_450MHz, 160MHz
!============================================================


!=====MALA=====
REAL*8, DIMENSION(ROWS,DIS,TRA) :: B_SCAN_IMAGE2
REAL*8, DIMENSION(DIS,TRA,ROWS) :: B_SCAN_IMAGE3
REAL*8, DIMENSION(DIS,TRA,ROWS) :: HILBERT_B_SCAN
!============================================================      


!=====XY CORRECTION=====
REAL*8, DIMENSION(TRA,4) :: START_END_XY
REAL*8 :: MAX_D, MAX_X
REAL*8 :: H
INTEGER :: MAX_D_PIXEL,MAX_X_PIXEL
REAL*8 :: DISTANCE_INTERVAL = 0.0519

!============================================================
REAL*8, DIMENSION(1,1,1:ROWS) :: HILBERT_SIGNAL
REAL*8, DIMENSION(1:ROWS,1) :: f_real
REAL*8, DIMENSION(1:ROWS,1) :: f_imag


INTEGER             :: I,J,K,G,N,P,R, SAMPLE
INTEGER             :: X, Y, Z
INTEGER             :: DIS_in
REAL*8              :: BGR
REAL*8              :: MEAN
REAL*8              :: MAX_SLICE, SLICE_MEAN, SLICE_MEAN2

!=============================================================

!=====MALA=====
!CHARACTER (LEN=11)  :: FH1='201223__0'
!CHARACTER (LEN=11)  :: FH1='210201__0'
!CHARACTER (LEN=11)  :: FH1='201223__0'
!CHARACTER (LEN=18)  :: FH1='f1-500-profile-'
!CHARACTER (LEN=18)  :: FH1='f1-450-profile-'
!CHARACTER (LEN=18)  :: FH1='f1-160-profile-'
!CHARACTER (LEN=18)  :: FH1='f1-600-profile-'
CHARACTER (LEN=11) :: FH1='Miho11H_'


!CHARACTER (LEN=4)  :: FT='.rd3'
CHARACTER (LEN=4)  :: FT='.rd7'


!CHARACTER (LEN=13)  :: FH1='211027_4__'
!CHARACTER (LEN=11)  :: FH1='200430__'
!CHARACTER (LEN=11)  :: FH1='211028__'
!CHARACTER (LEN=4)  :: FT='.DZT'


!CHARACTER (LEN=22) :: ITEM_NUMBER
CHARACTER (LEN=15) :: ITEM_NUMBER
CHARACTER (LEN=30) :: ITEM_NUMBER2



!PRINT *, FH1
