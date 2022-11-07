!=======3D_CUBE============================
!X=DIS=THE NUMBER OF STACKING

!BEFORE REMOVING BACKGROUND

DO X = 1, DIS    	
    DO Y=1,TRA
        WRITE(80,*) (B_SCAN_IMAGE3(X,Y,Z), Z = 1, ROWS) 
    END DO
END DO 

!=====CSCAN_rmbgr===================================
!B_SCAN_IMAGE3(DIS,TRA,ROWS)    

      DO Y = 1, TRA	
      DO Z = 1, ROWS2
      DO X = 1, DIS
      ! B_SCAN_IMAGE4_GC(X,1,Z) = B_SCAN_IMAGE4(X,1,Z) / SQRT(HILBERT_power2(X,Y,Z))  
       B_SCAN_IMAGE4_GC(X,1,Z) = B_SCAN_IMAGE4(X,1,Z) / HILBERT_power2(X,Y,Z)  
      END DO
      END DO
      END DO

	DO X = 1, DIS    	
    	DO Y=  1, TRA
        	WRITE(81,*) (B_SCAN_IMAGE4_GC(X,Y,Z), Z = 1, ROWS) 
    	END DO
	END DO    
!===================================================

!=======MEAN_A_SCOPE=============================== 
!    DO Z=1,ROWS
!       WRITE(20,*) MEAN_A_SCOPE(1,1,Z)        
!    END DO  
!=====================================================  

!=======HILBERT_A_SCOPE_REAL===============================
!    DO Z=1,ROWS
!       WRITE(21,*) HILBERT_SIGNAL(1,1,Z) 
!    END DO  
!=====================================================  

!=======INSTANTNEOUS_AMPLITUDE===============================
!    DO Z=1, ROWS
!       INST_A_SCOPE(1,1,Z) = SQRT(B_SCAN_IMAGE4(1,1,Z)**2 + HILBERT_SIGNAL(1,1,Z)**2)
!    END DO

!    DO Z=1,ROWS2
!       WRITE(22,*) HILBERT_power2(1,1,Z)  
!   END DO  
!=====================================================  

