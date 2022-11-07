!POWER
!INSTANTNEOUS POWER
DO X = 1, DIS
DO Y = 1, TRA
DO Z = 1, ROWS
      HILBERT_power(X,Y,Z) = SQRT(HILBERT_B_SCAN(X,Y,Z)**2 + B_SCAN_IMAGE4(X,Y,Z)**2)
END DO 
END DO 
END DO

!DECIBEL
DO X = 1, DIS             
DO Z = 1, ROWS           

!  HILBERT_powerdB(X,1,Z) = 10 * log10( HILBERT_power(X,1,Z)**2/(MAXVAL(HILBERT_power(X,1,:))**2))      
  HILBERT_powerdB(X,1,Z) = 10 * log10( HILBERT_power(X,1,Z)/MAXVAL(HILBERT_power(X,1,:)))      


END DO
END DO


!=====HILBERT_powerdB============================
       DO Z = 1, ROWS
            WRITE (50,*) (HILBERT_powerdB(X,1,Z), X = 1, DIS)
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


