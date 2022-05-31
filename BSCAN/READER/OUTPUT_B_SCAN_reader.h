    
!========BSCAN_noprocessing==========================
!B_SCAN_IMAGE3(DIS,TRA,ROWS)     
!Y = 1
      DO Z = 1, ROWS
         WRITE(30) (B_SCAN_IMAGE3(1,Y,Z), Y=1,TRA)
      END DO   
PRINT *, "COMPLETE TO PRINT B_SCAN"
!===================================================

