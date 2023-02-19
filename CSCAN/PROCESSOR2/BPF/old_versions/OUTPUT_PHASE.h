!=======INSTANTNEOUS PHASE=============================================
!THIS CODE CALUCUATE THE PHASE FROM -PI/2.0 TO PI/2.0.
DO Z = 1, ROWS
DO X = 1, DIS
   INST_PHASE(X,1,Z) = ATAN(HILBERT_B_SCAN(X,1,Z)/B_SCAN_IMAGE4(X,1,Z))
END DO 
END DO 

!SECOND QUADRANT IN COMPLEX DIAGRAM
DO Z = 1, ROWS
DO X = 1, DIS
   IF(HILBERT_B_SCAN(X,1,Z) > 0.0 .AND. B_SCAN_IMAGE4(X,1,Z) < 0.0) THEN
      INST_PHASE(X,1,Z) = INST_PHASE(X,1,Z) + PI  
   END IF     
END DO 
END DO 

!THIRD QUADRANT IN COMPLEX DIAGRAM
DO Z = 1, ROWS
DO X = 1, DIS
   IF(HILBERT_B_SCAN(X,1,Z) < 0.0 .AND. B_SCAN_IMAGE4(X,1,Z) < 0.0) THEN
      INST_PHASE(X,1,Z) = INST_PHASE(X,1,Z) + PI  
   END IF     
END DO 
END DO 

!FORTH QUADRANT IN COMPLEX DIAGRAM
DO Z = 1, ROWS
DO X = 1, DIS
   IF(HILBERT_B_SCAN(X,1,Z) < 0.0 .AND. B_SCAN_IMAGE4(X,1,Z) > 0.0) THEN
      INST_PHASE(X,1,Z) = INST_PHASE(X,1,Z) + 2.0 * PI  
   END IF     
END DO 
END DO 

DO Z = 1, ROWS
DO X = 1, DIS
   INST_PHASE2(X,1,Z) = INST_PHASE(X,1,Z) * 180.0/PI
END DO 
END DO 

DO Z = 1, ROWS
   WRITE(70,*) (INST_PHASE2(X,1,Z), X = 1, DIS)
END DO
PRINT *, "COMPLETE TO PRINT INSTANTNEOUS PHASE"
!==========================================================


!===================INSTANTNEOUS_FREQUENCY==================
DEPTH = 50.0
PER = 16.0
TIME_WIN = 2.0 * DEPTH / (C/sqrt(per))
PRINT *, "TIME_WINDOW",TIME_WIN

SAMPLE_TIME = TIME_WIN / 4096.0

DO Z = 1, ROWS-1
DO X = 1, DIS
   INST_FREQUENCY(X,1,Z) = ( INST_PHASE2(X,1,Z+1)-INST_PHASE2(X,1,Z) ) / SAMPLE_TIME
END DO 
END DO 

DO Z = 1, ROWS
   WRITE(71,*) (INST_FREQUENCY(X,1,Z), X = 1, DIS)
END DO
PRINT *, "COMPLETE TO PRINT INSTANTNEOUS FREQUENCY"
 

