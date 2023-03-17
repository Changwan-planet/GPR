!=======CROSS_CORRLEATION============================
    DO Z=1,CRRL_N
        WRITE(50,*) crrl(Z) 
    END DO

!=======SHIFT========================================
    DO X = 1, DIS
       WRITE(50,*) (SHIFT(X,Y), Y = 1,TRA) 
    END DO


PRINT *, "COMPELETED TO PRINT CROSS CORRELATION"

