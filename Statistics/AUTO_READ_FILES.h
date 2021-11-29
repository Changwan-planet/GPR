
INTEGER, PARAMETER :: N = 13
INTEGER, PARAMETER :: N2 = N-1
INTEGER, PARAMETER :: N3 = N-2

!CHARACTER (LEN=N) ::  FH1 =  '211027__'
!CHARACTER (LEN=N) ::  FH1 = '211029__'
!CHARACTER (LEN=N) ::  FH1 = '211027_3__'
CHARACTER (LEN=N) ::  FH1 = '201022_2__'


CHARACTER (LEN=4)  :: FT='.DZT'

CHARACTER (LEN=22) :: ITEM_NUMBER

DO G=1,TRA


!=====AUTOMATIC CHANCE CODE FOR OPENING FILE===================

   IF(G<=9.AND.G>=1) THEN

     WRITE(FH1(N3:N3), FMT='(I1)') 0
     WRITE(FH1(N2:N2), FMT='(I1)') 0
     WRITE(FH1(N:N), FMT='(I1)') G
   
   ELSE IF(G<=99.AND.G>=10) THEN
    
     WRITE(FH1(N3:N3), FMT='(I1)') 0
     WRITE(FH1(N2:N), FMT='(I2)') G
   
   ELSE

     WRITE(FH1(N3:N), FMT='(I3)') G
   END IF

   ITEM_NUMBER=TRIM(FH1//FT)

PRINT *, ITEM_NUMBER

!=============================PATH===================================
!COMMON_PATH1="/home/changwan/GPR/211029/"
!COMMON_PATH2="/home/changwan/GPR/211029/"

!COMMON_PATH1="/home/changwan/GPR/20211022/"
!COMMON_PATH2="/home/changwan/GPR/20211022/"

COMMON_PATH1="/home/changwan/GPR/20211022_2/"
COMMON_PATH2="/home/changwan/GPR/20211022_2/"

!COMMON_PATH1="/home/changwan/GPR/211027_3/"
!COMMON_PATH2="/home/changwan/GPR/211027_3/"


!COMMON_PATH1="/mnt/l/GPR_DATA/"
!COMMON_PATH2="/mnt/l/GPR_DATA/"

OUTPUT_NAME1="A_SCOPE_GPR.txt"
OUTPUT_NAME2="A_SCOPE_GPR_BGR.txt"
OUTPUT_NAME3="B_SCAN_IMAGE_GPR.txt"
OUTPUT_NAME4="STACKED_A_SCOPE_MULTIPLE.txt"
OUTPUT_NAME5="FFT_STACKED_A_GPR.txt"
OUTPUT_NAME6="HILBERT_A_GPR.txt"
OUTPUT_NAME7="HILBERT_STACKED_A_GPR.txt"
OUTPUT_NAME8="DFT_STACKED_A_GPR.txt"
OUTPUT_NAME9="MAX_LAYER.txt"



INPUT_PATH = TRIM(COMMON_PATH1)//ITEM_NUMBER
OUTPUT_PATH1 = TRIM(COMMON_PATH2)//OUTPUT_NAME1
OUTPUT_PATH2 = TRIM(COMMON_PATH2)//OUTPUT_NAME2
OUTPUT_PATH3 = TRIM(COMMON_PATH2)//OUTPUT_NAME3
OUTPUT_PATH4 = TRIM(COMMON_PATH2)//OUTPUT_NAME4
OUTPUT_PATH5 = TRIM(COMMON_PATH2)//OUTPUT_NAME5
OUTPUT_PATH6 = TRIM(COMMON_PATH2)//OUTPUT_NAME6
OUTPUT_PATH7 = TRIM(COMMON_PATH2)//OUTPUT_NAME7
OUTPUT_PATH8 = TRIM(COMMON_PATH2)//OUTPUT_NAME8
OUTPUT_PATH9 = TRIM(COMMON_PATH2)//OUTPUT_NAME9

!=====================================================================

OPEN(UNIT=10, FILE=INPUT_PATH, FORM='UNFORMATTED', ACCESS='STREAM', STATUS='OLD', ACTION='READ')
!OPEN(UNIT=10, FILE=INPUT_PATH, FORM='FORMATTED', STATUS='OLD', ACTION='READ')

!======INITIALIZATION=======
!B_SCAN_IMAGE = 0
!B_SCAN_IMAGE2 = 0
!===========================  

!PRINT *, "                                   X                                     "
!PRINT *, "                                .                                        "
!PRINT *, "                            .                                            " 
!PRINT *, "                         .                                               " 
!PRINT *, "                       *  *  *  *  *  *   *                              "
!PRINT *, "                    *  `   `   `  `    *  *                              "
!PRINT *, "                 *  `   `   A  `    *     *                              "
!PRINT *, "              *  `   `   `  `    *        *                              "
!PRINT *, "            * * * * * * * * * * - - - Y   *                              "
!PRINT *, "            *  `  `  `  `  `  *           *        A (X , Y , Z)         "
!PRINT *, "            *  `  `  `  `  `  *           *                              "   
!PRINT *, "            *  `  `  `  `  `  *        *                                 "
!PRINT *, "            *  `  `  `  `  `  *     *                                    "
!PRINT *, "            *  `  `  `  `  `  *  *                                       "
!PRINT *, "            *  `  `  `  `  `  *                                          "
!PRINT *, "            .                                                            "
!PRINT *, "            .                                                            " 
!PRINT *, "            .                                                            " 
!PRINT *, "            Z                                                            "


      READ(10) HEADER, B_SCAN_IMAGE(:,:,G)
             
      B_SCAN_IMAGE2(:,:,G) = B_SCAN_IMAGE(:,:,G)

!B_SCAN_IMAGE2(1000,100,G) = 1000000000  
!+++++REVERSING THE EVEN_GPR TRACKS+++++++++++++++++++++++
!     IF (MOD(G,2)/=0) THEN
!         B_SCAN_IMAGE2(:,:,G) = B_SCAN_IMAGE(:,:,G)
!     ELSE
!      DO P=1,DIS
!          B_SCAN_IMAGE2(:,(DIS-P+1),G) = B_SCAN_IMAGE(:,P,G) 
!      END DO
!     END IF

      PRINT *, "G=",G    

DO X = 1, DIS
  DO Y = 1, TRA
    DO Z = 1, ROWS

      B_SCAN_IMAGE3(X,Y,Z) = B_SCAN_IMAGE2(Z,X,Y)

!      PRINT *, X,Y,Z,"<----",Z,X,Y

    END DO
  END DO
END DO


CLOSE(10)

END DO


