!MANUAL EDIT OF THE POSITIN OF SIGNAL

!2022 November 40MHz MIHO GPR

EDIT = 255
EDIT2 = EDIT * 5


B_SCAN_IMAGE2(1, 17 ,Z) = 0

DO Z = 1, (ROWS - EDIT2)
   B_SCAN_IMAGE2(1, 17 ,Z) = B_SCAN_IMAGE(1, 17 ,7+Z)
END DO 

DO Z = 1, (ROWS - EDIT2)
   B_SCAN_IMAGE2(2, 17 ,Z) = B_SCAN_IMAGE(2, 17 ,9+Z)
END DO 

DO Z = 1, (ROWS - EDIT2)
   B_SCAN_IMAGE2(3, 17 ,Z) = B_SCAN_IMAGE(3, 17 ,9+Z)
END DO 

DO Z = 1, (ROWS - EDIT2)
   B_SCAN_IMAGE2(4, 17 ,Z) = B_SCAN_IMAGE(4, 17 ,12+Z)
END DO 

DO Z = 1, (ROWS - EDIT2)
   B_SCAN_IMAGE2(5, 17 ,Z) = B_SCAN_IMAGE(5, 17 ,12+Z)
END DO 

DO Z = 1, (ROWS - EDIT2)
   B_SCAN_IMAGE2(6, 17 ,Z) = B_SCAN_IMAGE(6, 17 ,18+Z)
END DO 

DO Z = 1, (ROWS - EDIT2)
   B_SCAN_IMAGE2(7, 17 ,Z) = B_SCAN_IMAGE(7, 17 ,19+Z)
END DO 

DO Z = 1, (ROWS - EDIT2)
   B_SCAN_IMAGE2(8, 17 ,Z) = B_SCAN_IMAGE(8, 17 ,23+Z)
END DO 

DO Z = 1, (ROWS - EDIT2)
   B_SCAN_IMAGE2(9, 17 ,Z) = B_SCAN_IMAGE(9, 17 ,25+Z)
END DO 

DO Z = 1, (ROWS - EDIT2)
!   B_SCAN_IMAGE2(10, 17 ,Z) = B_SCAN_IMAGE(10, 17, 31+Z)
!   B_SCAN_IMAGE2(10, 17 ,Z) = B_SCAN_IMAGE(10, 17, 23+Z)
   B_SCAN_IMAGE2(10, 17 ,Z) = B_SCAN_IMAGE(10, 17, 25+Z)



END DO 

DO Z = 1, (ROWS - EDIT2)
   B_SCAN_IMAGE2(11, 17 ,Z) = B_SCAN_IMAGE(11, 17 ,25+Z)
!   B_SCAN_IMAGE2(11, 17 ,Z) = B_SCAN_IMAGE(11, 17 ,23+Z)


END DO 

DO Z = 1, (ROWS - EDIT2)
   B_SCAN_IMAGE2(12, 17 ,Z) = B_SCAN_IMAGE(12, 17, 18+Z)
 
!   B_SCAN_IMAGE2(12, 17 ,Z) = B_SCAN_IMAGE(12, 17, 25+Z)
   B_SCAN_IMAGE2(12, 17 ,Z) = B_SCAN_IMAGE(12, 17, 27+Z)


END DO 

DO Z = 1, (ROWS - EDIT2)
!   B_SCAN_IMAGE2(13, 17 ,Z) = B_SCAN_IMAGE(13, 17, 23+Z)
   B_SCAN_IMAGE2(13, 17 ,Z) = B_SCAN_IMAGE(13, 17, 24+Z)


END DO 


