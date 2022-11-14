!=============================PATH===================================
!COMMON_PATH1 = "/home/changwan/GPR_DATA/KOREA/MIHO_ri/40MHz/CSCAN2/"
!COMMON_PATH1 = "/home/changwan/GPR_DATA/KOREA/MIHO_ri/40MHz/CSCAN3/NS/"
COMMON_PATH1 = "/home/changwan/GPR_DATA/KOREA/MIHO_ri/40MHz/CSCAN3/EW/"



INPUT_NAME10 = "3DCUBE_GPR_stacking.raw"

OUTPUT_NAME20= "A_SCOPE_GPR.txt"                     !20
OUTPUT_NAME30= "BSCAN_GPR_stacking.txt"              !30 
OUTPUT_NAME31= "BSCAN_GPR_rmavg.txt"                 !31
OUTPUT_NAME40= "3DCUBE_GPR_stacking.txt"             !40
OUTPUT_NAME50= "HILBERT_3DCUBE_stacking_powerdB.txt" !50


INPUT_PATH = TRIM(COMMON_PATH1)//INPUT_NAME10
OUTPUT_PATH20 = TRIM(COMMON_PATH1)//OUTPUT_NAME20   !20
OUTPUT_PATH30 = TRIM(COMMON_PATH1)//OUTPUT_NAME30   !30
OUTPUT_PATH31 = TRIM(COMMON_PATH1)//OUTPUT_NAME31   !31
OUTPUT_PATH40 = TRIM(COMMON_PATH1)//OUTPUT_NAME40   !40
OUTPUT_PATH50 = TRIM(COMMON_PATH1)//OUTPUT_NAME50   !50


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


      READ(10) STACKED_B_SCAN
             
!+++++REVERSING THE EVEN_GPR TRACKS+++++++++++++++++++++++
!!     IF (MOD(G,2)/=0) THEN
!!         B_SCAN_IMAGE2(:,:,G) = B_SCAN_IMAGE(:,:,G)
!!     ELSE
!!      DO P=1,DIS
!!          B_SCAN_IMAGE2(:,(DIS-P+1),G) = B_SCAN_IMAGE(:,P,G) 
!!      END DO
!!     END IF

DO F = 1, LINE
  DO Y = 1, TRA
    DO Z = 1, ROWS

      STACKED_B_SCAN2(F,Y,Z) = STACKED_B_SCAN(Z,Y,F)

!      PRINT *, X,Y,Z,"<----",Z,X,Y

    END DO
  END DO
END DO

PRINT *, "COMPLETE TO READ"


