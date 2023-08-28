import numpy as np
import matplotlib.pyplot as plt
from matplotlib import cm, colors
import pandas as pd
from pandas import Series, DataFrame 
from mpl_toolkits.mplot3d import Axes3D
from scipy.interpolate import interp1d

#import ipyvolume as ipv
#import cv2
import math

#PATH
#MIHO_ri
#NS
#BSCAN
input_path2 = "/home/changwan/GPR_DATA/KOREA/MIHO_ri/40MHz/2023/NS/3D_CUBE_GPR.txt"

#input_path2 = "/home/changwan/GPR_DATA/KOREA/MIHO_ri/3D_trench/40MHz/BSCAN/NS/3DCUBE_GPR_stacking.txt"
#input_path2 = "/home/changwan/GPR_DATA/KOREA/MIHO_ri/3D_trench/40MHz/BSCAN/NS/3D_CUBE_GPR.txt"
#input_path2 = "/home/changwan/GPR_DATA/KOREA/MIHO_ri/3D_trench/40MHz/BSCAN/NS/attribute/3D_HILBERT_powerdB.txt"

#CSCAN
#input_path2 = "/home/changwan/GPR_DATA/KOREA/MIHO_ri/3D_trench/40MHz/CSCAN3/NS/3D_CUBE_GPR.txt"
#input_path2 = "/home/changwan/GPR_DATA/KOREA/MIHO_ri/3D_trench/40MHz/CSCAN3/EW/3D_CUBE_GPR.txt"


#input_path2 = "/home/changwan/GPR_DATA/KOREA/MIHO_ri/3D_trench/40MHz/CSCAN3/NS/3DCUBE_GPR_stacking.txt"
#input_path2 = "/home/changwan/GPR_DATA/KOREA/MIHO_ri/3D_trench/40MHz/CSCAN3/NS/attribute/3D_GPR_frequency.txt"
#input_path2 = "/home/changwan/GPR_DATA/KOREA/MIHO_ri/3D_trench/40MHz/CSCAN3/NS/attribute/3D_HILBERT_powerdB.txt"


#input_path2 = "/home/changwan/GPR_DATA/KOREA/MIHO_ri/40MHz/2023/NS/3D_CUBE_GPR.txt"
#input_path2 = "/home/changwan/GPR_DATA/KOREA/MIHO_ri/40MHz/2023/NS/attribute/3D_HILBERT_powerdB_meandB.txt"
#input_path2 = "/home/changwan/GPR_DATA/KOREA/MIHO_ri/40MHz/220303/3D_CUBE_GPR.txt"



#MUNAM_ri
#input_path2 = "/home/changwan/GPR_DATA/KOREA/MUNAM_ri/2023/230601/3DCUBE_GPR_stacking.txt"

#input_path2 = "/home/changwan/GPR_DATA/KOREA/MUNAM_ri/2023/230601/attribute/3D_HILBERT_powerdB.txt"
#input_path2 = "/home/changwan/GPR_DATA/KOREA/MUNAM_ri/2023/230531/attribute/3D_HILBERT_powerdB.txt"



#input_path2 = "/home/changwan/GPR_DATA/KOREA/MUNAM_ri/2023/230531/3DCUBE_GPR_stacking.txt"


#input_path2 = "/home/changwan/GPR_DATA/KOREA/MUNAM_ri/3D_CUBE_GPR.txt"


#input_path3 = "/home/changwan/GPR_DATA/KOREA/MIHO_ri/3D_trench/40MHz/CSCAN3/NS/horizon/HORIZON_PICK_line21.txt"


#READ DATASET
#data=np.loadtxt(input_path1)
data2=np.loadtxt(input_path2)
#data3=np.loadtxt(input_path3)

#print(data3.shape)

#plt.scatter(data3[:,0],data3[:,1])
#plt.show()


#CALCULATE THE DISTANCE INTERVAL:
c_sl = 3*10**8   # speed of light
depth_range = 50 #  
#depth_range = 100 #  


#permit = 16
#depth_range2 = 50 / math.sqrt(permit)

sample = 4096
depth_int = (depth_range/ sample) 
#depth_int = (depth_range/ sample)*math.sqrt(16.0) / math.sqrt(9.0) 

depth_int2 = round(depth_int, 2)

print("\n")
print("++++++DATA INFO++++++")
print("depth_interval=",depth_int)

#C_SCAN_IMAGE

