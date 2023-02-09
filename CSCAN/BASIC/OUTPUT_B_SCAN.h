    
!========BSCAN_noprocessing==========================
!B_SCAN_IMAGE3(DIS,TRA,ROWS)     
Y = TRA

      DO Z = ROWS,1,-1
         WRITE(30,*) (B_SCAN_IMAGE3(X,1,Z), X=1,DIS)
      END DO   
!===================================================


!=====BSCAN_rmbgr===================================
!B_SCAN_IMAGE3(DIS,TRA,ROWS)    
Y = TRA

      DO Z = ROWS2,1,-1
         WRITE(31,*) (B_SCAN_IMAGE5(X,Y,Z), X=1,DIS)
      END DO     
!===================================================

!====BSCAN_afzp=================================   
Y = TRA
Y = INT(TRA/2.0)


      DO Z = ROWS3,1,-1
         WRITE(32,*) (B_SCAN_IMAGE6(X,1,Z), X=1,DIS)
      END DO  
!===================================================

!====BSCAN_YZ=================================   
X = 500
      DO Z = ROWS2,1,-1
         WRITE(39,*) (B_SCAN_IMAGE5(1,Y,Z), Y=1,TRA)
      END DO  
!===================================================


PRINT  *, "COMPLETE TO PRINT B_SCAN"
