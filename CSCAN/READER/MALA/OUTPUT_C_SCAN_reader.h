    
!========CSCAN==========================

DO X = 1, DIS
   DO Y = 1, TRA
       WRITE(40) (B_SCAN_IMAGE3(X, Y, Z), Z = 1,ROWS)
       WRITE(41,*) (B_SCAN_IMAGE3(X, Y, Z), Z = 1,ROWS)
!       PRINT *,  (B_SCAN_IMAGE3(X, Y, Z), Z = 1,ROWS)
          
   END DO 
END DO

!==> THIS STRUCTURE (X x Y) x Z CAN BE PRINTED.
!==> (X x Y) IS THE C_SCAN.
PRINT*, "3D CUBE (X,Y,Z) =","(",DIS,",",TRA,",",ROWS,")"
PRINT *, "COMPLETE 3D_CUBE IMAGE OUTPUT"
!==========================================


!JUST FOR CHECK 
!========CSCAN==========================

!DO Z = ROWS,1,-1
!DO Z = 1,ROWS
!   DO Y = 1, TRA
!       WRITE(40) (B_SCAN_IMAGE3(X, Y, Z), X = 1,DIS)
!       WRITE(41,*) (B_SCAN_IMAGE3(X, Y, Z), X = 1,DIS)
!       PRINT *,  (B_SCAN_IMAGE3(X, Y, Z), Z = 1,DIS)
          
!   END DO 
!END DO

!==> THIS STRUCTURE (X x Y) x Z CAN BE PRINTED.
!==> (X x Y) IS THE C_SCAN.
!PRINT *, "COMPLETE 3D_CUBE IMAGE OUTPUT"
!==========================================
