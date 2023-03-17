
!=============================PATH===================================
!COMMON_PATH1="/home/changwan/GPR_DATA/KOREA/SPALAND/"
!COMMON_PATH1="/home/changwan/GPR_DATA/KOREA/MIHO_ri/CSCAN3/220526_1.PRJ/"
!COMMON_PATH1="/home/changwan/GPR_DATA/MOGOD/2021/F1/500MHz/"
!COMMON_PATH1="/home/changwan/GPR_DATA/MOGOD/2020/Channel-1/500/"
!COMMON_PATH1="/home/changwan/GPR_DATA/KOREA/MIHO_ri/2022_BOMIN/Analysis/"
COMMON_PATH1="/home/changwan/GPR_DATA/KOREA/MIHO_ri/3D_trench/100MHz/Analysis/"


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
INPUT_NAME10 = "3DCUBE_GPR_rmbgr.raw"              !10


OUTPUT_NAME20 = "3D_A_SCOPE_GPR_afzp.txt"          !20
OUTPUT_NAME21 = "INSTANT_A_SCOPE_GPR.txt"          !21

OUTPUT_NAME30 = "3D_BSCAN_GPR_afzp.txt"            !30
OUTPUT_NAME31 = "3D_BSCAN_GPR_rmavg.txt"           !31

OUTPUT_NAME40 = "3D_CUBE_GPR_afzp.txt"             !40 
OUTPUT_NAME41 = "3D_CUBE_GPR_rmavg.txt"            !41 

OUTPUT_NAME50 = "3D_FFT.txt"                       !50
OUTPUT_NAME51 = "3D_FT_DIAGRAM.txt" 		   !51	

OUTPUT_NAME60 = "3D_HILBERT_powerdB.txt"           !60

OUTPUT_NAME70 = "3D_GPR_phase.txt"                 !70

OUTPUT_NAME80 = "3D_TW_BPF.txt"                    !80
OUTPUT_NAME81 = "3D_BPF_rmavg.txt"                    !81
OUTPUT_NAME82 = "3D_BPF_FT_DIAGRAM.txt"            !82


OUTPUT_NAME85 = "3D_TW_HPF.txt"                    !85
OUTPUT_NAME86 = "3D_HPF_GC.txt"                    !86
OUTPUT_NAME87 = "3D_HPF_FT_DIAGRAM.txt"            !87

OUTPUT_NAME90 = "HORIZON_PICK.txt"                 !90


INPUT_PATH = TRIM(COMMON_PATH1)//INPUT_NAME10
OUTPUT_PATH20 = TRIM(COMMON_PATH1)//OUTPUT_NAME20
OUTPUT_PATH21 = TRIM(COMMON_PATH1)//OUTPUT_NAME21

OUTPUT_PATH30 = TRIM(COMMON_PATH1)//OUTPUT_NAME30
OUTPUT_PATH31 = TRIM(COMMON_PATH1)//OUTPUT_NAME31


OUTPUT_PATH40 = TRIM(COMMON_PATH1)//OUTPUT_NAME40
OUTPUT_PATH41 = TRIM(COMMON_PATH1)//OUTPUT_NAME41

OUTPUT_PATH50 = TRIM(COMMON_PATH2)//OUTPUT_NAME50
OUTPUT_PATH51 = TRIM(COMMON_PATH2)//OUTPUT_NAME51


OUTPUT_PATH60 = TRIM(COMMON_PATH4)//OUTPUT_NAME60
OUTPUT_PATH70 = TRIM(COMMON_PATH4)//OUTPUT_NAME70

OUTPUT_PATH80 = TRIM(COMMON_PATH2)//OUTPUT_NAME80
OUTPUT_PATH81 = TRIM(COMMON_PATH2)//OUTPUT_NAME81
OUTPUT_PATH82 = TRIM(COMMON_PATH2)//OUTPUT_NAME82


OUTPUT_PATH85 = TRIM(COMMON_PATH2)//OUTPUT_NAME85
OUTPUT_PATH86 = TRIM(COMMON_PATH2)//OUTPUT_NAME86
OUTPUT_PATH87 = TRIM(COMMON_PATH2)//OUTPUT_NAME87


OUTPUT_PATH90 = TRIM(COMMON_PATH5)//OUTPUT_NAME90


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


      READ(10) B_SCAN_IMAGE66
!       READ(10) B_SCAN_IMAGE6 
            
DO X = 1, DIS
  DO Y = 1, TRA
    DO Z = 1, ROWS3

      B_SCAN_IMAGE6(X,Y,Z) = B_SCAN_IMAGE66(Z,Y,X)

!      PRINT *, X,Y,Z,"<----",Z,X,Y
        
    END DO
  END DO
END DO

PRINT *, "COMPLETED TO READ"    
PRINT *, "GPR TRACK REVERSED IN THE READER PROGRAM"

