!=============================PATH===================================
CALL getcwd(CWD)
!PRINT *, TRIM(CWD)
!COMMON_PATH1= "/home/changwan/GPR_DATA/KOREA/MIHO_ri/CSCAN3/220536_1.PRJ/"
!COMMON_PATH1= "/home/changwan/GPR_DATA/KOREA/MIHO_ri/220519_7.PRJ/"
!COMMON_PATH1= "/home/changwan/GPR_DATA/KOREA/MIHO_ri/220526_2.PRJ/"
!COMMON_PATH1= "/home/changwan/GPR_DATA/KOREA/INBO_ri/220223_5.PRJ/"
!COMMON_PATH1= "/home/changwan/GPR_DATA/KOREA/GYODONG_ri/20211022/"
!COMMON_PATH1= "/home/changwan/GPR_DATA/KOREA/GYODONG_ri/211029/"
!COMMON_PATH1= "/home/changwan/GPR_DATA/MOGOD/2022/Site-3/250/"
COMMON_PATH1= "/home/changwan/GPR_DATA/KOREA/MIHO_ri/2020_BOMIN/"
!============================================================

!INPUT_NAME = "DAT_1233_1.rd3"
INPUT_NAME = "DAT_1233_2.rd3"

OUTPUT_NAME20 = "A_SCOPE_GPR.txt"                 !20
OUTPUT_NAME30 = "BSCAN_GPR_noprocessing.raw"      !30
!OUTPUT_NAME30 = "BSCAN_GPR_noprocessing.txt"     !30
!OUTPUT_NAME40 = "3DCUBE_GPR_noprocessing.raw"    !40

INPUT_PATH = TRIM(COMMON_PATH1)//INPUT_NAME
OUTPUT_PATH20 = TRIM(COMMON_PATH1)//OUTPUT_NAME20
OUTPUT_PATH30 = TRIM(COMMON_PATH1)//OUTPUT_NAME30
!OUTPUT_PATH40 = TRIM(COMMON_PATH1)//OUTPUT_NAME40
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


      READ(10)  B_SCAN_IMAGE(:,:,1)

!      READ(10) HEADER, B_SCAN_IMAGE(:,:,1)

             
      B_SCAN_IMAGE2(:,:,1) = B_SCAN_IMAGE(:,:,1)

!+++++REVERSING THE EVEN_GPR TRACKS+++++++++++++++++++++++
!     IF (MOD(G,2)/=0) THEN
!         B_SCAN_IMAGE2(:,:,G) = B_SCAN_IMAGE(:,:,G)
!     ELSE
!      DO P=1,DIS
!          B_SCAN_IMAGE2(:,(DIS-P+1),G) = B_SCAN_IMAGE(:,P,G) 
!      END DO
!     END IF
!     PRINT *, "G=",G    

DO X = 1, DIS
  DO Y = 1, TRA
    DO Z = 1, ROWS

      B_SCAN_IMAGE3(X,Y,Z) = B_SCAN_IMAGE2(Z,X,Y)

!      PRINT *, X,Y,Z,"<----",Z,X,Y

    END DO
  END DO
END DO
 
!!CLOSE(10)

!!END DO


