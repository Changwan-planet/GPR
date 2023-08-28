!=======A-SCOPE============================
!NO ZERO_PADDING
    DO Z=1, ROWS
       WRITE(20,*) B_SCAN_IMAGE(1,1,Z) 
    END DO

!=======INSTANTNEOUS_AMPLITUDE===============================
!    DO Z=1,ROWS
!       WRITE(21,*) HILBERT_power2(1,1,Z)  
!   END DO  
!=====================================================  


PRINT *, "COMPELETE TO PRINT A_SCAN"

