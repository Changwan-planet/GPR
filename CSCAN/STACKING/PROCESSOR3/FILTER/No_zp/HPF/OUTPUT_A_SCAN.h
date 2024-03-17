!=======A-SCOPE============================
!NO ZERO_PADDING
!    DO Z=1, ROWS
!       WRITE(20,*) B_SCAN_IMAGE(1,1,Z), f_psd(1,1,Z), f_psd(1,21,Z), f_psd(41,1,Z), f_psd(41,21,Z) 
!    END DO

    DO Z=1, ROWS
       !WRITE(20,*) B_SCAN_IMAGE(1,1,Z), HIBLERT_B_SCAN(1,1,Z) f_pdB(1,21,Z), hpf_pdB(1,21,Z), filter(Z) 
        WRITE(20,*) B_SCAN_IMAGE(1,1,Z), HIBLERT_B_SCAN(1,1,Z) f_pdB(1,21,Z), hpf_pdB(1,21,Z), filter(Z) 
    
    END DO




!=======INSTANTNEOUS_AMPLITUDE===============================
!    DO Z=1,ROWS
!       WRITE(21,*) HILBERT_power2(1,1,Z)  
!   END DO  
!=====================================================  


PRINT *, "COMPELETE TO PRINT A_SCAN"

