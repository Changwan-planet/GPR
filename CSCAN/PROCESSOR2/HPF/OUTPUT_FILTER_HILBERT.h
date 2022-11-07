!=====POWER=====
DO X = 1, DIS
DO Y = 1, TRA
DO Z = 1, ROWS
   hpf_power(X,Y,Z) = SQRT(hpf_real(X,Y,Z)**2 + hpf_imag(X,Y,Z)**2)
END DO
END DO
END DO 
!===============

!=====dB=====
DO X = 1, DIS
DO Y = 1, TRA
DO Z = 1, ROWS
!   hpf_powerdB(X,1,Z) = 10 *log10(hpf_power(X,1,Z)**2/(MAXVAL(hpf_power(X,1,:))**2))
   hpf_powerdB(X,1,Z) = 10 *log10(hpf_power(X,1,Z)**2)


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
DO Z = 1, ROWS
   WRITE(70,*) hpf_real(X,1,Z), hpf_imag(X,1,Z), filter(Z), hpf_powerdB(X,1,Z), ifft_real(X,1,Z)
!   WRITE(70,*) hpf_real2(X,1,Z), hpf_imag2(X,1,Z), filter(Z), hpf_powerdB2(X,1,Z), ifft_real(X,1,Z)
!   WRITE(70,*) hpf_real2(X,1,Z), hpf_imag2(X,1,Z), TW(Z), hpf_powerdB2(X,1,Z), ifft_real(X,1,Z)
END DO
!==========================

!=====GAIN-CONTROL=====
DO Z = 1, ROWS
DO Y = 1, TRA
DO X = 1, DIS
   hpf_GC(X,Y,Z) = ifft_real(X,Y,Z) / HILBERT_power2(X,Y,Z)
END DO 
END DO
END DO 
!======================

   CALL mean_ascanx(hpf_GC(:,1,:),DIS,ROWS,MEAN_A_SCOPE)

!   CALL mean_ascanx(ifft_real(:,1,:),DIS,ROWS,MEAN_A_SCOPE)


DO X = 1, DIS
DO Y = 1, TRA
DO Z = 1, ROWS
   hpf_GC_RMV(X,Y,Z) = hpf_GC(X,Y,Z) - MEAN_A_SCOPE(1,Y,Z)
!   hpf_GC_RMV(X,1,Z) = ifft_real(X,1,Z) - MEAN_A_SCOPE(1,1,Z)
END DO 
END DO   
END DO


!DIS = 1498

!FLIP THE BSCAN IMAGE
DO Y = 1, TRA
	CALL flip_2d(hpf_GC(:,Y,:),DIS,ROWS,hpf_GC2(:,Y,:))
END DO 


!=====HIGH-PASS FILTER=====
DO Y = 1, TRA
DO Z = 1, ROWS
!    WRITE(71,*) (hpf_GC_RMV(X,1,Z), X = 1, DIS)
   WRITE(71,*) (hpf_GC2(X,Y,Z), X = 1, DIS)
!    WRITE(71,*) (ifft_real(X,1,Z), X = 1, DIS)
END DO
END DO 
!==========================
