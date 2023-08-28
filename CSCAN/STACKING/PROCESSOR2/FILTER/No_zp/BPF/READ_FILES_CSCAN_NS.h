
!=============================PATH===================================
!COMMON_PATH1="/home/changwan/GPR_DATA/KOREA/SPALAND/"
!COMMON_PATH1="/home/changwan/GPR_DATA/KOREA/MIHO_ri/CSCAN3/220526_1.PRJ/"
!COMMON_PATH1="/home/changwan/GPR_DATA/MOGOD/2021/F1/500MHz/"
!COMMON_PATH1="/home/changwan/GPR_DATA/MOGOD/2020/Channel-1/500/"

!NS
!MIHO_ri
COMMON_PATH1="/home/changwan/GPR_DATA/KOREA/MIHO_ri/40MHz/2023/NS/"
!
!COMMON_PATH1="/home/changwan/GPR_DATA/KOREA/MIHO_ri/3D_trench/40MHz/BSCAN/NS/"
!COMMON_PATH1="/home/changwan/GPR_DATA/KOREA/MIHO_ri/3D_trench/40MHz/CSCAN3/NS/"
!COMMON_PATH1="/home/changwan/GPR_DATA/KOREA/MIHO_ri/40MHz/2023/NS/"


!MUNAM_ri
!COMMON_PATH1="/home/changwan/GPR_DATA/KOREA/MUNAM_ri/"


!DIRECTORY TEST AND MAKER
l1 = .false.

PATH2 = "filter/"
PATH3 = "bpf/"
PATH4 = "attribute/"
PATH5 = "horizon/"

COMMON_PATH2 = TRIM(COMMON_PATH1)//PATH2
COMMON_PATH3 = TRIM(COMMON_PATH1)//PATH3
COMMON_PATH4 = TRIM(COMMON_PATH1)//PATH4
COMMON_PATH5 = TRIM(COMMON_PATH1)//PATH5

MKD = "mkdir"
CMD2 = MKD//COMMON_PATH2 
CMD3 = MKD//COMMON_PATH3 
CMD4 = MKD//COMMON_PATH4
CMD5 = MKD//COMMON_PATH5 


INQUIRE(FILE=COMMON_PATH2, EXIST=file_exists)
IF (file_exists .eqv.l1) CALL system(CMD2)
INQUIRE(FILE=COMMON_PATH3, EXIST=file_exists)
IF (file_exists .eqv.l1) CALL system(CMD3)
INQUIRE(FILE=COMMON_PATH4, EXIST=file_exists)
IF (file_exists .eqv.l1) CALL system(CMD4)
INQUIRE(FILE=COMMON_PATH5, EXIST=file_exists)
IF (file_exists .eqv.l1) CALL system(CMD5)



!INPUT_NAME10 = "3DCUBE_GPR_noprocessing.raw"      !10
!INPUT_NAME10 = "3DCUBE_GPR_rmbgr_zpd.raw"          !10
!INPUT_NAME10 = "3DCUBE_GPR_stacking.raw"          !10
INPUT_NAME10 = "3DCUBE_GPR_stacking.txt"          !10



OUTPUT_NAME20 = "3D_A_SCOPE_GPR.txt"          !20
OUTPUT_NAME21 = "INSTANT_A_SCOPE_GPR.txt"          !21

OUTPUT_NAME30 = "3D_BSCAN_GPR.txt"            !30
!OUTPUT_NAME31 = "3D_BSCAN_GPR_GC.txt"              !31

OUTPUT_NAME40 = "3D_CUBE_GPR.txt"                  !40 
OUTPUT_NAME41 = "3D_CUBE_GPR_rmavrg.txt"               !41 

OUTPUT_NAME50 = "3D_FFT.txt"                       !50

OUTPUT_NAME60 = "3D_HILBERT_powerdB.txt"           !60

OUTPUT_NAME70 = "3D_GPR_phase.txt"                 !70

OUTPUT_NAME80 = "3D_TW_BPF.txt"                    !80
!OUTPUT_NAME81 = "3D_BPF_GC.txt"                    !81
OUTPUT_NAME81 = "3D_BPF.txt"                    !81


!OUTPUT_NAME90 = "HORIZON_PICK.txt"                 !90


INPUT_PATH = TRIM(COMMON_PATH1)//INPUT_NAME10

OUTPUT_PATH20 = TRIM(COMMON_PATH1)//OUTPUT_NAME20
OUTPUT_PATH21 = TRIM(COMMON_PATH1)//OUTPUT_NAME21

OUTPUT_PATH30 = TRIM(COMMON_PATH1)//OUTPUT_NAME30
!OUTPUT_PATH31 = TRIM(COMMON_PATH1)//OUTPUT_NAME31


OUTPUT_PATH40 = TRIM(COMMON_PATH1)//OUTPUT_NAME40
OUTPUT_PATH41 = TRIM(COMMON_PATH1)//OUTPUT_NAME41

OUTPUT_PATH50 = TRIM(COMMON_PATH2)//OUTPUT_NAME50

OUTPUT_PATH60 = TRIM(COMMON_PATH4)//OUTPUT_NAME60
OUTPUT_PATH70 = TRIM(COMMON_PATH4)//OUTPUT_NAME70

OUTPUT_PATH80 = TRIM(COMMON_PATH2)//OUTPUT_NAME80
OUTPUT_PATH81 = TRIM(COMMON_PATH2)//OUTPUT_NAME81

!OUTPUT_PATH90 = TRIM(COMMON_PATH5)//OUTPUT_NAME90


!=====================================================================

PRINT*, INPUT_PATH

OPEN(UNIT=10, FILE=INPUT_PATH, FORM="FORMATTED", STATUS='OLD', ACTION='READ')
!OPEN(UNIT=10, FILE=INPUT_PATH,   ACCESS='STREAM',  STATUS='OLD', ACTION='READ')


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
!DO Y = 1, TRA
!DO X = 1, DIS
!DO Z = 1, ROWS
!       READ(10,*) B_SCAN_IMAGE(X,Y,Z), XX, YY, ZZ
        READ(10,*) XX, YY, ZZ, B_SCAN_IMAGE(XX,YY,ZZ)
!END DO 
!END DO 
!END DO 
END DO             
PRINT *, "COMPLETED TO READ"    

