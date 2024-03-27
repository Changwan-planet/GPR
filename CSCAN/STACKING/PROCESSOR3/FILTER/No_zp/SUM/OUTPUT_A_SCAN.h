!=======A-SCOPE============================
!NO ZERO_PADDING
!    DO Z=1, ROWS
!       WRITE(20,*) B_SCAN_IMAGE(1,1,Z), f_power(1,1,Z), f_power(1,21,Z), f_power(41,1,Z), f_power(41,21,Z) 
!    END DO

    DO Z=1, ROWS
!       WRITE(20,*) B_SCAN_IMAGE(1,1,Z), f_pdB(1,21,Z), f_power(1,21,Z), fk_real(1,21,Z) 
!       WRITE(20,*) B_SCAN_IMAGE(21,21,Z), HILBERT_B_SCAN(21,21,Z), f_power(21,21,Z), fk_real(21,21,Z) 
!       WRITE(20,*) B_SCAN_IMAGE(21,21,Z), HILBERT_B_SCAN(21,21,Z)
       WRITE(20,*) B_SCAN_IMAGE(21,21,Z), HILBERT_B_SCAN(21,21,Z), HILBERT_power(21,21,Z), HILBERT_powerdB(21,21,Z)



    END DO




!=======INSTANTNEOUS_AMPLITUDE===============================
!    DO Z=1,ROWS
!       WRITE(21,*) HILBERT_power2(1,1,Z)  
!   END DO  
!=====================================================  


PRINT *, "COMPELETE TO PRINT A_SCAN"

