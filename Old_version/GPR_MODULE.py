#FUNCTION 
import numpy as np

def flip_col(X):
    
    B=np.zeros(X.shape)
    a=len(X)-1
    b=len(X[1,:])-1
    #print(a)
    #print(b)
    #print(X) 
    for i in range(a):
     for k in range(b):
    
        B[i,0+k] = X[i,b-k]
    
    #print(B)
    return B

def GPR_binary(input_path, DISTANCE): 

#LABEL
 HEADER=32769  #THE BYTE OF HEADER IS 32769.
 ROWS=4096     #THIS VALUE IS FIXED.

#HEADER, intialization
 PARSING=np.zeros(HEADER,dtype=np.int)
            
#DATA
 SIGNAL_TIME_DOMAIN=np.zeros((ROWS,1))
 B_SCAN_IMAGE=np.zeros((ROWS,DISTANCE))
 IMAGE_MEAN=np.zeros(ROWS)
 IMAGE_AFTER_REMOVE_BG=np.zeros((ROWS,DISTANCE))
 a,c,d,i=0,0,0,0


#OPEN DATA
 print(input_path)
 #print(HEADER,DISTANCE,ROWS)
 with open(input_path, "rb") as f:
  
  for i in range(HEADER):
  
#HEADER
   
   BYTE_HEADER=f.read(4)
   PARSING[i]=np.frombuffer(BYTE_HEADER,dtype="i4")
   
    
#DATA
  for d in range(DISTANCE):
   
   for a in range(ROWS):
   
    BYTE_DATA=f.read(4)
    SIGNAL_TIME_DOMAIN[a][0]=np.frombuffer(BYTE_DATA,dtype="<i4")
    #print(SIGNAL_TIME_DOMAIN)
   for c in range(ROWS):
    B_SCAN_IMAGE[c][d]=SIGNAL_TIME_DOMAIN[c][0]  
    #print(B_SCAN_IMAGE)
 
  return B_SCAN_IMAGE

