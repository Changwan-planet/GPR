
!=============================PATH===================================
!COMMON_PATH1="/home/changwan/GPR_DATA/KOREA/SPALAND/"
!COMMON_PATH1="/home/changwan/GPR_DATA/KOREA/MIHO_ri/CSCAN3/220526_1.PRJ/"
!COMMON_PATH1="/home/changwan/GPR_DATA/MOGOD/2021/F1/500MHz/"
COMMON_PATH1="/home/changwan/GPR_DATA/MOGOD/2020/Channel-1/500/"

INPUT_NAME10 = "3DCUBE_GPR_noprocessing.raw"       !10

OUTPUT_NAME20 = "3D_A_SCOPE_GPR.txt"               !20
OUTPUT_NAME21 = "3D_A_SCOPE_GPR_rmbgr.txt"         !21
OUTPUT_NAME22 = "3D_A_SCOPE_GPR_afzp.txt"          !22
OUTPUT_NAME23 = "INSTANT_A_SCOPE_GPR.txt"          !23

OUTPUT_NAME30 = "3D_BSCAN_GPR_noprocessing.txt"    !30
OUTPUT_NAME31 = "3D_BSCAN_GPR_rmbgr.txt"           !31
OUTPUT_NAME32 = "3D_BSCAN_GPR_afzp.txt"            !32
OUTPUT_NAME33 = "3D_BSCAN_GC.txt"                  !33


OUTPUT_NAME40 = "3D_CUBE_GPR.txt"                  !40 
OUTPUT_NAME41 = "3D_CUBE_GPR_GC.txt"               !41 

OUTPUT_NAME50 = "3D_FFT.txt"                       !50

OUTPUT_NAME60 = "3D_HILBERT_powerdB.txt"           !60

OUTPUT_NAME70 = "3D_GPR_phase.txt"                 !70


INPUT_PATH = TRIM(COMMON_PATH1)//INPUT_NAME10
OUTPUT_PATH20 = TRIM(COMMON_PATH1)//OUTPUT_NAME20
OUTPUT_PATH21 = TRIM(COMMON_PATH1)//OUTPUT_NAME21
OUTPUT_PATH22 = TRIM(COMMON_PATH1)//OUTPUT_NAME22
OUTPUT_PATH23 = TRIM(COMMON_PATH1)//OUTPUT_NAME23

OUTPUT_PATH30 = TRIM(COMMON_PATH1)//OUTPUT_NAME30
OUTPUT_PATH31 = TRIM(COMMON_PATH1)//OUTPUT_NAME31
OUTPUT_PATH32 = TRIM(COMMON_PATH1)//OUTPUT_NAME32
OUTPUT_PATH33 = TRIM(COMMON_PATH1)//OUTPUT_NAME33

OUTPUT_PATH40 = TRIM(COMMON_PATH1)//OUTPUT_NAME40
OUTPUT_PATH41 = TRIM(COMMON_PATH1)//OUTPUT_NAME41

OUTPUT_PATH50 = TRIM(COMMON_PATH1)//OUTPUT_NAME50

OUTPUT_PATH60 = TRIM(COMMON_PATH1)//OUTPUT_NAME60
OUTPUT_PATH70 = TRIM(COMMON_PATH1)//OUTPUT_NAME70
!=====================================================================

PRINT*, INPUT_PATH

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
!       READ(10) B_SCAN_IMAGE3
             
DO X = 1, DIS
  DO Y = 1, TRA
    DO Z = 1, ROWS

      B_SCAN_IMAGE3(X,Y,Z) = B_SCAN_IMAGE33(Z,Y,X)

!      PRINT *, X,Y,Z,"<----",Z,X,Y
        
    END DO
  END DO
END DO

PRINT *, "COMPLETED TO READ"    
PRINT *, "GPR TRACK REVERSED IN THE READER PRORGRAM"

