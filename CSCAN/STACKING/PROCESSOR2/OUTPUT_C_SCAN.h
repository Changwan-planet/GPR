    
!========CSCAN==========================

DO F = 1, LINE
   DO Y = 1, TRA
       WRITE(40,*) (STACKED_B_SCAN2(F, Y, Z), Z = 1,ROWS)
   END DO 
END DO

!==> THIS STRUCTURE (F X Y) X Z CAN BE PRINTED.
!==> (F X Y) IS THE C_SCAN.
PRINT *, "COMPLETE 3D_CUBE IMAGE OUTPUT"
!==========================================
