DO I = 1, ROWS

psd(I,1) = 10 * log10(f_real(I,1)**2 + f_imag(I,1)**2)

END DO

!=======FFT_STACKED_A_SCOPE===============================
DO I = 1,ROWS
           WRITE(24,*) f_real(I,1), f_imag(I,1), psd(I,1), ifft_real(I,1), Ifft_imag(I,1) 
END DO
!=========================================================

!CONSIDER THE PROPERTY OF THE FFT GRAPHY

!=======USEFUL FFT_STACKED_A_SCOPE ===============================


!DO I = 1, INT(ROWS/2.0)

!    If (f_real(I,1) > 0) then

!    WRITE(*,*) "I=",I, f_real(I,1)
!    WRITE(24,*) f_real(I,1), f_imag(I,1), ifft_real(I,1), Ifft_imag(I,1) 

!END IF 

!END DO
!=====================================================
