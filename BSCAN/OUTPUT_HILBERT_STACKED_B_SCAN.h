!=======HILBERT_STACKED_B_SCAN===============================
   DO Z = 1,ROWS
            WRITE(35,*) (HILBERT_STACKED_B_SCAN(1,Y,Z), Y = 1,TRA) 
            !WRITE(35,*) (HILBERT_STACKED_B_SCAN(1,Y,Z), Y = TRA,1,-1) 
   END DO
!=====================================================
