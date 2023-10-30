
!========CSCAN==========================

!DO Y = 1, TRA
!DO Y = 3, 18
!      WRITE(51,*) (B_SCAN_IMAGE5(X, Y, 50), X = 1, DIS)
!END DO

DO Z = 0, ROWS2-1
DO Y = 0, TRA2
!DO Y = 0, 73


DO X = 0, DIS
!      WRITE(51,*) X, Y, Z, B_SCAN_IMAGE2(Z, X, Y)
!      WRITE(51,*) X, Y, Z, B_SCAN_IMAGE3(X, Y, Z)
!      WRITE(51,*) X, Y, Z, B_SCAN_IMAGE3F(X, Y, Z)
!     WRITE(51,*) X, Y, Z, B_SCAN_IMAGE4_CO(X, Y, Z)
     WRITE(51,*) X, Y, Z, B_SCAN_IMAGE5_zp(X, Y, Z)


END DO
END DO
END DO



!DO Y = 1, TRA
!DO X = 1, DIS
!      WRITE(51,*) B_SCAN_IMAGE3(X, Y, 50)
!END DO
!END DO


!==> THIS STRUCTURE (X x Y) x Z CAN BE PRINTED.
!==> (X x Y) IS THE C_SCAN.
PRINT*, "3D CUBE (X,Y,Z) =","(",DIS+1,",",TRA+1,",",ROWS2,")"
PRINT *, "COMPLETE 3D CUBE OUTPUT"
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
                                                                                                                                                               
