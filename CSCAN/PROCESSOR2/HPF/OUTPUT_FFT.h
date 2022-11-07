DO X = 1, DIS
!DO Y = 1, TRA
DO Z = 1, ROWS
      psd(X,1,Z) = SQRT(f_real(X,1,Z)**2 + f_imag(X,1,Z)**2)
END DO
END DO
!END DO

DO X = 1, DIS
!DO Y = 1, TRA
DO Z = 1, ROWS
!      psd2(X,1,Z) = 10 * log10(psd(X,1,Z)**2/MAXVAL(psd(X,1,:))**2)
      psd2(X,1,Z) = 10 * log10(psd(X,1,Z)/MAXVAL(psd(X,1,:)))


END DO
!END DO
END DO

!======================================================================
!TO MAKE A GRAPH IN FREQUENCY DOMAIN SYMMETRIC
!DO X = 1, DIS
!     CALL f_symmetry( f_real(X, 1, :), ROWS, f_real2(X, 1, :) )
!     CALL f_symmetry( f_imag(X, 1, :), ROWS, f_imag2(X, 1, :) )
!     CALL f_symmetry( psd2(X, 1, :), ROWS, psd3(X, 1, :) )
!END DO
!======================================================================

!=======FFT_STACKED_A_SCOPE===============================
X=1
DO Z = 1,ROWS
  ! WRITE(40,*) psd2(X,1,Z) 


  WRITE(40,*) B_SCAN_IMAGE4(X,1,Z), f_real(X,1,Z), f_imag(X,1,Z),&
              psd2(X,1,Z), ifft_real(X,1,Z), ifft_imag(X,1,Z) 


!  WRITE(40,'(6F20.10)') B_SCAN_IMAGE4(X,1,Z), f_real(X,1,Z), f_imag(X,1,Z),&
!                         psd2(X,1,Z), ifft_real(X,1,Z), ifft_imag(X,1,Z) 

!!  WRITE(40,'(6F20.10)') B_SCAN_IMAGE4(X,1,Z), f_real2(X,1,Z), f_imag2(X,1,Z),&
!!                         psd3(X,1,Z), ifft_real(X,1,Z), ifft_imag(X,1,Z) 



END DO
!=========================================================


