Program OPEN_GSSI
Implicit none

!USE GSSI_PROGRAM

!========PATH======================
CHARACTER (LEN=55) :: COMMON_PATH1
CHARACTER (LEN=55) :: COMMON_PATH2

CHARACTER (LEN=120) :: INPUT_PATH

CHARACTER (LEN=120) :: OUTPUT_PATH1
CHARACTER (LEN=120) :: OUTPUT_PATH2
CHARACTER (LEN=120) :: OUTPUT_PATH3

CHARACTER (LEN=50) :: OUTPUT_NAME1
CHARACTER (LEN=50) :: OUTPUT_NAME2
CHARACTER (LEN=50) :: OUTPUT_NAME3
!=================================


!==================================
INTEGER, DIMENSION(32768) :: HEADER    !32768 * 4 BYTES
INTEGER, PARAMETER :: ROWS=4096
!INTEGER            :: TRACK=19
!INTEGER            :: NU_Z,NU_X,NU_Y
INTEGER            :: DIS 
INTEGER            :: TRA
!==================================


!===========================================================
INTEGER, DIMENSION(:,:,:), ALLOCATABLE :: B_SCAN_IMAGE
!INTEGER, DIMENSION(:,:,:), ALLOCATABLE :: C_SCAN_IMAGE

REAL, DIMENSION(:,:,:), ALLOCATABLE :: B_SCAN_IMAGE2
REAL, DIMENSION(:,:,:), ALLOCATABLE :: C_SCAN_IMAGE
 
REAL, DIMENSION(ROWS,1) :: INTENSITY
!============================================================      


INTEGER             :: I,J,K,L,G, ALLOCATESTATUS


!=============================================================
CHARACTER (LEN=11)  :: FH1='201223__0'
CHARACTER (LEN=4)  :: FT='.DZT'
CHARACTER (LEN=15) :: ITEM_NUMBER



PRINT *, "PLEASE ENTER THE DISTANCE."
READ *, DIS
PRINT *, "PLEASE ENTER THE TRACK."
READ *, TRA

!G=11
Do G=1,TRA

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


OUTPUT_NAME1="A_SCOPE_GPR.txt"
OUTPUT_NAME2="B_SCAN_IMAGE_GPR.txt"
OUTPUT_NAME3="C_SCAN_IMAGE_GPR.txt"


INPUT_PATH = TRIM(COMMON_PATH1)//ITEM_NUMBER
OUTPUT_PATH1 = TRIM(COMMON_PATH2)//OUTPUT_NAME1
OUTPUT_PATH2 = TRIM(COMMON_PATH2)//OUTPUT_NAME2
OUTPUT_PATH3 = TRIM(COMMON_PATH2)//OUTPUT_NAME3
!=====================================================================

!Print*, INPUT_PATH
OPEN(UNIT=10,FILE=INPUT_PATH,FORM='UNFORMATTED',STATUS='OLD',ACTION='READ')
!OPEN(UNIT=20,FILE=OUTPUT_PATH1,STATUS='REPLACE',ACTION='WRITE')
!OPEN(UNIT=21,FILE=OUTPUT_PATH2,STATUS='REPLACE',ACTION='WRITE')
OPEN(UNIT=22,FILE=OUTPUT_PATH3,STATUS='REPLACE',ACTION='WRITE')


!======INITIALIZATION=======
!NU = 0
!DIS = 0
!TRA = 0
!B_SCAN_IMAGE = 0
!B_SCAN_IMAGE2 = 0
!C_SCAN_IMAGE = 0
!C_SCAN_IMAGE2 =0
!===========================  

