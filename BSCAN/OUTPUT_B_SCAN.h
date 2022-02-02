    
!======B_SCAN=======================================
!B_SCAN_IMAGE3(DIS,TRA,ROWS)     
!Y = TRA

      DO Z = 1, ROWS
         WRITE(21,*) (B_SCAN_IMAGE3(X,Y,Z), X=1,DIS) 
      END DO
!===================================================


