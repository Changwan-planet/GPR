    
!========3DCUBE==========================

!DO Y = 1, TRA
!DO Y = 3, 18
!      WRITE(51,*) (B_SCAN_IMAGE5(X, Y, 50), X = 1, DIS)     
!END DO 

DO Z = 0, ROWS-1
DO J = 0, TRA2
DO I = 0, DIS2

   WRITE(50,*) I, J, Z, B_SCAN_IMAGE5(I, J, Z)     

END DO 
END DO 
END DO 


!==> THIS STRUCTURE (I x J) x Z CAN BE PRINTED.
!==> (I x J) IS THE C_SCAN.
PRINT*, "3D CUBE (X,Y,Z) =","(",DIS2+1,",",TRA2+1,",",ROWS,")"
PRINT *, "COMPLETE 3D CUBE OUTPUT"
!==========================================

