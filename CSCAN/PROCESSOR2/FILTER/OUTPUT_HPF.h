!=====POWER=====
DO X = 1, DIS
DO Y = 1, TRA
DO Z = 1, ROWS3
   hpf_power(X,Y,Z) = SQRT(hpf_real(X,Y,Z)**2 + hpf_imag(X,Y,Z)**2)
END DO
END DO
END DO 
!===============

!=====dB=====
DO X = 1, DIS
DO Y = 1, TRA
DO Z = 1, ROWS3
   !hpf_powerdB(X,Y,Z) = 10 *log10(hpf_power(X,Y,Z)**2/(MAXVAL(hpf_power(X,Y,:))**2))  !relative values
   hpf_powerdB(X,Y,Z) = 10 *log10(hpf_power(X,Y,Z)**2)  !absolute values

END DO 
END DO
END DO
!============

!======================================================================
!TO MAKE A GRAPH IN FREQUENCY DOMAIN SYMMETRIC
!!DO X = 1, DIS
!!     CALL f_symmetry( hpf_real(X, 1, :), ROWS, hpf_real2(X, 1, :) )
!!     CALL f_symmetry( hpf_imag(X, 1, :), ROWS, hpf_imag2(X, 1, :) )
!!     CALL f_symmetry( hpf_powerdB(X, 1, :), ROWS, hpf_powerdB2(X, 1, :) )
!!END DO
!======================================================================


!=====HIGH-PASS FILTER=====
X = 1
DO Z = 1, ROWS3
   WRITE(85,*) hpf_real(X,1,Z), hpf_imag(X,1,Z), filter(Z), hpf_powerdB(X,1,Z), ifft_real(X,1,Z)
!   WRITE(85,*) hpf_real2(X,1,Z), hpf_imag2(X,1,Z), filter(Z), hpf_powerdB2(X,1,Z), ifft_real(X,1,Z)
!   WRITE(85,*) hpf_real2(X,1,Z), hpf_imag2(X,1,Z), TW(Z), hpf_powerdB2(X,1,Z), ifft_real(X,1,Z)
END DO
!==========================

!=====GAIN-CONTROL=====
!DO Z = 1, ROWS4
!DO Y = 1, TRA
!DO X = 1, DIS
!   hpf_GC(X,Y,Z) = ifft_real(X,Y,Z) / HILBERT_power2(X,Y,Z)
!END DO 
!END DO
!END DO 
!======================

!   CALL mean_ascanx(hpf_GC(:,1,:),DIS,ROWS,MEAN_A_SCOPE)
!   CALL mean_ascanx(ifft_real(:,1,:),DIS,ROWS,MEAN_A_SCOPE)


!DO X = 1, DIS
!DO Z = 1, ROWS4
!   hpf_GC_RMV(X,1,Z) = hpf_GC(X,1,Z) - MEAN_A_SCOPE(1,1,Z)
!   hpf_GC_RMV(X,1,Z) = ifft_real(X,1,Z) - MEAN_A_SCOPE(1,1,Z)
!END DO 
!END DO   

!=====HIGH-PASS FILTER-python=====
!DO X = 1, DIS
!   DO Y = 1, TRA 
!    WRITE(86,*) (hpf_GC_RMV(X,Y,Z), Z = 1, ROWS4)
!     WRITE(86,*) (hpf_GC(X,Y,Z), Z = 1, ROWS4)
!    WRITE(86,*) (ifft_real(X,Y,Z), Z = 1, ROWS4)
!END DO
!END DO
!=================================

!=====HIGH-PASS FILTER-python=====
!DO Z = 1, ROWS4
!   DO Y = 1, TRA 
!    WRITE(86,*) (hpf_GC_RMV(X,Y,Z), X = 1, DIS)
!     WRITE(86,*) (hpf_GC(X,Y,Z), X = 1, DIS)
!    WRITE(86,*) (ifft_real(X,Y,Z), X = 1, DIS)
!END DO
!END DO
!=================================

!=====HIGH-PASS POWER-python=====
!DO Z = 1, ROWS4
!   DO Y = 1, TRA 
!      WRITE(86,*) (hpf_powerdB(X,Y,Z), X = 1, DIS)
!   END DO
!END DO
!=================================


PRINT*, "COMPLETED TO PRINT FILTER"
