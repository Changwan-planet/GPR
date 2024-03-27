

Z = 500

DO Y = 1, TRA
DO X = 1, DIS

!      WRITE(40,*) X, Y, Z, B_SCAN_IMAGE2_GC(X, Y, Z)
      WRITE(40,*) X, Y, Z, B_SCAn_IMAGE2(X,Y,Z), hpf_power(X, Y, Z), hpf_pdB(X, Y, Z)


END DO 
END DO 



!==> THIS STRUCTURE (F X Y) X Z CAN BE PRINTED.
!==> (F X Y) IS THE C_SCAN.
PRINT *, "USED ROW2 FOR GAIN CONTROAL"
PRINT *, "3D CUBE=", DIS, "X", TRA, "X", ROWS2

!PRINT *, "COMPLETE C SCAN IMAGE OUTPUT"

!===================================================


