    
!========CSCAN==========================

!STACKED_B_SCAN = 0.0


DO Y = 1, TRA
   DO F = 1, LINE
      WRITE(40) (STACKED_B_SCAN(Y, F, Z), Z = 1,ROWS)
      WRITE(41,*) (STACKED_B_SCAN(Y, F, Z), Z = 1,ROWS) 
   END DO 
END DO

!==> THIS STRUCTURE (F X Y) X Z CAN BE PRINTED.
!==> (F X Y) IS THE C_SCAN.

PRINT *, "(TRA, LINE, ROWS)=","(",TRA,",", LINE,",",ROWS ,")"
PRINT *, "COMPLETE 3D_CUBE IMAGE OUTPUT"
!==========================================
