!======B_SCAN=================================
Y = TRA            

DO X = 1, DIS
   DO Z = 1, ROWS
      B_SCAN_IMAGE4(X,Y,Z) = 10 * log10(B_SCAN_IMAGE4(X,Y,Z)**2)
      B_SCAN_IMAGE5(X,Y,Z) = 10 * log10(B_SCAN_IMAGE5(X,Y,Z)**2)
   END DO
END DO   

Y = TRA

!TOTAL SAMPLES
!!DO Z = 1, ROWS           
!!   WRITE(22,*) (B_SCAN_IMAGE5(X,Y,Z), X = 1, DIS) 
!!END DO

!B_SCAN_IMAGE_MEAN_MEANTINGFUL SAMPLES
DO Z = 900,1500            
   WRITE(23,*) (B_SCAN_IMAGE4(X,Y,Z), X = 1, DIS) 
END DO

!B_SCAN_IMAGE_MEAN_MEANTINGFUL SAMPLES
!DO Z = 900,1500            
!   WRITE(24,*) (B_SCAN_IMAGE5(X,Y,Z), X = 1, DIS) 
!END DO


!=============================================

!======STACKED_B_SCAN=========================

!!X=1

!!DO Z = 1, ROWS
!!   STACKED_B_SCAN(X,Y,Z) = 10 * log10(STACKED_B_SCAN(X,Y,Z)**2)
!!END DO  

!!X = 1

!!DO Z = 1, ROWS
!!   WRITE(29,*) (STACKED_B_SCAN(X,Y,Z), Y = 1, TRA)
!!END DO    
