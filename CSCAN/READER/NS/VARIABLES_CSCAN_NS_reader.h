
!===============NS=================

!===============GSSI, KOREA================
INTEGER, PARAMETER :: DIS=1900      !X
INTEGER, PARAMETER :: TRA=17        !Y
INTEGER, PARAMETER :: ROWS=4096     !Z 4096
!==================================

!===============MALA, MOGOD=================
!INTEGER, PARAMETER :: DIS=2300     !X
!INTEGER, PARAMETER :: TRA=100      !Y
!INTEGER, PARAMETER :: ROWS=512     !Z 
!=====================================

!===========================================================
INTEGER, DIMENSION(32768) :: HEADER !32768 * 4 BYTES GSSI, KOREA
INTEGER, DIMENSION(ROWS,DIS,TRA) :: B_SCAN_IMAGE     !GSSI, KOERA
!INTEGER*2, DIMENSION(ROWS,DIS,TRA) :: B_SCAN_IMAGE  !MALA, MOGOD
REAL*8, DIMENSION(ROWS,DIS,TRA) :: B_SCAN_IMAGE2
REAL*8, DIMENSION(DIS,TRA,ROWS) :: B_SCAN_IMAGE3
!============================================================

!===========================================================
INTEGER             :: I,J,K,G,N,P,R, SAMPLE
INTEGER             :: X, Y, Z
!=============================================================


!=====MALA=====
!CHARACTER (LEN=11)  :: FH1='201223__0'
!CHARACTER (LEN=11)  :: FH1='210201__0'
!CHARACTER (LEN=11)  :: FH1='201223__0'
!CHARACTER (LEN=18)  :: FH1='f1-500-profile-'
!CHARACTER (LEN=4)  :: FT='.rd3'
!==============

!=====GSSI=====
CHARACTER (LEN=13)  :: FH1='220526_1__'
!CHARACTER (LEN=11)  :: FH1='211028__'
CHARACTER (LEN=4)  :: FT='.DZT'
!==============


CHARACTER (LEN=22) :: ITEM_NUMBER


!PRINT *, FH1


