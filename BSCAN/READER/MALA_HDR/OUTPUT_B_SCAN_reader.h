    
!========BSCAN_noprocessing==========================
!B_SCAN_IMAGE3(DIS,TRA,ROWS)     
!Y = 1
      DO Z = 1, ROWS
         WRITE(30) (B_SCAN_IMAGE3(X,1,Z), X=1,DIS)    !BINARY
         !WRITE(30,*) (B_SCAN_IMAGE3(X,1,Z), X=1,DIS) !ASCII
      END DO   
PRINT *, "COMPLETE TO PRINT B_SCAN"
PRINT *, "BSCAN_STUCTURE = (X, 1, Z)"
PRINT *, "(",DIS,", 1,",ROWS,")"
!===================================================