#RESAHPE THE INPUT DATA
print("input_shape=",data2.shape)    
#40MHz
point = 41
l = 21

#data2_2=data2.reshape(21,41,4096)
#data2_3=data2.reshape(21,41,4096)

#READER TEST
#data2_2=data2.reshape(l,point,sample)
#data2_3=data2.reshape(l,point,sample)

#BASIC-PROCESS
data2_2=data2.reshape(point,l,sample)
data2_3=data2.reshape(point,l,sample)
#data2_3_e=data2.reshape(point,l,sample)


print("3D_shape (x,y,z) =",data2_2.shape)
print("+++++++++++++++++++++")
print("\n")

fig,host =plt.subplots()

print(data2_2.shape[0])
print(data2_2.shape[1])
print(data2_2.shape[2])


ax1_min=0
#BASIC PROGRAM

#ax1_max=data2_2.shape[0] * 1     #This is Easting.
ax1_max=data2_2.shape[0] * 0.5     #This is Easting.
#ax1_max=data2_2.shape[0] * 0.2     #This is Easting.


#ax1_max=data2_2.shape[0]* 0.25     #This is Easting.
#READER TEST
#ax1_max=data2_2.shape[1]* 0.5      #Test for reader program.

ay1_min=data2_2.shape[2]* depth_int #This is Depth.
ay1_max=0

#subgroup
#ss = 980     #subgroup start
#se = 1600     #subgroup end
#ay1_min = depth_int * se
#ay1_max = 0

#ay1_min=0
#ay1_max=data2_2.shape[1]*1 #This is Easting.

#cmap=colors.ListedColormap(["white","blue","red"])

#     ++++++++++++++++++++++
#++++++Before interploation++++++
#     ++++++++++++++++++++++
start =  0
end   =  l
#end   =  1



lines=list(range(start,end,1))
samples=list(range(0,sample,1,))

dis_s = 0
dis_e = data2_2.shape[0]
dis=list(range(dis_s,dis_e,1))

#PLEASE CHECK THE DIRECTION OF THE GRAPH.
#Check the direction of the graph
#data2_2[10:20,1,start] = 1000000*100000 
#data2_2[70:80,1,start] = -1000000*100000 
#data2_2[3,30:40,start] = -1000000*100000 
#data2_2[1:10,30,start] = -1000000*100000 

#manual edit of the position of the signal
#edit = 255 
#for i in np.arange(0,(sample-edit),1):
#    print("i=",i)
#    data2_3_e[7,1,i] = data2_3[7,1,edit+i]
#    data2_3_e[27,1,i] = data2_3[27,1,edit+i]




#     ++++++++++++++++++++
#++++++Remove the average++++++
#     ++++++++++++++++++++

#remove the noise of the cable
##for depth in rows:
## data2_2[:,:,depth] = data2_2[:,:,depth] - np.mean(data2_2[:,:,depth])
##for east in dis:
## data2_2[east,:,depth] = data2_2[east,:,depth] \
##                         - np.mean(data2_2[east,:,depth])
plt.rcParams['font.size'] = 15
#plt.rcParams['figure.figsize'] = (8,13)


for line in lines:
# for depth in samples:
#     data2_3[:,line,depth] = data2_2[:,line,depth] - np.mean(data2_2[:,line,depth])

