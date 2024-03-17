
!===============NS=================
!INTEGER, PARAMETER :: LINE = 7          !THE NUMBER OF LINE
!INTEGER, PARAMETER :: DIS = 50         !X !THE NUMBER OF STACK
INTEGER, PARAMETER :: LINE = 21          !THE NUMBER OF LINE
INTEGER, PARAMETER :: DIS = 50         !X !THE NUMBER OF STACK



INTEGER, PARAMETER :: TRA = 41        !Y !THE NUMBER OF STATIC POINT
INTEGER, PARAMETER :: ROWS = 4096     !Z 4096
!==================================

!===========================================================
INTEGER, DIMENSION(32768) :: HEADER !32768 * 4 BYTES!
INTEGER, DIMENSION(ROWS,DIS,TRA) :: B_SCAN_IMAGE 


REAL*8, DIMENSION(ROWS,DIS,TRA) :: B_SCAN_IMAGE2 
REAL*8, DIMENSION(DIS,TRA,ROWS) :: B_SCAN_IMAGE3 
REAL*8, DIMENSION(DIS,TRA,ROWS) :: B_SCAN_IMAGE4 
REAL*8, DIMENSION(DIS,TRA,ROWS) :: B_SCAN_IMAGE5 


!===========================================================

!===========================================================
REAL*8, DIMENSION(  1,  1, ROWS) :: STACKED_A_SCOPE 
REAL*8, DIMENSION(   LINE, TRA, ROWS) :: STACKED_B_SCAN 
REAL*8, DIMENSION(   TRA, LINE, ROWS) :: STACKED_B_SCAN2
REAL*8, DIMENSION(   TRA, LINE, ROWS) :: STACKED_B_SCAN2_flip 
!===========================================================



!===========================================================
REAL*8, DIMENSION(  1,  1, ROWS) :: MEAN_A_SCOPE 
!===========================================================

!===========================================================
REAL*8, DIMENSION(DIS,TRA,ROWS) :: HILBERT_B_SCAN 
REAL*8, DIMENSION(LINE,TRA,ROWS) :: HILBERT_STACKED_B_SCAN 
REAL*8, DIMENSION(LINE,TRA,ROWS) :: HILBERT_STACKED_B_SCAN_imag 

REAL*8, DIMENSION(LINE,TRA,ROWS) :: HILBERT_STACKED_power 
REAL*8, DIMENSION(LINE,TRA,ROWS) :: HILBERT_STACKED_powerdB 

REAL*8, DIMENSION(1,1,ROWS) :: HILBERT_STACKED_SIGNAL 
REAL*8, DIMENSION(1,1,ROWS) :: HILBERT_STACKED_SIGNAL_imag

!============================================================      


!============================================================
REAL*8, DIMENSION(1,1,1:ROWS) :: HILBERT_SIGNAL 

REAL*8, DIMENSION(1:ROWS,1) :: f_real
REAL*8, DIMENSION(1:ROWS,1) :: f_imag


INTEGER             :: I,J,K,G,N,P,R, SAMPLE
INTEGER             :: X, Y, Z, F
INTEGER             :: NN
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
!CHARACTER (LEN=8)  :: FH1='221109_'
!CHARACTER (LEN=13) :: FH2


!MUNAM
!CHARACTER(LEN=9) :: FH3 = "220420_"
!CHARACTER(LEN=9) :: FH3 = "230531_"
!CHARACTER(LEN=9) :: FH3 = "230608_"



!MIHO
!CHARACTER (LEN=9)   :: FH3='230322_'
CHARACTER (LEN=9)   :: FH3='221109_'
!CHARACTER (LEN=9)   :: FH3='221116_'

!CHARACTER (LEN=9)   :: FH3='220519_'
!CHARACTER (LEN=9)   :: FH3='220525_'

!CHARACTER (LEN=9)   :: FH3='220506_'
!CHARACTER (LEN=9)   :: FH3='220303_'



CHARACTER (LEN=14)  :: FH4


!CHARACTER (LEN=11)  :: FH1='220421__'
CHARACTER (LEN=2) :: FT='__'
CHARACTER (LEN=4)  :: FT2='.DZT'

CHARACTER (LEN=22) :: ITEM_NUMBER
!==============
