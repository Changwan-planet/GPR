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


     IF (  POWER_SUM(X, YY, Z-1) < POWER_SUM(X, YY, Z) .AND. &
         & POWER_SUM(X, YY, Z+1) < POWER_SUM(X, YY, Z)  ) THEN


        WRITE(92,*) X, Z

     END IF

 
END DO
END DO



