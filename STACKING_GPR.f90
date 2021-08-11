Program OPEN_GSSI
USE MD_BACKGROUND
USE MD_STACKING

IMPLICIT NONE

INCLUDE "IN_OUT_PATH.h"
INCLUDE "VARIABLES.h"
INCLUDE "PATH_NAME_OPEN.h"

!======INITIALIZATION=======
DIS = 0
!B_SCAN_IMAGE = 0
!B_SCAN_IMAGE2 = 0.0
!B_SCAN_IMAGE3 = 0.0
!INTENSITY = 0.0
!===========================

PRINT *, "PLEASE TYPE THE DISTANCE"
READ *, DIS

INCLUDE "ALLOCATE.h"

READ(10) HEADER,B_SCAN_IMAGE

!INTEGER => REAL*8
B_SCAN_IMAGE2=B_SCAN_IMAGE

!ERASE THE UNECESSARY NUMBER. 
!THE NUMBER MEANS THE VALUE OF THE J-1.
B_SCAN_IMAGE2(1,:) = 0


DO J = 1,DIS
!CALCUATE THE BACKGROUND
    CALL background(B_SCAN_IMAGE2(:,J),ROWS,2001,4000,BGR)

!REMOVE THE BACKGROUND
    B_SCAN_IMAGE3(:,J) = B_SCAN_IMAGE2(:,J) - BGR
END DO

!TO MAKE THE GRAPH STABLE
B_SCAN_IMAGE3(1,:) = 0
B_SCAN_IMAGE3(2,:) = 0

!STACKING THE A_SCOPE TO SUPPRESS THE BACKGROUND
    CALL stacking(B_SCAN_IMAGE3,ROWS,DIS,STACKED_A_SCOPE)

INCLUDE "OUTPUT_A_SCOPE.h"
!INCLUDE "OUTPUT_B_SCAN.h"
INCLUDE "OUTPUT_STACKED_A_SCOPE.h"

!         DO I=1,DIS
!             WRITE(21,*) (B_SCAN_IMAGE2(J,I), J=601,800)
!         END DO
! CHECK THE DIRECTION OF OUTPUT
!         DO I =1,DIS
!            DO J=601,610
!               PRINT *, J, I
!            END DO
!         END DO

!PRINT *, "----------------------------------------------"
 
!!         DO J=601,800
!!           WRITE(21,*) (B_SCAN_IMAGE2(J,I), I=1,DIS)
!!         END DO

!         DO J=601,610
!            DO I=1,DIS
!                PRINT *, J,I
!            END DO
!         END DO   


!=============================================

!!I = 0

!=====INTENSITY_PROFILE=======================

!!DO I=1,DIS
!!   DO J=1,ROWS
  
!!      IF (B_SCAN_IMAGE2(J,I)==0.0) then 
!!         B_SCAN_IMAGE2(J,I)=1.0
!!      END IF

!!          INTENSITY(J,1)=INTENSITY(J,1)+10*log10((B_SCAN_IMAGE2(J,I)**2))     
!!   END DO

!+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
!PRINT THE INTENSITY_PROFILE OF THE FIRST DIS VALUE.         
!JUST ONE INTENSITY VALUE
!IF YOU WANT THE INTENSITY PROFILE OF THE OTHER DIS VALUE, THEN JUST CHANGE THE I BELOW. 
!!      IF (I==1) THEN 
!!               INTENSITY(1,1)=INTENSITY(2,1)
!!               INTENSITY(4096,1)=INTENSITY(4095,1)
!!          DO L=1,ROWS     
!!                WRITE(22,*) INTENSITY(L,1) 
!                PRINT *,    INTENSITY(L,1)
!!          END DO
!!      END IF 
!+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

!!END DO

!!INTENSITY(1,1)=INTENSITY(2,1)
!!INTENSITY(4096,1)=INTENSITY(4095,1)

!DO K=1,ROWS
!   PRINT *, "B_SCAN_IMAGE2(",K,"1)=",B_SCAN_IMAGE2(K,1) 
!END DO   

!!K=0

!INTEGRATED INTENSITY_PROFIEL AS THE NUMBER OF THE DISTANCE.
!!DO K=1,ROWS
!   PRINT *, "INTENSITY(",K,")=",INTENSITY(K,1) 
!!   WRITE(23,*) INTENSITY(K,1)
!!END DO   

!=============================================


END PROGRAM
