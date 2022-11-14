!!POWER


DO Y = 1, TRA
DO Z = 1, ROWS

      HILBERT_STACKED_power(1,Y,Z) = SQRT(HILBERT_STACKED_B_SCAN(1,Y,Z)**2 + STACKED_B_SCAN(1,Y,Z)**2)

END DO 
END DO 


!DECIBEL
DO Y = 1, TRA
     MAX_ASCAN = MAXVAL(HILBERT_STACKED_power(1,Y,:)) 
      DO Z = 1, ROWS          
       HILBERT_STACKED_powerdB(1,Y,Z) = 10 * log10(((HILBERT_STACKED_power(1,Y,Z))**2)/(MAX_ASCAN**2))
      END DO
END DO

!=======INSTANTNEOUS_POWERdB_B_SCAN===============================
   DO Z = 1,ROWS
            WRITE(35,*) (HILBERT_STACKED_powerdB(1,Y,Z), Y = 1,TRA) 
            !WRITE(35,*) (HILBERT_STACKED_power(1,Y,Z), Y = TRA,1,-1) 
   END DO
!=====================================================
