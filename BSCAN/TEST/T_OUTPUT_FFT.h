DO X = 1, DIS3
   DO Z = 1, ROWS
      psd(X,1,Z) = 10 * log10(f_real(X,1,Z)**2 + f_imag(X,1,Z)**2)

   END DO
END DO


!======================================================================
!TO MAKE A GRAPH OF THE PSD WITH SYMMETRY
DO X = 1, DIS3
   DO Z = 1, ROWS/2
      psd2(X, 1, Z) = psd(X, 1, Z+ROWS/2)
   END DO
END DO

DO X = 1, DIS3
   DO Z = ROWS/2+1, ROWS
      psd2(X, 1, Z) = psd(X, 1, Z-ROWS/2)
   END DO
END DO
!======================================================================

!=======FFT_STACKED_A_SCOPE===============================
!!Y=10
!!DO Z = 1,ROWS
!!           WRITE(24,*) f_real(1,Y,Z),    f_imag(1,Y,Z), &
!!                         psd2(1,Y,Z), ifft_real(1,Y,Z), Ifft_imag(1,Y,Z) 
!!END DO
!=========================================================

!=======FFT_Phase===============================

DO X = 1, DIS3
DO Z = 1, ROWS

   f_phase(X,1,Z) =   180 * ATAN(f_real(X,1,Z)/f_imag(X,1,Z)) /PI

END DO
END DO

X=1

DO Z = 1,ROWS
!           WRITE(24,*) (f_real(X,1,Z),    f_imag(X,1,Z), &
!                     psd2(X,1,Z), f_phase(X,1,Z),ifft_real(X,1,Z), Ifft_imag(X,1,Z), X=DIS3,1,-1) 
           WRITE(24,*) (f_real(X,1,Z),    f_imag(X,1,Z), &
                     psd2(X,1,Z), f_phase(X,1,Z),ifft_real(X,1,Z), Ifft_imag(X,1,Z), X=DIS3,1,-1) 
END DO



!!DO Z = 1,ROWS
!!           WRITE(24,*) f_real(1,Y,Z),    f_imag(1,Y,Z), &
!!                         psd2(1,Y,Z), ifft_real(1,Y,Z), Ifft_imag(1,Y,Z) 
!!END DO
!=========================================================




