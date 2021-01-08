import numpy as np
import matplotlib.pyplot as plt
import pandas as pd
from pandas import Series, DataFrame 
from mpl_toolkits.mplot3d import Axes3D
from io import BytesIO
import math


input_path3="/home/changwan/GPR/INTENSITY_PROFILE_GPR.txt"
input_path4="/home/changwan/GPR/INTENSITY_PROFILE2_GPR.txt"
#input_path5="/home/changwan/GPR/C_SCAN_IMAGE_GPR.txt"
#input_path6="/home/changwan/GPR/C_SCAN_IMAGE_GPR_flip.txt"
#input_path6="/home/changwan/GPR/3D_IMAGE_GPR.txt"




#A_SCOPE=np.loadtxt(input_path1)
#B_SCAN_IMAGE=np.loadtxt(input_path2)
INTENSITY_PROFILE=np.loadtxt(input_path3)
INTENSITY_PROFILE2=np.loadtxt(input_path4)
#C_SCAN_IMAGE=np.loadtxt(input_path5)
#C_SCAN_IMAGE2=np.loadtxt(input_path6)




##CUBE_IMAGE=np.loadtxt(input_path)
#im = plt.imread(input_path)
#im.shppe

"""
plt.figure(figsize=(5,5))
plt.plot(A_SCOPE)


plt.figure(figsize=(10,10))
#B_SCAN_IMAGE.info()
print(B_SCAN_IMAGE.shape)
plt.imshow(B_SCAN_IMAGE)
"""


plt.figure(figsize=(20,15))
plt.subplots_adjust(left=0.125, bottom=0.1,  right=0.9, top=0.9, wspace=0.2, hspace=0.35)
plt.subplot(2,1,1)
plt.plot(INTENSITY_PROFILE)
plt.title('INTENSITY',fontsize=20)

plt.grid()

xt=np.arange(0,4095,500)
#TW=90/(3*10**9) #TIME_WINDOW
DW=90                 #DISTANCE_WINDOW, DISTANCE  THAT THE LIGHT MOVES.
SF=4096 #SAMPLING FREQUENCY
DP=16 #DIELECTRIC PERMITTIVITY
DISTANCE_STEP=(DW/SF)/math.sqrt(DP)

plt.xticks(xt,(i*round(DISTANCE_STEP,2) for i in xt),fontsize=10)

plt.ylabel("INTENSITY [dB]",fontsize=20)
plt.xlabel("Depth [m],  $\epsilon_r$=16",fontsize=20)
plt.tick_params(which="both", width=2)
plt.tick_params(which="major",length=7)
plt.minorticks_on()
plt.tick_params(which="minor",length=4,color='r')


################################################################

plt.subplot(2,1,2)
plt.plot(INTENSITY_PROFILE2)
plt.title('INTENSITY_INTEGRATION',fontsize=20)
plt.grid()

xt=np.arange(0,4095,500)
#TW=90/(3*10**9) #TIME_WINDOW
DW=90                 #DISTANCE_WINDOW, DISTANCE  THAT THE LIGHT MOVES.
SF=4096 #SAMPLING FREQUENCY
DP=16 #DIELECTRIC PERMITTIVITY
DISTANCE_STEP=(DW/SF)/math.sqrt(DP)

plt.xticks(xt,(i*round(DISTANCE_STEP,2) for i in xt),fontsize=10)

plt.ylabel("INTENSITY [dB]",fontsize=20)
plt.xlabel("Depth [m],  $\epsilon_r$=16",fontsize=20)
plt.tick_params(which="both", width=2)
plt.tick_params(which="major",length=7)
plt.minorticks_on()
plt.tick_params(which="minor",length=4,color='r')


"""
plt.figure(figsize=(10,10))
#C_SCAN_IMAGE.info()
print(C_SCAN_IMAGE.shape)
plt.subplot(1,2,1)
plt.imshow(C_SCAN_IMAGE)

plt.subplot(1,2,2)
plt.imshow(C_SCAN_IMAGE2)

#fig=plt.figure()
#C_SCAN_IMAGE.info()
#print(CUBE_IMAGE.shape)
#plt.imshow(CUBE_IMAGE)
"""


plt.show()
