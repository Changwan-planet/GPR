!========3DCUBE==========================
DO Z = 0, ROWS2-1
DO J = 0, TRA2
DO I = 0, DIS2


     WRITE(50,*) I, J, Z, B_SCAN_IMAGE_GC(I, J, Z)  
!     WRITE(50,*) I, J, Z, B_SCAN_IMAGE_GC(I, TRA2-J, Z)     

END DO 
END DO 
END DO 


!==> THIS STRUCTURE (X x Y) x Z CAN BE PRINTED.
!==> (X x Y) IS THE C_SCAN.
PRINT*, "3D CUBE (I,J,Z) =","(",DIS2+1,",",TRA2+1,",",ROWS2,")"
PRINT *, "COMPLETE 3D CUBE OUTPUT"
!==========================================

!=====GAIN-CONTROL=====

DO Z = 0, ROWS2-1
DO J = 0, TRA2
DO I = 0, DIS2
      B_SCAN_IMAGE_GC(I,J,Z) = B_SCAN_IMAGE(I,J,Z) / SQRT(HILBERT_power2(I,J,Z))
END DO 
END DO
END DO 

!========3DCUBE-GC==========================
DO Z = 0, ROWS2-1
DO J = 0, TRA2
DO I = 0, DIS2

!     WRITE(51,*) I, J, Z, B_SCAN_IMAGE_GC(I, TRA2-J, Z)     
      WRITE(51,*) I, J, Z, B_SCAN_IMAGE_GC(I, J, Z)     



END DO 
END DO 
END DO 
PRINT *, "COMPLETE 3D CUBE-GC OUTPUT"
!







