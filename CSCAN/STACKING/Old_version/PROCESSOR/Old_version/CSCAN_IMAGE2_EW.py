import numpy as np
import matplotlib.pyplot as plt
from matplotlib import cm
import pandas as pd
from pandas import Series, DataFrame 
from mpl_toolkits.mplot3d import Axes3D
from scipy.interpolate import interp1d
#import ipyvolume as ipv
#import cv2
import math

def make_patch_spines_invisible(ax):
    ax.set_frame_on(True)
    ax.patch.set_visible(False)
    for sp in ax.spines.values():
        sp.set_visible(False)

#PATH
#input_path1="/home/changwan/GPR/C_SCAN_IMAGE_GPR_flip.txt"
#input_path2="/home/changwan/GPR/3D_IMAGE_GPR.txt"
#input_path2="L:/MOGOD_GPR/2021/3D_CUBE_IMAGE_GPR.txt"

#input_path2 = "/home/changwan/GPR/211028/3D_CUBE_IMAGE_GPR.txt"
#input_path2 = "/home/changwan/GPR/211028/HILBERT_3D_CUBE_IMAGE_GPR.txt"
#input_path2 = "/home/changwan/GPR/211028/HILBERT_3D_CUBE_IMAGE_GPR.txt"

#input_path2="L:\mnt\l\GPR_DATA/211028.PRJ/HILBERT_3D_CUBE_IMAGE_GPR.txt"

#input_path2="L:\GPR_DATA"+"\P211028.PRJ\HILBERT_3D_CUBE_IMAGE_GPR.txt"
#input_path2="L:\GPR_DATA"+"\P211027_4.PRJ\HILBERT_3D_CUBE_IMAGE_GPR.txt"


#READ DATASET
#data=np.loadtxt(input_path1)
data2=np.loadtxt(input_path2)


#CALCULATE THE DISTANCE INTERVAL:
c_sl = 3*10**8   # speed of light
depth_range = 90 # 90 m 
permit = 25
sample = 4096
depth_int = depth_range/ sample 
depth_int = round(depth_int, 2)

print("\n")
print("++++++DATA INFO++++++")
print("depth_interval=",depth_int)

#C_SCAN_IMAGE

#RESAHPE THE INPUT DATA
print("input_shape=",data2.shape)    
data2_2=data2.reshape(140,67,4096)
print("3D_shape (x,y,z) =",data2_2.shape)
print("+++++++++++++++++++++")
print("\n")

fig,host =plt.subplots()

print(data2_2.shape[2])

ax1_min=0
ax1_max=data2_2.shape[0]*0.05  #This is Northing.
ay1_min=0
ay1_max=data2_2.shape[1]*0.5 #This is Eastilng.


#     ++++++++++++++++++++++
#++++++Before interploation++++++
#     ++++++++++++++++++++++
start =  900
end   = 1050
rows=list(range(start,end,1))

dis_s = 0
dis_e = data2_2.shape[0]
dis=list(range(dis_s,dis_e,1))

tra_s = 0
tra_e = data2_2.shape[1]
tra=list(range(tra_s,tra_e,1))
print(tra)

#PLEASE CHECK THE DIRECTION OF THE GRAPH.
#Check the direction of the graph
#data2_2[:,0:20,start] = 1000000*100000 
#data2_2[100:200,:,start+1] = 1000000*100000 

#     ++++++++++++++++++++
#++++++Remove the average++++++
#     ++++++++++++++++++++

#remove the noise of the cable
#for depth in rows:
#  for east  in tra:
#     data2_2[:,east,depth] = data2_2[:,east,depth] \
#                              - np.mean(data2_2[:,east,depth])

for depth in rows:
# data2_2[:,:,depth] = data2_2[:,:,depth] - np.mean(data2_2[:,:,depth])

#Transpose the C_scan, and
#Flip the C_scan when it comes to up and down
#Becasue I consider the tendency the imhosw plots.
 plt.imshow(np.flipud(data2_2[:,:,depth])
           ,extent=(ay1_min,ay1_max,ax1_min,ax1_max)
           ,cmap='gist_rainbow')

#Almost similar in with and without the interpolation.
#,interpolation = 'spline16')

 plt.colorbar()
 plt.text(35.5, 15, '[dB]', fontweight="bold", fontsize=15)

 depth_title = round(((depth-start) * depth_int), 2)
 print(depth_title,"m", "sample=",depth)

 plt.title("Gyodong-ri_100 MHz_EW_Pol.", fontweight="bold", fontsize=30)

#Track interval 
 plt.ylabel("Northing [m] int=0.05 m", fontweight="bold", fontsize=20)
#Distance interval
 plt.xlabel("Easting [m] int=0.5 m", fontweight="bold", fontsize=20)

#Tick 
 plt.xticks(fontsize=15, fontweight="bold")
 plt.yticks(fontsize=15, fontweight="bold")

#Grid
 plt.grid()

# plt.show(block=False)
 plt.draw()

#Wait for the button press
 plt.waitforbuttonpress()
 
