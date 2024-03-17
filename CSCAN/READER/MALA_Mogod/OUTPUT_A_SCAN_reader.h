!=======B-SCAN============================
!BEFORE REMOVING BACKGROUND
X=1
Y=1

    DO Z=0,ROWS2-1
!       WRITE(20) B_SCAN_IMAGE3(1,1,Z) 
       WRITE(20,*) X, Y, Z, B_SCAN_IMAGE3(X,Y,Z),  B_SCAN_IMAGE4(X,Y,Z), B_SCAN_IMAGE4_zp(X,Y,Z) 
    END DO

!    DO Z=1,ROWS
!        WRITE(20,*) B_SCAN_IMAGE2(Z,1,1) 
!    END DO





