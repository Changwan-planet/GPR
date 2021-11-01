!=======A-SCOPE===============================
X=1
Y=1
      DO Z = 1, ROWS
         WRITE(20,*) B_SCAN_IMAGE3(X,Y,Z) 
      END DO
   
!============================================= 
     
!======B_SCAN=======================================
!B_SCAN_IMAGE3(DIS,TRA,ROWS)     
Y = TRA

      DO Z = 1, ROWS
         WRITE(21,*) (B_SCAN_IMAGE3(X,Y,Z), X=1,DIS) 
      END DO
!===================================================



!=====3D_CUBE_IMAGE============================
!J=ROWS 
!DECIBEL
      DO X = 1, DIS
         DO Y = 1, TRA
            DO Z = 1, ROWS
               B_SCAN_IMAGE3(X,Y,Z) = 10 * log10(B_SCAN_IMAGE3(X,Y,Z)**2)
            END DO
         END DO
      END DO

      DO X = 1, DIS
         DO Y = 1, TRA 
            WRITE (23,*) (B_SCAN_IMAGE3(X,Y,Z), Z = 1, ROWS)
         END DO 
      END DO

!==>  THIS STRUCTURE (X x Y) X Z CAN BE PRINTED. 
!==>  (X x Y) IS THE C_SCAN.
!     PRINT *, "COMPLETE 3D_CUBE_IMAGE OUPUT"
!=============================================

PRINT *, char(7)


