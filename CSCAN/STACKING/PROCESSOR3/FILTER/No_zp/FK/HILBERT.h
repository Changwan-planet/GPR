!HILBERT TRANSFORM
!HILBERT_A_SCOPE
DO X = 1, DIS
  DO Y = 1, TRA
      CALL fft_hilbert(B_SCAN_IMAGE(X,Y,:),ROWS,HILBERT_SIGNAL) 
!      CALL fft_hilbert(ifft_real(X,Y,:), ROWS, HILBERT_SIGNAL)
      HILBERT_B_SCAN(X,Y,:) = HILBERT_SIGNAL(1,1,:)
   END DO
END DO

