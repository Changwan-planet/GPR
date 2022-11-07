!=======A-SCOPE============================
!X=DIS=THE NUMBER OF STACKING

!BEFORE REMOVING BACKGROUND
!    DO Z=1,ROWS
!        WRITE(20,*) B_SCAN_IMAGE3(1,1,Z) 
!    END DO

!AFTER REMOVING BACKGROUND
    DO Z=1,ROWS
        WRITE(20,*) B_SCAN_IMAGE4(1,1,Z) 
    END DO

!AFTER REMOVING MEAN
!    DO Z=1,ROWS
!        WRITE(20,*) B_SCAN_IMAGE5(1,1,Z) 
!    END DO


!=======MEAN_A_SCOPE=============================== 
!    DO Z=1,ROWS
!       WRITE(20,*) MEAN_A_SCOPE(1,1,Z)        
!    END DO  
!=====================================================  

!=======HILBERT_A_SCOPE_REAL===============================
    DO Z=1,ROWS
       WRITE(21,*) HILBERT_SIGNAL(1,1,Z) 
    END DO  
!=====================================================  

!=======INSTANTNEOUS_AMPLITUDE===============================
!    DO Z=1, ROWS
!       INST_A_SCOPE(1,1,Z) = SQRT(B_SCAN_IMAGE4(1,1,Z)**2 + HILBERT_SIGNAL(1,1,Z)**2)
!    END DO

    DO Z=1,ROWS2
       WRITE(22,*) HILBERT_power2(1,1,Z)  
   END DO  
!=====================================================  

