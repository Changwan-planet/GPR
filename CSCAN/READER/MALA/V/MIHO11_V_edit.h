!CALL flip_3d_y( B_SCAN_IMAGE3(2-1  ,:,:), 1, TRACE(2-1), ROWS,B_SCAN_IMAGE3F(2-1  ,:,:) )
!CALL flip_3d_y( B_SCAN_IMAGE3(104-1,:,:), 1, TRACE(104-1), ROWS,B_SCAN_IMAGE3F(104-1,:,:) )
!CALL flip_3d_y( B_SCAN_IMAGE3(106-1,:,:), 1, TRACE(106-1), ROWS,B_SCAN_IMAGE3F(106-1,:,:) )
!CALL flip_3d_y( B_SCAN_IMAGE3(108-1,:,:), 1, TRACE(108-1), ROWS,B_SCAN_IMAGE3F(108-1,:,:) )
!CALL flip_3d_y( B_SCAN_IMAGE3(110-1,:,:), 1, TRACE(110-1), ROWS,B_SCAN_IMAGE3F(110-1,:,:) )

G = 2
DO P =1, TRACE(G) 
   B_SCAN_IMAGE3F(2-1,TRACE(G)-P+1,:) = B_SCAN_IMAGE3(2-1,P,:) 
END DO 

G = 104
DO P =1, TRACE(G) 
   B_SCAN_IMAGE3F(104-1,TRACE(G)-P+1,:) = B_SCAN_IMAGE3(104-1,P,:) 
END DO 

G = 106
DO P =1, TRACE(G) 
   B_SCAN_IMAGE3F(106-1,TRACE(G)-P+1,:) = B_SCAN_IMAGE3(106-1,P,:) 
END DO 

G = 108
DO P =1, TRACE(G) 
   B_SCAN_IMAGE3F(108-1,TRACE(G)-P+1,:) = B_SCAN_IMAGE3(108-1,P,:) 
END DO 

G = 110
DO P =1, TRACE(G) 
   B_SCAN_IMAGE3F(110-1,TRACE(G)-P+1,:) = B_SCAN_IMAGE3(110-1,P,:) 
END DO 


 

!MANUAL EDITING (REASON, THOSE LINES ARE TOO WIERD!)
COL_COR_PIXEL2(32) =  INT(COL_COR_PIXEL2(31) +  COL_COR_PIXEL2(33) / 2.0)  
COL_COR_PIXEL2(50) =  INT(COL_COR_PIXEL2(49) +  COL_COR_PIXEL2(51) / 2.0)
COL_COR_PIXEL2(76) =  INT(COL_COR_PIXEL2(75) +  COL_COR_PIXEL2(77) / 2.0)  
COL_COR_PIXEL2(84) =  INT(COL_COR_PIXEL2(83) +  COL_COR_PIXEL2(85) / 2.0) 



