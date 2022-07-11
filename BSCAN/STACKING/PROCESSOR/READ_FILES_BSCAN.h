!COMMON_PATH1= "/home/changwan/GPR_DATA/KOREA/MIHO_ri/CSCAN2/220525_17.PRJ/"
COMMON_PATH1= "/home/changwan/GPR_DATA/KOREA/MIHO_ri/220506_3.PRJ/"
!COMMON_PATH1= "/home/changwan/GPR_DATA/KOREA/INBO_ri/220223_5.PRJ/"
!COMMON_PATH1= "/home/changwan/GPR_DATA/KOREA/GYODONG_ri/20211022/"
!COMMON_PATH1= "/home/changwan/GPR_DATA/KOREA/GYODONG_ri/211029/"

!INPUT_NAME10 = "BSCAN_GPR_noprocessing.raw"      !10
INPUT_NAME10 = "3DCUBE_GPR_noprocessing.raw"      !10


OUTPUT_NAME20 = "A_SCOPE_GPR.txt"                !20
OUTPUT_NAME21 = "A_SCOPE_GPR_Hilbert_real.txt"   !21
OUTPUT_NAME22 = "INSTANT_A_SCOPE_GPR.txt"        !22
OUTPUT_NAME23 = "test.txt"                       !23


OUTPUT_NAME30 = "BSCAN_GPR_noprocessing.txt"     !30
OUTPUT_NAME31 = "BSCAN_GPR_rmbgr_GC.txt"         !31
OUTPUT_NAME32 = "STACKED_BSCAN_GPR_rmbgr_GC.txt" !32
OUTPUT_NAME33 = "STACKED_BSCAN_GPR_rmavrg_GC.txt"!33


OUTPUT_NAME50 = "INSTANT_GPR_powerdB.txt"        !50
OUTPUT_NAME51 = "INSTANT_GPR_power.txt"          !51

OUTPUT_NAME60 = "INSTANT_GPR_phase.txt"          !60
OUTPUT_NAME61 = "INSTANT_GPR_frequency.txt"      !61



INPUT_PATH = TRIM(COMMON_PATH1)//INPUT_NAME10
OUTPUT_PATH20 = TRIM(COMMON_PATH1)//OUTPUT_NAME20
OUTPUT_PATH21 = TRIM(COMMON_PATH1)//OUTPUT_NAME21
OUTPUT_PATH22 = TRIM(COMMON_PATH1)//OUTPUT_NAME22
OUTPUT_PATH23 = TRIM(COMMON_PATH1)//OUTPUT_NAME23

OUTPUT_PATH30 = TRIM(COMMON_PATH1)//OUTPUT_NAME30
OUTPUT_PATH31 = TRIM(COMMON_PATH1)//OUTPUT_NAME31
OUTPUT_PATH32 = TRIM(COMMON_PATH1)//OUTPUT_NAME32
OUTPUT_PATH33 = TRIM(COMMON_PATH1)//OUTPUT_NAME33

OUTPUT_PATH50 = TRIM(COMMON_PATH1)//OUTPUT_NAME50
OUTPUT_PATH51 = TRIM(COMMON_PATH1)//OUTPUT_NAME51


OUTPUT_PATH60 = TRIM(COMMON_PATH1)//OUTPUT_NAME60
OUTPUT_PATH61 = TRIM(COMMON_PATH1)//OUTPUT_NAME61



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


      READ(10) B_SCAN_IMAGE33
             
!+++++REVERSING THE EVEN_GPR TRACKS+++++++++++++++++++++++
!     IF (MOD(G,2)/=0) THEN
!         B_SCAN_IMAGE2(:,:,G) = B_SCAN_IMAGE(:,:,G)
!     ELSE
!      DO P=1,DIS
!          B_SCAN_IMAGE2(:,(DIS-P+1),G) = B_SCAN_IMAGE(:,P,G) 
!      END DO
!     END IF

      PRINT *, "COMPLETE TO READ"

DO X = 1, DIS
  DO Y = 1, TRA
    DO Z = 1, ROWS

      B_SCAN_IMAGE3(X,Y,Z) = B_SCAN_IMAGE33(Z,Y,X)

!      PRINT *, X,Y,Z,"<----",Z,X,Y

    END DO
  END DO
END DO
 
