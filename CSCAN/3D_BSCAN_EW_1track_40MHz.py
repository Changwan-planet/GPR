import numpy as np
import matplotlib.pyplot as plt
from matplotlib import cm, colors
from mpl_toolkits.mplot3d import Axes3D

from bokeh.layouts import gridplot
from bokeh.plotting import figure, show


#import ipyvolume as ipv
#import cv2
import math

#PATH
input_path2 = "/home/changwan/GPR_DATA/KOREA/MIHO_ri/3D_trench/40MHz/BSCAN/EW/3DCUBE_GPR_stacking.txt"


#READ DATASET
data2=np.loadtxt(input_path2)



#CALCULATE THE DISTANCE INTERVAL:
c_sl = 3*10**8   # speed of light
t_window = 10**(-7)
depth_range = 50
#permit = 
sample = 4096

depth_int = (depth_range/ sample) 
depth_int2 = round(depth_int, 2)

print("\n")
print("++++++DATA INFO++++++")
print("depth_interval=",depth_int)

#C_SCAN_IMAGE

point = 41
l = 4 

#RESAHPE THE INPUT DATA
print("input_shape=",data2.shape)    
#40MHz
data2_2=data2.reshape(l, point, sample)
data2_3=data2.reshape(l, point, sample)


print("3D_shape (x,y,z) =",data2_2.shape)
print("+++++++++++++++++++++")
print("\n")

#bscan = np.zeros(shape=(point,sample))
#bscan = data2_2[0.:,:]

plot = figure(x_range=(0,1), y_range=(0,1), toolbar_location=None)
r = plot.image(data2_2[0,:,:])

show(plot)


