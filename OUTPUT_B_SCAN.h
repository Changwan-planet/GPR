!======B_SCAN=================================
x = 1             

DO Y = 1, TRA
   DO Z = 1, ROWS
      B_SCAN_IMAGE4(X,Y,Z) = 10 * log10(B_SCAN_IMAGE4(X,Y,Z)**2)
   END DO
END DO   

X = 1
DO Z = 1, ROWS           
   WRITE(22,*) (B_SCAN_IMAGE4(X,Y,Z), Y = 1, TRA) 
END DO
!=============================================

!======STACKED_B_SCAN=========================

X=1

DO Z = 1, ROWS
   STACKED_B_SCAN(X,Y,Z) = 10 * log10(STACKED_B_SCAN(X,Y,Z)**2)
END DO  

X = 1

DO Z = 1, ROWS
   WRITE(29,*) (STACKED_B_SCAN(X,Y,Z), Y = 1, TRA)
END DO    
