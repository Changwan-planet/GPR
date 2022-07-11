!POWER
!INSTANTNEOUS AMPLITUDE

DO Y = 1, TRA
DO Z = 1, ROWS

      HILBERT_STACKED_power(1,Y,Z) = SQRT(HILBERT_STACKED_B_SCAN(1,Y,Z)**2 + STACKED_B_SCAN(1,Y,Z)**2)

END DO 
END DO 
 


!DECIBEL
DO Y = 1, TRA             
DO Z = 1, ROWS           

  HILBERT_STACKED_powerdB(1,Y,Z) = 10 * log10( HILBERT_STACKED_power(1,Y,Z)/(MAXVAL(HILBERT_STACKED_power(1,Y,:))))      

END DO
END DO


!=====HILBERT_BSCAN_IMAGE============================
       DO Z = 1, ROWS
            WRITE (50,*) (HILBERT_STACKED_powerdB(1,Y,Z), Y = 1, TRA)
         END DO 

     PRINT *, "COMPLETE HILBERT_BSCAN_IMAGE OUTPUT"
!=============================================

!=====INSTANTNEOUS_power_SMOOTHING_MOVING AVERAGE=============
        DO Z = 1, ROWS2
             !WRITE (51,*) (SQRT(HILBERT_power2(1,Y,Z)), Y = 1, TRA)
             WRITE (51,*) (HILBERT_STACKED_power2(1,Y,Z), Y = 1, TRA)
 
        END DO
!     PRINT *, "COMPLETE HILBERT_BSCAN_IMAGE OUTPUT"
!=============================================================


!PRINT *, char(7)


