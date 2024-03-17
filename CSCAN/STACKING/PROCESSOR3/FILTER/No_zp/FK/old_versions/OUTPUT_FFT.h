DO X = 1, DIS
DO Y = 1, TRA
DO Z = 1, ROWS2
      psd(X,Y,Z) = SQRT(f_real(X,Y,Z)**2 + f_imag(X,Y,Z)**2)
END DO
END DO
END DO

DO X = 1, DIS
DO Y = 1, TRA
DO Z = 1, ROWS2
!  psd2(X,Y,Z) = 10 * log10(psd(X,Y,Z)/MAXVAL(psd(X,Y,:))) !Relative values
      
   psd2(X,Y,Z) = 10 * log10(psd(X,Y,Z)) !Absolute values

END DO
END DO
END DO

!======================================================================
!TO MAKE A GRAPH IN FREQUENCY DOMAIN SYMMETRIC
!!DO X = 1, DIS
!!     CALL f_symmetry( f_real(X, 1, :), ROWS2, f_real2(X, 1, :) )
!!     CALL f_symmetry( f_imag(X, 1, :), ROWS2, f_imag2(X, 1, :) )
!!     CALL f_symmetry( psd2(X, 1, :), ROWS2, psd3(X, 1, :) )
!!END DO
!======================================================================

!=======FFT_STACKED_A_SCOPE===============================
X=1
Y=1
DO Z = 1,ROWS2
  ! WRITE(50,*) psd2(X,Y,Z) 

  WRITE(50,*) B_SCAN_IMAGE5(X,Y,Z), f_real(X,Y,Z), f_imag(X,Y,Z),&
                         psd2(X,Y,Z), ifft_real(X,Y,Z), ifft_imag(X,Y,Z) 
!  WRITE(50,'(6F20.10)') B_SCAN_IMAGE4(X,Y,Z), f_real2(X,Y,Z), f_imag2(X,Y,Z),&
!                         psd3(X,Y,Z), ifft_real(X,Y,Z), ifft_imag(X,Y,Z) 


END DO
!=========================================================


