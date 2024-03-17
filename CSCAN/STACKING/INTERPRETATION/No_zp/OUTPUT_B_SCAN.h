    
!====AMP=================================   
!Y = TRA
!Y = 1

!      DO Z = 1, ROWS2    
!      DO X = 1, DIS     
!         WRITE(30,*) X, Y, Z, B_SCAN_IMAGE_GC(X,Y,Z)
!         WRITE(30,*) X, Y, Z, B_SCAN_IMAGE(X,Y,Z)
!      END DO  
!      END DO 

      DO Z = 1, ROWS     
         WRITE(30,*) ( B_SCAN_IMAGE(X,Y,Z), X = 1, DIS)
      END DO  


!===================================================
 
!====HILBERT=================================   
!Y = TRA
!Y = 21

!      DO Z = 1, ROWS    
!      DO X = 1, DIS     

!       WRITE(31,*) X, Y, Z, HILBERT_powerdB(X,Y,Z)
!        WRITE(31,*) X, Y, Z, B_SCAN_IMAGE(X,Y,Z)

!      END DO  
!      END DO 

      DO Z = 1, ROWS     
         WRITE(31,*) (HILBERT_powerdB(X,Y,Z), X = 1, DIS)
      END DO  


!===================================================


!=====BSCAN_GC======================================
!B_SCAN_IMAGE6(DIS,TRA,ROWS)    

!      DO Z = 1, ROWS4
!      DO X = 1, DIS 
      ! B_SCAN_IMAGE6_GC(X,1,Z) = B_SCAN_IMAGE6(X,1,Z) / SQRT(HILBERT_power2(X,1,Z))  
!       B_SCAN_IMAGE6_GC(X,1,Z) = B_SCAN_IMAGE6(X,1,Z) / HILBERT_power2(X,1,Z)  
!      END DO
!      END DO

!      DO Z = 1, ROWS4
!         WRITE(31,*) (B_SCAN_IMAGE6_GC(X,1,Z), X = 1, DIS)
!      END DO  
!===================================================


PRINT  *, "COMPLETE TO PRINT B_SCAN"
