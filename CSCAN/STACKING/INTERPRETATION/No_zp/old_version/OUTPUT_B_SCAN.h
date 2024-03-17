!YY = 21
    
!====BSCAN-power================================   
!Y = TRA
      DO Z = 1, ROWS
         WRITE(60,*) (B_SCAN_IMAGE6F(X,YY,Z), X=1,DIS)
      END DO  
!===================================================

!====BSCAN-Amp================================   
!Y = TRA
      DO Z = 1, ROWS
         WRITE(61,*) (B_SCAN_IMAGE7F(X,YY,Z), X=1,DIS)
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
