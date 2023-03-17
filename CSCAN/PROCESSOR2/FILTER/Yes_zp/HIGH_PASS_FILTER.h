!450MHz HIGH PASS FILTER
f_c = 25
k = 3

!500MHz HIGH PASS FILTER
!f_c = 80
!k = 3

DO X = 1, DIS
   DO Y = 1, TRA
      CALL hpf_butter(f_real(X,Y,:), f_imag(X,Y,:), ROWS3, f_c, k, filter, hpf_real(X,Y,:), hpf_imag(X,Y,:))
     !CALL hpf(f_real(X,Y,:), f_imag(X,Y,:), ROWS2, BAND, TW, hpf_real(X,Y,:), hpf_imag(X,Y,:))
   END DO 
END DO

!IFFT
DO X = 1, DIS
   DO Y = 1, TRA
      CALL ifft(hpf_real(X,Y,:), hpf_imag(X,Y,:), ROWS3, ifft_real(X,Y,:), ifft_imag(X,Y,:))
   END DO
END DO

PRINT *, "HPF END"


