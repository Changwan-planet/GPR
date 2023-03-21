  
!========CSCAN==========================

!STACKED_B_SCAN = 0.0


DO F = 1, LINE
   DO Y = 1, TRA
      WRITE(40) (STACKED_B_SCAN(F, Y, Z), Z = 1,ROWS)
      WRITE(41,*) (STACKED_B_SCAN(F, Y, Z), Z = 1,ROWS) 
      !WRITE(40) (STACKED_B_SCAN_flip(F, Y, Z), Z = 1,ROWS)
      !WRITE(41,*) (STACKED_B_SCAN_flip(F, Y, Z), Z = 1,ROWS) 

   END DO 
END DO

!==> THIS STRUCTURE (F X Y) X Z CAN BE PRINTED.
!==> (F X Y) IS THE C_SCAN.

PRINT *, "(LINE, TRA, ROWS)=","(",LINE,",", TRA,",",ROWS ,")"
PRINT *, "COMPLETE 3D_CUBE IMAGE OUTPUT"
!==========================================
