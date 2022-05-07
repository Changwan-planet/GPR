
!N = FH1 - 3

!N = 10
N = 8

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
CALL getcwd(CWD)
!PRINT *, TRIM(CWD)

!COMMON_PATH1= "/home/changwan/GPR_DATA/KOREA/MIHO_ri/220506_3.PRJ/"
COMMON_PATH1= "/home/changwan/GPR_DATA/KOREA/MIHO_ri/220503.PRJ/"
!COMMON_PATH1= "/home/changwan/GPR_DATA/KOREA/INBO_ri/220223_5.PRJ/"
!COMMON_PATH1= "/home/changwan/GPR_DATA/KOREA/GYODONG_ri/20211022/"
!COMMON_PATH1= "/home/changwan/GPR_DATA/KOREA/GYODONG_ri/211029/"



OUTPUT_NAME1="A_SCOPE_GPR.txt"                !20
OUTPUT_NAME2="BSCAN_GPR_noprocessing.txt"     !30
OUTPUT_NAME3="BSCAN_GPR_rmbgr.txt"            !31
OUTPUT_NAME4="BSCAN_GPR_stacking.txt"         !32
OUTPUT_NAME5="BSCAN_GPR_rmavrg.txt"           !33
OUTPUT_NAME6="HILBERT_BSCAN.txt"              !34
OUTPUT_NAME7="HILBERT_BSCAN_stacking.txt"     !35

INPUT_PATH = TRIM(COMMON_PATH1)//ITEM_NUMBER
OUTPUT_PATH1 = TRIM(COMMON_PATH1)//OUTPUT_NAME1
OUTPUT_PATH2 = TRIM(COMMON_PATH1)//OUTPUT_NAME2
OUTPUT_PATH3 = TRIM(COMMON_PATH1)//OUTPUT_NAME3
OUTPUT_PATH4 = TRIM(COMMON_PATH1)//OUTPUT_NAME4
OUTPUT_PATH5 = TRIM(COMMON_PATH1)//OUTPUT_NAME5
OUTPUT_PATH6 = TRIM(COMMON_PATH1)//OUTPUT_NAME6
OUTPUT_PATH7 = TRIM(COMMON_PATH1)//OUTPUT_NAME7





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


