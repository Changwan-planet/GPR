
!=============================PATH===================================
!COMMON_PATH1="/home/changwan/GPR_DATA/KOREA/SPALAND/"
!COMMON_PATH1="/home/changwan/GPR_DATA/KOREA/MIHO_ri/CSCAN3/220526_1.PRJ/"
!COMMON_PATH1="/home/changwan/GPR_DATA/MOGOD/2021/F1/500MHz/"
!COMMON_PATH1="/home/changwan/GPR_DATA/MOGOD/2020/Channel-1/500/"

!NS
COMMON_PATH1 = "/home/changwan/GPR_DATA/KOREA/MIHO_ri/3D_trench/40MHz/CSCAN3/NS/attribute/"
COMMON_PATH2 = "/home/changwan/GPR_DATA/KOREA/MIHO_ri/3D_trench/40MHz/CSCAN3/NS/horizon/"
COMMON_PATH3 = "/home/changwan/GPR_DATA/KOREA/MIHO_ri/3D_trench/40MHz/CSCAN3/NS/"


!EW
!COMMON_PATH1 = "/home/changwan/GPR_DATA/KOREA/MIHO_ri/3D_trench/40MHz/CSCAN3/EW/attribute/"
!COMMON_PATH2 = "/home/changwan/GPR_DATA/KOREA/MIHO_ri/3D_trench/40MHz/CSCAN3/EW/horizon/"
!COMMON_PATH3 = "/home/changwan/GPR_DATA/KOREA/MIHO_ri/3D_trench/40MHz/CSCAN3/EW/"

!SUM
COMMON_PATH4 = "/home/changwan/GPR_DATA/KOREA/MIHO_ri/3D_trench/40MHz/CSCAN3/SUM/"



INPUT_NAME10 = "3D_HILBERT_powerdB.txt"            !10
INPUT_NAME11 = "3D_CUBE_GPR.txt"                   !11
!INPUT_NAME12 = "HORIZON_PICK_AMPSUM.txt"           !12 


OUTPUT_NAME20 = "TOTAL_SUM_ASCAN.txt"              !20

!OUTPUT_NAME50 = "3D_FFT.txt"                       !50

OUTPUT_NAME60 = "2D_HILBERT_powerdB.txt"           !60
OUTPUT_NAME61 = "2D_GPR_amp.txt"                   !61


!OUTPUT_NAME70 = "3D_GPR_phase.txt"                 !70

OUTPUT_NAME90 = "HORIZON_PICK.txt"                 !90
OUTPUT_NAME91 = "MSR_PICK.txt"                     !91
OUTPUT_NAME92 = "HORIZON_PICK_SHOULDER.txt"        !92



INPUT_PATH10 = TRIM(COMMON_PATH1)//INPUT_NAME10
INPUT_PATH11 = TRIM(COMMON_PATH3)//INPUT_NAME11
!INPUT_PATH12 = TRIM(COMMON_PATH4)//INPUT_NAME12


!INPUT_PATH14 = TRIM(COMMON_PATH1)//INPUT_NAME14
!INPUT_PATH15 = TRIM(COMMON_PATH1)//INPUT_NAME15
!INPUT_PATH16 = TRIM(COMMON_PATH1)//INPUT_NAME16


OUTPUT_PATH20 = TRIM(COMMON_PATH3)//OUTPUT_NAME20
!OUTPUT_PATH21 = TRIM(COMMON_PATH1)//OUTPUT_NAME21
!OUTPUT_PATH30 = TRIM(COMMON_PATH1)//OUTPUT_NAME30
!OUTPUT_PATH31 = TRIM(COMMON_PATH1)//OUTPUT_NAME31
!OUTPUT_PATH40 = TRIM(COMMON_PATH1)//OUTPUT_NAME40
!OUTPUT_PATH41 = TRIM(COMMON_PATH1)//OUTPUT_NAME41
!OUTPUT_PATH50 = TRIM(COMMON_PATH1)//OUTPUT_NAME50
OUTPUT_PATH60 = TRIM(COMMON_PATH2)//OUTPUT_NAME60
OUTPUT_PATH61 = TRIM(COMMON_PATH2)//OUTPUT_NAME61


!OUTPUT_PATH70 = TRIM(COMMON_PATH1)//OUTPUT_NAME70
!OUTPUT_PATH80 = TRIM(COMMON_PATH1)//OUTPUT_NAME80
!OUTPUT_PATH81 = TRIM(COMMON_PATH1)//OUTPUT_NAME81

OUTPUT_PATH90 = TRIM(COMMON_PATH2)//OUTPUT_NAME90
OUTPUT_PATH91 = TRIM(COMMON_PATH2)//OUTPUT_NAME91
OUTPUT_PATH92 = TRIM(COMMON_PATH2)//OUTPUT_NAME92




!=====================================================================
PRINT*, "INPUT FILE"
PRINT*, INPUT_PATH10
PRINT*, INPUT_PATH11
!PRINT*, INPUT_PATH12

!PRINT*, INPUT_PATH13
!PRINT*, INPUT_PATH14
!PRINT*, INPUT_PATH15
!PRINT*, INPUT_PATH16

OPEN(UNIT=10, FILE=INPUT_PATH10,  FORM ="FORMATTED",  STATUS='OLD', ACTION='READ')
!OPEN(UNIT=10, FILE=INPUT_PATH10,   ACCESS='STREAM',  STATUS='OLD', ACTION='READ')

OPEN(UNIT=11, FILE=INPUT_PATH11,  FORM ="FORMATTED",  STATUS='OLD', ACTION='READ')

!OPEN(UNIT=12, FILE=INPUT_PATH12,  FORM = "FORMATTED",STATUS='OLD', ACTION='READ')



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


      READ(10,*) B_SCAN_IMAGE66
      READ(11,*) B_SCAN_IMAGE77
!      READ(12,*) HORIZON_AS



!      READ(10) B_SCAN_IMAGE66
!       READ(10) B_SCAN_IMAGE6 
            
DO X = 1, DIS
  DO Y = 1, TRA
    DO Z = 1, ROWS

      B_SCAN_IMAGE6(X,Y,Z) = B_SCAN_IMAGE66(Z,Y,X)
      B_SCAN_IMAGE7(X,Y,Z) = B_SCAN_IMAGE77(Z,Y,X)

!      PRINT *, X,Y,Z,"<----",Z,X,Y
        
    END DO
  END DO
END DO

!B_SCAN_IMAGE6F = B_SCAN_IMAGE6
!B_SCAN_IMAGE7F = B_SCAN_IMAGE7


CALL  flip_3d(B_SCAN_IMAGE6, DIS, TRA, ROWS, B_SCAN_IMAGE6F)
CALL  flip_3d(B_SCAN_IMAGE7, DIS, TRA, ROWS, B_SCAN_IMAGE7F)


PRINT *, "COMPLETED TO READ"    
PRINT *, "GPR TRACK REVERSED IN THE READER PROGRAM"

