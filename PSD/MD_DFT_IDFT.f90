MODULE MD_DFT_IDFT

IMPLICIT NONE

CONTAINS

  SUBROUTINE dft(xxreal, xximag, S, dft_real, dft_imag)

  IMPLICIT NONE

  INTEGER, INTENT(IN) :: S !THE NUMBER OF SAMPLE POINT
  INTEGER :: k
  INTEGER :: n

  REAL*8, PARAMETER :: pi = ACOS(-1.0)

  REAL*8, DIMENSION(0:S-1), INTENT(IN) :: xxreal
  REAL*8, DIMENSION(0:S-1), INTENT(IN) :: xximag

  REAL*8, DIMENSION(0:S-1) :: xreal
  REAL*8, DIMENSION(0:S-1) :: ximag

!  COMPLEX*8, DIMENSION(0:S-1) :: x_complex

  REAL*8, DIMENSION(0:S-1) :: dft_real
  REAL*8, DIMENSION(0:S-1) :: dft_imag

  REAL*8, DIMENSION(0:S-1) :: treal  
  REAL*8, DIMENSION(0:S-1) :: timag  

  REAL*8 :: sum_real  
  REAL*8 :: sum_imag  

  REAL*8 :: ARG
  REAL*8 :: CC, SS


  arg = 0.0

  CC = 0.0
  SS = 0.0

!  treal = 0.0
!  timag = 0.0

  xreal = xxreal
  ximag = xximag


!DO k=0, S-1
!   WRITE(*,*) k, xreal(k), ximag(k)
!END DO

!DO i = 0, S-1

!   x_complex(i) = cmplx(xreal(i),ximag(i))

!END DO

  DO n = 0, S-1

     sum_real = 0.0
     sum_imag = 0.0

     DO k = 0, S-1

        arg = 2 * pi * n * k / S

        CC = COS(arg)
        SS = SIN(arg)

!++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
!xreal(ARG2) = define above
!ximag(ARG2) = 0.0

! **[FOURIER TRANSFORM]
!=[(xreal(arg2) + j ximag(arg2)) * ( COS(arg) - j SIN(arg))]

!=[ xreal(arg2) * COS(arg) + ximag(arg2) * SIN(arg)] 
! j [ ximag(arg2) * COS(arg) - xreal(arg2) * SIN(arg) ]

! **[INVERSE FOURIER TRANSFORM]
!=[ xreal(arg2) + j ximag(arg2) * ( COS(arg) + j SIN(arg))]

!=[ xreal(arg2) * COS(arg) - ximag(arg2) * SIN(arg)] 
! j [ ximag(arg2) * COS(arg) + xreal(arg2) * SIN(arg) ]
!+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

        treal(k) = xreal(k) * CC + ximag(k) * SS
        timag(k) = ximag(k) * CC - xreal(k) * SS
 
        sum_real = sum_real + treal(k)
        sum_imag = sum_imag + timag(k)
 
      END DO

     dft_real(n) = sum_real
     dft_imag(n) = sum_imag

  END DO


!  DO n = 0, S-1
!     WRITE(*,*) n, dft_real(n), dft_imag(n)
!  END DO 


  END SUBROUTINE dft

  SUBROUTINE idft(xxreal, xximag, S, idft_real, idft_imag)

  IMPLICIT NONE

  INTEGER, INTENT(IN) :: S !THE NUMBER OF SAMPLE POINT
  INTEGER :: k
  INTEGER :: n

  REAL*8, PARAMETER :: pi = ACOS(-1.0)

  REAL*8, DIMENSION(0:S-1), INTENT(IN) :: xxreal
  REAL*8, DIMENSION(0:S-1), INTENT(IN) :: xximag

  REAL*8, DIMENSION(0:S-1) :: xreal
  REAL*8, DIMENSION(0:S-1) :: ximag

  REAL*8, DIMENSION(0:S-1) :: idft_real
  REAL*8, DIMENSION(0:S-1) :: idft_imag

  REAL*8, DIMENSION(0:S-1) :: treal  
  REAL*8, DIMENSION(0:S-1) :: timag  

  REAL*8 :: sum_real  
  REAL*8 :: sum_imag  

  REAL*8 :: ARG
  REAL*8 :: CC, SS


  arg = 0.0

  CC = 0.0
  SS = 0.0

!  treal = 0.0
!  timag = 0.0

  xreal = xxreal
  ximag = xximag


!DO k=0, S-1
!   WRITE(*,*) k, xreal(k), ximag(k)
!END DO

  DO n = 0, S-1

     sum_real = 0.0
     sum_imag = 0.0

     DO k = 0, S-1

        arg = 2 * pi * n * k / S

        CC = COS(arg)
        SS = SIN(arg)
       
!       IF (n == 1)  WRITE(*,*) CC, SS
!++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
!xreal(ARG2) = define above
!ximag(ARG2) = 0.0

! **[FOURIER TRANSFORM]
!=[(xreal(arg2) + j ximag(arg2)) * ( COS(arg) - j SIN(arg))]

!=[ xreal(arg2) * COS(arg) + ximag(arg2) * SIN(arg)] 
! j [ ximag(arg2) * COS(arg) - xreal(arg2) * SIN(arg) ]

! **[INVERSE FOURIER TRANSFORM]
!=[ xreal(arg2) + j ximag(arg2) * ( COS(arg) + j SIN(arg))]

!=[ xreal(arg2) * COS(arg) - ximag(arg2) * SIN(arg)] 
! j [ ximag(arg2) * COS(arg) + xreal(arg2) * SIN(arg) ]
!+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

        treal(k) = xreal(k) * CC - ximag(k) * SS
        timag(k) = ximag(k) * CC + xreal(k) * SS
 
        sum_real = sum_real + treal(k)
        sum_imag = sum_imag + timag(k)
 
      END DO
     
     sum_real = sum_real / S
     sum_imag = sum_imag / S
     
     idft_real(n) = sum_real
     idft_imag(n) = sum_imag

  END DO


!  DO n = 0, S-1
!     WRITE(*,*) n, dft_real(n), dft_imag(n)
!  END DO 


  END SUBROUTINE idft

END MODULE  
