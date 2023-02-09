!========3D CUBE==========================
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

!========CSCAN==========================
Z = 30 

B_SCAN_IMAGE5(:,24,:) = 2*10**6

DO Y = 1, TRA
       WRITE(41,*) (B_SCAN_IMAGE5(X, Y, Z), X = 1,DIS)
END DO 

!==> THIS STRUCTURE (F X Y) X Z CAN BE PRINTED.
!==> (F X Y) IS THE C_SCAN.
!PRINT *, "COMPLETE C_SCAN IMAGE OUTPUT"
!==========================================


