MODULE MD_BACKGROUND
IMPLICIT NONE

CONTAINS

  SUBROUTINE background(signal,ROWS,e_1,e_2,bgr)
  IMPLICIT NONE

  INTEGER, INTENT(IN) :: ROWS
 
  REAL*8, DIMENSION(1:ROWS), INTENT(IN) :: signal
  !Start from the 1 index. 
  !This is becasue I did not fix the number in the header.
  INTEGER, INTENT(IN) :: e_1
  INTEGER, INTENT(IN) :: e_2
   
  REAL*8 :: bgr_sum 
  REAL*8 :: bgr

  INTEGER :: i
  INTEGER :: t
  
bgr_sum = 0.0

  DO i = e_1,e_2,1

    bgr_sum = bgr_sum + signal(i)

  END DO
  
  t = e_2 - e_1 + 1

bgr =  bgr_sum / t

    END SUBROUTINE background

END MODULE MD_BACKGROUND


