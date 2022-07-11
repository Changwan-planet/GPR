!========BSCAN_noprocessing==========================
!B_SCAN_IMAGE3(DIS,TRA,ROWS)     

      DO Z = 1, ROWS
         WRITE(30,*) (B_SCAN_IMAGE3(X,1,Z), X = 1, DIS)
      END DO   
!===================================================


!=====BSCAN_rmbgr===================================
!B_SCAN_IMAGE3(DIS,TRA,ROWS)    

      DO Z = 1, ROWS2
      DO X = 1, DIS
      ! B_SCAN_IMAGE4_GC(X,1,Z) = B_SCAN_IMAGE4(X,1,Z) / SQRT(HILBERT_power2(X,1,Z))  
       B_SCAN_IMAGE4_GC(X,1,Z) = B_SCAN_IMAGE4(X,1,Z) / HILBERT_power2(X,1,Z)  
      END DO
      END DO

      DO Z = 1, ROWS2
         WRITE(31,*) (B_SCAN_IMAGE4_GC(X,1,Z), X = 1, DIS)
      END DO
 
      DO Z = 1, ROWS
         WRITE(33,*) (B_SCAN_IMAGE4(X,1,Z), X = 1, DIS)
      END DO
     
!===================================================

!====BSCAN_remove_average=================================   
      DO Z = 1, ROWS2
      DO X = 1, DIS
       !B_SCAN_IMAGE5_GC(X,1,Z) = B_SCAN_IMAGE5(X,1,Z) / SQRT(HILBERT_power2(X,1,Z))  
       B_SCAN_IMAGE5_GC(X,1,Z) = B_SCAN_IMAGE5(X,1,Z) / HILBERT_power2(X,1,Z)  
      END DO
      END DO

      DO Z = 1, ROWS2 
         WRITE(32,*) (B_SCAN_IMAGE5_GC(X,1,Z), X= 1, DIS)     
      END DO
!=========================================================
