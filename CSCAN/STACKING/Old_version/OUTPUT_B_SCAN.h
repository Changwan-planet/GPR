    
!========BSCAN_noprocessing==========================
!B_SCAN_IMAGE3(DIS,TRA,ROWS)     
Y = TRA

      DO Z = 1, ROWS
         WRITE(30,*) (B_SCAN_IMAGE3(X,Y,Z), X=1,DIS)
      END DO   
!===================================================


!=====BSCAN_rmbgr===================================
!B_SCAN_IMAGE3(DIS,TRA,ROWS)    
Y = TRA

      DO Z = 1, ROWS
         WRITE(31,*) (B_SCAN_IMAGE4(X,Y,Z), X=1,DIS)
      END DO     
!===================================================


!====BSCAN_stacking=================================   
      DO Z = 1, ROWS
         WRITE(32,*) (STACKED_B_SCAN(1,Y,Z), Y=TRA,1,-1)     
         !WRITE(32,*) (STACKED_B_SCAN(1,Y,Z), Y=1,TRA)     
      END DO
!===================================================

!====BSCAN_remove_average=================================   
!!      DO Z = 1, ROWS
!!        WRITE(33,*) (STACKED_B_SCAN2(1,Y,Z), Y=TRA,1,-1)     
!!        ! WRITE(33,*) (STACKED_B_SCAN2(1,Y,Z), Y=1,TRA)     
!!      END DO
!===================================================


