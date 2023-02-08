!=====POWER=====
DO X = 1, DIS
DO Z = 1, ROWS
   bpf_power(X,1,Z) = SQRT(bpf_real(X,1,Z)**2 + bpf_imag(X,1,Z)**2)
END DO
END DO
!===============

!=====dB=====
DO X = 1, DIS
DO Z = 1, ROWS
   !bpf_powerdB(X,1,Z) = 10 *log10(bpf_power(X,1,Z)**2/(MAXVAL(bpf_power(X,1,:))**2))  !relative values
   bpf_powerdB(X,1,Z) = 10 *log10(bpf_power(X,1,Z))  !absolute values



END DO 
END DO
!============

!======================================================================
!TO MAKE A GRAPH IN FREQUENCY DOMAIN SYMMETRIC
!!DO X = 1, DIS
!!     CALL f_symmetry( bpf_real(X, 1, :), ROWS, bpf_real2(X, 1, :) )
!!     CALL f_symmetry( bpf_imag(X, 1, :), ROWS, bpf_imag2(X, 1, :) )
!!     CALL f_symmetry( bpf_powerdB(X, 1, :), ROWS, bpf_powerdB2(X, 1, :) )
!!END DO
!======================================================================


!=====HIGH-PASS FILTER=====
X = 2
DO Z = 1, ROWS
   WRITE(70,*) bpf_real(X,1,Z), bpf_imag(X,1,Z), filter(Z), bpf_powerdB(X,1,Z), ifft_real(X,1,Z)
!   WRITE(70,*) bpf_real2(X,1,Z), bpf_imag2(X,1,Z), filter(Z), bpf_powerdB2(X,1,Z), ifft_real(X,1,Z)
!   WRITE(70,*) bpf_real2(X,1,Z), bpf_imag2(X,1,Z), TW(Z), bpf_powerdB2(X,1,Z), ifft_real(X,1,Z)
END DO
!==========================

!=====GAIN-CONTROL=====
DO Z = 1, ROWS
DO X = 1, DIS
   bpf_GC(X,1,Z) = ifft_real(X,1,Z) / HILBERT_power2(X,1,Z)
END DO 
END DO
!======================

   CALL mean_ascanx(bpf_GC(:,1,:),DIS,ROWS,MEAN_A_SCOPE)

!   CALL mean_ascanx(ifft_real(:,1,:),DIS,ROWS,MEAN_A_SCOPE)


DO X = 1, DIS
DO Z = 1, ROWS
   bpf_GC_RMV(X,1,Z) = bpf_GC(X,1,Z) - MEAN_A_SCOPE(1,1,Z)
!   bpf_GC_RMV(X,1,Z) = ifft_real(X,1,Z) - MEAN_A_SCOPE(1,1,Z)
END DO 
END DO   

!=====HIGH-PASS FILTER=====
DO Z = 1, ROWS
!    WRITE(71,*) (bpf_GC_RMV(X,1,Z), X = 1, DIS)
   WRITE(71,*) (bpf_GC(X,1,Z), X = 1, DIS)
!    WRITE(71,*) (ifft_real(X,1,Z), X = 1, DIS)

END DO
!==========================
