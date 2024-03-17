S1 = 1000
S2 = 1100


DO Y = 1, TRA 
   CALL horizon_pick(POWER_SUM(:,YY,:), DIS, TRA, ROWS, S1, S2, H_1)
END DO 


DO Y = 1, TRA
   CALL horizon_pick(HILBERT_AS_powerdB(:,YY,:), DIS, TRA, ROWS, S1, S2, H_2)
END DO 


!=====HORIZON_1=======================
DO X = 1, DIS 
   WRITE(90,*) X, H_1(X)
END DO  
!=====================================


!=====HORIZON_2=======================
DO X = 1, DIS 
   WRITE(91,*) X, H_2(X)
END DO  
!=====================================

