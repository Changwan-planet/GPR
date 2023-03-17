    
!========BSCAN_noprocessing==========================
!B_SCAN_IMAGE3(DIS,TRA,ROWS)     
Y = TRA

      !DO Z = ROWS,1,-1
      DO Z = 1,ROWS     
         WRITE(30,*) (B_SCAN_IMAGE3(X,1,Z), X=1,DIS)
      END DO   
!===================================================


!=====BSCAN_rmbgr===================================
!B_SCAN_IMAGE3(DIS,TRA,ROWS)    
Y = TRA

 !     DO Z = ROWS2,1,-1
      DO Z = 1,ROWS2      
         WRITE(31,*) (B_SCAN_IMAGE5(X,Y,Z), X=1,DIS)
      END DO     
!===================================================

!====BSCAN_afzp=================================   
Y = TRA
Y = INT(TRA/2.0)

!      DO Z = ROWS3,1,-1
      DO Z = 1,ROWS3
         WRITE(32,*) (B_SCAN_IMAGE6(X,1,Z), X=1,DIS)
      END DO  
!===================================================

!====BSCAN_YZ=================================   
!X = 500
!      DO Z = ROWS2,1,-1
!         WRITE(39,*) (B_SCAN_IMAGE5(X,Y,Z), Y=1,TRA)
!      END DO  

!      DO Z = 1, ROWS2
!         TEMP(Z) =SUM( B_SCAN_IMAGE5(X,:,Z) ) /SIZE( B_SCAN_IMAGE5(X,:,Z) )
!      END DO 
     
!      DO Z = 1, ROWS2 
!      DO Y = 1, TRA
!         B_SCAN_IMAGE9(X,Y,Z) = B_SCAN_IMAGE5(X,Y,Z) / TEMP(Z)
!      END DO 
!      END DO 

!      DO Y = 1, TRA 
!         WRITE(39,*) (B_SCAN_IMAGE9(X,Y,Z), Z = 1,ROWS2)
!     END DO  


!===================================================

PRINT  *, "COMPLETE TO PRINT B_SCAN"
