   
!====BSCAN-POWERSUM================================   
      DO Z = 1, ROWS
         WRITE(60,*) (POWER_SUM(X,YY,Z), X=1,DIS)
     END DO  
!===================================================

!====BSCAN-AMPSUM================================   
      DO Z = 1, ROWS
         WRITE(61,*) (AMP_SUM(X,YY,Z), X=1,DIS)
      END DO  
!===================================================

PRINT  *, "COMPLETE TO PRINT B_SCAN"
