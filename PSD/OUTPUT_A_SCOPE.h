!=======A-SCOPE============================
!X=DIS=THE NUMBER OF STACKING
Y=TRA
X=100        


!BEFORE REMOVING BACKGROUND
    DO Z=1,ROWS
        WRITE(20,*) B_SCAN_IMAGE3(X,Y,Z) 
    END DO

!AFTER REMOVING BACKGROUND
    DO Z=1,ROWS
        WRITE(21,*) B_SCAN_IMAGE4(X,Y,Z) 
    END DO

!AFTER REMOVING MEAN
!    DO Z=1,ROWS
!        WRITE(22,*) B_SCAN_IMAGE5(X,Y,Z) 
!    END DO


!=======STACKED_A_SCOPE===============================
Y = 1
! DO Y = 1, TRA    
!!    DO Z=1,ROWS
!!       WRITE(23,*) STACKED_A_SCOPE(1,Y,Z) 
!!    END DO
! END DO   
!=====================================================  
