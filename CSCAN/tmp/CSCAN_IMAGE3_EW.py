import numpy as np
import matplotlib.pyplot as plt
from matplotlib import cm, colors
import pandas as pd
from pandas import Series, DataFrame 
import math

#PATH
#Miho
input_path="/home/changwan/GPR_DATA/KOREA/MIHO_ri/40MHz/2023/EW/3D_CUBE_GPR.txt"

#READ DATASET
read_1=np.loadtxt(input_path)
read_2 = pd.DataFrame(read_1, columns=["data","x","y","z"])


print("input_shape=", read_2.shape)

#(dis, tra, rows)
dis = 41
tra = 18
rows = 4096

data_1 = np.zeros( shape = (dis, tra, rows) )


x_l = list(range(1,dis+1))
y_l = list(range(1,tra+1))
z_l = list(range(1,rows+1))

#print(x_l)
#print(read_2)


#print(read_2[(read_2["z"]==1) & (read_2["y"]==1) ])

for y in y_l : 
   for x in x_l :
#       for x in x_l :
        line_1 = read_2[(read_2["x"]==int(x)) & (read_2["y"]==int(y))]
#        print("line_1=",line_1)
#        print (x, y)
#        print(data_1[:,0,0].shape)
#        print(line_1.loc[:,["data"]].T.shape)
#        print(line_1.loc[:,["data"]].values.shape)
#        print(data_1[x:x+1,y:y+1,:].shape,  line_1.loc[:,["data"]].T.shape)
#        print (x,y)
        #data_1[x:x+1,y:y+1,:] = line_1.loc[:,["data"]].T
        data_1[x-1,y-1,:] = line_1.loc[:,["data"]].T


        #data_1[:,y,z] = line_1.loc[:,["data"]]



        #data_1[:][int(y)][int(z)] = line_1.loc[:,["data"]].T

#test
#line_1 = read_2[(read_2["z"]==int(1)) & (read_2["y"]==int(1))]
#print(line_1)
#print(line_1.loc[:,["data"]])
#print(line_1.loc[:,["data"]].shape)
#print(data_1[:,1,1].shape)




"""
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

#RESAHPE THE INPUT DATA
print("input_shape=",data2.shape)    

#data2_2=data2.reshape(1900,17,4096)

#Miho-ri
#202303
data2_2=data2.reshape(41,18,4096)


print("3D_shape (x,y,z) =",data2_2.shape)
print("+++++++++++++++++++++")
print("\n")

fig,host =plt.subplots()

print(data2_2.shape[2])

ax1_min=0
#ax1_max=data2_2.shape[0]*0.01  #This is Northing.
ax1_max=data2_2.shape[0]*0.5  #This is Northing.


ay1_min=0
ay1_max=data2_2.shape[1]*0.5 #This is Easting.
#make a uppder-left figure zero.
#ay1_max=0
#ay1_min=data2_2.shape[1]*0.5 #This is Easting.



#cmap=colors.ListedColormap(["white","blue","red"])



#     ++++++++++++++++++++++
#++++++Before interploation++++++
#     ++++++++++++++++++++++
#start = 1000
#end   = 2000

#40MHz
start = 1037
end   = 2000


rows=list(range(start,end,1))


dis_s = 0
dis_e = data2_2.shape[0]
dis=list(range(dis_s,dis_e,1))

#PLEASE CHECK THE DIRECTION OF THE GRAPH.
#Check the direction of the graph
#data2_2[100:300,3,start] = 1000000*100000 
#data2_2[100:200,:,start+1] = 1000000*100000 

#     ++++++++++++++++++++
#++++++Remove the average++++++
#     ++++++++++++++++++++

#remote the noise of the cable
##for depth in rows:
#data2_2[:,:,depth] = data2_2[:,:,depth] - np.mean(data2_2[:,:,depth])
##for east in dis:
## data2_2[east,:,depth] = data2_2[east,:,depth] \
##                         - np.mean(data2_2[east,:,depth])
plt.rcParams['font.size'] = 15

#direction check
#data2_2[:,2,1100] = 1000000
#data2_2[10,2,1100] = 1000000
#data2_2[10,2,1050] = 1000000
 
for depth in rows:
# data2_2[:,:,depth] = data2_2[:,:,depth] - np.mean(data2_2[:,:,depth])


#Transpose the C_scan, and
#Flip the C_scan when it comes to up and down
#Becasue I consider the tendency the imhosw plots.
 #plt.imshow(np.flipud(data2_2[:,:,depth].T)
 plt.imshow(np.flipud(data2_2[:,:,depth].T)


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
"""
