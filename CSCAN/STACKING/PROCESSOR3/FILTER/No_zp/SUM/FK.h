!FK
imag = 0.0
DO X = 1, DIS
   DO Y = 1, TRA
!  CALL fft(B_SCAN_IMAGE(X,Y,:), imag, ROWS, f_real(X,Y,:), f_imag(X,Y,:))
  CALL fft(f_power(X,Y,:), imag, ROWS, fk_real(X,Y,:), fk_imag(X,Y,:))


!!   CALL fft(B_SCAN_IMAGE2_rmavrg(X,Y,:), imag, ROWS, f_real(X,Y,:), f_imag(X,Y,:))


!    CALL ifft(f_real(1,Y,:), f_imag(1,Y,:), ROWS, ifft_real(1,Y,:), ifft_imag(1,Y,:))l
   END DO
END DO
PRINT *, "FK END"

