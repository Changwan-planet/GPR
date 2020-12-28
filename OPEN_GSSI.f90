Program OPEN_GSSI
Implicit none


!========PATH=====================
CHARACTER (LEN=55) :: COMMON_PATH1
CHARACTER (LEN=55) :: COMMON_PATH2
CHARACTER (LEN=50) :: ITEM_NUMBER
CHARACTER (LEN=120) :: INPUT_PATH
CHARACTER (LEN=120) :: OUTPUT_PATH1
CHARACTER (LEN=120) :: OUTPUT_PATH2
CHARACTER (LEN=50) :: OUTPUT_NAME1
CHARACTER (LEN=50) :: OUTPUT_NAME2
!================================


!==================================
REAL, DIMENSION(32769) :: HEADER
INTEGER, PARAMETER :: ROWS=4096
INTEGER, PARAMETER :: DISTANCE=500
INTEGER            :: DIS 
!==================================


!================================================
REAL, DIMENSION(ROWS,1) :: SIGNAL_TIME_DOMAIN
INTEGER, DIMENSION(ROWS,DISTANCE) :: B_SCAN_IMAGE
REAL, DIMENSION(ROWS,1) :: INTENSITY
!=================================================      

INTEGER             :: I,J

!=============================PATH===================================
COMMON_PATH1="/home/changwan/GPR/2020_11(three tombs)/201109.PRJ/"
COMMON_PATH2="/home/changwan/GPR/"
ITEM_NUMBER="201109__003.DZT"

OUTPUT_NAME1="A_scope_output.txt"
OUTPUT_NAME2="B_SCAN_IMAGE_output.txt"
INPUT_PATH = TRIM(COMMON_PATH1)//ITEM_NUMBER
OUTPUT_PATH1 = TRIM(COMMON_PATH2)//OUTPUT_NAME1
OUTPUT_PATH2 = TRIM(COMMON_PATH2)//OUTPUT_NAME2
!=====================================================================


OPEN(UNIT=10,FILE=INPUT_PATH,FORM='UNFORMATTED',STATUS='OLD',ACTION='READ')
OPEN(UNIT=20,FILE=OUTPUT_PATH1,STATUS='REPLACE',ACTION='WRITE')
OPEN(UNIT=21,FILE=OUTPUT_PATH2,STATUS='REPLACE',ACTION='WRITE')


!======INITIALIZATION=======
DIS=0
B_SCAN_IMAGE=0
!===========================


PRINT *, "PLEASE TYPTE THE DISTANCE"
READ *, DIS
!PRINT *, DIS

     READ(10) HEADER,B_SCAN_IMAGE
     
     !PRINT *, HEADER


!=======A-SCOPE OUTPUT========================
     J=2
     WRITE(20,*) (B_SCAN_IMAGE(I,J), I=1,ROWS)
!============================================= 

     DO J=1,ROWS

     WRITE(21,*)(B_SCAN_IMAGE(J,I), I=1,DIS)
   
     END DO


END PROGRAM
