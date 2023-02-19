!========3D CUBE-noprocessing==========================
DO X = 1, DIS
DO Y = 1, TRA
       WRITE(40,*) (B_SCAN_IMAGE5(X, Y, Z), Z = 1,ROWS2)
!       WRITE(40,*) (B_SCAN_IMAGE4(X, Y, Z), Z = 1,ROWS/2)
!       WRITE(40) (B_SCAN_IMAGE4(X, Y, Z), Z = 313,1,-1)
END DO 
END DO

!==> THIS STRUCTURE (F X Y) X Z CAN BE PRINTED.
!==> (F X Y) IS THE C_SCAN.
!PRINT *, "COMPLETE 3D_CUBE IMAGE OUTPUT"
!==========================================


!========3D CUBE-rmbpg-zpd==========================
DO X = 1, DIS
DO Y = 1, TRA
!       WRITE(42,*) (B_SCAN_IMAGE6(X, Y, Z), Z = 1,ROWS3)
       WRITE(42) (B_SCAN_IMAGE6(X, Y, Z), Z = 1,ROWS3)


END DO 
END DO
PRINT*, "3D CUBE (X,Y,Z) =","(",DIS,",",TRA,",",ROWS3,")"
!==> THIS STRUCTURE (F X Y) X Z CAN BE PRINTED.
!==> (F X Y) IS THE C_SCAN.
!PRINT *, "COMPLETE 3D_CUBE IMAGE OUTPUT"
!==========================================




!========CSCAN-DIRECTION CHECK==========================
!Z = 2 
!B_SCAN_IMAGE5(:,24,:) = 2*10**5

!DO Y = 1, TRA
!       WRITE(41,*) (B_SCAN_IMAGE5(X, Y, Z), X = 1,DIS)
!END DO 

!==> THIS STRUCTURE (F X Y) X Z CAN BE PRINTED.
!==> (F X Y) IS THE C_SCAN.
!PRINT *, "COMPLETE C_SCAN IMAGE OUTPUT"
!==========================================


