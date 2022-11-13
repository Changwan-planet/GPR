
!N = FH2 - 3
N = 10 
!N = 8 

DO F = 1, LINE
!DO F = 1, 2


PRINT *, ""
PRINT *, "F=",F


!====AUTOMATIC CHANGE CODE FOR OPENING FOLDER====
COMMON_PATH1 = "/home/changwan/GPR_DATA/KOREA/MIHO_ri/40MHz/CSCAN3/EW/"

!PRINT *, LEN(TRIM(COMMON_PATH1)

!NN = LEN(TRIM(COMMON_PATH1))
NN = 7

!WRITE(COMMON_PATH1(NN+1:NN+1),FMT='(I1)') F 

IF(F<=9.AND.F>=1) THEN

   WRITE(FH1(NN+1:NN+1), FMT='(I1)') F
ELSE IF(F<=99.AND.F>=10) THEN

   WRITE(FH3(NN+1:NN+2), FMT='(I1)') F
END IF

!PRINT *, "FH1=", FH1
FH2 = TRIM(FH1)//FT
!PRINT *, "FH2=", FH2

!PRINT *, "COMMON_PATH1=",COMMON_PATH1
!PRINT *, LEN(TRIM(COMMON_PATH1))

TAIL_PATH = ".PRJ/"

COMMON_PATH2 = TRIM(COMMON_PATH1)//FH1//TAIL_PATH
!PRINT *, COMMON_PATH2


DO G = 1, TRA
!=====AUTOMATIC CHANCE CODE FOR OPENING FILENAME====

   IF(G<=9.AND.G>=1) THEN

     WRITE(FH2(N+1:N+1), FMT='(I1)') 0
     WRITE(FH2(N+2:N+2), FMT='(I1)') 0
     WRITE(FH2(N+3:N+3), FMT='(I1)') G
   
   ELSE IF(G<=99.AND.G>=10) THEN
    
     WRITE(FH2(N+1:N+1), FMT='(I1)') 0
     WRITE(FH2(N+2:N+3), FMT='(I2)') G
   
   ELSE

     WRITE(FH2(N+1:N+3), FMT='(I3)') G
   END IF

   ITEM_NUMBER=TRIM(FH2//FT2)

!   PRINT *, ITEM_NUMBER
!=============================PATH===================================
OUTPUT_NAME20= "A_SCOPE_GPR.raw"                     !20
OUTPUT_NAME30= "BSCAN_GPR_stacking.raw"              !30
OUTPUT_NAME40= "3DCUBE_GPR_stacking.raw"             !40

INPUT_PATH = TRIM(COMMON_PATH2)//ITEM_NUMBER
OUTPUT_PATH20 = TRIM(COMMON_PATH1)//OUTPUT_NAME20   !20
OUTPUT_PATH30 = TRIM(COMMON_PATH1)//OUTPUT_NAME30   !30
OUTPUT_PATH40 = TRIM(COMMON_PATH1)//OUTPUT_NAME40   !40

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


      READ(10) HEADER, B_SCAN_IMAGE(:,:,G)
             
      B_SCAN_IMAGE2(:,:,G) = B_SCAN_IMAGE(:,:,G)

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

      B_SCAN_IMAGE3(X,Y,Z) = B_SCAN_IMAGE2(Z,X,Y)

!      PRINT *, X,Y,Z,"<----",Z,X,Y

    END DO
  END DO
END DO
 
CLOSE(10)

END DO


