

!100MHz BAND PASS FILTER-GSSI-MIHO
f_l = 90
f_h = 200 
k = 7 

!450MHz BAND PASS FILTER-MALA-BOMIN
!f_l = 15
!f_h = 40 
!k = 2 

!500MHz BAND PASS FILTER-MALA-MOGOD
!f_l = 30
!f_h = 115 
!k = 2 
!BAND = 30
!PRINT *, "BAND=",BAND

DO X = 1, DIS 
DO Y = 1, TRA
   CALL bpf_butter(f_real(X,Y,:), f_imag(X,Y,:), ROWS3, f_l, f_h, k, filter, bpf_real(X,Y,:), bpf_imag(X,Y,:))
END DO
END DO

!IFFT
DO X = 1, DIS 
DO Y = 1, TRA
  CALL ifft(bpf_real(X,Y,:), bpf_imag(X,Y,:), ROWS3, ifft_real(X,Y,:), ifft_imag(X,Y,:))
END DO
END DO 

PRINT *, "BPF END"


