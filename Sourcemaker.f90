PROGRAM Sourcemaker
IMPLICIT NONE

INTEGER :: t
INTEGER, PARAMETER :: S = 4096
REAL*8, DIMENSION(0:S-1) :: y
REAL*8 :: pi = Acos(-1.0)


OPEN(UNIT=20, FILE='/home/changwan/GPR/Source_sine.txt', STATUS='REPLACE', ACTION='WRITE')

DO t = 0, S-1

   y(t) = sin(t*2*pi/(S-1))
!   PRINT *, t, y

END DO

DO t = 0, S-1
   WRITE(20,*) y(t)
END DO

END PROGRAM Sourcemaker
