
!===============EW=================
INTEGER, PARAMETER :: DIS=496      !X
INTEGER, PARAMETER :: TRA=1       !Y
INTEGER, PARAMETER :: ROWS=4096     !Z 4096
!==================================


!===========================================================
INTEGER, DIMENSION(32768) :: HEADER !32768 * 4 BYTES!
INTEGER, DIMENSION(ROWS,DIS,TRA) :: B_SCAN_IMAGE
REAL*8, DIMENSION(ROWS,DIS,TRA) :: B_SCAN_IMAGE2
REAL*8, DIMENSION(DIS,TRA,ROWS) :: B_SCAN_IMAGE3
REAL*8, DIMENSION(DIS,TRA,ROWS) :: HILBERT_B_SCAN
!============================================================      


!============================================================
REAL*8, DIMENSION(1,1,1:ROWS) :: HILBERT_SIGNAL

REAL*8, DIMENSION(1:ROWS,1) :: f_real
REAL*8, DIMENSION(1:ROWS,1) :: f_imag


INTEGER             :: I,J,K,G,N,P,R, SAMPLE
INTEGER             :: X, Y, Z
REAL*8              :: BGR
REAL*8              :: MEAN
REAL*8              :: MAX_SLICE, SLICE_MEAN, SLICE_MEAN2

!=============================================================
!CHARACTER (LEN=11)  :: FH1='201223__0'
!CHARACTER (LEN=11)  :: FH1='210201__0'
!CHARACTER (LEN=11)  :: FH1='201223__0'
!CHARACTER (LEN=18)  :: FH1='f1-500-profile-'
!CHARACTER (LEN=4)  :: FT='.rd3'

!CHARACTER (LEN=13)  :: FH1='211027_4__'
CHARACTER (LEN=11)  :: FH1='200430__'
!CHARACTER (LEN=11)  :: FH1='211028__'
CHARACTER (LEN=4)  :: FT='.DZT'

CHARACTER (LEN=22) :: ITEM_NUMBER


!PRINT *, FH1