#Transpose the C_scan, and
#Flip the C_scan when it comes to up and down
#Becasue I consider the tendency the imhosw plots.
# plt.imshow((data2_2[:,:,depth].T)
# plt.imshow(np.flipud(data2_2[:,:,depth].T)
# d_m = 600    # display_moderator

 #plt.imshow(np.fliplr(data2_3[:,line,:].T)
 plt.imshow(data2_3[:,line,:].T
 #plt.imshow(data2_3[line,:,:].T         
 #plt.imshow(data2_3[:,line,:].T
            ,extent=(ax1_min,ax1_max,ay1_min,ay1_max)
           #,cmap='gist_rainbow'
#            ,cmap="gnuplot" 
#            ,cmap="inferno" 
#             ,cmap="RdGy"

            ,cmap="Greys_r" 

#            ,aspect=3
#            ,aspect=1
)
#Almost similar in with and without the interpolation.
#,interpolation = 'spline16')
 
 #plt.scatter(data3[:,0],data3[:,1])


 s = "line="+ str(line+1)
 plt.colorbar()
 #full view
 #plt.text(10,-1, s, fontweight="bold",fontsize=15) 
 #enlarged view
 #plt.text(10,11.125, s, fontweight="bold",fontsize=15) 
 
 #enlarged view2-Northern Miho
 #plt.text(10,20.125, s, fontweight="bold",fontsize=15) 
 
 #enlarged view3-Southern Miho
 #plt.text(10,11.125, s, fontweight="bold",fontsize=15) 
 
 #colorbar
 #plt.clim(10,-10)
 #plt.clim(10,-30)
 #plt.clim(0,-100)
 
 #plt.clim(150,130)
 #plt.clim(0,-60)
 

 #plt.clim(-1* 10**(6),1*10**(6))
 #plt.clim(-2* 10**(6),2*10**(6))
 #plt.clim(-4* 10**(5),4*10**(5))
 plt.clim(-1* 10**(5),1*10**(5))



 #depth_title = round(((depth-start) * depth_int), 2)
 print("line=",line+1,"m")

 #plt.figure(figsize=(8,11))
 
 #plt.title("BSCAN MIHO-ri_40 MHz_XX_Pol.", fontweight="bold", fontsize=20, position=(0.5,-3))
 #plt.title("40 MHz Y direction", fontweight="bold", fontsize=20, position=(0.5,-3))
 plt.title("40 MHz GPR YY pol.", fontweight="bold", fontsize=20, position=(0.5,-3))
 
#plt.title("BSCAN MIHO-ri_100 MHz_EW_Pol.", fontweight="bold", fontsize=20)
 #plt.title("BSCAN MUNAM_ri_40 MHz_XX_Pol.", fontweight="bold", fontsize=20)
 #plt.title("BSCAN DAEGOK_CHEON_MIHO-ri_40 MHz_NS_Pol.", fontweight="bold", fontsize=20)
 

#Track interval 
 plt.ylabel("Depth [m]", fontweight="bold",fontsize=25)
#Distance interval
 #plt.xlabel("Northing [m]  int_0.5 m", fontweight="bold",fontsize=25)
 #plt.xlabel("Distance [m]  int_0.5 m", fontweight="bold",fontsize=25)
 plt.xlabel("Distance [m]  int = 0.5 m", fontweight="bold",fontsize=25)

#Ticks
 plt.xticks(fontsize=25, fontweight="bold")
 plt.yticks(fontsize=25, fontweight="bold")
 
 #enlarged view
 thick = 10
 ss = 11.5    #subgroup start
 #ss = 11.625    #subgroup start


 #ss = 15.5    #subgroup start
 se = ss+ thick  #subgroup end

 #enlarged view_2-Northern Miho-depth_range:100 m 
 #ss = 20.5 #subgroup start
 #se = ss + thick  #subgroup end

 #enlarged view_3-Northern Miho
 #ss = 11.5 #subgroup start
 #se = 25.5  #subgroup end

 #enlarged view_3-Munam
 #ss = 20.0 #subgroup start
 #se = 30.0  #subgroup end


 #full view
 #ss = 0      #subgroup start
 #se = ay1_min  #subgroup end

 plt.xticks(np.arange(0,20,2),np.arange(0,20,2),fontsize=15, fontweight="bold")
 #plt.xticks(np.arange(0,31,2),np.arange(0,31,2),fontsize=15, fontweight="bold")


 #full view
 #plt.yticks(np.arange(ss,se,10),np.arange((ss-ss)-1,(se-ss)-1,10),fontsize=15, fontweight="bold")
 #enlarged view
 plt.yticks(np.arange(ss,se,1),np.arange((ss-ss)-1,(se-ss)-1,1),fontsize=15, fontweight="bold")


#Ticks limit
 plt.xlim(0,20)

 #enlarged view-Southern Miho
 es = ss
 plt.ylim(es+thick,es)

 #enlarged view_2-Northen Miho-depth_range: 100 m 
 #es = ss
 #plt.ylim(es+thick,es)

 #enlarged view_3-Southern Miho
 #es = ss
 #plt.ylim(es+thick,es)

 #enlarged view_3-Munam
 #es = ss
 #plt.ylim(es+10,es)

 #full view
 #plt.ylim(se,ss)


#Grid
# plt.grid()

#tight_layout
# plt.tight_layout()

# plt.show(block=False)
 
 plt.draw()

#Wait for the button press
 plt.waitforbuttonpress()
 
#Keep changing the graph with a 0.05 s pause.
# plt.pause(0.05)
 #plt.figure(figsize=(8,10))
 
 fig.clear()

#plt.show()

