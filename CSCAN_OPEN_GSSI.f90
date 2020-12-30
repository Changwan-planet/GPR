Program OPEN_GSSI
Implicit none

!USE GSSI_PROGRAM

!========PATH======================
CHARACTER (LEN=55) :: COMMON_PATH1
CHARACTER (LEN=55) :: COMMON_PATH2

CHARACTER (LEN=120) :: INPUT_PATH

CHARACTER (LEN=120) :: OUTPUT_PATH1
CHARACTER (LEN=120) :: OUTPUT_PATH2

CHARACTER (LEN=50) :: OUTPUT_NAME1
CHARACTER (LEN=50) :: OUTPUT_NAME2
!=================================


!==================================
INTEGER, DIMENSION(32768) :: HEADER
!REAL, DIMENSION(32768) :: HEADER2    !32768
INTEGER, PARAMETER :: ROWS=4096
INTEGER, PARAMETER :: DISTANCE=560
INTEGER, PARAMETER :: TRACK=19
INTEGER            :: DIS 
INTEGER            :: :TRA
!==================================


!================================================
INTEGER, DIMENSION(ROWS,DISTANCE) :: B_SCAN_IMAGE
REAL, DIMENSION(ROWS,DISTANCE) :: B_SCAN_IMAGE2
REAL, DIMENSION(ROWS,1) :: INTENSITY
!REAL, DIMENSION(ROWS,DISTANCE,TRACK) :: C_SCAN_IMAGE
!=================================================      


INTEGER             :: I,J,K,G


CHARACTER (LEN=11)  :: FH1='201223__0'
CHARACTER (LEN=4)  :: FT='.DZT'
CHARACTER (LEN=15) :: ITEM_NUMBER


Do G=1,19

!=====AUTOMATIC CHANCE CODE FOR OPENING FILE===================

   If(G<=9.AND.G>=1) then
     Write(FH1(10:10),FMT='(I1)') 0
     Write(FH1(11:11),FMT='(I1)') G
   Else
     Write(FH1(10:11),FMT='(I2)') G
   End if

   ITEM_NUMBER=trim(FH1//FT)


!=============================PATH===================================
COMMON_PATH1="/home/changwan/GPR/201223/"
COMMON_PATH2="/home/changwan/GPR/"


OUTPUT_NAME1="A_SCOPE_IMAGE_GPR.txt"
OUTPUT_NAME1="C_SCAN_IMAGE_GPR.txt"


INPUT_PATH = TRIM(COMMON_PATH1)//ITEM_NUMBER
OUTPUT_PATH1 = TRIM(COMMON_PATH2)//OUTPUT_NAME1
OUTPUT_PATH2 = TRIM(COMMON_PATH2)//OUTPUT_NAME2

!=====================================================================


OPEN(UNIT=10,FILE=INPUT_PATH,FORM='UNFORMATTED',STATUS='OLD',ACTION='READ')
OPEN(UNIT=20,FILE=OUTPUT_PATH1,STATUS='REPLACE',ACTION='WRITE')
!OPEN(UNIT=21,FILE=OUTPUT_PATH2,STATUS='REPLACE',ACTION='WRITE')



!======INITIALIZATION=======
DIS = 0
B_SCAN_IMAGE = 0
B_SCAN_IMAGE2 = 0
C_SCAN_IMAGE = 0
!===========================


PRINT *, "PLEASE TYPE THE DISTANCE"
READ *, DIS
!PRINT *, "PLEASE TYPE THE TRACK"
!READ *, TRA


      READ(10) HEADER,B_SCAN_IMAGE

!=======A-SCOPE===============================
    B_SCAN_IMAGE2=B_SCAN_IMAGE
    J=1
    WRITE(20,*) (B_SCAN_IMAGE2(I,J), I=1,ROWS)
!    PRINT *, (B_SCAN_IMAGE2(I,J), I=1,ROWS)

!============================================= 


!======B_SCAN=================================
!     DO J=1,ROWS
!     WRITE(21,*)(B_SCAN_IMAGE2(J,I,1), I=1,DIS)
!     END DO
!=============================================


!=====C_SCAN_IMAGE============================
!     DO K=1,TRA 
            
!       C_SCAN_IMAGE(ROWS,DIS,K)=B_SCAN_IMAGE2(ROWS,DIS,1)
           

!     END DO
!=============================================

!CLOSE(10)
!CLOSE(20)

END DO

END PROGRAM
