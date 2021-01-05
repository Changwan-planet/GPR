PROGRAM OPEN_GSSI
Implicit none

!USE GSSI_PROGRAM

!========PATH======================
CHARACTER (LEN=55) :: COMMON_PATH1
CHARACTER (LEN=55) :: COMMON_PATH2

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
INTEGER, DIMENSION(32768) :: HEADER    !32768 * 4 BYTES
INTEGER, PARAMETER :: ROWS=4096
INTEGER, PARAMETER :: DIS=500 
INTEGER, PARAMETER :: TRA=19
!==================================


!===========================================================
INTEGER, DIMENSION(ROWS,DIS,TRA) :: B_SCAN_IMAGE
REAL, DIMENSION(ROWS,DIS,TRA) :: B_SCAN_IMAGE2
REAL, DIMENSION(ROWS,1) :: INTENSITY
!============================================================      


INTEGER             :: I,J,K,G,O,P,Q, SAMPLE, ALLOCATESTATUS


!=============================================================
CHARACTER (LEN=11)  :: FH1='201223__0'
CHARACTER (LEN=4)  :: FT='.DZT'
CHARACTER (LEN=15) :: ITEM_NUMBER

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
OUTPUT_NAME4="3D_IMAGE_GPR.txt"

INPUT_PATH = TRIM(COMMON_PATH1)//ITEM_NUMBER
OUTPUT_PATH1 = TRIM(COMMON_PATH2)//OUTPUT_NAME1
OUTPUT_PATH2 = TRIM(COMMON_PATH2)//OUTPUT_NAME2
OUTPUT_PATH3 = TRIM(COMMON_PATH2)//OUTPUT_NAME3
OUTPUT_PATH4 = TRIM(COMMON_PATH2)//OUTPUT_NAME4
!=====================================================================

!Print*, INPUT_PATH
OPEN(UNIT=10,FILE=INPUT_PATH,FORM='UNFORMATTED',STATUS='OLD',ACTION='READ')
!OPEN(UNIT=20,FILE=OUTPUT_PATH1,STATUS='REPLACE',ACTION='WRITE')  !A_SCOPE
!OPEN(UNIT=21,FILE=OUTPUT_PATH2,STATUS='REPLACE',ACTION='WRITE')  !B_SCAN_IMAGE

!======INITIALIZATION=======
!B_SCAN_IMAGE = 0
!B_SCAN_IMAGE2 = 0
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


      READ(10) HEADER,B_SCAN_IMAGE(:,:,G)

      B_SCAN_IMAGE2(:,:,G)=B_SCAN_IMAGE(:,:,G)
      PRINT *, "G=",G    
!=======A-SCOPE===============================
!    I=DIS

    !WRITE(20,*) (B_SCAN_IMAGE2(J,I,1), J=1,ROWS)
!    PRINT *, (B_SCAN_IMAGE2(J,I,1), J=1,ROWS)
   
!============================================= 

     
!======B_SCAN=================================
     
!     DO J=1,ROWS
!        WRITE(21,*)(B_SCAN_IMAGE2(J,I,G), I=1,DIS)
!     END DO
!=============================================
!     PRINT *, "CHECK",G


CLOSE(10)

END DO
 
!PRINT *, "SIZE(B_SCAN_IMAGE2)_x=",SIZE(B_SCAN_IMAGE2,1)
!PRINT *, "SIZE(B_SCAN_IMAGE2)_y=",SIZE(B_SCAN_IMAGE2,2)
!PRINT *, "SIZE(B_SCAN_IMAGE2)_z=",SIZE(B_SCAN_IMAGE2,3)

OPEN(UNIT=22,FILE=OUTPUT_PATH3,STATUS='REPLACE',ACTION='WRITE')  !C_SCAN_IMAGE
OPEN(UNIT=23,FILE=OUTPUT_PATH4,STATUS='REPLACE',ACTION='WRITE')   !3D_IMAGE


!=====C_SCAN_IMAGE============================
I=0
J=0
K=0

PRINT *, "PLEASE ENTER THE SAMPLE AMONG 4096 SAMPLES [DEPTH]."
READ *, SAMPLE
 I=SAMPLE
       DO J=1,DIS            

          WRITE(22,*) (B_SCAN_IMAGE2(I,J,K),K=1,TRA)          
!          PRINT *, (B_SCAN_IMAGE2(I,J,K),K=1,TRA)          

       END DO
     PRINT *, "COMPLETE C_SCAN_IMAGE OUPUT"

!=============================================

!====3D DATASET===============================
I=0
J=0
K=0

       DO I=1,ROWS           
          DO J=1,DIS
             WRITE(23,*) (B_SCAN_IMAGE2(I,J,K),K=1,TRA)          
!             PRINT *, (B_SCAN_IMAGE2(I,J,K),K=1,TRA)          
          END DO
       END DO
     PRINT *, "COMPLETE 3D_DATASET OUTPUT"

PRINT *, "SIZE(B_SCAN_IMAGE2)_x=",SIZE(B_SCAN_IMAGE2,1)
PRINT *, "SIZE(B_SCAN_IMAGE2)_y=",SIZE(B_SCAN_IMAGE2,2)
PRINT *, "SIZE(B_SCAN_IMAGE2)_z=",SIZE(B_SCAN_IMAGE2,3)

!==============================================


STOP  

END PROGRAM
