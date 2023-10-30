    
!========CSCAN==========================
!              X  Y
!B_SCAN_IMAGE3(:, 50, 50) = -10000    


Z = 50

DO Y = 0, TRA
DO X = 0, DIS    
     
      !WRITE(40,*) X, Y, Z, B_SCAN_IMAGE3(X, Y, Z)     
!      WRITE(40,*) X, Y, Z, B_SCAN_IMAGE3F(X, Y, Z)     
!      WRITE(40,*) X, Y, Z, B_SCAN_IMAGE4(X, Y, Z)     
      WRITE(40,*) X, Y, Z, B_SCAN_IMAGE5(X, Y, Z)     





END DO 
END DO 


!==> THIS STRUCTURE (X x Y) x Z CAN BE PRINTED.
!==> (X x Y) IS THE C_SCAN.
PRINT*, "CSCAN =","(",DIS+1,",",TRA+1,",", Z,")"
PRINT *, "COMPLETE C_SCAN IMAGE OUTPUT"
!==========================================


