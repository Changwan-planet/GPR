    
!======B_SCAN=======================================
!B_SCAN_IMAGE3(DIS,TRA,ROWS)     
!Y = TRA
      DO Z = 1, ROWS
         WRITE(21,*) (B_SCAN_IMAGE4(X,1,Z), X=DIS,1,-1)
      END DO
!===================================================

    
!======B_SCAN=======================================
!B_SCAN_IMAGE3(DIS,TRA,ROWS)     

!      DO Z = 1, ROWS
!         WRITE(21,*) (MV_MEAN_BSCAN2(X,1,Z), X=1,DIS3)
!      END DO
!===================================================

!======B_SCAN=======================================
!!      DO Z = 1, ROWS
!!         WRITE(21,*) (STACKED_BSCAN(X,1,Z), X=DIS3,1,-1)   
!!      END DO


!MEAN_A_SCOPE
!      DO Z = 1, ROWS
!         WRITE(21,*) MEAN_A_SCOPE(1,1,Z)   
!      END DO
!===================================================


