    
!========CSCAN==========================

DO X = 1, DIS
   DO Y = 1, TRA
       WRITE(40) (B_SCAN_IMAGE3(X, Y, Z), Z = 1,ROWS)
!       WRITE(40,*) (B_SCAN_IMAGE3(X, Y, Z), Z = 1,ROWS)
!       PRINT *,  (B_SCAN_IMAGE3(X, Y, Z), Z = 1,ROWS)
          
   END DO 
END DO

!==> THIS STRUCTURE (X x Y) x Z CAN BE PRINTED.
!==> (X x Y) IS THE C_SCAN.
PRINT *, "COMPLETE 3D_CUBE IMAGE OUTPUT"
!==========================================
