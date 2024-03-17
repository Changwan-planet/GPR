!N = FH1 - 3
!N = 8
!N = 10
N = 15 !MALA
!N = 8 !MALA2

DO G=1,TRA

!=====AUTOMATIC CHANCE CODE FOR OPENING FILE===================

   IF(G<=9.AND.G>=1) THEN

     WRITE(FH1(N+1:N+1), FMT='(I1)') 0
     WRITE(FH1(N+2:N+2), FMT='(I1)') 0
     WRITE(FH1(N+3:N+3), FMT='(I1)') G

!     WRITE(FH2(N+1:N+1), FMT='(I1)') 0
!     WRITE(FH2(N+2:N+2), FMT='(I1)') 0
!     WRITE(FH2(N+3:N+3), FMT='(I1)') G

   
   ELSE IF(G<=99.AND.G>=10) THEN
    
     WRITE(FH1(N+1:N+1), FMT='(I1)') 0
     WRITE(FH1(N+2:N+3), FMT='(I2)') G

!     WRITE(FH2(N+1:N+1), FMT='(I1)') 0
!     WRITE(FH2(N+2:N+3), FMT='(I2)') G
   
   ELSE

     WRITE(FH1(N+1:N+3), FMT='(I3)') G

!     WRITE(FH2(N+1:N+3), FMT='(I3)') G


   END IF

   ITEM_NUMBER=TRIM(FH1//FT)
!   ITEM_NUMBER2=TRIM(FH2//FT2)


!=============================PATH===================================
COMMON_PATH1="/home/csun/GPR_DATA/MOGOD/2020/Channel-1/500/"


ITEM_NUMBER3 = "trace.txt"
!ITEM_NUMBER4 = "Row_cor_dis2.txt"                  
!ITEM_NUMBER5 = "Col_cor_dis2.txt"                  


!OUTPUT_NAME20 = "A_SCOPE_GPR.raw"                !20
OUTPUT_NAME20 = "A_SCOPE_GPR.txt"                !20


!OUTPUT_NAME30 = "BSCAN_GPR_noprocessing.raw"     !30
!OUTPUT_NAME30 = "BSCAN_GPR_noprocessing.txt"     !30


!OUTPUT_NAME40 = "3DCUBE_GPR_noprocessing.raw"    !40 
!OUTPUT_NAME41 = "3D_CSCAN_GPR.txt"                !41 


!OUTPUT_NAME50 = "CSCAN_GNSS.txt"                 !50 
OUTPUT_NAME51 = "3D_CUBE_GPR_zp.txt"                  !51 

!OUTPUT_NAME60 = "Row_cor_dis2.txt"                 !60 
!OUTPUT_NAME61 = "Col_cor_dis2.txt"                 !61 


INPUT_PATH = TRIM(COMMON_PATH1)//ITEM_NUMBER
INPUT_PATH2 = TRIM(COMMON_PATH1)//ITEM_NUMBER2
INPUT_PATH3 = TRIM(COMMON_PATH1)//ITEM_NUMBER3
!INPUT_PATH4 = TRIM(COMMON_PATH2)//ITEM_NUMBER4
!INPUT_PATH5 = TRIM(COMMON_PATH2)//ITEM_NUMBER5


OUTPUT_PATH20 = TRIM(COMMON_PATH1)//OUTPUT_NAME20
OUTPUT_PATH30 = TRIM(COMMON_PATH1)//OUTPUT_NAME30

OUTPUT_PATH40 = TRIM(COMMON_PATH1)//OUTPUT_NAME40
OUTPUT_PATH41 = TRIM(COMMON_PATH1)//OUTPUT_NAME41

!OUTPUT_PATH50 = TRIM(COMMON_PATH1)//OUTPUT_NAME50
OUTPUT_PATH51 = TRIM(COMMON_PATH1)//OUTPUT_NAME51

OUTPUT_PATH60 = TRIM(COMMON_PATH2)//OUTPUT_NAME60
OUTPUT_PATH61 = TRIM(COMMON_PATH2)//OUTPUT_NAME61

!=====================================================================

PRINT*, INPUT_PATH
!======INITIALIZATION=======
!B_SCAN_IMAGE = 0.0
!===========================

OPEN(UNIT=10, FILE=INPUT_PATH,   ACCESS='STREAM',  STATUS='OLD', ACTION='READ')
!OPEN(UNIT=11, FILE=INPUT_PATH2, FORM='FORMATTED', STATUS='OLD', ACTION='READ')
OPEN(UNIT=12, FILE=INPUT_PATH3, FORM='FORMATTED', STATUS='OLD', ACTION='READ')
!OPEN(UNIT=13, FILE=INPUT_PATH4, FORM='FORMATTED', STATUS='OLD', ACTION='READ')
!OPEN(UNIT=14, FILE=INPUT_PATH5, FORM='FORMATTED', STATUS='OLD', ACTION='READ')




!DO NOT USE THE INITIALIZATION IN THIS LOOP!!
!======INITIALIZATION=======
!B_SCAN_IMAGE2 = 0.0
B_SCAN_IMAGE = 0 
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


!     READ(10) HEADER, B_SCAN_IMAGE(:,:,G)   !GSSI-KOREA
 
      READ(12,*) TRACE(G)     

      PRINT *, "TRACE_NUMBER=",TRACE(G)

!      READ(11,*,END = 100) XYZ(:,:,G)            !MOGOD-MALA, MALA
!      100 CLOSE(11) 

!       READ(13,*) ROW_COR_DIS(G)
!      READ(14,*) COL_COR_DIS(G)
 

    
     READ(10, END = 200) B_SCAN_IMAGE(:,:,G-1)    !MOGOD-MALA, MALA
     200 CLOSE(10)

             
      B_SCAN_IMAGE2(:,:,G-1) = B_SCAN_IMAGE(:,:,G-1)


!+++++REVERSING THE EVEN_GPR TRACKS+++++++++++++++++++++++
     IF (MOD(G,2)/=0) THEN
         B_SCAN_IMAGE2(:,:,G-1) = B_SCAN_IMAGE(:,:,G-1)
     ELSE

!        DO P=1,DIS
         DO P =0, TRACE(G)-1
            B_SCAN_IMAGE2(:,(TRACE(G)-P+1),G-1) = B_SCAN_IMAGE(:,P,G-1) 
         END DO      

     END IF

      PRINT *, "G=",G    

DO X = 0, DIS-1
  DO Y = 0, TRA-1
    DO Z = 0, ROWS-1

      B_SCAN_IMAGE3(X,Y,Z) = B_SCAN_IMAGE2(Z,X,Y)

!      PRINT *, X,Y,Z,"<----",Z,X,Y

    END DO
  END DO
END DO


END DO






