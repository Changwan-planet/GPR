!=======PHASE=============================================

!DO Z = 1, ROWS
!DO Y = 1, TRA
!   phase(1,Y,Z) = ATAN(HILBERT_STACKED_B_SCAN_imag(1,Y,Z)/HILBERT_STACKED_B_SCAN(1,Y,Z))
!END DO 
!END DO 

!DO Z = 1, ROWS
!DO Y = 1, TRA
!   IF(HILBERT_STACKED_B_SCAN(1,Y,Z) < 0.0 .AND. HILBERT_STACKED_B_SCAN_imag(1,Y,Z) < 0.0) THEN
!      phase(1,Y,Z) = phase(1,Y,Z) + PI  
!   END IF     
!END DO 
!END DO 

!DO Z = 1, ROWS
!DO Y = 1, TRA
!   phase2(1,Y,Z) = phase(1,Y,Z) * 180.0/PI
!END DO 
!END DO 

DO Z = 1,ROWS
   WRITE(52,*) (HILBERT_STACKED_B_SCAN_imag(1,Y,Z), Y = TRA,1,-1)
END DO

!DO Z = 1,ROWS
!   WRITE(52,*) (phase2(1,Y,Z), Y = TRA,1,-1)
!END DO
!=========================================================


