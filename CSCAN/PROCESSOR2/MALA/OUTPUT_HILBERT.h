!POWER
DO I = 0, DIS2
DO J = 0, TRA2
DO Z = 0, ROWS2-1

   HILBERT_power(I,J,Z) = SQRT(HILBERT_B_SCAN(I,J,Z)**2 + B_SCAN_IMAGE2(I,J,Z)**2)

END DO 
END DO 
END DO 


!DECIBEL TO MEAN OF SLICE
!DO Z = 0, ROWS2-1
!     SLICE_MEAN2 = SUM(HILBERT_power(:,:,Z))/SIZE(HILBERT_power(:,:,Z)) 

!   DO I = 0, DIS2
!      DO J = 0, TRA2             

!      HILBERT_powerdB(I,J,Z) = 10 * log10( ((HILBERT_power(I,J,Z))**2)/ ((SLICE_MEAN2)**2) )   

!      END DO
!   END DO

!END DO

!dB to Max
DO I = 0, DIS2
DO J = 0, TRA2
DO Z = 0, ROWS2-1
   HILBERT_powerdB(I,J,Z) = 10 * log10( (HILBERT_power(I,J,Z)**2)/(MAXVAL(HILBERT_power(I,J,:))**2) )
END DO     
END DO 
END DO 

!just log

!DO I = 0, DIS2
!DO J = 0, TRA2
!DO Z = 0, ROWS2-1
  
!   HILBERT_powerlog(I,J,Z) = 10 * log10( HILBERT_power(I,J,Z)**2 )

!END DO     
!END DO 
!END DO 


!HILBERT_powerdB(10,3,:) = -1000000



!=====BSCAN====
!J = 15
I = 13
J = 50 

DO Z = 0, ROWS2-1
DO I = 0, DIS2

      WRITE (60,*) I, J, Z, HILBERT_powerdB(I,J,Z)
!       WRITE (60,*) I, J, Z, HILBERT_powerlog(I,J,Z)


END DO 
END DO 
!==========
PRINT *, "COMPELETE HILBERT_BSCAN_IMAGE OUTPUT"




!=====CSCAN====
Z = 150
DO J = 0, TRA2
DO I = 0, DIS2

       WRITE (61,*) I, J, Z, HILBERT_powerdB(I,J,Z)

END DO 
END DO 
!==========
PRINT *, "COMPELETE HILBERT_CSCAN_IMAGE OUTPUT"



!=====3DCUBE=====
DO Z = 0, ROWS2-1
DO J = 0, TRA2
DO I = 0, DIS2

       WRITE (62,*) I, J, Z, HILBERT_powerdB(I,J,Z)

END DO 
END DO 
END DO 
!==========
PRINT *, "COMPELETE HILBERT_3D_CUBE_IMAGE OUTPUT"


!=====PRINT FOR PRYTHON.HILBERT_3D_CUBE_IMAGE==
!J=ROWS 

!!DO Z = 1, ROWS
!!DO Y = 1, TRA
!!DO X = 1, DIS
!           WRITE (60,*) HILBERT_powerdB(X,Y,Z), X, Y, Z
!           WRITE (60,*) X, Y, Z, HILBERT_powerdB(X,Y,Z)
!           WRITE (60,*) X, Y, Z, HILBERT_powerlog(X,Y,Z)
!!           WRITE (60,*) HILBERT_powerlog(X,Y,Z), X, Y, Z

!!END DO 
!!END DO
!!END DO 

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
!     PRINT *, "COMPELETE HILBERT_3D_CUBE_IMAGE OUTPUT"
!=============================================


!PRINT *, char(7)


