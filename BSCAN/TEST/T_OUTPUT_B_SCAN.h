    
!======B_SCAN=======================================
!B_SCAN_IMAGE3(DIS,TRA,ROWS)     
!Y = TRA

      DO Z = 1, ROWS
         WRITE(21,*) (B_SCAN_IMAGE4(X,Y,Z), X=1,DIS)
         !WRITE(21,*) (STACKED_B_SCAN(1,Y,Z), Y=1,TRA)
      END DO
!===================================================


