    
!====BSCAN=================================   
Y = 6
      DO Z = 1, ROWS
         WRITE(30,*) (HILBERT_B_SCAN(X,Y,Z), X=1,TRA)
!          WRITE(30,*) (B_SCAN_IMAGE8(X,Y,Z), X=1,TRA)
      
      END DO  
!===================================================

!====BSCAN_afzp=================================   
!Y = TRA
      !DO Z = 1, ROWS3
      !   WRITE(30,*) (B_SCAN_IMAGE6(X,1,Z), X=1,DIS)
      !END DO  
!===================================================


!=====BSCAN_GC======================================
!B_SCAN_IMAGE6(DIS,TRA,ROWS)    

      !DO Z = 1, ROWS4
      !DO X = 1, DIS 
      ! B_SCAN_IMAGE6_GC(X,1,Z) = B_SCAN_IMAGE6(X,1,Z) / SQRT(HILBERT_power2(X,1,Z))  
      ! B_SCAN_IMAGE6_GC(X,1,Z) = B_SCAN_IMAGE6(X,1,Z) / HILBERT_power2(X,1,Z)  
      !END DO
      !END DO

      !DO Z = 1, ROWS4
      !   WRITE(31,*) (B_SCAN_IMAGE6_GC(X,1,Z), X = 1, DIS)
      !END DO  
!===================================================


PRINT  *, "COMPLETE TO PRINT B_SCAN"
