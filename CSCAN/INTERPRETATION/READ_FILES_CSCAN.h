
!=============================PATH===================================
!COMMON_PATH1="/home/changwan/GPR_DATA/KOREA/SPALAND/"
!COMMON_PATH1="/home/changwan/GPR_DATA/KOREA/MIHO_ri/CSCAN3/220526_1.PRJ/"
!COMMON_PATH1="/home/changwan/GPR_DATA/MOGOD/2021/F1/500MHz/"
!COMMON_PATH1="/home/changwan/GPR_DATA/MOGOD/2020/Channel-1/500/"
!COMMON_PATH1="/home/changwan/GPR_DATA/MIHO_ri/3D_trench/40MHz/CSCAN3/NS/attrtibute/"
COMMON_PATH1="/home/changwan/GPR_DATA/KOREA/MIHO_ri/3D_trench/40MHz/CSCAN3/NS/"

COMMON_PATH2="/home/changwan/GPR_DATA/KOREA/MIHO_ri/3D_trench/40MHz/CSCAN3/NS/attribute/"



!INPUT_NAME10 = "3DCUBE_GPR_noprocessing.raw"       !10
!INPUT_NAME10 = "3DCUBE_GPR_rmbgr_zpd.raw"          !10
INPUT_NAME10 = "3D_CUBE_GPR.txt"                    !10
INPUT_NAME11 = "3D_CUBE_GPR_gc.txt"                 !11
INPUT_NAME12 = "3D_HILBERT_powerdB.txt"             !12



INPUT_NAME13 = "3D_BSCAN_GPR_GC.txt"                !31
INPUT_NAME14 = "3D_CUBE_GPR.txt"                    !40 
INPUT_NAME15 = "3D_CUBE_GPR_GC.txt"                 !41 
INPUT_NAME16 = "3D_BPF_GC.txt"                      !81


OUTPUT_NAME20 = "3D_ASCAN_GPR.txt"                  !20
OUTPUT_NAME21 = "3D_ASCAN_GPR_gc.txt"               !21
OUTPUT_NAME22 = "3D_ASCAN_powerdB.txt"              !22


OUTPUT_NAME30 = "3D_BSCAN_AMP_GC.txt"                  !30
OUTPUT_NAME31 = "3D_BSCAN_AMP.txt"               !31


!OUTPUT_NAME31 = "3D_BSCAN_powerdB.txt"              !31


!OUTPUT_NAME50 = "3D_FFT.txt"                       !50
!OUTPUT_NAME60 = "3D_HILBERT_powerdB.txt"           !60
!OUTPUT_NAME70 = "3D_GPR_phase.txt"                 !70

OUTPUT_NAME90 = "HORIZON_PICK_SURFACE.txt"          !90
OUTPUT_NAME91 = "HORIZON_PICK_DIFF.txt"             !91
OUTPUT_NAME92 = "HORIZON_PICK2.txt"                 !92




INPUT_PATH10 = TRIM(COMMON_PATH1)//INPUT_NAME10
INPUT_PATH11 = TRIM(COMMON_PATH1)//INPUT_NAME11
INPUT_PATH12 = TRIM(COMMON_PATH2)//INPUT_NAME12
!INPUT_PATH13 = TRIM(COMMON_PATH1)//INPUT_NAME13
!INPUT_PATH14 = TRIM(COMMON_PATH1)//INPUT_NAME14
!INPUT_PATH15 = TRIM(COMMON_PATH1)//INPUT_NAME15
!INPUT_PATH16 = TRIM(COMMON_PATH1)//INPUT_NAME16



OUTPUT_PATH20 = TRIM(COMMON_PATH1)//OUTPUT_NAME20
OUTPUT_PATH21 = TRIM(COMMON_PATH1)//OUTPUT_NAME21
OUTPUT_PATH22 = TRIM(COMMON_PATH1)//OUTPUT_NAME22


OUTPUT_PATH30 = TRIM(COMMON_PATH1)//OUTPUT_NAME30
OUTPUT_PATH31 = TRIM(COMMON_PATH1)//OUTPUT_NAME31
!OUTPUT_PATH40 = TRIM(COMMON_PATH1)//OUTPUT_NAME40
!OUTPUT_PATH41 = TRIM(COMMON_PATH1)//OUTPUT_NAME41
!OUTPUT_PATH50 = TRIM(COMMON_PATH1)//OUTPUT_NAME50
!OUTPUT_PATH60 = TRIM(COMMON_PATH1)//OUTPUT_NAME60
!OUTPUT_PATH70 = TRIM(COMMON_PATH1)//OUTPUT_NAME70
!OUTPUT_PATH80 = TRIM(COMMON_PATH1)//OUTPUT_NAME80
!OUTPUT_PATH81 = TRIM(COMMON_PATH1)//OUTPUT_NAME81

OUTPUT_PATH90 = TRIM(COMMON_PATH1)//OUTPUT_NAME90
OUTPUT_PATH91 = TRIM(COMMON_PATH1)//OUTPUT_NAME91
OUTPUT_PATH92 = TRIM(COMMON_PATH1)//OUTPUT_NAME92
!=====================================================================

PRINT*, INPUT_PATH10
PRINT*, INPUT_PATH11
PRINT*, INPUT_PATH12
!PRINT*, INPUT_PATH13
!PRINT*, INPUT_PATH14
!PRINT*, INPUT_PATH15
!PRINT*, INPUT_PATH16

!OPEN(UNIT=10, FILE=INPUT_PATH10,   ACCESS='STREAM',  STATUS='OLD', ACTION='READ')
OPEN(UNIT=10, FILE=INPUT_PATH10,  FORM="FORMATTED",  STATUS='OLD', ACTION='READ')


!OPEN(UNIT=11, FILE=INPUT_PATH11,   ACCESS='STREAM',  STATUS='OLD', ACTION='READ')
OPEN(UNIT=11, FILE=INPUT_PATH11,  FORM="FORMATTED",  STATUS='OLD', ACTION='READ')


!OPEN(UNIT=12, FILE=INPUT_PATH12,   ACCESS='STREAM',  STATUS='OLD', ACTION='READ')
OPEN(UNIT=12, FILE=INPUT_PATH12,  FORM="FORMATTED",  STATUS='OLD', ACTION='READ')


!OPEN(UNIT=13, FILE=INPUT_PATH13,   ACCESS='STREAM',  STATUS='OLD', ACTION='READ')
!OPEN(UNIT=14, FILE=INPUT_PATH14,   ACCESS='STREAM',  STATUS='OLD', ACTION='READ')
!OPEN(UNIT=15, FILE=INPUT_PATH15,   ACCESS='STREAM',  STATUS='OLD', ACTION='READ')
!OPEN(UNIT=16, FILE=INPUT_PATH16,   ACCESS='STREAM',  STATUS='OLD', ACTION='READ')



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



DO R = 1, DIS * TRA * ROWS
       READ(10,*) XX, YY, ZZ, B_SCAN_IMAGE(XX,YY,ZZ)
END DO    

DO R = 1, DIS * TRA * ROWS2
       READ(11,*) XX, YY, ZZ, B_SCAN_IMAGE_GC(XX,YY,ZZ)
END DO    

DO R = 1, DIS * TRA * ROWS
       READ(12,*) XX, YY, ZZ, HILBERT_powerdB(XX,YY,ZZ)
END DO    



PRINT *, "COMPLETED TO READ"    
            

