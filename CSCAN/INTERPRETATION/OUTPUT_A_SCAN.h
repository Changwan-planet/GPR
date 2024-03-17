!=====A-SCOPE=====
X = 31

!BEFORE ZERO_PADDING
    DO Z=1, ROWS
       WRITE(20,*) Z, B_SCAN_IMAGE(X,Y,Z) 
    END DO
!=================

!AFTER GAIN-CONTROL
    DO Z=1, ROWS2
       WRITE(21,*) Z, B_SCAN_IMAGE_GC(X,Y,Z) 
    END DO

!AFTER HILBERT TRANSFORMING, POWER DECIBEL TO MAXIMUM
    DO Z=1, ROWS
       WRITE(22,*) Z, HILBERT_powerdB(X,Y,Z) 
    END DO


PRINT *, "COMPELETE TO PRINT A_SCAN"

