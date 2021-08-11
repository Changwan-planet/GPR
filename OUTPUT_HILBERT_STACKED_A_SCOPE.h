!=======HILBERT_STACKED_A_SCOPE===============================
!DO I =1, ROWS

!    HILBERT_STACKED_SIGNAL(I,1) = HILBERT_STACKED_SIGNAL(I,1)**2

!END DO



!DO I =1, ROWS

!    HILBERT_STACKED_SIGNAL(I,1) = 10 * log10(HILBERT_STACKED_SIGNAL(I,1))

!END DO


DO I = 1,ROWS

!            WRITE(24,*) AIMAG(HILBERT_STACKED_SIGNAL(I,1)) 
            WRITE(26,*) HILBERT_STACKED_SIGNAL(I,1) 
END DO
!=====================================================
