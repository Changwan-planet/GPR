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


 
     IF (  HILBERT_AS_powerdB(X, YY, Z-1) < HILBERT_AS_powerdB(X, YY, Z) .AND. &
         & HILBERT_AS_powerdB(X, YY, Z+1) < HILBERT_AS_powerdB(X, YY, Z)  ) THEN

        WRITE(93,*) X, Z

     END IF

 
END DO
END DO

