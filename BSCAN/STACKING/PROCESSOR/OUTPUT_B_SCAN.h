    
!========BSCAN_noprocessing==========================
!B_SCAN_IMAGE3(DIS,TRA,ROWS)     
!Y = 1

      DO Z = 1, ROWS
         WRITE(30,*) (B_SCAN_IMAGE3(1,Y,Z), Y=1,TRA)
      END DO   
!===================================================


!=====BSCAN_rmbgr===================================
!B_SCAN_IMAGE3(DIS,TRA,ROWS)    
!Y = 1

      DO Z = 1, ROWS
         WRITE(31,*) (B_SCAN_IMAGE4(1,Y,Z), Y=1,TRA)
      END DO     
!===================================================


!====STACEKD_BSCAN_rmbgr=================================   
       DO Z = 1, ROWS2
       DO Y = 1, TRA
          STACKED_B_SCAN_GC(1,Y,Z) = STACKED_B_SCAN(1,Y,Z) / HILBERT_STACKED_power2(1,Y,Z)
       END DO
       END DO

      DO Z = 1, ROWS
         WRITE(32,*) (STACKED_B_SCAN_GC(1,Y,Z), Y=1,TRA)     
         !WRITE(32,*) (STACKED_B_SCAN(1,Y,Z), Y=1,TRA)     
      END DO

!====STACEKD_BSCAN_rmavg=================================   
 
       DO Z = 1, ROWS2
       DO Y = 1, TRA
          STACKED_B_SCAN2_GC(1,Y,Z) = STACKED_B_SCAN2(1,Y,Z) / HILBERT_STACKED_power2(1,Y,Z)
       END DO
       END DO

      DO Z = 1, ROWS
        WRITE(33,*) (STACKED_B_SCAN2_GC(1,Y,Z), Y=1,TRA)     
        ! WRITE(33,*) (STACKED_B_SCAN2(1,Y,Z), Y=1,TRA)     
      END DO
!===================================================


