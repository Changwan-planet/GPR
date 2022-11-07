    
!========BSCAN_noprocessing==========================
!B_SCAN_IMAGE3(DIS,TRA,ROWS)     
Y = TRA

      DO Z = 1, ROWS
         WRITE(30,*) (HdB2(X,1,Z), X=1,DIS)
      END DO   
!===================================================


PRINT  *, "COMPLETE TO PRINT B_SCAN"
