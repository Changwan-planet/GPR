!DECIBEL
DO Z=1,ROWS
!Z=1
   !HILBERT_B_SCAN(:,:,Z) = HILBERT_B_SCAN(:,:,Z)**2
   !MAX_SLICE = MAXVAL(HILBERT_B_SCAN(:,:,Z)) 
    SLICE_MEAN2 = SUM(HILBERT_B_SCAN(:,:,Z))/SIZE(HILBERT_B_SCAN(:,:,Z)) 


!   WRITE(25,*) HILBERT_B_SCAN(:,:,Z)
!   PRINT *, HILBERT_B_SCAN(:,:,Z)               
!   PRINT *, MAX_SLICE
  
   DO X = 1, DIS
      DO Y = 1, TRA             

!         HILBERT_B_SCAN(X,Y,Z) = 10 * log10((HILBERT_B_SCAN(X,Y,Z))/(MAX_SLICE))      
         HILBERT_B_SCAN(X,Y,Z) = 10 * log10( ((HILBERT_B_SCAN(X,Y,Z))**2) / ((SLICE_MEAN2)**2))      

      END DO
   END DO

! WRITE(25,*) HILBERT_B_SCAN(:,:,Z)
!
!   MAX_SLICE = MAXVAL(HILBERT_B_SCAN(:,:,Z)) 
   PRINT *, SLICE_MEAN2

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


