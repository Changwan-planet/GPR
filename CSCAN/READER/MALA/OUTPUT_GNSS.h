
!=====OUTPUT_CSAN=====
DO Y = 1, TRA2
!DO Y = 3, 18


DO X = 1, TRACE(Y)
!   WRITE(50,*) ( XYZ(X,CL,Y), CL=1,3)
!   WRITE(50,*)  XYZ(1,X,Y), XYZ(2,X,Y),  XYZ(3,X,Y)
   WRITE(50,*)  XYZ(1,X,Y), XYZ(2,X,Y),  0.0



END DO 
END DO
!=====================
