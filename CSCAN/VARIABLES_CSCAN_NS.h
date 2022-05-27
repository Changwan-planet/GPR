
!===============NS=================
INTEGER, PARAMETER :: DIS=1900      !X
INTEGER, PARAMETER :: TRA=17        !Y
INTEGER, PARAMETER :: ROWS=4096     !Z 4096
!==================================

!===========================================================
INTEGER, DIMENSION(32768) :: HEADER !32768 * 4 BYTES!
INTEGER, DIMENSION(ROWS,DIS,TRA) :: B_SCAN_IMAGE
REAL*8, DIMENSION(ROWS,DIS,TRA) :: B_SCAN_IMAGE2
REAL*8, DIMENSION(DIS,TRA,ROWS) :: B_SCAN_IMAGE3
REAL*8, DIMENSION(DIS,TRA,ROWS) :: B_SCAN_IMAGE4
!============================================================

!===========================================================
REAL*8, DIMENSION(1,1,1:ROWS) :: HILBERT_SIGNAL
REAL*8, DIMENSION(1,1,1:ROWS) :: HILBERT_SIGNAL_imag
REAL*8, DIMENSION(DIS,TRA,ROWS) :: HILBERT_B_SCAN
REAL*8, DIMENSION(DIS,TRA,ROWS) :: HILBERT_B_SCAN_imag


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


