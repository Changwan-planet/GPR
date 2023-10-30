!=======A-SCOPE============================


!AFTER AUGEMNTING
I = 13
J = 50
   DO Z=0,ROWS-1
       WRITE(20,*) I,J,Z,B_SCAN_IMAGE5(I,J,Z)  
   END DO  

!NO DATA AUGMENTATION
!X = 65
X = 75

Y = 250


CALL fft_hilbert(B_SCAN_IMAGE4(X,Y,0:511) , 512, TEMP)

DO Z=0,511
   TEMP2(Z) = SQRT(TEMP(Z)**2 + B_SCAN_IMAGE4(X,Y,Z)**2)
END DO

DO Z=0,511

   TEMP3(Z) = 10 * log10( TEMP2(Z)**2)

!   TEMP3(Z) = 10 * log10( TEMP2(Z)**2/(MAXVAL(TEMP(:))**2) )

END DO



!   DO Z=0,ROWS-1
   DO Z=0,511

!      WRITE(21,*) X,Y,Z,B_SCAN_IMAGE_H(X,Y,Z), B_SCAN_IMAGE_V(X,Y,Z), B_SCAN_IMAGE4(X,Y,Z), B_SCAN_IMAGE3(X,Y,Z)  
   WRITE(21,*) X, Y, Z, B_SCAN_IMAGE_H(X,Y,Z), B_SCAN_IMAGE_V(X,Y,Z), B_SCAN_IMAGE2(X,Y,Z), &
               B_SCAN_IMAGE3(X,Y,Z), B_SCAN_IMAGE4(X,Y,Z)  

!      WRITE(21,*) X,Y,Z,B_SCAN_IMAGE4(X,Y,Z), TEMP3(Z)  

   END DO  


!=====================================================  


PRINT *, "COMPELETE TO PRINT A_SCAN"

