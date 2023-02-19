import numpy as np
import math
import matplotlib.pyplot as plt
import GSSI_PROGRAM as GP
 

#PATH
#common_path="/home/changwan/GPR/"
#common_path="/home/changwan/GPR/2020_11(three tombs)/201109_2.PRJ/"
#common_path="/home/changwan/GPR/2020_11(three tombs)/201110_2.PRJ/"
#common_path="/home/changwan/GPR/2020_11(three tombs)/201109.PRJ/"
#common_path="/home/changwan/GPR/2020_11(three tombs)/201109_3.PRJ/"
common_path="/home/changwan/GPR/2020_11(three tombs)/201109.PRJ/"


item_number1="201109__008.DZT"
input_path=common_path+item_number1

#Label

HEADER=32769  #THE BYTE OF HEADER IS 32769.
ROWS=4096     #THIS VALUE IS FIXED.
DISTANCE=3324 #THIS VALUE IS CHANGABLE.

#HEADER, intialization
PARSING=np.zeros(HEADER,dtype=np.int)
	
#DATA
SIGNAL_TIME_DOMAIN=np.zeros((ROWS,1))
B_SCAN_IMAGE=np.zeros((ROWS,DISTANCE))
IMAGE_MEAN=np.zeros(ROWS)
IMAGE_AFTER_REMOVE_BG=np.zeros((ROWS,DISTANCE))
a,c,d,i=0,0,0,0


with open(input_path, "rb") as f:

 for i in range(HEADER):

#Header 

  BYTE_HEADER=f.read(4)   
  PARSING[i]=np.frombuffer(BYTE_HEADER,dtype="i4")


#DATA
 for d in range(DISTANCE):
 
  for a in range(ROWS):	

   BYTE_DATA=f.read(4)	   
   SIGNAL_TIME_DOMAIN[a][0]=np.frombuffer(BYTE_DATA,dtype="<i4")

  for c in range(ROWS):
   
   B_SCAN_IMAGE[c][d]=SIGNAL_TIME_DOMAIN[c][0]


#SINGAL PROCESSING

IMAGE_AFTER_REMOVE_BG=GP.remove_background(B_SCAN_IMAGE)
IMAGE_MEAN=GP.mean_profile(B_SCAN_IMAGE)




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

plt.figure(figsize=(15,11))
plt.suptitle(item_number1,fontsize=20)                                 #TOTAL TITLE

plt.subplot(2,1,1)

plt.imshow(B_SCAN_IMAGE[ROWS_GRAPH_UP:ROWS_GRAPH_DOWN],'gray')
xt=np.arange(0,DISTANCE,100)
#yt=np.arange(ROWS_GRAPH_UP,ROWS_GRAPH_DOWN,100)

plt.colorbar()

plt.xticks(xt,(i*0.05 for i in xt),fontsize=10)
#plt.yticks(yt,(i for i in yt),fontsize=20)
plt.minorticks_on()
plt.tick_params(which="both", width=2)
plt.tick_params(which="major",length=7)
plt.tick_params(which="minor",length=4,color='r')

plt.xlabel("DISTANCE [m]",fontsize=15)
plt.ylabel("SAMPLE",fontsize=15)
plt.title('B_SCAN_IMAGE',fontsize=15)                                  #SUBTITLE
#plt.tight_layout()



#IMAGE_AFTER_REMOVE_BG
plt.subplot(2,1,2)                     
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
plt.title('IMAGE_AFTER_REMOVE_BG',fontsize=15)                       #SUBTITLE
#plt.tight_layout()
#"""

#A-SCOPE

plt.figure(figsize=(6,10))
SPOT=600
x=np.arange(0,4096,1)
plt.gca().invert_yaxis()
plt.plot(B_SCAN_IMAGE[x,SPOT], x, color='red',label='B_SCAN_IMAGE')
plt.plot(IMAGE_MEAN[x],x,color='green',label='MEAN_PROFILE')
plt.plot(IMAGE_AFTER_REMOVE_BG[x,SPOT], x, color='blue', label='IMAGE_AFTER_REMOVE_BG')
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


#test
#plt.plot(IMAGE_REAL_POWER)


plt.show()

      
