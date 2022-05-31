    
!========BSCAN_noprocessing==========================
!B_SCAN_IMAGE3(DIS,TRA,ROWS)     
Y = TRA

      DO Z = 1, ROWS
         WRITE(30,*) (B_SCAN_IMAGE3(X,1,Z), X=1,DIS)
      END DO   
!===================================================


!=====BSCAN_rmbgr===================================
!B_SCAN_IMAGE3(DIS,TRA,ROWS)    
Y = TRA

      DO Z = 1, ROWS
         WRITE(31,*) (B_SCAN_IMAGE4(X,1,Z), X=1,DIS)
      END DO     
!===================================================

!====BSCAN_remove_average=================================   
!===================================================


PRINT  *, "COMPLETE TO PRINT B_SCAN"
