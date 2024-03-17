!POWER
DO I = 0, DIS2-1
DO J = 0, TRA-1
DO Z = 0, ROWS-1

   HILBERT_power(I,J,Z) = SQRT(HILBERT_B_SCAN(I,J,Z)**2 + B_SCAN_IMAGE2(I,J,Z)**2)

END DO 
END DO 
END DO 


!DECIBEL TO MEAN OF SLICE
DO Z = 0, ROWS-1
     SLICE_MEAN2 = SUM(HILBERT_power(:,:,Z))/SIZE(HILBERT_power(:,:,Z)) 

   DO I = 0, DIS2-1
      DO J = 0, TRA-1             

      HILBERT_powerdB(I,J,Z) = 10 * log10( ((HILBERT_power(I,J,Z))**2)/ ((SLICE_MEAN2)**2) )   

      END DO
   END DO

END DO

!dB to Max
!DO I = 0, DIS2-1
!DO J = 0, TRA-1
!DO Z = 0, ROWS-1
!   HILBERT_powerdB(I,J,Z) = 10 * log10( (HILBERT_power(I,J,Z)**2)/(MAXVAL(HILBERT_power(I,J,:))**2) )
!END DO     
!END DO 
!END DO 

!just log

!DO I = 0, DIS2-1
!DO J = 0, TRA-1
!DO Z = 0, ROWS-1
  
!   HILBERT_powerlog(I,J,Z) = 10 * log10( HILBERT_power(I,J,Z)**2 )

!END DO     
!END DO 
!END DO 


!HILBERT_powerdB(10,3,:) = -1000000



!=====BSCAN====
!J = 15
I = 13
J = 50 

DO Z = 0, ROWS-1
DO I = 0, DIS2-1

      WRITE (60,*) I, J, Z, HILBERT_powerdB(I,J,Z)
!       WRITE (60,*) I, J, Z, HILBERT_powerlog(I,J,Z)


END DO 
END DO 
!==========
PRINT *, "COMPELETE HILBERT_BSCAN_IMAGE OUTPUT"




!=====CSCAN====
Z = 150
DO J = 0, TRA-1
DO I = 0, DIS2-1

       WRITE (61,*) I, J, Z, HILBERT_powerdB(I,J,Z)

END DO 
END DO 
!==========
PRINT *, "COMPELETE HILBERT_CSCAN_IMAGE OUTPUT"



!=====3DCUBE=====
DO Z = 0, ROWS-1
DO J = 0, TRA-1
DO I = 0, DIS2-1

!       WRITE (62,*) I, J, Z, HILBERT_powerdB(I,J,Z)
       WRITE (62,*) I, J, Z, HILBERT_power(I,J,Z)


END DO 
END DO 
END DO 
!==========
PRINT *, "COMPELETE HILBERT_3D_CUBE_IMAGE OUTPUT"