PRINT *, "                                   X                                     "
PRINT *, "                                .                                        "
PRINT *, "                            .                                            " 
PRINT *, "                         .                                               " 
PRINT *, "                       *  *  *  *  *  *   *                              "
PRINT *, "                    *  `   `   `  `    *  *                              "
PRINT *, "                 *  `   `   A  `    *     *                              "
PRINT *, "              *  `   `   `  `    *        *                              "
PRINT *, "            * * * * * * * * * * - - - Y   *                              "
PRINT *, "            *  `  `  `  `  `  *           *        A (X , Y , Z)         "
PRINT *, "            *  `  `  `  `  `  *           *                              "   
PRINT *, "            *  `  `  `  `  `  *        *                                 "
PRINT *, "            *  `  `  `  `  `  *     *                                    "
PRINT *, "            *  `  `  `  `  `  *  *                                       "
PRINT *, "            *  `  `  `  `  `  *                                          "
PRINT *, "            .                                                            "
PRINT *, "            .                                                            " 
PRINT *, "            .                                                            " 
PRINT *, "            Z                                                            "

                    
!PRINT *,"PLEASE ENTER THE X NUMBER OF A_SCOPE THAT YOU WANNA PRINT OUT." 
!READ *, NU_X 
!PRINT *,"PLEASE ENTER THE Y NUMBER OF A_SCOPE THAT YOU WANNA PRINT OUT." 
!READ *, NU_Y 


ALLOCATE(B_SCAN_IMAGE(ROWS,DIS,TRA), &
         B_SCAN_IMAGE2(ROWS,DIS,TRA),&
         C_SCAN_IMAGE(ROWS,DIS,TRA),&
         STAT=ALLOCATESTATUS)

IF (ALLOCATESTATUS /= 0) STOP "***!NOT ENOUGH MEMORY***"

    PRINT *, "SIZE(C_SCAN_IMAGE)_x=",SIZE(B_SCAN_IMAGE,1)
    PRINT *, "SIZE(C_SCAN_IMAGE)_y=",SIZE(B_SCAN_IMAGE,2)
    PRINT *, "SIZE(C_SCAN_IMAGE)_z=",SIZE(B_SCAN_IMAGE,3)


      READ(10) HEADER,B_SCAN_IMAGE

    B_SCAN_IMAGE2=B_SCAN_IMAGE


!=======A-SCOPE===============================
    I=DIS

!    WRITE(20,*) (B_SCAN_IMAGE2(J,I,1), J=1,ROWS)
!    PRINT *, (B_SCAN_IMAGE2(J,I,1), J=1,ROWS)
   
!============================================= 


!======B_SCAN=================================
     
!     DO J=1,ROWS
!     WRITE(21,*)(B_SCAN_IMAGE2(J,I,1), I=1,DIS)
!    END DO
 
!    PRINT *, "SIZE(B_SCAN_IMAGE2)_x=",SIZE(B_SCAN_IMAGE2,1)
!    PRINT *, "SIZE(B_SCAN_IMAGE2)_y=",SIZE(B_SCAN_IMAGE2,2)
!    PRINT *, "SIZE(B_SCAN_IMAGE2)_z=",SIZE(B_SCAN_IMAGE2,3)


!=============================================
!SAMPLE
!NU_Z
!=====C_SCAN_IMAGE============================
  
          
    C_SCAN_IMAGE(ROWS,DIS,G) = B_SCAN_IMAGE2(ROWS,DIS,1)         

        
     PRINT *, "CHECK"
!=============================================


      
CLOSE(10)
CLOSE(22)

END DO
      
     J=500
       
       PRINT *, C_SCAN_IMAGE (J,DIS,TRA)
!       WRITE(22,*) C_SCAN_IMAGE (J,DIS,TRA)
       PRINT *, C_SCAN_IMAGE 


    PRINT *, "SIZE(C_SCAN_IMAGE)_x=",SIZE(C_SCAN_IMAGE,1)
    PRINT *, "SIZE(C_SCAN_IMAGE)_y=",SIZE(C_SCAN_IMAGE,2)
    PRINT *, "SIZE(C_SCAN_IMAGE)_z=",SIZE(C_SCAN_IMAGE,3)

END PROGRAM
