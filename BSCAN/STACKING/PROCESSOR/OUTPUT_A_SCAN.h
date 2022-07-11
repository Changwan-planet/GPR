!=======A-SCOPE============================
!X=DIS=THE NUMBER OF STACKING
Y=TRA
X=100        


!BEFORE REMOVING BACKGROUND
!    DO Z=1,ROWS
!        WRITE(20,*) B_SCAN_IMAGE3(X,Y,Z) 
!    END DO

!AFTER REMOVING BACKGROUND
!    DO Z=1,ROWS
!        WRITE(20,*) B_SCAN_IMAGE4(X,Y,Z) 
!    END DO

!AFTER REMOVING MEAN
!    DO Z=1,ROWS
!        WRITE(20,*) B_SCAN_IMAGE5(X,Y,Z) 
!    END DO


!=======STACKED_A_SCOPE===============================
Y = 1
!! DO Y = 1, TRA    
!!    DO Z=1,ROWS
!!       WRITE(20,*) STACKED_A_SCOPE(1,Y,Z) 
!!    END DO
!! END DO   
!=====================================================  

!=======MEAN_A_SCOPE===============================
Y = 1   
    DO Z=1,ROWS
       !WRITE(20,*) MEAN_A_SCOPE(1,Y,Z) 
       WRITE(20,*) STACKED_B_SCAN(1,1,Z) 
    END DO  
!=====================================================  

!=======HILBERT_A_SCOPE_REAL===============================
Y = 1   
    DO Z=1,ROWS
       WRITE(21,*) HILBERT_STACKED_SIGNAL(1,1,Z) 
    END DO  
!=====================================================  

!=======INSTANTNEOUS_AMPLITUDE===============================
Y = 1
!    DO Z=1, ROWS
!       INST_A_SCOPE(1,1,Z) = SQRT(STACKED_B_SCAN(1,1,Z)**2 + HILBERT_STACKED_SIGNAL(1,1,Z)**2)
!    END DO

    DO Z=1,ROWS
       WRITE(22,*) HILBERT_power2(1,1,Z)  
    END DO  
!=====================================================  

