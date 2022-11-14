
!===============NS=================
!INTEGER, PARAMETER :: DIS = 50       !X !THE NUMBER OF STACK

INTEGER, PARAMETER :: LINE = 17      !F !THE NUMBER OF LINE
INTEGER, PARAMETER :: TRA = 41        !Y !THE NUMBER OF STATIC POINT
INTEGER, PARAMETER :: ROWS = 4096     !Z 4096
!==================================
!===========================================================
REAL*8, DIMENSION(     1,   1, ROWS) :: STACKED_A_SCAN
REAL*8, DIMENSION(  ROWS, TRA, LINE) :: STACKED_B_SCAN 
REAL*8, DIMENSION(  LINE, TRA, ROWS) :: STACKED_B_SCAN2
!===========================================================

!===========================================================
REAL*8, DIMENSION(  1,  1, ROWS) :: MEAN_A_SCOPE 
!===========================================================

!===========================================================
!REAL*8, DIMENSION(DIS,TRA,ROWS) :: HILBERT_B_SCAN 
REAL*8, DIMENSION(LINE,TRA,ROWS) :: HILBERT_STACKED_B_SCAN 
REAL*8, DIMENSION(LINE,TRA,ROWS) :: HILBERT_STACKED_B_SCAN_imag 

REAL*8, DIMENSION(LINE,TRA,ROWS) :: HILBERT_STACKED_power 
REAL*8, DIMENSION(LINE,TRA,ROWS) :: HILBERT_STACKED_powerdB 
REAL*8, DIMENSION(LINE,TRA,ROWS) :: HILBERT_STACKED_powerdB2


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

