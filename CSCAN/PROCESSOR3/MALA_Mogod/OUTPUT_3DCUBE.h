!========3DCUBE==========================
DO Z = 0, ROWS-1
DO J = 0, TRA-1
DO I = 0, DIS2-1


     WRITE(50,*) I, J, Z, B_SCAN_IMAGE2(I, J, Z)  
!     WRITE(50,*) I, J, Z, B_SCAN_IMAGE(I, TRA2-J, Z)     

END DO 
END DO 
END DO 


!==> THIS STRUCTURE (X x Y) x Z CAN BE PRINTED.
!==> (X x Y) IS THE C_SCAN.
PRINT*, "3D CUBE (I,J,Z) =","(",DIS2,",",TRA,",",ROWS,")"
PRINT *, "COMPLETE 3D CUBE OUTPUT"
!==========================================

!=====GAIN-CONTROL=====

DO Z = 0, ROWS-1
DO J = 0, TRA-1
DO I = 0, DIS2-1
      B_SCAN_IMAGE2_GC(I,J,Z) = B_SCAN_IMAGE2(I,J,Z) / SQRT(HILBERT_power2(I,J,Z))
END DO 
END DO
END DO 

PRINT*, "GAIN CONTROL END"


!========3DCUBE-GC==========================
DO Z = 0, ROWS-1
DO J = 0, TRA-1
DO I = 0, DIS2-1

!     WRITE(51,*) I, J, Z, B_SCAN_IMAGE_GC(I, TRA-J, Z)     
      WRITE(51,*) I, J, Z, B_SCAN_IMAGE2_GC(I, J, Z)     
!      WRITE(51,*) I, J, Z, HILBERT_power(I, J, Z)     


END DO 
END DO 
END DO 
PRINT *, "COMPLETE 3D CUBE-GC OUTPUT"
!


