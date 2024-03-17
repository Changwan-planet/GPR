    
!====BSCAN=================================   
J = 15
       
      DO Z = 0, ROWS2-1
!      DO J = 0, TRA2
      DO I = 0, DIS2

!          WRITE(30,*) I, J, Z, B_SCAN_IMAGE(I,J,Z)
          WRITE(30,*) I, J, Z, HILBERT_B_SCAN(I,J,Z)


      END DO  
!      END DO 
      END DO

!===================================================


!====BSCAN=================================   
Y = 1
!     DO X = 1, DIS
!         WRITE(30,*) (HILBERT_B_SCAN(X,Y,Z), X=1,DIS)
!         WRITE(30,*) (B_SCAN_IMAGE2(X,Y,Z), Z=1,ROWS)
     
!      END DO  
!===================================================




!====BSCAN_afzp=================================   
!Y = TRA
      !DO Z = 1, ROWS3
      !   WRITE(30,*) (B_SCAN_IMAGE(X,1,Z), X=1,DIS)
      !END DO  
!===================================================


!=====BSCAN_GC======================================
!B_SCAN_IMAGE6(DIS,TRA,ROWS)    

      !DO Z = 1, ROWS4
      !DO X = 1, DIS 
      ! B_SCAN_IMAGE6_GC(X,1,Z) = B_SCAN_IMAGE(X,1,Z) / SQRT(HILBERT_power2(X,1,Z))  
      ! B_SCAN_IMAGE6_GC(X,1,Z) = B_SCAN_IMAGE(X,1,Z) / HILBERT_power2(X,1,Z)  
      !END DO
      !END DO

      !DO Z = 1, ROWS4
      !   WRITE(31,*) (B_SCAN_IMAGE_GC(X,1,Z), X = 1, DIS)
      !END DO  
!===================================================


PRINT  *, "COMPELETE TO PRINT B_SCAN"
