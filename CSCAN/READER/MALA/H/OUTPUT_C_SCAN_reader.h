    
!========CSCAN==========================

!DO Y = 1, TRA
!DO Y = 3, 18
!      WRITE(41,*) (B_SCAN_IMAGE5(X, Y, 50), X = 1, DIS)     
!END DO 


Z = 50
DO Y = 0, TRA
DO X = 0, DIS
 !     WRITE(41,*) X,Y,Z, B_SCAN_IMAGE3(X, Y, Z)   
 !     WRITE(41,*) X,Y,Z, B_SCAN_IMAGE4(X, Y, Z)   
 !     WRITE(41,*) X,Y,Z, B_SCAN_IMAGE4_CO(X, Y, Z)   
      WRITE(41,*) X,Y,Z, B_SCAN_IMAGE5(X, Y, Z)    
END DO 
END DO


!==> THIS STRUCTURE (X x Y) x Z CAN BE PRINTED.
!==> (X x Y) IS THE C_SCAN.
PRINT*, "3D CUBE (X,Y,Z) =","(",DIS+1,",",TRA+1,",",ROWS,")"
PRINT *, "COMPLETE C_SCAN IMAGE OUTPUT"
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
