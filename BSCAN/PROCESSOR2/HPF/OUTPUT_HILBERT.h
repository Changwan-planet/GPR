!POWER
!INSTANTNEOUS POWER
DO X = 1, DIS
DO Z = 1, ROWS
      HILBERT_power(X,1,Z) = SQRT(HILBERT_B_SCAN(X,1,Z)**2 + B_SCAN_IMAGE4(X,1,Z)**2)
END DO 
END DO 
 

!DECIBEL
DO X = 1, DIS             
DO Z = 1, ROWS           

  HILBERT_powerdB(X,1,Z) = 10 * log10( HILBERT_power(X,1,Z)**2/(MAXVAL(HILBERT_power(X,1,:))**2))           
!   HILBERT_powerdB(X,1,Z) = 10 * log10( HILBERT_power(X,1,Z)**2/((SUM(HILBERT_power(:,1,Z))/SIZE(HILBERT_power(:,1,Z)))**2))      



END DO
END DO



!CALL flip_2d(HILBERT_powerdB,DIS,ROWS2,HILBERT_powerdB2)

DIS2 = 1498


!=====HILBERT_powerdB============================
       DO Z = 1, ROWS
!            WRITE (50,*) (HILBERT_powerdB2(X,1,Z), X = 1, DIS2)
            WRITE (50,*) (HILBERT_powerdB(X,1,Z), X = 1, DIS2)
       END DO 

     PRINT *, "COMPLETE HILBERT_BSCAN_IMAGE OUTPUT"
!=============================================

!=====INSTANTNEOUS_power_SMOOTHING_MOVING AVERAGE=============
       DO Z = 1, ROWS2
            !WRITE (51,*) (SQRT(HILBERT_power2(X,1,Z)), X = 1, DIS)
            WRITE (51,*) (HILBERT_power2(X,1,Z), X = 1, DIS)
       
       END DO 
!     PRINT *, "COMPLETE HILBERT_BSCAN_IMAGE OUTPUT"
!=============================================================


