!!DO Y = 1, TRA
!!   DO Z = 1, ROWS
!!
!!      psd(1,Y,Z) = 10 * log10(f_real(1,Y,Z)**2 + f_imag(1,Y,Z)**2)
!!   END DO
!!END DO


!======================================================================
!TO MAKE A GRAPH OF THE PSD WITH SYMMETRY
!!DO Y = 1, TRA
!!   DO Z = 1, ROWS/2
!!      psd2(1, Y, Z) = psd(1, Y, Z+ROWS/2)
!!   END DO
!!END DO

!!DO Y = 1, TRA
!!   DO Z = ROWS/2+1, ROWS
!!      psd2(1, Y, Z) = psd(1, Y, Z-ROWS/2)
!!   END DO
!!END DO
!======================================================================

!=======FFT_STACKED_A_SCOPE===============================
!!Y=10
!!DO Z = 1,ROWS
!!           WRITE(24,*) f_real(1,Y,Z),    f_imag(1,Y,Z), &
!!                         psd2(1,Y,Z), ifft_real(1,Y,Z), Ifft_imag(1,Y,Z) 
!!END DO
!=========================================================


