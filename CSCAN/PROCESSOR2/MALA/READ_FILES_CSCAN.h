
!=============================PATH===================================
!MIHO_ri
!COMMON_PATH1="/home/changwan/GPR_DATA/KOREA/MIHO_ri/2022_BOMIN/Edit_data/Miho11/STACK_CUBE/"
COMMON_PATH1="/home/changwan/GPR_DATA/KOREA/MIHO_ri/2022_BOMIN/Edit_data/Miho21/P_CUBE/"


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


!INPUT_NAME10 = "3D_CUBE_GPR_EDIT_zpt.txt"             !10
INPUT_NAME10 = "3D_CUBE_GPR_H_zpt.txt"             !10


!INPUT_NAME10 = "3D_CUBE_GPR_noflip.txt"             !10


OUTPUT_NAME20 = "3D_A_STACK_GPR.txt"              !20
OUTPUT_NAME21 = "B4EDIT_A_SCOPE_GPR.txt"          !21

OUTPUT_NAME30 = "3D_B_STACK_GPR.txt"                !30
!OUTPUT_NAME31 = "3D_BSCAN_GPR_GC.txt"            !31

OUTPUT_NAME40 = "3D_C_STACK_GPR.txt"                !40 

OUTPUT_NAME50 = "3D_STACK_GPR_zp.txt"              !50 
OUTPUT_NAME51 = "3D_STACK_GPR_zpgc.txt"              !51 


!OUTPUT_NAME51 = "3D_CUBE_GPR_rmavrg.txt"         !41 


!OUTPUT_NAME50 = "3D_FFT.txt"                     !50
OUTPUT_NAME60 = "2D_HILBERT_powerdB.txt"         !60
OUTPUT_NAME61 = "CSCAN_HILBERT_powerdB.txt"         !60
OUTPUT_NAME62 = "3D_HILBERT_powerdB.txt"         !60


!OUTPUT_NAME70 = "3D_GPR_phase.txt"               !70
!OUTPUT_NAME80 = "3D_TW_BPF.txt"                  !80
!OUTPUT_NAME81 = "3D_BPF_GC.txt"                  !81
!OUTPUT_NAME81 = "3D_BPF.txt"                     !81


!OUTPUT_NAME90 = "HORIZON_PICK.txt"               !90


INPUT_PATH =  TRIM(COMMON_PATH1)//INPUT_NAME10
INPUT_PATH1 = TRIM(COMMON_PATH1)//INPUT_NAME11


OUTPUT_PATH20 = TRIM(COMMON_PATH1)//OUTPUT_NAME20
OUTPUT_PATH21 = TRIM(COMMON_PATH1)//OUTPUT_NAME21

OUTPUT_PATH30 = TRIM(COMMON_PATH1)//OUTPUT_NAME30
!OUTPUT_PATH31 = TRIM(COMMON_PATH1)//OUTPUT_NAME31

OUTPUT_PATH40 = TRIM(COMMON_PATH1)//OUTPUT_NAME40

OUTPUT_PATH50 = TRIM(COMMON_PATH1)//OUTPUT_NAME50
OUTPUT_PATH51 = TRIM(COMMON_PATH1)//OUTPUT_NAME51


OUTPUT_PATH60 = TRIM(COMMON_PATH4)//OUTPUT_NAME60
OUTPUT_PATH61 = TRIM(COMMON_PATH4)//OUTPUT_NAME61
OUTPUT_PATH62 = TRIM(COMMON_PATH4)//OUTPUT_NAME62


!OUTPUT_PATH70 = TRIM(COMMON_PATH4)//OUTPUT_NAME70

!OUTPUT_PATH80 = TRIM(COMMON_PATH2)//OUTPUT_NAME80
!OUTPUT_PATH81 = TRIM(COMMON_PATH2)//OUTPUT_NAME81

!OUTPUT_PATH90 = TRIM(COMMON_PATH5)//OUTPUT_NAME90


!=====================================================================

PRINT*, INPUT_PATH
!PRINT*, OUTPUT_PATH20

OPEN(UNIT=10, FILE=INPUT_PATH , FORM="FORMATTED", STATUS='OLD', ACTION='READ')
!OPEN(UNIT=11, FILE=INPUT_PATH1, FORM="FORMATTED", STATUS='OLD', ACTION='READ')


!OPEN(UNIT=10, FILE=INPUT_PATH,   ACCESS='STREAM',  STATUS='OLD', ACTION='READ')
!OPEN(UNIT=11, FILE=INPUT_PATH1,   ACCESS='STREAM',  STATUS='OLD', ACTION='READ')



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


DO R = 1, (DIS2+1) * (TRA2+1) * ROWS
   READ(10, *) XX, YY, ZZ, B_SCAN_IMAGE(XX,YY,ZZ)
END DO             

PRINT *, "COMPLETED TO READ GPR 3D_CUBE_GPR_EDIT"    

