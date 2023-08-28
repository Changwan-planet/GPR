DO X = 1, DIS
DO Y = 1, TRA
DO Z = 1, ROWS
      psd(X,Y,Z) = SQRT(f_real(X,Y,Z)**2 + f_imag(X,Y,Z)**2)
END DO
END DO
END DO

DO X = 1, DIS
DO Y = 1, TRA
DO Z = 1, ROWS
!  psd2(X,Y,Z) = 10 * log10(psd(X,Y,Z)/MAXVAL(psd(X,Y,:))) !Relative values
      
   psd2(X,Y,Z) = 10 * log10(psd(X,Y,Z)) !Absolute values

END DO
END DO
END DO

!======================================================================
!TO MAKE A GRAPH IN FREQUENCY DOMAIN SYMMETRIC
!!DO X = 1, DIS
!!     CALL f_symmetry( f_real(X, 1, :), ROWS3, f_real2(X, 1, :) )
!!     CALL f_symmetry( f_imag(X, 1, :), ROWS3, f_imag2(X, 1, :) )
!!     CALL f_symmetry( psd2(X, 1, :), ROWS3, psd3(X, 1, :) )
!!END DO
!======================================================================

!=======FFT_STACKED_A_SCOPE===============================
X=21
Y=1
DO Z = 1,ROWS
  ! WRITE(50,*) psd2(X,Y,Z) 

  WRITE(50,*) B_SCAN_IMAGE2(X,Y,Z), f_real(X,Y,Z), f_imag(X,Y,Z),&
                         psd2(X,Y,Z), ifft_real(X,Y,Z), ifft_imag(X,Y,Z) 
!  WRITE(50,'(6F20.10)') B_SCAN_IMAGE4(X,Y,Z), f_real2(X,Y,Z), f_imag2(X,Y,Z),&
!                         psd3(X,Y,Z), ifft_real(X,Y,Z), ifft_imag(X,Y,Z) 


END DO
!=========================================================

!=======FREQUENCY_TIME_DIAGRAM===============================
!X=21
Y=5

!DO X = 1, DIS
!  WRITE(51,*) (psd2(X,Y,Z), Z=1, ROWS)
!END DO

!=========================================================

!=======FREQUENCY_TIME_DIAGRAM===============================
!X=21
!Y=5

!DO Y = 1, TRA 
!  WRITE(51,*) (SUM( psd2(X,Y,26:80) ) / SIZE ( psd2(X,Y,26:80) ), X=1, DIS)
!END DO

DO X= 1, DIS 
  !WRITE(51,*) (SUM( psd2(X,Y,26:80) ) / SIZE ( psd2(X,Y,26:80) ), Y=1, TRA)
  WRITE(51,*) (MINVAL( psd2(X,Y,26:80)), Y=1, TRA)
END DO


!=========================================================




PRINT*, "COMPLETED TO PRINT FFT"
