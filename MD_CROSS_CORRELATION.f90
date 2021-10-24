!>MD_CROSS_CORRELATION.f90


MODULE MD_CROSS_CORRELATION
IMPLICIT NONE


CONTAINS 
  SUBROUTINE cross_corl(x,h,S,crrl)
  IMPLICIT NONE

  INTEGER, INTENT(IN) :: S

  REAL*8, DIMENSION(0:S-1), INTENT(IN) :: h
  REAL*8, DIMENSION(0:S-1), INTENT(IN) :: x 

  REAL*8, DIMENSION(-S:2*S-1) :: h_dis
  REAL*8, DIMENSION(-S:2*S-1) :: h_dis2


  REAL*8, DIMENSION(-S:2*S-1) :: x_dis

  REAL*8, DIMENSION(-S:2*S-1) :: multi
  REAL*8, DIMENSION(0:2*S) :: crrl
 
  INTEGER :: i,j,k

x_dis = 0.0
h_dis = 0.0
multi = 0.0
crrl = 0.0


DO i=0, S-1
   x_dis(i) = x(i)
END DO


DO i=0,S-1
   h_dis(-S+i)=h(i)
END DO


DO j=0,2*S

   DO i=-S,-1
      h_dis2(i+j)=h_dis(i)
   END DO

   DO i =-S,2*S-1
!      PRINT *, "h_dis(",i,")=",h_dis(i), "h_dis2(",i,")=",h_dis2(i)
      multi(i) = h_dis2(i) * x_dis(i) 
!      PRINT *, "h_dis(",i,")=",h_dis(i), "h_dis2(",i,")=",h_dis2(i),"multi=",multi(i)
 
   END DO
      crrl(j) = SUM(multi)
            
!      PRINT *, j, crrl(j) 

END DO

  END SUBROUTINE
END MODULE
