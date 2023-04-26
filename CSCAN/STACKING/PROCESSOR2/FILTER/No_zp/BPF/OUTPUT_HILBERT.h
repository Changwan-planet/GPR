!POWER
DO X = 1, TRA
DO Y = 1, LINE
DO Z = 1, ROWS
      HILBERT_power(X,Y,Z) = SQRT(HILBERT_B_SCAN(X,Y,Z)**2 + B_SCAN_IMAGE8(X,Y,Z)**2)
END DO 
END DO 
END DO 


!DECIBEL TO MEAN OF SLICE
!DO Z = 1, ROWS
!     SLICE_MEAN2 = SUM(HILBERT_power(:,:,Z))/SIZE(HILBERT_power(:,:,Z)) 

!   DO X = 1, TRA
!      DO Y = 1, LINE             

!      HILBERT_powerdB(X,Y,Z) = 10 * log10( ((HILBERT_power(X,Y,Z))**2)/ ((SLICE_MEAN2)**2) )   

!      END DO
!   END DO

!END DO

!dB to Max
DO X = 1, TRA
DO Y = 1, LINE
DO Z = 1,  ROWS
  
   HILBERT_powerdB(X,Y,Z) = 10 * log10( (HILBERT_power(X,Y,Z)**2)/(MAXVAL(HILBERT_power(X,Y,:))**2) )

END DO     
END DO 
END DO 

!just log
!DO X = 1, TRA
!DO Y = 1, LINE
!DO Z = 1,  ROWS
  
!   HILBERT_powerlog(X,Y,Z) = 10 * log10( HILBERT_power(X,Y,Z) )

!END DO     
!END DO 
!END DO 


!=====PRINT FOR PRYTHON.HILBERT_3D_CUBE_IMAGE==
!J=ROWS 
      DO X = 1, TRA
        DO Y = 1, LINE
!            WRITE (60,*) (HILBERT_power(X,Y,Z), Z = 1, ROWS)
            WRITE (60,*) (HILBERT_powerdB(X,Y,Z), Z = 1, ROWS)
!            WRITE (60,*) (HILBERT_powerlog(X,Y,Z), Z = 1, ROWS)
!            WRITE (60,*) (HILBERT_B_SCAN(X,Y,Z), Z = 1, ROWS)

         END DO 
      END DO

!==>  THIS STRUCTURE (F x Y) X Z CAN BE PRINTED. 
!==>  (F x Y) IS THE C_SCAN.
!=============================================


!=====PRINT FOR GNUPLOT.HILBERT_3D_CUBE_IMAGE==
!J=ROWS 

!!     DO X = 1, LINE
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


