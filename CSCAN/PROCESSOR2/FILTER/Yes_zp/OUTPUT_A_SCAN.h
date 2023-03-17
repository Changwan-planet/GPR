!=======A-SCOPE============================
!AFTER ZERO_PADDING
    DO Z=1, ROWS3
       WRITE(20,*) B_SCAN_IMAGE6(1,1,Z) 
    END DO

    DO Z=1, ROWS3
       !WRITE(22,*a) B_SCAN_IMAGE6_rmavg(1,1,Z) 
       WRITE(22,*) ifft_real(1,1,Z) 


    END DO


!=======INSTANTNEOUS_AMPLITUDE===============================
!    DO Z=1,ROWS4
!       WRITE(21,*) (HILBERT_power2(X,1,Z),X=1,DIS)  
!   END DO  
!=====================================================  


PRINT *, "COMPELETE TO PRINT A_SCAN"

