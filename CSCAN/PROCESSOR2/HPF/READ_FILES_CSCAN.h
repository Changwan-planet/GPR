!=============================PATH========================================
!COMMON_PATH1= "/home/changwan/GPR_DATA/KOREA/MIHO_ri/CSCAN3/220526_1.PRJ/"
!COMMON_PATH1= "/home/changwan/GPR_DATA/KOREA/MIHO_ri/220526_2.PRJ/result_1/"
!COMMON_PATH1= "/home/changwan/GPR_DATA/KOREA/INBO_ri/220223_5.PRJ/"
!COMMON_PATH1= "/home/changwan/GPR_DATA/KOREA/GYODONG_ri/20211022/"
!COMMON_PATH1= "/home/changwan/GPR_DATA/KOREA/GYODONG_ri/211029/"
!COMMON_PATH1= "/home/changwan/GPR_DATA/KOREA/MIHO_ri/100MHz/CSCAN3/220526_1.PRJ/"


!COMMON_PATH1= "/home/changwan/GPR_DATA/MOGOD/2021/F1/500MHz/"
!COMMON_PATH1= "/home/changwan/GPR_DATA/MOGOD/2022/Site-3/250/"
!COMMON_PATH1= "/home/changwan/GPR_DATA/MOGOD/2022/Site-1/RTA50/"
!COMMON_PATH1= "/home/changwan/GPR_DATA/MOGOD/2020/Pr-1/250MHz/"
!COMMON_PATH1= "/home/changwan/GPR_DATA/MOGOD/2020/Channel-1/500/Pr-1/"
COMMON_PATH1= "/home/changwan/GPR_DATA/MOGOD/2020/Channel-1/500/"


!INPUT_NAME10 = "BSCAN_GPR_noprocessing.raw"      !10
INPUT_NAME10 = "3DCUBE_GPR_noprocessing.raw"    !10

OUTPUT_NAME20 = "A_SCOPE_GPR.txt"                !20
OUTPUT_NAME21 = "A_SCOPE_GPR_Hilbert_real.txt"   !21
OUTPUT_NAME22 = "INSTANT_A_SCOPE_GPR.txt"        !22

OUTPUT_NAME30 = "BSCAN_GPR_noprocessing.txt"     !30
OUTPUT_NAME31 = "BSCAN_GPR_rmbgr_GC.txt"         !31
OUTPUT_NAME32 = "BSCAN_GPR_rmavrg_GC.txt"        !32
OUTPUT_NAME33 = "test.txt"                       !33

OUTPUT_NAME40 = "FFT.txt"                        !40
!OUTPUT_NAME41 = "test.txt"                      !41

OUTPUT_NAME50 = "INSTANT_GPR_powerdB.txt"        !50
OUTPUT_NAME51 = "INSTANT_GPR_power.txt"          !51

OUTPUT_NAME60 = "INSTANT_GPR_phase.txt"          !60
OUTPUT_NAME61 = "INSTANT_GPR_frequency.txt"      !61

OUTPUT_NAME70 = "TW_HPF.txt"                     !70
OUTPUT_NAME71 = "HPF_BSCAN_GC.txt"               !71

OUTPUT_NAME80 = "CSCAN_GPR_noprocessing.txt"     !80
OUTPUT_NAME81 = "CSCAN_GPR_rmbgr_GC.txt"         !81



INPUT_PATH = TRIM(COMMON_PATH1)//INPUT_NAME10
OUTPUT_PATH20 = TRIM(COMMON_PATH1)//OUTPUT_NAME20
OUTPUT_PATH21 = TRIM(COMMON_PATH1)//OUTPUT_NAME21
OUTPUT_PATH22 = TRIM(COMMON_PATH1)//OUTPUT_NAME22

OUTPUT_PATH30 = TRIM(COMMON_PATH1)//OUTPUT_NAME30
OUTPUT_PATH31 = TRIM(COMMON_PATH1)//OUTPUT_NAME31
OUTPUT_PATH32 = TRIM(COMMON_PATH1)//OUTPUT_NAME32
OUTPUT_PATH33 = TRIM(COMMON_PATH1)//OUTPUT_NAME33

OUTPUT_PATH40 = TRIM(COMMON_PATH1)//OUTPUT_NAME40
!OUTPUT_PATH41 = TRIM(COMMON_PATH1)//OUTPUT_NAME41

OUTPUT_PATH50 = TRIM(COMMON_PATH1)//OUTPUT_NAME50
OUTPUT_PATH51 = TRIM(COMMON_PATH1)//OUTPUT_NAME51

OUTPUT_PATH60 = TRIM(COMMON_PATH1)//OUTPUT_NAME60
OUTPUT_PATH61 = TRIM(COMMON_PATH1)//OUTPUT_NAME61

OUTPUT_PATH70 = TRIM(COMMON_PATH1)//OUTPUT_NAME70
OUTPUT_PATH71 = TRIM(COMMON_PATH1)//OUTPUT_NAME71

OUTPUT_PATH80 = TRIM(COMMON_PATH1)//OUTPUT_NAME80
OUTPUT_PATH81 = TRIM(COMMON_PATH1)//OUTPUT_NAME81

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

      READ(10) B_SCAN_IMAGE3
           
!+++++REVERSING THE EVEN_GPR TRACKS+++++++++++++++++++++++
!     READ(10) B_SCAN_IMAGE2

!     IF (MOD(G,2)/=0) THEN
!         B_SCAN_IMAGE3(:,:,G) = B_SCAN_IMAGE2(:,:,G)
!     ELSE
!      DO P=1,DIS
!          B_SCAN_IMAGE3(:,(DIS-P+1),G) = B_SCAN_IMAGE2(:,P,G) 
!      END DO
!     END IF


PRINT *, "COMPLETE TO READ"


