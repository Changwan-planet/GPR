import numpy as np
import math
import matplotlib.pyplot as plt
import GSSI_PROGRAM as GP
import GPR_MODULE as GM

#PATH
#common_path="/home/changwan/GPR/"
#common_path="/home/changwan/GPR/2020_11(three tombs)/201109_2.PRJ/"
#common_path="/home/changwan/GPR/2020_11(three tombs)/201110_2.PRJ/"
common_path="/home/changwan/GPR/2020_11(three tombs)/201109.PRJ/"
#common_path="/home/changwan/GPR/2020_11(three tombs)/201109_3.PRJ/"
#common_path="/home/changwan/GPR/2020_11(three tombs)/201109.PRJ/"
#common_path="/home/changwan/GPR/2020_11(three tombs)/201110_3.PRJ/"


item_number1="201109__002.DZT"
item_number2="201109__003.DZT"
item_number3="201109__004.DZT"
item_number4="201109__005.DZT"

input_path1=common_path+item_number1
input_path2=common_path+item_number2
input_path3=common_path+item_number3
input_path4=common_path+item_number4


#DATA
INTENSITY=np.zeros((4096,1))


#LABEL
DISTANCE=input("Type the distance, please") 
DISTANCE=int(DISTANCE)

#SIGNAL PROCESSING
B_SCAN_IMAGE1=GM.GPR_binary(input_path1,DISTANCE)
#B_SCAN_IMAGE2=GM.GPR_binary(input_path2,DISTANCE)
#B_SCAN_IMAGE3=GM.GPR_binary(input_path3,DISTANCE)
#B_SCAN_IMAGE4=GM.GPR_binary(input_path4,DISTANCE)

#IMAGE_AFTER_REMOVE_BG=GP.remove_background(B_SCAN_IMAGE)
#IMAGE_MEAN=GP.mean_profile(B_SCAN_IMAGE)

#test=GM.flip_col(B_SCAN_IMAGE2)
#test2=GM.flip_col(B_SCAN_IMAGE4)


#INTEGRAL_B_SCAN=(B_SCAN_IMAGE1 \
#                + test \
#                + B_SCAN_IMAGE3 \
#                + test2) 

#IMAGE_AFTER_REMOVE_BG=GP.remove_background(INTEGRAL_B_SCAN)
#IMAGE_MEAN=GP.mean_profile(INTEGRAL_B_SCAN)

#A-scope-test
#print(B_SCAN_IMAGE1[:,500])
#print(np.power(B_SCAN_IMAGE1[:,500]+2,2))
#print(np.log10(np.power(B_SCAN_IMAGE1[:,500],2)))

#INTENSITY=10*np.log10(np.power(B_SCAN_IMAGE1[:,500],2))

#

for t in range(DISTANCE):
 for k in range(4096) :
  INTENSITY=INTENSITY+10*np.log10(np.power(B_SCAN_IMAGE1[k,t]+1,2))

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
"""
#B-SCAN_IMAGE
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
plt.subplot(2,1,2)                     
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

#A-SCOPE

plt.figure(figsize=(6,10))

SPOT=500
x=np.arange(0,4096,1)
plt.gca().invert_yaxis()

plt.plot(B_SCAN_IMAGE1[x,SPOT], x, color='red',label='B_SCAN_IMAGE1')

#xt=np.arange(0,4000,100)
#plt.xticks(xt,(i for i in xt),fontsize=10)

plt.minorticks_on()
plt.tick_params(which="both",width=2)
plt.tick_params(which="major",length=7)
plt.tick_params(which="minor",length=4,color='r')

plt.legend()
plt.xlabel("AMPLITUDE",fontsize=20)
plt.ylabel("SAMPLE",fontsize=20)
plt.title("A-SCOPE",fontsize=30)
plt.grid()



#A-scope-test

plt.figure(figsize=(6,10))

#plt.gca().invert_yaxis()

#plt.plot(IMAGE_MEAN[x],x,color='green',label='MEAN_PROFILE')
#plt.plot(IMAGE_AFTER_REMOVE_BG[x,SPOT], x, color='blue', label='IMAGE_AFTER_REMOVE_BG')
plt.plot(INTENSITY,color='blue',label='B_SCAN_IMAGE1[500]')

k=90.450005/4096
#k=int(k)
"""
xt=np.arange(1,4097,500)
plt.xticks(xt,(int(i*k) for i in xt),fontsize=10)
plt.grid()
plt.minorticks_on()
plt.tick_params(which="both",width=2)
plt.tick_params(which="major",length=7)
plt.tick_params(which="minor",length=4,color='r')
#plt.legend()
plt.ylabel("Log(Amplitude^2)",fontsize=20)
plt.xlabel("SAMPLE",fontsize=20)
plt.title("A-SCOPE test",fontsize=30)
"""
#plt.plot(IMAGE_REAL_POWER)


plt.show()

 


