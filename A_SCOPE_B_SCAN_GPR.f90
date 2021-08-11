Program OPEN_GSSI
IMPLICIT NONE

!USE GSSI_PROGRAM

!========PATH======================
CHARACTER (LEN=55) :: COMMON_PATH1
CHARACTER (LEN=55) :: COMMON_PATH2

CHARACTER (LEN=50) :: ITEM_NUMBER

CHARACTER (LEN=120) :: INPUT_PATH

CHARACTER (LEN=120) :: OUTPUT_PATH1
CHARACTER (LEN=120) :: OUTPUT_PATH2
CHARACTER (LEN=120) :: OUTPUT_PATH3
CHARACTER (LEN=120) :: OUTPUT_PATH4


CHARACTER (LEN=50) :: OUTPUT_NAME1
CHARACTER (LEN=50) :: OUTPUT_NAME2
CHARACTER (LEN=50) :: OUTPUT_NAME3
CHARACTER (LEN=50) :: OUTPUT_NAME4
!=================================


!==================================
INTEGER, DIMENSION(32768) :: HEADER   !32768 * 4 BYTES!
INTEGER, PARAMETER :: ROWS=4096
INTEGER            :: DIS 
!==================================

!=====================================================
INTEGER, DIMENSION(:,:), ALLOCATABLE :: B_SCAN_IMAGE
REAL, DIMENSION(:,:), ALLOCATABLE :: B_SCAN_IMAGE2
REAL, DIMENSION(ROWS,1) :: INTENSITY
!=====================================================      

INTEGER :: L,I,J,K,T,ALLOCATESTATUS

!=============================PATH===================================
!COMMON_PATH1="/home/changwan/GPR/2020_11(three tombs)/201109.PRJ/"
!COMMON_PATH1="/home/changwan/GPR/201223/"
!COMMON_PATH1="/home/changwan/GPR/"

COMMON_PATH1="/home/changwan/GPR/GPR_202107/210713.PRJ/"
COMMON_PATH2="/home/changwan/GPR/GPR_202107/"

!COMMON_PATH2="/home/changwan/GPR/"



!ITEM_NUMBER="201109__002.DZT"
!ITEM_NUMBER="201223__011.DZT"
!ITEM_NUMBER="201223__001.DZT"

ITEM_NUMBER="210713__003.DZT"

OUTPUT_NAME1="A_SCOPE_GPR.txt"
OUTPUT_NAME2="B_SCAN_IMAGE_GPR.txt"
OUTPUT_NAME3="INTENSITY_PROFILE_GPR.txt"
OUTPUT_NAME4="INTENSITY_PROFILE2_GPR.txt"

INPUT_PATH = TRIM(COMMON_PATH1)//ITEM_NUMBER
OUTPUT_PATH1 = TRIM(COMMON_PATH2)//OUTPUT_NAME1
OUTPUT_PATH2 = TRIM(COMMON_PATH2)//OUTPUT_NAME2
OUTPUT_PATH3 = TRIM(COMMON_PATH2)//OUTPUT_NAME3
OUTPUT_PATH4 = TRIM(COMMON_PATH2)//OUTPUT_NAME4
!=====================================================================


OPEN(UNIT=10,FILE=INPUT_PATH,FORM='UNFORMATTED',ACCESS='STREAM',STATUS='OLD',ACTION='READ')
OPEN(UNIT=20,FILE=OUTPUT_PATH1,STATUS='REPLACE',ACTION='WRITE')
OPEN(UNIT=21,FILE=OUTPUT_PATH2,STATUS='REPLACE',ACTION='WRITE')
OPEN(UNIT=22,FILE=OUTPUT_PATH3,STATUS='REPLACE',ACTION='WRITE')
OPEN(UNIT=23,FILE=OUTPUT_PATH4,STATUS='REPLACE',ACTION='WRITE')


!======INITIALIZATION=======
DIS = 0
!B_SCAN_IMAGE = 0
!B_SCAN_IMAGE2 = 0.0
INTENSITY = 0.0
!===========================


PRINT *, "PLEASE TYPE THE  DISTANCE"
READ *, DIS
!PRINT *, DIS


ALLOCATE(B_SCAN_IMAGE(ROWS,DIS), STAT=ALLOCATESTATUS)
IF (ALLOCATESTATUS /= 0) STOP "***NOT ENOUGH MEMORY***"

ALLOCATE(B_SCAN_IMAGE2(ROWS,DIS), STAT=ALLOCATESTATUS)
IF (ALLOCATESTATUS /= 0) STOP "***NOW ENOUGH MEMORY***"


      READ(10) HEADER,B_SCAN_IMAGE

!=======A-SCOPE===============================
    B_SCAN_IMAGE2=B_SCAN_IMAGE
    J=1
    DO I=1,ROWS
    !   WRITE(20,*) B_SCAN_IMAGE2(I,J), I=1,ROWS)
        WRITE(20,*) B_SCAN_IMAGE2(I,J)
    END DO
!PRINT *, (B_SCAN_IMAGE2(I,J), I=1,ROWS)
!============================================= 


!======B_SCAN=================================
      
        DO J = 1,4096
            
           WRITE(21,*) (B_SCAN_IMAGE2(J,I), I=1,DIS)
        
        END DO

!         DO I=1,DIS
!             WRITE(21,*) (B_SCAN_IMAGE2(J,I), J=601,800)
!         END DO
! CHECK THE DIRECTION OF OUTPUT
!         DO I =1,DIS
!            DO J=601,610
!               PRINT *, J, I
!            END DO
!         END DO

!PRINT *, "----------------------------------------------"
 
!!         DO J=601,800
!!           WRITE(21,*) (B_SCAN_IMAGE2(J,I), I=1,DIS)
!!         END DO

!         DO J=601,610
!            DO I=1,DIS
!                PRINT *, J,I
!            END DO
!         END DO   


!=============================================

!!I = 0

!=====INTENSITY_PROFILE=======================

!!DO I=1,DIS
!!   DO J=1,ROWS
  
!!      IF (B_SCAN_IMAGE2(J,I)==0.0) then 
!!         B_SCAN_IMAGE2(J,I)=1.0
!!      END IF

!!          INTENSITY(J,1)=INTENSITY(J,1)+10*log10((B_SCAN_IMAGE2(J,I)**2))     
!!   END DO

!+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
!PRINT THE INTENSITY_PROFILE OF THE FIRST DIS VALUE.         
!JUST ONE INTENSITY VALUE
!IF YOU WANT THE INTENSITY PROFILE OF THE OTHER DIS VALUE, THEN JUST CHANGE THE I BELOW. 
!!      IF (I==1) THEN 
!!               INTENSITY(1,1)=INTENSITY(2,1)
!!               INTENSITY(4096,1)=INTENSITY(4095,1)
!!          DO L=1,ROWS     
!!                WRITE(22,*) INTENSITY(L,1) 
!                PRINT *,    INTENSITY(L,1)
!!          END DO
!!      END IF 
!+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

!!END DO

!!INTENSITY(1,1)=INTENSITY(2,1)
!!INTENSITY(4096,1)=INTENSITY(4095,1)

!DO K=1,ROWS
!   PRINT *, "B_SCAN_IMAGE2(",K,"1)=",B_SCAN_IMAGE2(K,1) 
!END DO   

!!K=0

!INTEGRATED INTENSITY_PROFIEL AS THE NUMBER OF THE DISTANCE.
!!DO K=1,ROWS
!   PRINT *, "INTENSITY(",K,")=",INTENSITY(K,1) 
!!   WRITE(23,*) INTENSITY(K,1)
!!END DO   

!=============================================


END PROGRAM
