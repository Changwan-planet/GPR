import numpy as np
import math
import matplotlib.pyplot as plt
import GSSI_PROGRAM as GP
 

#PATH
common_path="/home/changwan/GPR/"
item_number1="200702__014.DZT"
input_path=common_path+item_number1

#Label

HEADER=32769  #THE BYTE OF HEADER IS 32769.
ROWS=4096     #THIS VALUE IS FIXED.
DISTANCE=1329 #THIS VALUE IS CHANGABLE.

#HEADER, intialization
PARSING=np.zeros(HEADER,dtype=np.int)
	
#DATA
SIGNAL_TIME_DOMAIN=np.zeros((ROWS,1))
B_SCAN_IMAGE=np.zeros((ROWS,DISTANCE))
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
   
print(B_SCAN_IMAGE[1][1])
print(IMAGE_AFTER_REMOVE_BG[1][1])

#GRAPH

#A-SCOPE

plt

#B-SACAN_IMAGE
plt.figure(figsize=(15,8))

ROWS_GRAPH_UP=600
ROWS_GRAPH_DOWN=800
#plt.imshow(B_SCAN_IMAGE[ROWS_GRAPH_UP:ROWS_GRAPH_DOWN],'gray')
plt.imshow(IMAGE_AFTER_REMOVE_BG[ROWS_GRAPH_UP:ROWS_GRAPH_DOWN],'gray')

xt=np.arange(0,DISTANCE,100)
yt=np.arange(ROWS_GRAPH_UP,ROWS_GRAPH_DOWN,100)

plt.xticks(xt,(i*0.05 for i in xt),fontsize=20)
plt.yticks(yt,(i for i in yt),fontsize=20)
plt.minorticks_on()

plt.tick_params(which="both", width=2)
plt.tick_params(which="major",length=7)
plt.tick_params(which="minor",length=4,color='r')

plt.xlabel("DISNTACE [m]",fontsize=20)
plt.ylabel("SAMPLE [m]",fontsize=20)

plt.title(item_number1,fontsize=60)




#test
#plt.plot(IMAGE_REAL_POWER)

plt.show()

      
