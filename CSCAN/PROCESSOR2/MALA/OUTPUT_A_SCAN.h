


!=======A-SCOPE================================
I = 13
J = 50
   DO Z = 0, ROWS2-1 
      !WRITE(20,*) I, J, Z, HILBERT_B_SCAN(I,J,Z)
      WRITE(20,*) I, J, Z, HILBERT_power2(I,J,Z)
  
   END DO  


   !DO Z = 0, ROWS2-1 
   !   WRITE(20,*) I, J, Z, B_SCAN_IMAGE2(I,J,Z)  
   !END DO  

   !DO Z = 0, ROWS-1 
   !    WRITE(20,*) I, J, Z, B_SCAN_IMAGE(I,J,Z)  
   !END DO  


!==============================================
!I = 13
!J = 0
!   DO Z = 0, ROWS-1
!   DO J = 0, TRA2
!   DO I = 0, DIS2 
!       WRITE(20,*) I,J,Z,B_SCAN_IMAGE(I,J,Z)  
!   END DO  
!   END DO 
!   END DO

!==============================================  


PRINT *, "COMPELETE TO PRINT A_SCAN"

