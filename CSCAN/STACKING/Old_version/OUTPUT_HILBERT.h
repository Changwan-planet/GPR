!POWER

DO F = 1, LINE
DO Y = 1, TRA
DO Z = 1, ROWS

      HILBERT_STACKED_power(F,Y,Z) = SQRT(HILBERT_STACKED_B_SCAN(F,Y,Z)**2 + STACKED_B_SCAN(F,Y,Z)**2)

END DO 
END DO 
END DO 


!DECIBEL
DO Z = 1, ROWS
 
     SLICE_MEAN2 = SUM(HILBERT_STACKED_power(:,:,Z))/SIZE(HILBERT_STACKED_power(:,:,Z)) 
 
   DO F = 1, LINE
      DO Y = 1, TRA             

         HILBERT_STACKED_powerdB(F,Y,Z) = 10 * log10( ((HILBERT_STACKED_power(F,Y,Z))**2)/ ((SLICE_MEAN2)**2) )      

      END DO
   END DO

END DO

!=====HILBERT_3D_CUBE_IMAGE============================
!J=ROWS 
      DO F = 1, LINE
        DO Y = 1, TRA
            WRITE (50,*) (HILBERT_STACKED_powerdB(F,Y,Z), Z = 1, ROWS)
         END DO 
      END DO

!==>  THIS STRUCTURE (F x Y) X Z CAN BE PRINTED. 
!==>  (F x Y) IS THE C_SCAN.
     PRINT *, "COMPLETE HILBERT_3D_CUBE_IMAGE OUTPUT"
!=============================================

PRINT *, char(7)


