!=======A-SCOPE============================
!X=DIS=THE NUMBER OF STACKING
!Y=TRA
!X=100        

!BEFORE REMOVING BACKGROUND
!    DO Z=1,ROWS
!        WRITE(20,*) B_SCAN_IMAGE3(X,Y,Z) 
!    END DO

!AFTER REMOVING BACKGROUND
    DO Z=1,ROWS
        WRITE(20,*) B_SCAN_IMAGE4(1,1,Z) 
    END DO

!AFTER REMOVING MEAN
!    DO Z=1,ROWS
!        WRITE(20,*) B_SCAN_IMAGE5(X,Y,Z) 
!    END DO



