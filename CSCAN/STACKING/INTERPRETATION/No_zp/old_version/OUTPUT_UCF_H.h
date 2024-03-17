!YY = 21	

DO X= 1, DIS  

!   DO Z = H_1(X)+164, H_1(X)+245
   DO Z = H_1(X)+81, H_1(X)+245


     IF (  B_SCAN_IMAGE6F(X, YY, Z-1) < B_SCAN_IMAGE6F(X, YY, Z) .AND. &
         & B_SCAN_IMAGE6F(X, YY, Z+1) < B_SCAN_IMAGE6F(X, YY, Z)  ) THEN
  
        WRITE(90,*) X, Z
        
        WRITE(100+X,*) Z, B_SCAN_IMAGE6F(X,YY,Z) 


     END IF

 
END DO
END DO



PRINT*, "COMPLEDTED TO PRINT INTERPRETATION"
