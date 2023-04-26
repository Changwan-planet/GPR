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
input_path2 = "/home/changwan/GPR_DATA/KOREA/MIHO_ri/40MHz/2023/NS/3D_CUBE_GPR.txt"
#input_path2 = "/home/changwan/GPR_DATA/KOREA/MIHO_ri/3D_trench/40MHz/CSCAN3/NS/3D_CUBE_GPR.txt"



#READ DATASET
#data=np.loadtxt(input_path1)
data2=np.loadtxt(input_path2)


#CALCULATE THE DISTANCE INTERVAL:
c_sl = 3*10**8   # speed of light
#t_window = 10**(-7)
permit = 16.0
#depth_range = t_window * (c_sl/math.sqrt(permit)) * 0.5 
depth_range = 50
#permit = 
sample = 4096

depth_int = (depth_range/ sample) 
depth_int2 = round(depth_int, 2)

print("\n")
print("++++++DATA INFO++++++")
print("depth_interval=",depth_int)

#C_SCAN_IMAGE

#RESAHPE THE INPUT DATA
print("input_shape=",data2.shape)    
#40MHz
line = 18 
points  = 41
data2_2=data2.reshape(points,line,sample)
data2_3=data2.reshape(points,line,sample)

data2_4=np.zeros(shape=(points,1,sample))
data2_4_m=np.zeros(shape=(points,1,sample))



print("3D_shape (x,y,z) =",data2_2.shape)
print("+++++++++++++++++++++")
print("\n")

fig,host =plt.subplots()

print(data2_2.shape[0])
print(data2_2.shape[1])
print(data2_2.shape[2])


dis_int = 0.5
ax1_min=0
ax1_max=data2_2.shape[0]* dis_int #This is Easting.
ay1_min=data2_2.shape[2]* depth_int #This is Depth.
ay1_max=0

print(ay1_min)
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
#start =  0
#end   = line
#end   = 3

start = 12 
#end   = line
end = 18 
#end   = 21


lines=list(range(start,end,1))
samples=list(range(0,sample,1,))

dis_s = 0
dis_e = data2_2.shape[0]
dis=list(range(dis_s,dis_e,1))
dis = dis_e *dis_int
#PLEASE CHECK THE DIRECTION OF THE GRAPH.
#Check the direction of the graph
#data2_2[10:20,1,start] = 1000000*100000 
#data2_2[70:80,1,start] = -1000000*100000 
#data2_2[3,30:40,start] = -1000000*100000 
#data2_2[1:10,30,start] = -1000000*100000 


#processing

for line in lines:
    print("summed lines")
    print("line=",line)
    data2_4[:,0,:]= data2_4[:,0,:] + data2_3[:,line,:]

#data2_4[:,0,:]= data2_4[:,0,:] + data2_3[:,1,:] + data2_3[:,3,:]  + data2_3[:,5,:]+ data2_3[:,7,:]
#data2_4[:,0,:]= data2_4[:,0,:] + data2_3[:,0,:] + data2_3[:,2,:]  + data2_3[:,4,:]+ data2_3[:,6,:]


data2_4_m = data2_4/(end-start)


#     ++++++++++++++++++++
#++++++Remove the average++++++
#     ++++++++++++++++++++

#remove the noise of the cable
##for depth in rows:
## data2_2[:,:,depth] = data2_2[:,:,depth] - np.mean(data2_2[:,:,depth])
##for east in dis:
## data2_2[east,:,depth] = data2_2[east,:,depth] \
##                         - np.mean(data2_2[east,:,depth])

#for line in lines:
# for depth in samples:
#     data2_3[line,:,depth] = data2_2[line,:,depth] - np.mean(data2_2[line,:,depth])

#line = 1

#Transpose the C_scan, and
#Flip the C_scan when it comes to up and down
#Becasue I consider the tendency the imhosw plots.
# plt.imshow((data2_2[:,:,depth].T)
# plt.imshow(np.flipud(data2_2[:,:,depth].T)

#plt.imshow(np.fliplr(data2_4_m[:,0,:].T)
plt.imshow(data2_4_m[:,0,:].T
           ,extent=(ax1_min,ax1_max,ay1_min,ay1_max)
           #,cmap='gist_rainbow'
            ,cmap="Greys_r" 
)
#Almost similar in with and without the interpolation.
#,interpolation = 'spline16')
 
plt.colorbar()
#plt.text(37,15,'[dB]', fontweight="bold",fontsize=15) 

#colorbar

#plt.clim(10**(7),-10**(7))
plt.clim(10**(6),-10**(6))
#plt.clim(10**(5),-10**(5))


 #depth_title = round(((depth-start) * depth_int), 2)
 #d
#plt.title("BSCAN MIHO-ri_160 MHz_YY_Pol.", fontweight="bold", fontsize=20)
plt.title("BSCAN MIHO-ri_40 MHz_YY_Pol.", fontweight="bold", fontsize=20)


#Track interval 
plt.ylabel("Depth [m]", fontweight="bold",fontsize=20)
#Distance interval
#plt.xlabel("Easting [m]  int_0.23 m", fontweight="bold",fontsize=20)
plt.xlabel("Easting [m]  int_0.5 m", fontweight="bold",fontsize=20)


#Ticks
plt.xticks(fontsize=15, fontweight="bold")
plt.yticks(fontsize=15, fontweight="bold")
 
#subgroup
thick = 10
#enlarged view2-southern miho
ss = 11.5      #subgroup start
se = ss+thick  #subgroup end

#full view
#ss = 0  #subgroup start, zero-level moderator 
#se = ay1_min  #subgroup end


plt.xticks(np.arange(0,20,2),np.arange(0,20,2),fontsize=15, fontweight="bold")
#plt.yticks(np.arange(ss,se),np.arange((ss-ss)-1,(se-ss)-1,1),fontsize=15, fontweight="bold")
plt.yticks(np.arange(ss,se),np.arange((ss-ss)-1,(se-ss)-1,1),fontsize=15, fontweight="bold")

#Ticks limit
#plt.xlim(0,26)
plt.xlim(0,20)

#enlarged view2-southern miho
es = ss
plt.ylim(es+thick,es)

#full view
#plt.ylim(se,ss)



#Grid
# plt.grid()

#tight_layout
# plt.tight_layout()

# plt.show(block=False)
#plt.draw()

#Wait for the button press
#plt.waitforbuttonpress()
 
#Keep changing the graph with a 0.05 s pause.
# plt.pause(0.05)

#fig.clear()

plt.show()

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



