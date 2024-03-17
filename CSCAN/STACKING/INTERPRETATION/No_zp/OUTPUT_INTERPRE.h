
!=====HORIZON_1=======================
DO X = 1, DIS
   WRITE(90,*) X, H_S(X)
END DO 

DO X = 1, DIS
!DO Z = 1, i_h2(X)
   WRITE(91,*) X, H_Z(X) 
END DO 
!END DO 


DO X = 1, DIS
   WRITE(92,*) X, H_S(X), H_Z(X)
END DO 
 


!=====================================
PRINT*, "COMPLEDTED TO PRINT INTERPRETATION"
