  
!========CSCAN==========================

!STACKED_B_SCAN = 0.0

DO F = 1, LINE
DO Y = 1, TRA
DO Z = 1, ROWS

   STACKED_B_SCAN2(Y, F, Z) =  STACKED_B_SCAN(F, Y, Z) 

END DO 
END DO 
END DO


DO F = 1, LINE
DO Y = 1, TRA
DO Z = 1, ROWS

      !WRITE(40) (STACKED_B_SCAN(F, Y, Z), Z = 1,ROWS)
!      WRITE(41,*) (STACKED_B_SCAN(F, Y, Z), Y, F, Z, Z = 1,ROWS) 
!      WRITE(41,*) STACKED_B_SCAN(F, Y, Z), Y, F, Z 
      WRITE(41,*) Y, F, Z, STACKED_B_SCAN2(Y, F, Z) 

      !WRITE(40) (STACKED_B_SCAN2_flip(F, Y, Z), Z = 1,ROWS)
      !WRITE(41,*) (STACKED_B_SCAN2_flip(F, Y, Z), Z = 1,ROWS) 
END DO 
END DO 
END DO

!==> THIS STRUCTURE (F X Y) X Z CAN BE PRINTED.
!==> (F X Y) IS THE C_SCAN.

PRINT *, "(TRA, LINE, ROWS)=","(",TRA,",", LINE,",",ROWS ,")"
PRINT *, "COMPLETE 3D_CUBE IMAGE OUTPUT"
!==========================================
