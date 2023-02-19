!=====POWER=====
DO X = 1, DIS
DO Z = 1, ROWS
   hpf_power(X,1,Z) = SQRT(hpf_real(X,1,Z)**2 + hpf_imag(X,1,Z)**2)
END DO
END DO
!===============

!=====dB=====
DO X = 1, DIS
DO Z = 1, ROWS
   hpf_powerdB(X,1,Z) = 10 *log10(hpf_power(X,1,Z)**2)  !ABSOLUTE VALUES
!   hpf_powerdB(X,1,Z) = 10 *log10(hpf_power(X,1,Z)**2/(MAXVAL(hpf_power(X,1,:))**2))
!   hpf_powerdB(X,1,Z) = 10 *log10(hpf_power(X,1,Z)/MAXVAL(hpf_power(X,1,:)))


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

!DO Z = 1, ROWS2
!   PRINT*, Z, HILBERT_power2(1,1,Z)
!END DO 

!=====GAIN-CONTROL=====
!DO Z = 1, ROWS
DO Z = 1, ROWS2
DO X = 1, DIS
   hpf_GC(X,1,Z) = ifft_real(X,1,Z) / HILBERT_power2(X,1,Z)
END DO 
END DO
!======================
DO X = 1, DIS
!   IF(hpf_GC(X,1,1) /= hpf_GC(X,1,1)) PRINT*, X, hpf_GC(X,1,1)
   IF(hpf_GC(X,1,1) /= hpf_GC(X,1,1)) hpf_GC(X,1,:) = 0.0
END DO 

!  CALL mean_ascanx(hpf_GC(:,1,:),DIS,ROWS,MEAN_A_SCOPE)
   CALL mean_ascanx(hpf_GC(:,1,:),DIS,ROWS2,MEAN_A_SCOPE)
!  CALL mean_ascanx(ifft_real(:,1,:),DIS,ROWS,MEAN_A_SCOPE)


DO X = 1, DIS
!DO Z = 1, ROWS
DO Z = 1, ROWS2
   hpf_GC_RMV(X,1,Z) = hpf_GC(X,1,Z) - MEAN_A_SCOPE(1,1,Z)
!   hpf_GC_RMV(X,1,Z) = ifft_real(X,1,Z) - MEAN_A_SCOPE(1,1,Z)
END DO 
END DO   

!FLIP THE BSCAN IMAGE
!CALL flip_2d(hpf_GC,DIS,ROWS,hpf_GC2)

!CALL flip_2d(hpf_GC_RMV,DIS,ROWS2,hpf_GC_RMV2)


!DIS2 = 1498

!=====HIGH-PASS FILTER=====
DO Z = 1, ROWS2

!    WRITE(71,*) (hpf_GC_RMV(X,1,Z), X = 1, DIS)
!    WRITE(71,*) (ifft_real(X,1,Z), X = 1, DIS)
   WRITE(71,*) (hpf_GC(X,1,Z), X = 1, DIS)



!    WRITE(71,*) (hpf_GC_RMV(X,1,Z), X = 1, DIS2)
!    WRITE(71,*) (hpf_GC_RMV2(X,1,Z), X = 1, DIS2)



!   WRITE(71,*) (hpf_GC2(X,1,Z), X = 1, DIS2)
!   WRITE(71,*) (hpf_GC(X,1,Z), X = 1, DIS2)

END DO
!==========================
