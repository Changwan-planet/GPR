Program GSSI_PROGRAM
IMPLICIT NONE

INTEGER, PARAMETER ::  DISTANCE=3324
REAL, DIMENSION(4096,DISTANCE) :: B_SCAN_IMAGE
REAL, DIMENSION(4096,1) :: IMAGE_MEAN
REAL, DIMENSION(4096,DISTANCE) :: IMAGE_AFTER_REMOVE_BG

CALL remove_background(B_SCAN_IMAGE,IMAGE_AFTER_REMOVE_BG)
CALL mean_profile(B_SCAN_IMAGE, IMAGE_MEAN)
END PROGRAM

!the name of subroutine must be small letter!
SUBROUTINE remove_background(B_SCAN_IMAGE, IMAGE_AFTER_REMOVE_BG) 
IMPLICIT NONE

INTEGER :: a,n
INTEGER, PARAMETER :: DISTANCE=3324
REAL, DIMENSION(4096,DISTANCE), INTENT(IN) :: B_SCAN_IMAGE
REAL, DIMENSION(4096,1) :: IMAGE_MEAN
REAL, DIMENSION(4096,DISTANCE), INTENT(OUT)  :: IMAGE_AFTER_REMOVE_BG

!ROWS=4096 


DO a=1, 4096
  
  IMAGE_MEAN(a,1) = SUM(B_SCAN_IMAGE(a,:)) / REAL(SIZE(B_SCAN_IMAGE(a,:)))
  IMAGE_AFTER_REMOVE_BG(a,:) = B_SCAN_IMAGE(a,:) - IMAGE_MEAN(a,1)
  
 ! PRINT*, IMAGE_MEAN(2)  
END DO

n=500  


!  PRINT*, ""
!  PRINT*, "******FORTRAN*******"
!  PRINT*, "SUM(B_SCAN_IMAGE(",n,":))=",SUM(B_SCAN_IMAGE(n,:))
!  PRINT*, "SIZE(B_SCAN_IMAGE(",n,":)=",REAL(SIZE(B_SCAN_IMAGE(n,:)))  

!  PRINT*,  SUM(B_SCAN_IMAGE(n,:)) / REAL(SIZE(B_SCAN_IMAGE(n,:)))
 
!  PRINT*, "IMAGE_MEAN(",n,")=",IMAGE_MEAN(n,1)  
!  PRINT*, "IMAGE_AFTER_REMOVE_BG(",n,")=",IMAGE_AFTER_REMOVE_BG(n,2)  
!  PRINT*, ""


END SUBROUTINE


!the name of subroutine must be small letter!
SUBROUTINE mean_profile(B_SCAN_IMAGE, IMAGE_MEAN) 
IMPLICIT NONE

INTEGER :: a
INTEGER, PARAMETER :: DISTANCE=3324
REAL, DIMENSION(4096,DISTANCE), INTENT(IN) :: B_SCAN_IMAGE
REAL, DIMENSION(4096,1), INTENT(OUT) :: IMAGE_MEAN


!ROWS=4096 

DO a=1, 4096
  
  IMAGE_MEAN(a,1) = SUM(B_SCAN_IMAGE(a,:)) / SIZE(B_SCAN_IMAGE(a,:))

END DO

   
!  PRINT*, "******FORTRAN*******"
  !PRINT*, "SUM(B_SCAN_IMAGE(2,:))=",SUM(B_SCAN_IMAGE(2,:))
  !PRINT*, "SIZE(B_SCAN_IMAGE(2,:)=",SIZE(B_SCAN_IMAGE(2,:))  
!  PRINT*,  SUM(B_SCAN_IMAGE(500,:)) / SIZE(B_SCAN_IMAGE(500,:))
!  PRINT*, "IMAGE_MEAN(500)=",IMAGE_MEAN(500,1)  
  !PRINT*, ""

END SUBROUTINE


