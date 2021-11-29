
!LAYER(3,:,1) = 100000

!DO Y = 1, TRA
!   WRITE(28,*) (LAYER(X, Y, 1), X=1,DIS)
!END DO



DO X = 1, DIS2
   WRITE(28,*) (LAYER(X, Y, 1), Y=1,TRA)
END DO
