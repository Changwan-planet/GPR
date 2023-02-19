 
CALL flip_2d(B_SCAN_IMAGE3, DIS, ROWS,B_SCAN_IMAGE3_FLIP)  

!========BSCAN_noprocessing==========================
!B_SCAN_IMAGE3(DIS,TRA,ROWS)     
!Y = 1
      DO Z = 1, ROWS
         WRITE(30) (B_SCAN_IMAGE3_FLIP(X,1,Z), X=1,DIS)
         WRITE(31,*) (B_SCAN_IMAGE3_FLIP(X,1,Z), X=1,DIS)
      END DO   
PRINT *, "COMPLETE TO PRINT B_SCAN"
PRINT *, "BSCAN_STUCTURE = (X, 1, Z)"
PRINT *, "(",DIS,", 1,",ROWS,")"
!===================================================