#Keep changing the graph with a 0.05 s pause.
# plt.pause(0.05)

 fig.clear()

#plt.show()

#
#      +++++++++++++++
#+++++++Interpolation++++++
#      +++++++++++++++

"""
x=np.arange(0,data2_2.shape[2],1)
xint = np.linspace(x.min(), x.max(), 1000)
yint2d=np.zeros((1,data2_2.shape[1],xint.shape[0]))
d_profile=np.arange(0, data2_2.shape[1],1)
"""

#     ++++++++++++++++++
#++++++1D interpolation++++++
#     ++++++++++++++++++

#fq = interp1d(x,data2_2[380,100,:], kind = 'quadratic')
#yintq=fq(xint)
#plt.plot(xint, yintq, 'ro')
#plt.plot(x,data2_2[380,100,:],'bo')


#     ++++++++++++++++++++++++++++++++++++++
#++++++2D interpolatian along one direction++++++
#     ++++++++++++++++++++++++++++++++++++++
"""
for i in d_profile:

 fq = interp1d(x,data2_2[380,i,:], kind = 'quadratic')

 yint2d[0][i][:] =  fq(xint)
"""
#     ++++++++++++++++++
#++++++Tick designation++++++
#     ++++++++++++++++++
"""
ax1_min=0
ax1_max=yint2d.shape[1]*0.05
ay1_min=0

interval=0.5 *19 / 1000
print(interval)

ay1_max=yint2d.shape[2]*interval
"""

#plt.imshow(yint2d[0,:,:],extent=(ax1_min,ax1_max,ay1_min,ay1_max),aspect="auto")
#plt.imshow(yint2d[0,:,:],aspect="auto")
#plt.colorbar()


#plt.imshow(yint2d[0,:,:],aspect="auto")
#plt.colorbar()


#     ++++++++++
#++++++1D check++++++
#     ++++++++++
#plt.plot(xint,yint2d[0,100,:],'ro')
#plt.plot(x,data2_2[380,100,:],'bo')

#plt.grid()
#plt.show()

#print(yint2d.shape)

#ipv.figure()
#ipv.quickvolshow(yint2d)
#ipv.quickvolshow(data2_2)

#ipv.show()

"""
#B_SCAN_IMAGE
fig, host=plt.subplots(figsize=(15,18))

plt.title('item_name',fontsize=40)
plt.grid()

par1 = host.twiny()
par2 = host.twiny()

par2.spines["top"].set_position(("axes",1.1))
make_patch_spines_invisible(par2)
par2.spines["top"].set_visible(True)


par1_min=data_2.loc[0,['SC_Lat']]               
par1_max=data_2.loc[len(data_2)-1,['SC_Lat']]
par2_min=data_2.loc[0,['SC_Long']]               
par2_max=data_2.loc[len(data_2)-1,['SC_Long']]


ax1_min=0
ax1_max=len(data_2)*0.075
ay1_min=1000*0.025
ay1_max=0

#host.imshow(B_SCAN_IMAGE,'rainbow', aspect="auto")
#host.imshow(B_SCAN_IMAGE,'rainbow', aspect="auto")
host.imshow(B_SCAN_IMAGE,extent=(ax1_min,ax1_max,ay1_min,ay1_max),aspect="auto")


#B_SCAN_IMAGE_LIMIT
#host.set_ylim(ay1_min,ay1_max)
host.set_xlim(ax1_min,ax1_max)
par1.set_xlim(par1_min.item(),par1_max.item())
par2.set_xlim(par2_min.item(),par2_max.item())

#B_SCAN_IMAGE_LABEL

host.set_ylabel('DEPTH [KM]', fontsize=15)
host.set_xlabel('DISTANCE [KM]', fontsize=15)
par1.set_xlabel('LATITUDE [DEGREE]', fontsize=15)
par2.set_xlabel('LONGITUDEE [DEGREE]', fontsize=15)

#B_SCAN_IMAGE_TICK
host.tick_params(which="both", width=2)
host.tick_params(which="major",length=7)
par1.tick_params(which="both", width=2)
par1.tick_params(which="major",length=7)
par2.tick_params(which="both", width=2)
par2.tick_params(which="major",length=7)

#B_SCAN_IMAGE_MINORTICK
host.minorticks_on()
host.tick_params(which="minor",length=4,color='r')
par1.minorticks_on()
par1.tick_params(which="minor",length=4,color='r')
par2.minorticks_on()
par2.tick_params(which="minor",length=4,color='r')


#INTESNTIY#
plt.figure()
plt.title('item_number',fontsize=40)

plt.grid()

plt.plot(INTENSITY,color='black')

xt=np.arange(0,1200,200)
plt.xticks(xt,(i*0.025 for i in xt),fontsize=10)

plt.ylabel("INTENSITY [dB]",fontsize=20)
plt.xlabel("Depth [km]",fontsize=20)
plt.tick_params(which="both", width=2)
plt.tick_params(which="major",length=7)
plt.minorticks_on()
plt.tick_params(which="minor",length=4,color='r')
"""

#plt.show()



