!==================================
INTEGER, PARAMETER :: DIS=20       !X
INTEGER, PARAMETER :: TRA=1       !Y
INTEGER, PARAMETER :: ROWS=4096    !Z 4096
!==================================

!===========================================================
INTEGER, DIMENSION(32768) :: HEADER !32768 * 4 BYTES!
INTEGER, DIMENSION(ROWS,DIS,TRA) :: B_SCAN_IMAGE
REAL*8, DIMENSION(ROWS,DIS,TRA) :: B_SCAN_IMAGE2
REAL*8, DIMENSION(DIS,TRA,ROWS) :: B_SCAN_IMAGE3
!============================================================

!===============================
INTEGER             :: P,G,N
INTEGER             :: X, Y, Z
!===============================

!=====MALA=====
!CHARACTER (LEN=11)  :: FH1='201223__0'
!CHARACTER (LEN=11)  :: FH1='210201__0'
!CHARACTER (LEN=11)  :: FH1='201223__0'
!CHARACTER (LEN=18)  :: FH1='f1-500-profile-'
!CHARACTER (LEN=4)  :: FT='.rd3'
!==============

!=====GSSI=====
!CHARACTER (LEN=11) :: FH1='200430__'
!CHARACTER (LEN=11) :: FH1='220519__'
CHARACTER (LEN=13)  :: FH1='220525_1__'
!CHARACTER (LEN=14)  :: FH1='220525_1__'
!CHARACTER (LEN=13) :: FH1='20211022__'
CHARACTER (LEN=4)  :: FT='.DZT'
!==============

CHARACTER (LEN=22) :: ITEM_NUMBER
!PRINT *, FH1


