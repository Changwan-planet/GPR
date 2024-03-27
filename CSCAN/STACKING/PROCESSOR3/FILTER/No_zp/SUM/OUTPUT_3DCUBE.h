    
!========CSCAN==========================

!=====CSCAN_GC======================================
!B_SCAN_IMAGE5(DIS,TRA,ROWS)    

!      DO Z = 1, ROWS2      
!      DO Y = 1, TRA
!      DO X = 1, DIS 
      ! B_SCAN_IMAGE5_GC(X,Y,Z) = B_SCAN_IMAGE6(X,1,Z) / SQRT(HILBERT_power2(X,Y,Z))  

!       B_SCAN_IMAGE2_GC(X,Y,Z) = B_SCAN_IMAGE2(X,Y,Z) / HILBERT_power2(X,Y,Z)  
!      END DO
!      END DO
!      END DO
 
!===================================================

!================================================================
!CALL flip_3d_y(B_SCAN_IMAGE2, DIS, TRA, ROWS, B_SCAN_IMAGE3)


DO Z = 1, ROWS
DO Y = 1, TRA
DO X = 1, DIS

      WRITE(50,*) X, Y, Z, HILBERT_powerdB(X, Y, Z)

END DO 
END DO 
END DO


!==> THIS STRUCTURE (F X Y) X Z CAN BE PRINTED.
!==> (F X Y) IS THE C_SCAN.
PRINT *, "3D CUBE=", DIS, "X", TRA, "X", ROWS

!PRINT *, "COMPLETE 3D_CUBE IMAGE OUTPUT"

!===================================================


!DO Z = 1, ROWS2
!DO Y = 1, TRA
!DO X = 1, DIS

!      WRITE(41,*) X, Y, Z, B_SCAN_IMAGE2_GC(X, Y, Z)

!END DO 
!END DO 
!END DO


!==> THIS STRUCTURE (F X Y) X Z CAN BE PRINTED.
!==> (F X Y) IS THE C_SCAN.
PRINT *, "USED ROW2 FOR GAIN CONTROAL"
PRINT *, "3D CUBE=", DIS, "X", TRA, "X", ROWS2

!PRINT *, "COMPLETE 3D_CUBE IMAGE OUTPUT"

!===================================================


