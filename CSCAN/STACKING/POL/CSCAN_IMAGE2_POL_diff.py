import numpy as np
import matplotlib.pyplot as plt
from matplotlib import cm, colors
import pandas as pd
from pandas import Series, DataFrame 

import math

#PATH
#Miho
#Amplitude
#input_path="/home/changwan/GPR_DATA/KOREA/MIHO_ri/40MHz/2023/EW/3D_CUBE_GPR.txt"
#input_path2="/home/changwan/GPR_DATA/KOREA/MIHO_ri/40MHz/2023/NS/3D_CUBE_GPR.txt"

#Power
input_path="/home/changwan/GPR_DATA/KOREA/MIHO_ri/40MHz/2023/EW/attribute/3D_HILBERT_powerdB.txt"
input_path2="/home/changwan/GPR_DATA/KOREA/MIHO_ri/40MHz/2023/NS/attribute/3D_HILBERT_powerdB.txt"


#READ DATASET
read_1=np.loadtxt(input_path)
read_2=np.loadtxt(input_path2)

read_3 = pd.DataFrame(read_1, columns=["x","y","z","data"])
read_4 = pd.DataFrame(read_2, columns=["x","y","z","data"])


#CALCULATE THE DISTANCE INTERVAL:
c_sl = 3*10**8   # speed of light
depth_range = 50 # 90 m 
permit = 16
sample = 4096
depth_int = depth_range/ sample 
depth_int = round(depth_int, 2)

print("\n")
print("++++++DATA INFO++++++")
print("depth_interval=",depth_int)



#C_SCAN_IMAGE
print("EW input_shape=",read_3.shape)    
print("NS input_shape=",read_4.shape)    

#ASSIGN VALUES IN MATRIXES
#(dis, tra, rows)
dis = 41
tra = 18 
rows = 4096

data_1 = np.zeros( shape = (dis, tra, rows) )
data_2 = np.zeros( shape = (dis, tra, rows) )
data_poldif = np.zeros( shape = (dis, tra, rows) )



x_l = list(range(1,dis+1))
y_l = list(range(1,tra+1))
z_l = list(range(1,rows+1))

for y in y_l :
   for x in x_l :
       line_3 = read_3[(read_3["x"]==int(x)) & (read_3["y"]==int(y))]
       line_4 = read_4[(read_4["x"]==int(x)) & (read_4["y"]==int(y))]

       data_1[x-1,y-1,:] = line_3.loc[:,["data"]].T
       data_2[x-1,y-1,:] = line_4.loc[:,["data"]].T


#Miho-ri
#202303
print("EW 3D_shape (x,y,z) =",data_1.shape)
print("NS 3D_shape (x,y,z) =",data_2.shape)


print("+++++++++++++++++++++")
print("\n")

fig,host =plt.subplots()

ax1_min=0
#ax1_max=data_1.shape[0]*0.01  #This is Northing.
ax1_max=data_1.shape[0] * 0.5  #This is Northing.


ay1_min=0
ay1_max=data_1.shape[1] * 0.5 #This is Easting.

ay2_max=0
ay2_min=data_1.shape[2]*depth_int #This is Easting.


#make a uppder-left figure zero.
#ay1_max=0
#ay1_min=data2_2.shape[1]*0.5 #This is Easting.


#40MHz
start = 1037
end   = 2000


rows=list(range(start,end,1))

lines=list(range(0,tra,1))


dis_s = 0
dis_e = data_1.shape[0]
dis=list(range(dis_s,dis_e,1))

plt.rcParams['font.size'] = 15

"""
print("#####BSCAN#####")
for line in lines:
    #EW
    plt.subplot(2,1,1)
    plt.imshow(np.fliplr(data_1[:,line,:].T)
          ,extent=(ax1_min,ax1_max,ay1_min,ay1_max)
           #,cmap='gnuplot'
           ,cmap="Greys_r"
           ,aspect = 3
           )
    plt.colorbar()
    plt.clim(0,-50)
 
    #NS
    plt.subplot(2,1,2)
    plt.imshow(data_2[:,line,:].T
 

          ,extent=(ax1_min,ax1_max,ay1_min,ay1_max)
           #,cmap='gnuplot'
           ,cmap="Greys_r"
           ,aspect = 3
           )
    #s = "line="+ str(line+1)
    plt.colorbar()
    plt.clim(0,-50)
    #plt.clim(-10**(5),10**(5))
    plt.draw()
    plt.waitforbuttonpress()
    fig.clear()
"""


#"""
for depth in rows: 
  #data_poldif[:,:,depth] =  np.flipud(data_2[:,:,depth].T).T- np.fliplr(np.flipud(data_1[:,:,depth].T)).T
  data_poldif[:,:,depth] =  (np.flipud(data_2[:,:,depth].T) - np.fliplr(np.flipud(data_1[:,:,depth].T))).T


#for depth in rows:
#  data_poldif2[x,y,depth] = data_poldif[x,y,depth] / math.max(data_poldif[:,:,depth]
#    data4[:,:,depth] =  np.flipud(data3_2[:,:,depth].T)
#    data4[:,:,depth] =  np.flipud(data2_2[:,:,depth].T).T



    #data4[:,:,depth] =  np.flipud(data2_2[:,:,depth].T)- np.flipud(np.fliplr(data3_2[:,:,depth].T))
 
for depth in rows:
#plt.imshow(np.flipud(data2_2[:,:,depth].T)
 plt.imshow(data_poldif[:,:,depth].T


           ,extent=(ax1_min,ax1_max,ay1_min,ay1_max)
#           ,cmap='gist_rainbow'
           ,cmap= "Greys_r"
#           ,cmap='RdGy' 


#Almost similar in with and without the interpolation.
,interpolation = 'spline16')
 
 plt.colorbar()
 plt.text(37,15,'[dB]', fontweight="bold",fontsize=15) 


 depth_title = round(((depth-start) * depth_int), 2)
 print(depth_title,"m", "sample=",depth)

 plt.title("MIHO_ri 40 MHz_XX_Pol.", fontweight="bold", fontsize=30)

#Track interval 
 plt.ylabel("Y [m] int=0.5 m", fontweight="bold",fontsize=20)
#Distance interval
 plt.xlabel("X [m] int=0.5 m", fontweight="bold",fontsize=20)

#Ticks
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
#"""
