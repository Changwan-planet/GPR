!=======HILBERT_B_SCAN===============================
!X=DIS
!Y=TRA
!Z=ROWS

DO Z = 1,ROWS
            WRITE(34,*) (HILBERT_B_SCAN(1,Y,Z), Y = 1,TRA)
END DO
!=====================================================
