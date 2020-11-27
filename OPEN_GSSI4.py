import numpy as np
import math
import matplotlib.pyplot as plt
import GSSI_PROGRAM as GP
import GPR_MODULE as GM

#PATH
#common_path="/home/changwan/GPR/"
#common_path="/home/changwan/GPR/2020_11(three tombs)/201109_2.PRJ/"
#common_path="/home/changwan/GPR/2020_11(three tombs)/201110_2.PRJ/"
#common_path="/home/changwan/GPR/2020_11(three tombs)/201109.PRJ/"
#common_path="/home/changwan/GPR/2020_11(three tombs)/201109_3.PRJ/"
#common_path="/home/changwan/GPR/2020_11(three tombs)/201109.PRJ/"
common_path="/home/changwan/GPR/2020_11(three tombs)/201110_3.PRJ/"


item_number1="201110_3__001.DZT"
item_number2="201110_3__002.DZT"

"""
item_number1="201109__002.DZT"
item_number2="201109__003.DZT"
item_number3="201109__004.DZT"
item_number4="201109__005.DZT"
"""

#item_number1="201109_2__001.DZT"
#item_number1="201109_2__001.DZT"
#item_number1="201109_2__001.DZT"
#item_number1="201109_2__001.DZT"

input_path1=common_path+item_number1
input_path2=common_path+item_number2
#input_path3=common_path+item_number3
#input_path4=common_path+item_number4


#LABEL
#HEADER=32769  #THE BYTE OF HEADER IS 32769.
#ROWS=4096     #THIS VALUE IS FIXED.
DISTANCE=input("Type the distance, please") 
DISTANCE=int(DISTANCE)

#SIGNAL PROCESSING
B_SCAN_IMAGE1=GM.GPR_binary(input_path1,DISTANCE)
B_SCAN_IMAGE2=GM.GPR_binary(input_path2,DISTANCE)
#B_SCAN_IMAGE3=GM.GPR_binary(input_path3,DISTANCE)
#B_SCAN_IMAGE4=GM.GPR_binary(input_path4,DISTANCE)

#IMAGE_AFTER_REMOVE_BG=GP.remove_background(B_SCAN_IMAGE)
#IMAGE_MEAN=GP.mean_profile(B_SCAN_IMAGE)

test=GM.flip_col(B_SCAN_IMAGE2)
#test2=GM.flip_col(B_SCAN_IMAGE4)


#INTEGRAL_B_SCAN=(B_SCAN_IMAGE1 \
#                + test \
#                + B_SCAN_IMAGE3 \
#                + test2) 

#IMAGE_AFTER_REMOVE_BG=GP.remove_background(INTEGRAL_B_SCAN)
#IMAGE_MEAN=GP.mean_profile(INTEGRAL_B_SCAN)



#GSSI_PROGRAM CHECK
"""
n=500-1
print("******python*******")
print("np.sum(B_SCAN_IMAGE[",n,":]=",np.sum(B_SCAN_IMAGE[n,:]))   
print("np.mean(B_SCAN_IMAGE[",n,":]=",np.mean(B_SCAN_IMAGE[n,:]))

print("IMAGE_MEAN[",n,"]=",IMAGE_MEAN[n])
print("IMAGE_AFTER_REMOVE_BG[",n,"][1]=",IMAGE_AFTER_REMOVE_BG[n][1])

test=B_SCAN_IMAGE[n,1]-np.mean(B_SCAN_IMAGE[n,:])
print("IMAGE_AFTER_REMOVE_BG[",n,"][1]_python=",test)
"""

#GRAPH
#"""
#B-SACAN_IMAGE
ROWS_GRAPH_UP=600
ROWS_GRAPH_DOWN=800

plt.figure(figsize=(15,20))
#plt.tight_layout()
#plt.subplots_adjust(bottom=-0.05)
#plt.suptitle("test", position=(0,-0.05), fontsize=10)                     #TOTAL TITLE

plt.subplot(2,1,1)

plt.imshow(B_SCAN_IMAGE1[ROWS_GRAPH_UP:ROWS_GRAPH_DOWN],'gray')
xt=np.arange(0,DISTANCE,100)
#yt=np.arange(ROWS_GRAPH_UP,ROWS_GRAPH_DOWN,50)
#yt=np.arange(600,800,50)

plt.colorbar()

plt.xticks(xt,(i*0.05 for i in xt),fontsize=10)
#plt.yticks(yt,(i for i in yt),fontsize=10)
plt.minorticks_on()
plt.tick_params(which="both", width=2)
plt.tick_params(which="major",length=7)
plt.tick_params(which="minor",length=4,color='r')

