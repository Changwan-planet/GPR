    
!========BSCAN_noprocessing==========================
     ! DO Z = 1, ROWS
      DO Z = 1, 313
        WRITE(30) (B_SCAN_IMAGE3(X,1,Z), X=1,DIS)
     !!    WRITE(30,*) (B_SCAN_IMAGE3(X,1,Z), X=1,100)
      END DO   
!===================================================

