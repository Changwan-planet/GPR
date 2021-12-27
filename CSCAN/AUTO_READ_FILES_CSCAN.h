
!N = FH1 - 3
N = 10 

DO G=1,TRA


!=====AUTOMATIC CHANCE CODE FOR OPENING FILE===================

   IF(G<=9.AND.G>=1) THEN

     WRITE(FH1(N+1:N+1), FMT='(I1)') 0
     WRITE(FH1(N+2:N+2), FMT='(I1)') 0
     WRITE(FH1(N+3:N+3), FMT='(I1)') G
   
   ELSE IF(G<=99.AND.G>=10) THEN
    
     WRITE(FH1(N+1:N+1), FMT='(I1)') 0
     WRITE(FH1(N+2:N+3), FMT='(I2)') G
   
   ELSE

     WRITE(FH1(N+1:N+3), FMT='(I3)') G
   END IF

   ITEM_NUMBER=TRIM(FH1//FT)

!=============================PATH===================================
!COMMON_PATH1="/home/changwan/GPR/211028/"
!COMMON_PATH2="/home/changwan/GPR/211028/"

!COMMON_PATH1="/home/changwan/GPR/211027_4/"
!COMMON_PATH2="/home/changwan/GPR/211027_4/"

!COMMON_PATH1="/mnt/l/MOGOD_GPR/2021/F1/250MHz/"
!COMMON_PATH1="/mnt/l/MOGOD_GPR/2021/F1/500MHz/"
!COMMON_PATH2="/mnt/l/MOGOD_GPR/2021/"

!COMMON_PATH1="/mnt/l/GPR_DATA/P211028.PRJ/"
!COMMON_PATH2="/mnt/l/GPR_DATA/P211028.PRJ/"

COMMON_PATH1="/mnt/l/GPR_DATA/P211027_4.PRJ/"
COMMON_PATH2="/mnt/l/GPR_DATA/P211027_4.PRJ/"

OUTPUT_NAME1="A_SCOPE_GPR.txt"
OUTPUT_NAME2="B_SCAN_IMAGE_GPR.txt"
OUTPUT_NAME3="C_SCAN_IMAGE_GPR.txt"
!OUTPUT_NAME3="C_SCAN_IMAGE_GPR_flip.txt"
OUTPUT_NAME4="3D_CUBE_IMAGE_GPR.txt"
OUTPUT_NAME5="HILBERT_3D_CUBE_IMAGE_GPR.txt"
OUTPUT_NAME6="OUPUT_TEST.txt"

INPUT_PATH = TRIM(COMMON_PATH1)//ITEM_NUMBER
OUTPUT_PATH1 = TRIM(COMMON_PATH2)//OUTPUT_NAME1
OUTPUT_PATH2 = TRIM(COMMON_PATH2)//OUTPUT_NAME2
OUTPUT_PATH3 = TRIM(COMMON_PATH2)//OUTPUT_NAME3
OUTPUT_PATH4 = TRIM(COMMON_PATH2)//OUTPUT_NAME4
OUTPUT_PATH5 = TRIM(COMMON_PATH2)//OUTPUT_NAME5
OUTPUT_PATH6 = TRIM(COMMON_PATH2)//OUTPUT_NAME6

!=====================================================================

!PRINT*, INPUT_PATH

OPEN(UNIT=10, FILE=INPUT_PATH,   ACCESS='STREAM',  STATUS='OLD', ACTION='READ')

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

!+++++REVERSING THE EVEN_GPR TRACKS+++++++++++++++++++++++
     IF (MOD(G,2)/=0) THEN
         B_SCAN_IMAGE2(:,:,G) = B_SCAN_IMAGE(:,:,G)
     ELSE
      DO P=1,DIS
          B_SCAN_IMAGE2(:,(DIS-P+1),G) = B_SCAN_IMAGE(:,P,G) 
      END DO
     END IF

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