#plt.xlabel("DISTANCE [m]",fontsize=15)
plt.ylabel("SAMPLE",fontsize=15)
plt.title(item_number1,fontsize=10, position=(-0.2,0))                                 #SUBTITLE



#flip_col
plt.subplot(2,1,2)                     
#plt.figure(figsize=(15,8))

plt.imshow(test[ROWS_GRAPH_UP:ROWS_GRAPH_DOWN],'gray')

xt=np.arange(0,DISTANCE,100)
#yt=np.arange(ROWS_GRAPH_UP,ROWS_GRAPH_DOWN,50)

plt.colorbar()

plt.xticks(xt,(i*0.05 for i in xt),fontsize=10)
#plt.yticks(yt,(i for i in yt),fontsize=20)
plt.minorticks_on()
plt.tick_params(which="both", width=2)
plt.tick_params(which="major",length=7)
plt.tick_params(which="minor",length=4,color='r')

#plt.xlabel("DISTANCE [m]",fontsize=15)
plt.ylabel("SAMPLE",fontsize=15)
plt.title(item_number2,fontsize=10, position=(-0.2,0))                       #SUBTITLE

"""
#B-SACAN_IMAGE3
ROWS_GRAPH_UP=600
ROWS_GRAPH_DOWN=800

#plt.figure(figsize=(15,11))
#plt.suptitle(item_number1,fontsize=20)                     #TOTAL TITLE

plt.subplot(5,1,3)

plt.imshow(B_SCAN_IMAGE3[ROWS_GRAPH_UP:ROWS_GRAPH_DOWN],'gray')
xt=np.arange(0,DISTANCE,100)
#yt=np.arange(ROWS_GRAPH_UP,ROWS_GRAPH_DOWN,50)
#yt=np.arange(600,800,50)

plt.colorbar()

plt.xticks(xt,(i*0.05 for i in xt),fontsize=10)
#plt.yticks(yt,(i for i in yt),fontsize=10)
plt.minorticks_on()
plt.tick_params(which="both", width=2)
plt.tick_params(which="major",length=7)
plt.tick_params(which="minor",length=4,color='r')

#plt.xlabel("DISTANCE [m]",fontsize=15)
plt.ylabel("SAMPLE",fontsize=15)
plt.title(item_number3,fontsize=10, position=(-0.2,0))                                  #SUBTITLE


#B-SACAN_IMAGE4
ROWS_GRAPH_UP=600
ROWS_GRAPH_DOWN=800

#plt.figure(figsize=(15,11))
#plt.suptitle(item_number1,fontsize=20)                     #TOTAL TITLE

plt.subplot(5,1,4)

plt.imshow(test2[ROWS_GRAPH_UP:ROWS_GRAPH_DOWN],'gray')
xt=np.arange(0,DISTANCE,100)
#yt=np.arange(ROWS_GRAPH_UP,ROWS_GRAPH_DOWN,50)
#yt=np.arange(600,800,50)

plt.colorbar()

plt.xticks(xt,(i*0.05 for i in xt),fontsize=10)
#plt.yticks(yt,(i for i in yt),fontsize=10)
plt.minorticks_on()
plt.tick_params(which="both", width=2)
plt.tick_params(which="major",length=7)
plt.tick_params(which="minor",length=4,color='r')

#plt.xlabel("DISTANCE [m]",fontsize=15)
plt.ylabel("SAMPLE",fontsize=15)
plt.title(item_number4,fontsize=10, position=(-0.2,0))                                  #SUBTITLE


#integral
plt.subplot(5,1,5)                     
#plt.figure(figsize=(15,8))

plt.imshow(INTEGRAL_B_SCAN[ROWS_GRAPH_UP:ROWS_GRAPH_DOWN],'gray')

xt=np.arange(0,DISTANCE,100)
#yt=np.arange(ROWS_GRAPH_UP,ROWS_GRAPH_DOWN,50)

plt.colorbar()

plt.xticks(xt,(i*0.05 for i in xt),fontsize=10)
#plt.yticks(yt,(i for i in yt),fontsize=20)
plt.minorticks_on()
plt.tick_params(which="both", width=2)
plt.tick_params(which="major",length=7)
plt.tick_params(which="minor",length=4,color='r')

plt.xlabel("DISTANCE [m]",fontsize=15)
plt.ylabel("SAMPLE",fontsize=15)
plt.title('INTEGRAL_B_SCAN',fontsize=10, position=(-0.2,0))                       #SUBTITLE


#IMAGE_AFTER_REMOVE_BG
plt.subplot(5,1,5)                     
#plt.figure(figsize=(15,8))

plt.imshow(IMAGE_AFTER_REMOVE_BG[ROWS_GRAPH_UP:ROWS_GRAPH_DOWN],'gray')

xt=np.arange(0,DISTANCE,100)
#yt=np.arange(ROWS_GRAPH_UP,ROWS_GRAPH_DOWN,50)

plt.colorbar()

plt.xticks(xt,(i*0.05 for i in xt),fontsize=10)
#plt.yticks(yt,(i for i in yt),fontsize=20)
plt.minorticks_on()
plt.tick_params(which="both", width=2)
plt.tick_params(which="major",length=7)
plt.tick_params(which="minor",length=4,color='r')

plt.xlabel("DISTANCE [m]",fontsize=15)
plt.ylabel("SAMPLE",fontsize=15)
plt.title('IMAGE_AFTER_REMOVE_BG',fontsize=10, position=(-0.2,0))                       #SUBTITLE
"""
"""
#A-SCOPE

plt.figure(figsize=(6,10))
SPOT1=580
SPOT2=585
SPOT3=590
SPOT4=595
SPOT5=600
SPOT6=700
#x=np.arange(0,4096,1)
x=np.arange(650,700,1)
plt.gca().invert_yaxis()


plt.plot(INTEGRAL_B_SCAN[x,SPOT1], x, color='red',label='INTEGRAL_B_SCAN_580')
plt.plot(INTEGRAL_B_SCAN[x,SPOT2], x, color='orange',label='INTEGRAL_B_SCAN_585')
plt.plot(INTEGRAL_B_SCAN[x,SPOT3], x, color='yellow',label='INTEGRAL_B_SCAN_590')
plt.plot(INTEGRAL_B_SCAN[x,SPOT4], x, color='green',label='INTEGRAL_B_SCAN_595')
plt.plot(INTEGRAL_B_SCAN[x,SPOT5], x, color='blue',label='INTEGRAL_B_SCAN_600')
plt.plot(INTEGRAL_B_SCAN[x,SPOT6], x, color='black',label='INTEGRAL_B_SCAN_700')


plt.plot(B_SCAN_IMAGE1[x,SPOT1], x, color='red',label='B_SCAN_IMAGE1_580')
plt.plot(test[x,SPOT1], x, color='orange',label='B_SCAN_IMAGE2_580')
plt.plot(B_SCAN_IMAGE3[x,SPOT1], x, color='yellow',label='B_SCAN_IMAGE3_580')
plt.plot(test2[x,SPOT1], x, color='green',label='B_SCAN_IMAGE4_580')


plt.plot(IMAGE_AFTER_REMOVE_BG[x,SPOT1], x, color='red',label='IMAGE_AFTER_REMOVE_BG_580')
plt.plot(IMAGE_AFTER_REMOVE_BG[x,SPOT2], x, color='orange',label='IMAGE_AFTER_REMOVE_BG_585')
plt.plot(IMAGE_AFTER_REMOVE_BG[x,SPOT3], x, color='yellow',label='IMAGE_AFTER_REMOVE_BG_590')
plt.plot(IMAGE_AFTER_REMOVE_BG[x,SPOT4], x, color='green',label='IMAGE_AFTER_REMOVE_BG_595')
plt.plot(IMAGE_AFTER_REMOVE_BG[x,SPOT5], x, color='blue',label='IMAGE_AFTER_REMOVE_BG_600')
plt.plot(IMAGE_AFTER_REMOVE_BG[x,SPOT6], x, color='black',label='IMAGE_AFTER_REMOVE_BG_700')



#
#plt.plot(IMAGE_MEAN[x],x,color='green',label='MEAN_PROFILE')
#plt.plot(IMAGE_AFTER_REMOVE_BG[x,SPOT], x, color='blue', label='IMAGE_AFTER_REMOVE_BG')
#plt.plot(INTEGRAL_B_SCAN[x,SPOT], x, color='blue',label='INTEGRAL_B_SCAN')
#
#xt=np.arange(0,4000,100)
#plt.xticks(xt,(i for i in xt),fontsize=10)
plt.grid()
plt.minorticks_on()
plt.tick_params(which="both",width=2)
plt.tick_params(which="major",length=7)
plt.tick_params(which="minor",length=4,color='r')
plt.legend()
plt.xlabel("AMPLITUDE",fontsize=20)
plt.ylabel("SAMPLE",fontsize=20)
plt.title("A-SCOPE",fontsize=30)
"""

#test
#plt.plot(IMAGE_REAL_POWER)


plt.show()

 


