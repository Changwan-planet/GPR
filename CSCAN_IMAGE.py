import numpy as np
import matplotlib.pyplot as plt
import pandas as pd
from pandas import Series, DataFrame 


def make_patch_spines_invisible(ax):
    ax.set_frame_on(True)
    ax.patch.set_visible(False)
    for sp in ax.spines.values():
        sp.set_visible(False)

#PATH
input_path1="/home/changwan/GPR/C_SCAN_IMAGE_GPR_flip.txt"
input_path2="/home/changwan/GPR/3D_IMAGE_GPR.txt"



#READ DATASET
data=np.loadtxt(input_path1)
data2=np.loadtxt(input_path2)


#C_SCAN_IMAGE
######READ HEADER#######
ROW = np.linspace(0,(data.shape[0]-1),data.shape[0],dtype='int64')
COL = np.linspace(0,(data.shape[1]-1),data.shape[1],dtype='int64')
#data_2=pd.DataFrame(data,index=ROW,columns=COL)
data_2=pd.DataFrame(data)


data_2.info()
print('\n')
print("data_2.shape=",data_2.shape)

print('\n')
print(data_2.head())
print(data_2.tail())
#########################

#C_SCAN_IMAGE.info()
print('\n')
print("C_SCAN_IMAGE.shape=",data_2.shape)

ax1_min=0
ax1_max=data.shape[0]*0.05
ay1_min=0
ay1_max=data.shape[1]*0.5

print("data.shape[0]",data.shape[0])
print("data.shape[1]",data.shape[1])

print("ax1_min=",ax1_min)
print("ax1_max=",ax1_max)
print("ay1_min=",ay1_min)
print("ay1_max=",ay1_max)


fit, host=plt.subplots()
plt.grid()
host.imshow(data_2,extent=(ax1_min,ax1_max,ay1_min,ay1_max),aspect="auto")
########


#3D_CUBE
data2_2=pd.Panel(data2)

print(data2_2)




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

plt.show()



