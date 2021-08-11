!=======HILBERT_A_SCOPE===============================
!DO I =1, ROWS

!    HILBERT_SIGNAL(I,1) = HILBERT_SIGNAL(I,1)**2

!END DO



!DO I =1, ROWS

!    HILBERT_SIGNAL(I,1) = 10 * log10(HILBERT_SIGNAL(I,1))

!END DO


DO I = 1,ROWS

!            WRITE(24,*) AIMAG(HILBERT_SIGNAL(I,1)) 
            WRITE(25,*) HILBERT_SIGNAL(I,1), a_idft_imag(I,1) 
END DO
!=====================================================
