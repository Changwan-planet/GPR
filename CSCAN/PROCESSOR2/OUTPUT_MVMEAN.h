!REMOVE 2D MOVING AVERAGE

DO Z = 1, ROWS
   DO MV_X = 1, MV_DIS
   DO MV_Y = 1, MV_TRA

      SUM_2DW_amp = 0.0
      DO X = MV_X, MV_X+W-1
      DO Y = MV_Y, MV_Y+W-1

             SUM_2DW_amp = SUM_2DW_amp + B_SCAN_IMAGE4(X,Y,Z)
                                             
      END DO
      END DO
 
      amp_2D_mvmean(MV_X,MV_Y,Z) = ( SUM_2DW_amp ) / (W**2)
   END DO
   END DO
END DO 

!=====HILBERT_3D_CUBE_IMAGE============================
!J=ROWS 
      DO X = 1, MV_DIS
        DO Y = 1, MV_TRA
            WRITE (50,*) (HdB_2D_mvmean(X,Y,Z), Z = 1, ROWS)
         END DO 
      END DO

!==>  THIS STRUCTURE (X x Y) X Z CAN BE PRINTED. 
!==>  (X x Y) IS THE C_SCAN.

     PRINT *, "COMPLETE HILBERT_3D_CUBE_IMAGE OUTPUT"
     PRINT *, "(", MV_DIS, ",", MV_TRA, ",", ROWS, ")"

!=============================================

!PRINT *, char(7)


