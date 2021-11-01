
!DECIBEL
DO X = 1, DIS
   DO Y = 1, TRA
      DO Z = 1, ROWS
!         HILBERT_B_SCAN(X,Y,Z) = HILBERT_B_SCAN(X,Y,Z)**2
         HILBERT_B_SCAN(X,Y,Z) = 10 * log10(HILBERT_B_SCAN(X,Y,Z)**2)
      END DO
    END DO
END DO


!=====HILBERT_3D_CUBE_IMAGE============================
!J=ROWS 
      DO X = 1, DIS
         DO Y = 1, TRA
            WRITE (24,*) (HILBERT_B_SCAN(X,Y,Z), Z = 1, ROWS)
         END DO 
      END DO

!==>  THIS STRUCTURE (X x Y) X Z CAN BE PRINTED. 
!==>  (X x Y) IS THE C_SCAN.
!     PRINT *, "COMPLETE HILBERT_3D_CUBE_IMAGE OUPUT"
!=============================================

PRINT *, char(7)


