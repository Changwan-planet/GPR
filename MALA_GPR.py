import numpy as np
import matplotlib.pyplot as plt
import MALA_GPR_signal
##############################################

#SAMPLE=308    # 512 + 52 ==>2256 bytes

SAMPLE=560

#TYPE SAMPLE FROM THE SAMPLE BELOW AFTER DIVIDING TWO

#SAMPLE=432    #800 MHz 

#SAMPLE=616    #500 MHz

#SAMPLE=560    #250 MHz   

#SAMPLE=1128   #50  MHz


DISTANCE=1000
AMPLITUDE=np.zeros((SAMPLE,DISTANCE))
INTENSITY=np.zeros((SAMPLE,1))
B_SCAN_IMAGE=np.zeros((SAMPLE,DISTANCE))
B_R=np.zeros((SAMPLE,DISTANCE))
MN=np.zeros((SAMPLE))
Window_running=np.zeros((SAMPLE,DISTANCE-5))
##############################################


##############################################
input_path="/home/Client/Jupyter/Python/Mogod_GPR/Pr-1/250 MHz/Profile01.rd3"
#input_path="/home/Client/Jupyter/Python/MALA/Profile02.rd3"
#input_path="/home/Client/Jupyter/Python/MALA/Channel-1/Profile050_500MHz.rd3"
output_path="GPR_MALA_test.txt"
##############################################

##############################################
with open(input_path, "rb") as f2:
  #f2.read(38352) #36864+372x4=38352

 
  for i in range (DISTANCE):   
   for a in range(SAMPLE):
    data1 = f2.read(4) # 1 sample=4 bytes   
    AMPLITUDE[a,0] = np.frombuffer(data1,dtype="i4")
    #AMPLITUDE = AMPLITUDE.astype(np.float64) 
    #INTENSITY[a,0]=AMPLITUDE[a,0]**2 
    

    #B_SCAN_IMAGE[:,i]=INTENSITY[:,0]
   B_SCAN_IMAGE[:,i] = AMPLITUDE[:,0]   #CAUTION FOR INDENATAION!!!

    #print("a=",b)
    #print("i=",i)

  B_R=MALA_GPR_signal.background_remove(B_SCAN_IMAGE,DISTANCE)
  MN =MALA_GPR_signal.mean(B_SCAN_IMAGE,DISTANCE)
  Window_running=MALA_GPR_signal.running_window(B_SCAN_IMAGE,DISTANCE)

##############AMPLITUDE#######################
#fig, axes = plt.subplots(2,2,figsize=(10,10))
#axes[0,0].plot(HEADERCHECK[:],'r')
#axes[0,0].plot(AMPLITUDE[:,0],'r')
#axes[0,0].plot(AMPLITUDE[:,1],'b')
#axes[0,0].plot(AMPLITUDE[:,2],'g')
#axes[0,0].plot(AMPLITUDE[:,3],'k')
#axes[0,1].plot(AMPLITUDE[0:200,2])
#axes[1,0].plot(AMPLITUDE[50:250,3])
#axes[1,1].plot(AMPLITUDE[100:300,4])
#for ax in axes.ravel():
#    ax.margins(0.05)
#fig.suptitle("GPR_MALA")
##############################################


##############INTENSITY#######################
#fig, axes = plt.subplots(2,2,figsize=(10,10))
#axes[0,0].plot(INTENSITY[1:],'r')
#axes[0,1].plot(INTENSITY[2:],'b')
#axes[1,0].plot(INTENSITY[:],'g')
#axes[1,1].imshow(B_SCAN_IMAGE[0:50][0:50])

#for ax in axes.ravel():
#    ax.margins(0.05)
#fig.suptitle("GPR_MALA")
##############################################


##############B_SCAN_IMAGE#######################
#fig, axes = plt.subplots(2,2,figsize=(10,10))
#axes[0,0].plot(B_SCAN_IMAGE[:,1],'r')
#axes[0,0].plot(B_SCAN_IMAGE[:,2],'b')
#axes[0,0].plot(B_SCAN_IMAGE[:,3],'g')
#axes[0,0].plot(B_SCAN_IMAGE[:,4],'k')
#axes[0,0].plot(B_SCAN_IMAGE[:,5],'r')
#axes[0,0].plot(B_SCAN_IMAGE[:,6],'b')
#axes[0,0].plot(B_SCAN_IMAGE[:,7],'g')
#axes[0,0].plot(B_SCAN_IMAGE[:,8],'k')
#axes[1,1].imshow(B_SCAN_IMAGE)

#axes[1,1].imshow(B_SCAN_IMAGE[:])
#for ax in axes.ravel():
#    ax.margins(0.05)
#fig.suptitle("GPR_MALA")
##############################################

#GRAPH 2
 
plt.figure(figsize=(20,15))
 
plt.subplot(2,2,1)
plt.imshow(B_SCAN_IMAGE[0:200,:])
plt.title("Raw_B_SCAN_IMAGE")
plt.grid()
plt.minorticks_on()
 
x=np.arange(len(B_SCAN_IMAGE[0:200]),0,-1)
"""
plt.subplot(2,2,2)
plt.plot(B_SCAN_IMAGE[0:200,800],x,'b',label="A_SCOPE From Raw")
plt.legend()
plt.grid()
plt.minorticks_on()
"""

plt.subplot(2,2,3)
plt.imshow(B_R[0:200,:])
plt.title("B_SCAN_IMAGE_AFTER_BR_remove")
plt.grid()
plt.minorticks_on()

"""
#y=np.arange(len(S_B))
plt.subplot(2,2,2)
plt.plot(B_R[0:200,800],x,'r',label="A-SCOPE From BR_remove")
plt.legend()
plt.grid()
plt.minorticks_on()
"""

#Comparison for MN and Window_running
#MN is a average of each row.
#Window_running is a average of window of row.
plt.subplot(2,2,2)
plt.plot(MN[0:200],x,'g',label='Mean_B_SCAN[Fortran]')
plt.legend()
plt.grid()
plt.minorticks_on()

plt.subplot(2,2,2)
plt.plot(Window_running[0:200,400],x,'pink',label='Window_running')
plt.legend()
plt.grid()
plt.minorticks_on()

#plt.imshow(B_R[0:50,])
#plt.plot(B_SCAN_IMAGE)
plt.show()
##############################################

##############################################
#np.savetxt(output_path,Sample,fmt="%i")
##############################################
