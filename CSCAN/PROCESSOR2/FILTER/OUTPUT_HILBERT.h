!POWER

DO X = 1, DIS
DO Y = 1, TRA
DO Z = 1, ROWS3

      HILBERT_power(X,Y,Z) = SQRT(HILBERT_B_SCAN(X,Y,Z)**2 + B_SCAN_IMAGE6(X,Y,Z)**2)

END DO 
END DO 
END DO 

!DECIBEL referred to Max
DO X = 1, DIS             
DO Z = 1, ROWS3           

  HILBERT_powerdB(X,1,Z) = 10 * log10( HILBERT_power(X,1,Z)/(MAXVAL(HILBERT_power(X,1,:))))      

END DO
END DO

!DECIBEL referred to MEAN
!!DO Z = 1, ROWS3
!!      SLICE_MEAN2 = SUM(HILBERT_power(:,:,Z))/SIZE(HILBERT_power(:,:,Z)) 
 
!!   DO X = 1, DIS
!!      DO Y = 1, TRA             

!!      HILBERT_powerdB(X,Y,Z) = 10 * log10( ((HILBERT_power(X,Y,Z))**2)/ ((SLICE_MEAN2)**2) )   

!!      END DO
!!   END DO

!!END DO


!=====PRINT FOR PYTHON.HILBERT_3D_CUBE_IMAGE==
!J=ROWS 
!      DO X = 1, DIS
!        DO Y = 1, TRA
!            WRITE (60,*) (HILBERT_powerdB(X,Y,Z), Z = 1, ROWS3)
!         END DO 
!      END DO

!      DO Z = ROWS3, 1, -1
      DO Z = 1,ROWS3


        DO Y = 1, TRA
            WRITE (60,*) (HILBERT_powerdB(X,Y,Z), X = 1, DIS)
         END DO 
      END DO


!==>  THIS STRUCTURE (F x Y) X Z CAN BE PRINTED. 
!==>  (F x Y) IS THE C_SCAN.
!=============================================


!=====PRINT FOR GNUPLOT.HILBERT_3D_CUBE_IMAGE==
!J=ROWS 

!!     DO X = 1, DIS
!      DO X = 1, 100
!!        DO Y = 1, TRA
!        DO Y = 1, 4
!!            WRITE (60,*) (HILBERT_powerdB(X,Y,Z), Z = 1, ROWS3)
!            WRITE (60,*) (HILBERT_powerdB(X,Y,Z), Z = 100, 101)
!!         END DO 
!!      END DO

!==>  THIS STRUCTURE (F x Y) X Z CAN BE PRINTED. 
!==>  (F x Y) IS THE C_SCAN.
!=============================================

!=====PRINT FOR GNUPLOT.HILBERT_3D_CUBE_IMAGE=====
!=====CONSIDERED INTEGRATION FROM MOVING AVERAGE=====
!J=ROWS 

!!     DO X = 1, MV_DIS
!!        DO Y = 1, MV_TRA
!!            WRITE (61,*) (HILBERT_powerdB(X,Y,Z), Z = 1, ROWS3)
!!         END DO 
!!      END DO

!==>  THIS STRUCTURE (F x Y) X Z CAN BE PRINTED. 
!==>  (F x Y) IS THE C_SCAN.
     PRINT *, "COMPLETE HILBERT_3D_CUBE_IMAGE OUTPUT"
!=============================================


!PRINT *, char(7)


