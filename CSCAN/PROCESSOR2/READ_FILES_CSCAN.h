!=============================PATH===================================
!COMMON_PATH1="/home/changwan/GPR_DATA/KOREA/SPALAND/"
!COMMON_PATH1="/home/changwan/GPR_DATA/KOREA/MIHO_ri/CSCAN3/220526_1.PRJ/"
COMMON_PATH1="/home/changwan/GPR_DATA/MOGOD/2021/F1/500MHz/"


INPUT_NAME10 = "3D_HILBERT_CUBE_powerdB.txt"       !10

OUTPUT_NAME20 = "3D_A_SCOPE_GPR.txt"               !20
OUTPUT_NAME30 = "3D_HdB_GPR_noprocessing.txt"      !30
!OUTPUT_NAME31 = "3D_BSCAN_GPR_rmbgr.txt"          !31
OUTPUT_NAME40 = "3D_CUBE_GPR.txt"                  !40 
OUTPUT_NAME50 = "3D_HdB_RM_mvmean.txt"            !50


INPUT_PATH = TRIM(COMMON_PATH1)//INPUT_NAME10
OUTPUT_PATH20 = TRIM(COMMON_PATH1)//OUTPUT_NAME20
OUTPUT_PATH30 = TRIM(COMMON_PATH1)//OUTPUT_NAME30
!OUTPUT_PATH31 = TRIM(COMMON_PATH1)//OUTPUT_NAME31
OUTPUT_PATH40 = TRIM(COMMON_PATH1)//OUTPUT_NAME40
OUTPUT_PATH50 = TRIM(COMMON_PATH1)//OUTPUT_NAME50
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


      READ(10) HdB
             
!+++++REVERSING THE EVEN_GPR TRACKS+++++++++++++++++++++++
!!     IF (MOD(G,2)/=0) THEN
!!         B_SCAN_IMAGE2(:,:,G) = B_SCAN_IMAGE(:,:,G)
!!     ELSE
!!      DO P=1,DIS
!!          B_SCAN_IMAGE2(:,(DIS-P+1),G) = B_SCAN_IMAGE(:,P,G) 
!!      END DO
!!     END IF
  

DO X = 1, DIS
  DO Y = 1, TRA
    DO Z = 1, ROWS

       HdB2(X,Y,Z) = HdB(Z,Y,X)

!      PRINT *, X,Y,Z,"<----",Z,X,Y
        
    END DO
  END DO
END DO

PRINT *, "COMPLETE TO READ"    


