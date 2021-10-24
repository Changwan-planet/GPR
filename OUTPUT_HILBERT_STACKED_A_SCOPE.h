!=======HILBERT_STACKED_A_SCOPE===============================
!DECIBEL
DO Y = 1, TRA
   DO Z = 1, ROWS
       HILBERT_STACKED_B_SCAN(1,Y,Z) = 10 * log10(HILBERT_STACKED_B_SCAN(1,Y,Z)**2)
   END DO

END DO


   DO Z = 1,ROWS
            WRITE(26,*) (HILBERT_STACKED_B_SCAN(1,Y,Z), Y = 1,TRA) 
   END DO

!=====================================================
