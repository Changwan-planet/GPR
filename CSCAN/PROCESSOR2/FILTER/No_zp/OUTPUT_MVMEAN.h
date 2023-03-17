

!POWER

DO X = 1, DIS
DO Y = 1, TRA
DO Z = 1, ROWS

      HILBERT_power(X,Y,Z) = SQRT(HILBERT_B_SCAN(X,Y,Z)**2 + B_SCAN_IMAGE4(X,Y,Z)**2)

END DO 
END DO 
END DO 


!DECIBEL
DO Z = 1, ROWS
 
     SLICE_MEAN2 = SUM(HILBERT_power(:,:,Z))/SIZE(HILBERT_power(:,:,Z)) 
 
   DO X = 1, DIS
      DO Y = 1, TRA             

      HILBERT_powerdB(X,Y,Z) = 10 * log10( ((HILBERT_power(X,Y,Z))**2)/ ((SLICE_MEAN2)**2) )   

      END DO
   END DO

END DO

!=====HILBERT_3D_CUBE_IMAGE============================
!J=ROWS 
      DO X = 1, DIS
        DO Y = 1, TRA
            WRITE (50,*) (HILBERT_powerdB(X,Y,Z), Z = 1, ROWS)
         END DO 
      END DO

!==>  THIS STRUCTURE (F x Y) X Z CAN BE PRINTED. 
!==>  (F x Y) IS THE C_SCAN.
     PRINT *, "COMPLETE HILBERT_3D_CUBE_IMAGE OUTPUT"
!=============================================

!PRINT *, char(7)


