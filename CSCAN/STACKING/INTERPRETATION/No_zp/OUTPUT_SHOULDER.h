!YY = 21	

DO X= 1, DIS  
SD1 = 0.0
SD2 = 0.0
SD3 = 0.0
SD4 = 0.0
!   DO Z = H_1(X)+164, H_1(X)+245
   DO Z = H_1(X)+81, H_1(X)+245

           SD1 = B_SCAN_IMAGE6F(X, YY, Z-1) - B_SCAN_IMAGE6F(X, YY, Z-2)
           SD2 = B_SCAN_IMAGE6F(X, YY, Z  ) - B_SCAN_IMAGE6F(X, YY, Z-1)
           SD3 = B_SCAN_IMAGE6F(X, YY, Z+1) - B_SCAN_IMAGE6F(X, YY, Z  )
           SD4 = B_SCAN_IMAGE6F(X, YY, Z+2) - B_SCAN_IMAGE6F(X, YY, Z+1)


        !IF(SD1 > 0 .AND. SD2 < 0 .AND. SD3 < 0 .AND. SD4 < 0) THEN
        IF(SD1 < SD2 .AND. SD2 > SD3 .AND. SD3 > SD4 .AND. &
           SD1 < 0 .AND. SD2 < 0 .AND. SD3 < 0 .AND. SD4 < 0 ) THEN


            
  
           WRITE(92,*) X, Z
        
        

        WRITE(200+X,*) Z, B_SCAN_IMAGE6F(X,YY,Z) 


     END IF

 
END DO
END DO



PRINT*, "COMPLEDTED TO PRINT SHOLDER PICK"
