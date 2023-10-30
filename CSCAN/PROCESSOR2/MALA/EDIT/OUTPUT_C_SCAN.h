!=======C-SCAN============================

!X = 0
!Y = 0

!    DO Z = 0, ROWS-1
!       WRITE(40,*) X, Y, Z, B_SCAN_IMAGE_H(X,Y,Z) 
!       WRITE(40,*) X, Y, Z, B_SCAN_IMAGE_H(X,Y,Z) 
!   END DO

Z = 150

    DO X = 0, DIS
    DO Y = 0, TRA
       WRITE(40,*) X, Y, Z, B_SCAN_IMAGE2(X,Y,Z), B_SCAN_IMAGE3(X,Y,Z), B_SCAN_IMAGE4(X,Y,Z) 

    END DO
    END DO

!    DO I = 0, DIS2
!    DO J = 0, TRA2
!       WRITE(40,*) I, J, Z, B_SCAN_IMAGE5(I,J,Z) 
!    END DO
!    END DO


PRINT *, "COMPELETE TO PRINT C_SCAN"

