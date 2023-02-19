    
!========CSCAN==========================

!=====CSCAN_GC======================================
!B_SCAN_IMAGE5(DIS,TRA,ROWS)    

      DO Z = 1, ROWS3
      DO Y = 1, TRA
      DO X = 1, DIS 
      ! B_SCAN_IMAGE5_GC(X,Y,Z) = B_SCAN_IMAGE5(X,1,Z) / SQRT(HILBERT_power2(X,Y,Z))  

       B_SCAN_IMAGE5_GC(X,Y,Z) = B_SCAN_IMAGE5(X,Y,Z) / HILBERT_power2(X,Y,Z)  
      END DO
      END DO
      END DO
 
!===================================================

!!DO X = 1, DIS
!!   DO Y = 1, TRA
!!       WRITE(40,*) (B_SCAN_IMAGE5(X, Y, Z), Z = ROWS/2,1-1)
!       WRITE(40,*) (B_SCAN_IMAGE4(X, Y, Z), Z = ROWS/2,1-1)
!       WRITE(40,*) (B_SCAN_IMAGE4(X, Y, Z), Z = 1,ROWS/2)
!       WRITE(40) (B_SCAN_IMAGE4(X, Y, Z), Z = 313,1,-1)
!!   END DO 
!!END DO

!==> THIS STRUCTURE (F X Y) X Z CAN BE PRINTED.
!==> (F X Y) IS THE C_SCAN.
!PRINT *, "COMPLETE 3D_CUBE IMAGE OUTPUT"
!===================================================

!===================================================

DO X = 1, DIS
   DO Y = 1, TRA
       WRITE(41,*) (B_SCAN_IMAGE5_GC(X, Y, Z), Z = 1,ROWS3)
   END DO 
END DO

!==> THIS STRUCTURE (F X Y) X Z CAN BE PRINTED.
!==> (F X Y) IS THE C_SCAN.
PRINT *, "COMPLETE 3D_CUBE IMAGE OUTPUT"
!===================================================



