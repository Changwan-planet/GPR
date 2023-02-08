!=======A-SCOPE===============================
X=1
Y=1
!!      DO Z = 1, ROWS
!!         WRITE(20,*) B_SCAN_IMAGE3(X,Y,Z) 
!!      END DO
   
!============================================= 
     
!======B_SCAN=======================================
!B_SCAN_IMAGE3(DIS,TRA,ROWS)     
!Y = TRA

!!      DO Z = 1, ROWS
!!         WRITE(21,*) (B_SCAN_IMAGE3(X,Y,Z), X=1,DIS) 
!!      END DO
!===================================================


!DECIBEL
!DO X = 1, DIS
!   DO Y = 1, TRA
!      DO Z = 1, ROWS
!         HILBERT_B_SCAN(X,Y,Z) = HILBERT_B_SCAN(X,Y,Z)**2
!         HILBERT_B_SCAN(X,Y,Z) = 10 * log10(HILBERT_B_SCAN(X,Y,Z)**2)
!      END DO
!    END DO
!END DO



!======B_SCAN=======================================
!B_SCAN_IMAGE3(DIS,TRA,ROWS)     
Y = 1

      DO Z = 1, ROWS
         WRITE(21,*) (HILBERT_B_SCAN(X,Y,Z), X=1,DIS) 
      END DO
!===================================================



