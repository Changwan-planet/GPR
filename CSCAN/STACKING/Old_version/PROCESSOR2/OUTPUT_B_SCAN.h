
!====BSCAN_stacking=================================   
      DO Z = 1, ROWS
         WRITE(30,*) (STACKED_B_SCAN2(1,Y,Z), Y=TRA,1,-1)     
         !WRITE(30,*) (STACKED_B_SCAN2(1,Y,Z), Y=1,TRA)     
      END DO
!===================================================

!====BSCAN_remove_average=================================   
!!      DO Z = 1, ROWS
!!        WRITE(31,*) (STACKED_B_SCAN3(1,Y,Z), Y=TRA,1,-1)     
!!        ! WRITE(31,*) (STACKED_B_SCAN3(1,Y,Z), Y=1,TRA)     
!!      END DO
!===================================================


