!YY = 21	

DO X= 1, DIS  

!  DO Z = 1090, 1390
!  DO Z = 1090, 1190
!  DO Z = 1090, 1240
!  DO Z = 1090, 1290
   DO Z = 1140, 1290
!   DO Z = 1190, 1290
!  DO Z = 1190, 1390
!  DO Z = 1290, 1390
!  DO Z = 1190, 1490


     !IF (  B_SCAN_SUM(X, YY, Z-1) < B_SCAN_SUM(X, YY, Z) .AND. &
     !    & B_SCAN_SUM(X, YY, Z+1) < B_SCAN_SUM(X, YY, Z)  ) THEN
  
     IF (  HILBERT_BSUM_powerdB(X, YY, Z-1) < HILBERT_BSUM_powerdB(X, YY, Z) .AND. &
         & HILBERT_BSUM_powerdB(X, YY, Z+1) < HILBERT_BSUM_powerdB(X, YY, Z)  ) THEN
 

        WRITE(90,*) X, Z

     END IF

 
END DO
END DO



!=====HORIZON_1=======================
DO X = 1, DIS
   WRITE(91,*) X, H_1(X)
END DO 
!=====================================
PRINT*, "COMPLEDTED TO PRINT INTERPRETATION"
