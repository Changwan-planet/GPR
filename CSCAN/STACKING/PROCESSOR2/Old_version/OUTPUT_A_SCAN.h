!=======A-SCOPE============================
!BEFORE REMOVING BACKGROUND
    DO Z=1,ROWS
        WRITE(20,*) B_SCAN_IMAGE3(1,1,Z) 
    END DO

!AFTER REMOVING BACKGROUND
    DO Z=1,ROWS
        WRITE(21,*) B_SCAN_IMAGE4(1,1,Z) 
    END DO

!AFTER ZERO_PADDING
    DO Z=1,ROWS2
        WRITE(22,*) B_SCAN_IMAGE5(1,1,Z) 
    END DO

!=======INSTANTNEOUS_AMPLITUDE===============================
    DO Z=1,ROWS3
       WRITE(23,*) HILBERT_power2(1,1,Z)  
   END DO  
!=====================================================  


PRINT *, "COMPELETE TO PRINT A_SCAN"

