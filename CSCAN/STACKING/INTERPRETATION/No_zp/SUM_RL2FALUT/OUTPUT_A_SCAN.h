!=======A-SCOPE============================
  
   DO Z = 1, ROWS
      ASCAN_SUM(1,1,Z) = SUM(B_SCAN_IMAGE7(:,:,Z)) / SIZE(B_SCAN_IMAGE7(:,:,Z))
   END DO  


   DO Z = 1, ROWS
      WRITE(20,*) ASCAN_SUM(1,1,Z) 
   END DO

   DO Z = 1, ROWS
      WRITE(99,*) B_SCAN_IMAGE7(1,1,Z) 
   END DO


!=======INSTANTNEOUS_AMPLITUDE===============================
!    DO Z=1,ROWS4
!       WRITE(21,*) HILBERT_power2(1,1,Z)  
!   END DO  
!=====================================================  


PRINT *, "COMPELETE TO PRINT A_SCAN"

