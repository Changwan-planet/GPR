S1 = 1000
S2 = 1100


DO Y = 1, TRA 

   CALL horizon_pick(B_SCAN_IMAGE6F(:,YY,:), DIS, TRA, ROWS, S1, S2, H_1)

END DO 



!=====HORIZON_1=======================
DO X = 1, DIS 
   WRITE(91,*) X, H_1(X)
END DO  
!=====================================


