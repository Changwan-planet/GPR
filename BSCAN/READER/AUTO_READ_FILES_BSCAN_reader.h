!=============================PATH===================================
CALL getcwd(CWD)
!PRINT *, TRIM(CWD)
!COMMON_PATH1= "/home/changwan/GPR_DATA/KOREA/MIHO_ri/CSCAN3/220536_1.PRJ/"
!COMMON_PATH1= "/home/changwan/GPR_DATA/KOREA/MIHO_ri/220519_7.PRJ/"
!COMMON_PATH1= "/home/changwan/GPR_DATA/KOREA/MIHO_ri/220526_2.PRJ/"
!COMMON_PATH1= "/home/changwan/GPR_DATA/KOREA/INBO_ri/220223_5.PRJ/"
!COMMON_PATH1= "/home/changwan/GPR_DATA/KOREA/GYODONG_ri/20211022/"
!COMMON_PATH1= "/home/changwan/GPR_DATA/KOREA/GYODONG_ri/211029/"
!COMMON_PATH1= "/home/changwan/GPR_DATA/MOGOD/2022/Site-1/RTA50/"
!COMMON_PATH1= "/home/changwan/GPR_DATA/MOGOD/2020/Pr-1/250MHz/"
!COMMON_PATH1= "/home/changwan/GPR_DATA/MOGOD/2020/Site-1/RTA50/"
!


COMMON_PATH1 = "/home/changwan/GPR_DATA"
!PRINT *, "COMMON_PATH=",COMMON_PATH1

PRINT *, "ENTER THE PATH OF THE FILE THAT YOU WANT TO READ." 
PRINT *, "INCLUDE DOUBLE QUOTATION MARKS AND SLASH ( / )  "
PRINT *, "YOUR PAHT WILL BE CONNECTED WITH BELOW" 
PRINT *, "COMMON_PATH1=",COMMON_PATH1

READ *, COMMON_PATH2

COMMON_PATH3 = TRIM(COMMON_PATH1)//TRIM(COMMON_PATH2)

!PRINT *, "COMMON_PATH1=",COMMON_PATH1
!PRINT *, "COMMON_PATH2=",COMMON_PATH2
PRINT *, "COMMON_PATH3=",COMMON_PATH3
PRINT *, ""
!=============================================================


!===================FILE_HEAD=================================
PRINT *, "ENTER THE FILE_HEAD THAT YOU WANT TO READ." 
PRINT *, "PLEASE CHANGE THE VALUE OF N IF YOU USE A NEW FH1"
PRINT *, "e.g.) 220526_1__"
PRINT *, "e.g.) f1-250-profile-"

READ *, FH1
PRINT *, "FH1=",FH1
PRINT *, ""

!N = FH1 - 3
!GSSI
N = 10

!MALA
!N = 15

!!DO G=1,TRA

!==================FILE_NUMBER================================
PRINT *, "ENTER THE FILE_NUMBER THAT YOU WANT TO READ." 
PRINT *, "e.g.) 1, not 001"
READ *, G
PRINT *, "G=",G
PRINT *,  ""

!=====AUTOMATIC CHANCE CODE FOR OPENING FILE===================

   IF(G<=9.AND.G>=1) THEN

     WRITE(FH1(N+1:N+1), FMT='(I1)') 0
     WRITE(FH1(N+2:N+2), FMT='(I1)') 0
     WRITE(FH1(N+3:N+3), FMT='(I1)') G
   
   ELSE IF(G<=99.AND.G>=10) THEN
    
     WRITE(FH1(N+1:N+1), FMT='(I1)') 0
     WRITE(FH1(N+2:N+3), FMT='(I2)') G
   
   ELSE

     WRITE(FH1(N+1:N+3), FMT='(I3)') G
   END IF

   ITEM_NUMBER=TRIM(FH1//FT)

!============================================================

OUTPUT_NAME20 = "A_SCOPE_GPR.raw"                !20
OUTPUT_NAME30 = "BSCAN_GPR_noprocessing.raw"     !30
OUTPUT_NAME31 = "BSCAN_GPR_noprocessing.txt"     !31


!OUTPUT_NAME40 = "3DCUBE_GPR_noprocessing.raw"    !40


INPUT_PATH = TRIM(COMMON_PATH3)//ITEM_NUMBER
OUTPUT_PATH20 = TRIM(COMMON_PATH3)//OUTPUT_NAME20
OUTPUT_PATH30 = TRIM(COMMON_PATH3)//OUTPUT_NAME30
OUTPUT_PATH31 = TRIM(COMMON_PATH3)//OUTPUT_NAME31


!OUTPUT_PATH40 = TRIM(COMMON_PATH3)//OUTPUT_NAME40
!=====================================================================

PRINT*, "FH1=",FH1
PRINT*, "ITEM_NUBMER=", ITEM_NUMBER
PRINT*, "INPUT_PAHT=",INPUT_PATH

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



!     READ(10)  B_SCAN_IMAGE(:,:,1)    !MONGOLIA
 
      READ(10) HEADER, B_SCAN_IMAGE(:,:,1)  !KOREA

             
      B_SCAN_IMAGE2(:,:,1) = B_SCAN_IMAGE(:,:,1)

!+++++REVERSING THE EVEN_GPR TRACKS+++++++++++++++++++++++
!     IF (MOD(G,2)/=0) THEN
!         B_SCAN_IMAGE2(:,:,G) = B_SCAN_IMAGE(:,:,G)
!     ELSE
!      DO P=1,DIS
!          B_SCAN_IMAGE2(:,(DIS-P+1),G) = B_SCAN_IMAGE(:,P,G) 
!      END DO
!     END IF
!     PRINT *, "G=",G    

DO X = 1, DIS
  DO Y = 1, TRA
    DO Z = 1, ROWS

      B_SCAN_IMAGE3(X,Y,Z) = B_SCAN_IMAGE2(Z,X,Y)

!      PRINT *, X,Y,Z,"<----",Z,X,Y

    END DO
  END DO
END DO
 
!!CLOSE(10)

!!END DO


