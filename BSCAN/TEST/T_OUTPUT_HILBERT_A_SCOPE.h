!=======HILBERT_A_SCOPE===============================
!X=DIS
!Y=TRA
!Z=ROWS

DO Y = 1, TRA
   DO Z =1, ROWS
      HILBERT_B_SCAN(1,Y,Z) = 10 * log10( HILBERT_B_SCAN(1,Y,Z)**2 )
   END DO
END DO

DO Z = 1,ROWS
            WRITE(25,*) (HILBERT_B_SCAN(1,Y,Z), Y = 1,TRA)
END DO
!=====================================================
