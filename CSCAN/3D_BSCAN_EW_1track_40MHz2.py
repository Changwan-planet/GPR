import numpy as np
import matplotlib.pyplot as plt
from matplotlib import cm, colors
from scipy.interpolate import interp1d

#import ipyvolume as ipv
#import cv2
import math

#PATH
#input_path="/home/changwan/GPR_DATA/KOREA/MIHO_ri/40MHz/2023/EW/attribute/3D_HILBERT_powerdB.txt"
input_path="/home/changwan/GPR_DATA/KOREA/MIHO_ri/3D_trench/40MHz/CSCAN3/EW/3D_CUBE_GPR.txt"


#READ DATASET
inputdata = np.loadtxt(input_path)

#extract the values and their coordinates
values = inputdata[:, 0]
coords = inputdata[:, 1:].astype(int) - 1 #subtract 1 due to indices starting at 0

#create your matrix
#(dis, tra, rows)
dis = 41
tra = 21
rows = 4096

data_1 = np.zeros( shape = (dis, tra, rows) )

#fill in your matrix at the appropriate coordinates
data_1.flat[np.ravel_multi_index(coords.T, data_1.shape)] = values


#CALCULATE THE DISTANCE INTERVAL:
#c_sl = 3*10**8   # speed of light
#t_window = 10**(-7)
#permit = 16.0
depth_range = 50
#depth_range = t_window * (c_sl/math.sqrt(permit)) * 0.5 
 
sample = 4096

dis_int = 0.5

depth_int = (depth_range/ sample) 
depth_int2 = round(depth_int, 2)

print("\n")
print("++++++DATA INFO++++++")
print("depth_interval=",depth_int)

#C_SCAN_IMAGE

#RESAHPE THE INPUT DATA
print("input_shape=",data_1.shape)    
#40MHz

print("3D_shape (x,y,z) =",data_1.shape)
print("+++++++++++++++++++++")
print("\n")

fig,host =plt.subplots()

print(data_1.shape[2])

ax1_min=0
#ax1_max=data_1.shape[0]*0.01  #This is Northing.
ax1_max=data_1.shape[0] * dis_int   #This is Northing.

ay1_min=0
ay1_max=data_1.shape[1] * dis_int   #This is Easting.

ay2_max=0
ay2_min=data_1.shape[2] * depth_int #This is Easting.


#cmap=colors.ListedColormap(["white","blue","red"])

#     ++++++++++++++++++++++
#++++++Before interploation++++++
#     ++++++++++++++++++++++
start = 1037
end   = 2000


rows = list(range(start,end,1))

#samples=list(range(0,sample,1,))

dis_s = 20
dis_e = data_1.shape[0]
dis=list(range(dis_s,dis_e,1))
#dis = dis_e *dis_int

#PLEASE CHECK THE DIRECTION OF THE GRAPH.
#Check the direction of the graph
#data2_2[10:20,1,start] = 1000000*100000 
#data2_2[70:80,1,start] = -1000000*100000 
#data2_2[3,30:40,start] = -1000000*100000 
#data2_2[1:10,30,start] = -1000000*100000 

#     ++++++++++++++++++++
#++++++Remove the average++++++
#     ++++++++++++++++++++

line = 20

#Transpose the C_scan, and
#Flip the C_scan when it comes to up and down
#Becasue I consider the tendency the imhosw plots.
# plt.imshow((data2_2[:,:,depth].T)
# plt.imshow(np.flipud(data2_2[:,:,depth].T)
plt.imshow(data_1[:,line,:].T
           ,extent=(ax1_min,ax1_max,ay2_min,ay2_max)
           #,cmap='gist_rainbow'
            ,cmap="Greys_r" 
)

#Almost similar in with and without the interpolation.
#,interpolation = 'spline16')
 
plt.colorbar()
#plt.text(37,15,'[dB]', fontweight="bold",fontsize=15) 

#colorbar
#Amp
plt.clim(10**(6),-10**(6))
#plt.clim(10**(5),-10**(5))

#Power
#plt.clim(10,-10)
#plt.clim(0,-100)

#depth_title = round(((depth-start) * depth_int), 2)

#plt.title("BSCAN MIHO-ri_160 MHz_YY_Pol.", fontweight="bold", fontsize=20)
plt.title("BSCAN MIHO-ri_40 MHz_YY_Pol.", fontweight="bold", fontsize=20)


#Track interval 
plt.ylabel("Depth [m]", fontweight="bold",fontsize=20)
#Distance interval
plt.xlabel("Easting [m] dis_int=0.5 m", fontweight="bold",fontsize=20)

#Ticks
plt.xticks(fontsize=15, fontweight="bold")
plt.yticks(fontsize=15, fontweight="bold")





plt.show()

"""

#subgroup
thick = 10
#enlarged view_2-Northern Miho-100 m depth range
ss = 0 #subgroup start
se = ss+thick  #subgroup end


#enlarged view_3-Northern Miho m depth range
#ss = 11.5 #subgroup start
#se = 25.5  #subgroup end

#full view
#ss = 0      #subgroup start
#se = ay1_min  #subgroup end

plt.xticks(np.arange(0,26,2),np.arange(0,26,2),fontsize=15, fontweight="bold")


#plt.yticks(np.arange(ss,se),np.arange((ss-ss)-1,(se-ss)-1,1),fontsize=15, fontweight="bold")
#enlarged view
plt.yticks(np.arange(ss,se,1),np.arange((ss-ss)-1,(se-ss)-1,1),fontsize=15, fontweight="bold")

#Ticks limit
plt.xlim(0,20)

#enlarged view_2-Northen Miho- 100 m depth range
#es = ss
#plt.ylim(es+5,es)

#enlarged view_3-Norhern Miho-100 m depth range
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
"""
