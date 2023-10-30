import numpy as np

import matplotlib.pyplot as plt
from matplotlib import cm
from matplotlib.colors import LinearSegmentedColormap

from scipy.interpolate import interp1d
from tifffile import imwrite 

import math

def create_and_register_slice_cmap():
    colors = ["#FFFFFF", "#9C9C9C", "#333333", "blue", "#007FFF", "cyan", "#7FFF7F", "yellow", "#FF7F00", "red"]
    n = 256
    slice_cmap = LinearSegmentedColormap.from_list("slice", colors, N=n)
    plt.cm.register_cmap(name='slice', cmap=slice_cmap)
# Create and register the custom color map
create_and_register_slice_cmap()



#PATH
#KOREA
#MIHO
#input_path2 = "/home/changwan/GPR_DATA/KOREA/MIHO_ri/40MHz/2023/NS/attribute/3D_HILBERT_powerdB.txt"
#input_path2 = "/home/changwan/GPR_DATA/KOREA/MIHO_ri/2022_BOMIN/Raw/Miho11H/3DCUBE_GPR_noprocessing.txt" 

#input_path2 = "/home/changwan/GPR_DATA/KOREA/MIHO_ri/2022_BOMIN/Edit_data/Miho11/STACK_CUBE/attribute/3D_HILBERT_powerdB_MaxdB.txt" 

input_path2 = "/home/changwan/GPR_DATA/KOREA/MIHO_ri/2022_BOMIN/Edit_data/Miho11/STACK_CUBE/attribute/3D_HILBERT_powerdB.txt" 


#READ DATASET
#data=np.loadtxt(input_path1)
inputdata=np.loadtxt(input_path2)

#extract the coordinates and the value
coords = inputdata[:,0:3].astype(int)
values = inputdata[:,3]

dis = 218
tra = 56
rows = 512

print(coords)

data_1 = np.zeros( shape = (dis, tra, rows) )
data_1.flat[np.ravel_multi_index(coords.T, data_1.shape)] = values

#CALCULATE THE DISTANCE INTERVAL:
#KOREA
c_sl = 3*10**8   # speed of light
depth_range = 30 # m 
permit = 16
sample = 512
depth_int = (depth_range/np.sqrt(permit))/ sample 
depth_int = round(depth_int, 2)

#MOGOD
#c_sl = 3*10**8   # speed of light
#t_window = 213.457859*10**(-9)
#t_window = 139.303478*10.0**(-9)

#permit = 9.0
#depth_range = t_window*(c_sl/np.sqrt(permit))
#sample = 512.0
#sample = 616.0
#sample = 542.0
#depth_int = depth_range/ sample 
#depth_int = round(depth_int, 2)

print("\n")
print("++++++DATA INFO++++++")
print("depth_interval=",depth_int)

#C_SCAN_IMAGE


print("3D_shape (x,y,z) =",data_1.shape)
print("+++++++++++++++++++++")
print("\n")

fig,host =plt.subplots()

print(data_1.shape[2])

#KOREA
ax1_min=0
ax1_max=data_1.shape[0]*0.25  #This is Northing.
ay1_min=0
ay1_max=data_1.shape[1]*0.25 #This is Eastilng.

#MOGOD
#ax1_min=0
#ax1_max=data_1.shape[0]*0.05  #This is Northing.
#ay1_min=0
#ay1_max=data_1.shape[1]*1   #This is Eastilng.


#     ++++++++++++++++++++++
#++++++Before interploation++++++
#     ++++++++++++++++++++++
#start =  0
#end   =  4
#rows=list(range(start,end,1))


#start =  900
#end   = 1050

start = 1
end   = 300

rows=list(range(start,end,1))

dis_s = 0
dis_e = data_1.shape[0]
dis=list(range(dis_s,dis_e,1))

tra_s = 0
tra_e = data_1.shape[1]
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
#     data_1[:,east,depth] = data_1[:,east,depth] \
#                              - np.mean(data_1[:,east,depth])

#p_depth = 53
#imwrite("INSTANT_powerdB_34.tif",data_1[:,:,34]) 
#imwrite("INSTANT_powerdB_34.tif",np.flipud(data_1[:,:,34])) 



#reverse colormap
#color_map = plt.cm.get_cmap('magma')
color_map = plt.cm.get_cmap('slice')


#reversed_color_map = color_map.reversed()


for depth in rows:
# data_1[:,:,depth] = data_1[:,:,depth] - np.mean(data_1[:,:,depth])

#Transpose the C_scan, and
#Flip the C_scan when it comes to up and down
#Becasue I consider the tendency the imhosw plots.

# if(depth==34):
# if(depth==53):
  #plt.imshow(np.flipud(data_1[:,:,depth])
  plt.imshow(data_1[:,:,depth]
           ,extent=(ay1_min,ay1_max,ax1_min,ax1_max)
#           ,cmap='gist_rainbow')
           ,cmap=color_map


#Almost similar in with and without the interpolation.
,interpolation = 'spline16')


#colorbar
  plt.colorbar()
#colorbar range
#  plt.clim(17,-5)
#  plt.clim(0,-30)


#colorbar titile
  plt.text(115,90, '[dB]', fontweight="bold", fontsize=15)

  depth_title = round(((depth-start) * depth_int), 2)
  print(depth_title,"m", "sample=",depth)

 #plt.title("Gyodong-ri_100 MHz_EW_Pol.", fontweight="bold", fontsize=30)
 #plt.title("MOGOD_500 MHz_EW_Pol.", fontweight="bold", fontsize=30)
  plt.title("MIHO_450 MHz.", fontweight="bold", fontsize=30)

#Track interval 
#  plt.ylabel("Northing [m] interval=0.05 m", fontweight="bold", fontsize=20)
  plt.ylabel("Y [m] interval=0.25 m", fontweight="bold", fontsize=20)


#Distance interval
  plt.xlabel("X [m] interval=0.25 m", fontweight="bold", fontsize=20)

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

