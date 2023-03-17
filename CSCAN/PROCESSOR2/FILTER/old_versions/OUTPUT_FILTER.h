!=====POWER=====
DO X = 1, DIS
DO Y = 1, TRA
DO Z = 1, ROWS2
   bpf_power(X,Y,Z) = SQRT(bpf_real(X,Y,Z)**2 + bpf_imag(X,Y,Z)**2)
END DO
END DO
END DO 
!===============

!=====dB=====
DO X = 1, DIS
DO Y = 1, TRA
DO Z = 1, ROWS2
   !bpf_powerdB(X,Y,Z) = 10 *log10(bpf_power(X,Y,Z)**2/(MAXVAL(bpf_power(X,Y,:))**2))  !relative values
   bpf_powerdB(X,Y,Z) = 10 *log10(bpf_power(X,Y,Z))  !absolute values

END DO 
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


!=====BAND-PASS FILTER=====
X = 2
DO Z = 1, ROWS2
   WRITE(80,*) bpf_real(X,1,Z), bpf_imag(X,1,Z), filter(Z), bpf_powerdB(X,1,Z), ifft_real(X,1,Z)
!   WRITE(80,*) bpf_real2(X,1,Z), bpf_imag2(X,1,Z), filter(Z), bpf_powerdB2(X,1,Z), ifft_real(X,1,Z)
!   WRITE(80,*) bpf_real2(X,1,Z), bpf_imag2(X,1,Z), TW(Z), bpf_powerdB2(X,1,Z), ifft_real(X,1,Z)
END DO
!==========================

!=====GAIN-CONTROL=====
DO Z = 1, ROWS3
DO Y = 1, TRA
DO X = 1, DIS
   bpf_GC(X,Y,Z) = ifft_real(X,Y,Z) / HILBERT_power2(X,Y,Z)
END DO 
END DO
END DO 
!======================

!   CALL mean_ascanx(bpf_GC(:,1,:),DIS,ROWS,MEAN_A_SCOPE)
!   CALL mean_ascanx(ifft_real(:,1,:),DIS,ROWS,MEAN_A_SCOPE)


!DO X = 1, DIS
!DO Z = 1, ROWS3
!   bpf_GC_RMV(X,1,Z) = bpf_GC(X,1,Z) - MEAN_A_SCOPE(1,1,Z)
!   bpf_GC_RMV(X,1,Z) = ifft_real(X,1,Z) - MEAN_A_SCOPE(1,1,Z)
!END DO 
!END DO   

!=====BAND-PASS FILTER-python=====
DO X = 1, DIS
   DO Y = 1, TRA 
!    WRITE(81,*) (bpf_GC_RMV(X,Y,Z), Z = 1, ROWS3)
     WRITE(81,*) (bpf_GC(X,Y,Z), Z = 1, ROWS3)
!    WRITE(81,*) (ifft_real(X,Y,Z), Z = 1, ROWS3)
END DO
END DO
!==========================

!=====BAND-PASS FILTER-python=====
!DO Z = 1, ROWS3
!   DO Y = 1, TRA 
!    WRITE(81,*) (bpf_GC_RMV(X,Y,Z), X = 1, DIS)
!     WRITE(81,*) (bpf_GC(X,Y,Z), X = 1, DIS)
!    WRITE(81,*) (ifft_real(X,Y,Z), X = 1, DIS)
!END DO
!END DO
!==========================
