!=======A-SCOPE===============================
J=3
    DO I=1,ROWS
    !   WRITE(20,*) (B_SCAN_IMAGE2(I,J), I=1,ROWS)
        WRITE(20,*) B_SCAN_IMAGE2(I,J) 
    END DO


!    DO I = 1,ROWS
!        B_SCAN_IMAGE3(I,J) = B_SCAN_IMAGE3(I,J)**2
!    END DO

!    DO I =1,ROWS
!        B_SCAN_IMAGE3(I,J) = 10 * log10(B_SCAN_IMAGE3(I,J))
!    END DO

    DO I=1,ROWS

       WRITE(21,*) B_SCAN_IMAGE3(I,J)
    
    END DO


