!=======A-SCOPE============================
!X=DIS=THE NUMBER OF STACKING
Y=TRA
X=1

!BEFORE REMOVING BACKGROUND
    DO Z=1,ROWS  
!       B_SCAN_IMAGE3(X,Y,Z)=10*log10(B_SCAN_IMAGE3(X,Y,Z)**2) 
       WRITE(20,*) B_SCAN_IMAGE3(X,Y,Z) 
    END DO

!AFTER REMOVING BACKGROUND
    DO Z=1,ROWS
!       B_SCAN_IMAGE4(X,Y,Z)=10*log10(B_SCAN_IMAGE4(X,Y,Z)**2)
       WRITE(21,*) B_SCAN_IMAGE4(X,Y,Z) 
    END DO

!AFTER REMOVING MEAN
!    DO Z=1,ROWS
!        WRITE(22,*) B_SCAN_IMAGE5(X,Y,Z) 
!    END DO


!=======STACKED_A_SCOPE_MULTIPLE==+===================
!    DO Z=1, ROWS
!       DO X = 1, DIS2
!          STACKED_B_SCAN(X,1,Z)=10*log(STACKED_B_SCAN(X,1,Z)**2) 
!       END DO
!    END DO   

    DO Z=1, ROWS
       WRITE(23,*) (STACKED_B_SCAN(X,1,Z), X=1,DIS2) 
    END DO  
!=====================================================  
