import numpy as np
import matplotlib.pyplot as plt
import pandas as pd
from pandas import Series, DataFrame 


input_path1="/home/changwan/GPR/A_scope_GPR.txt"
input_path2="/home/changwan/GPR/B_SCAN_IMAGE_GPR.txt"
input_path3="/home/changwan/GPR/INTENSITY_PROFILE_GPR.txt"
input_path4="/home/changwan/GPR/INTENSITY_PROFILE2_GPR.txt"


A_SCOPE=np.loadtxt(input_path1)
B_SCAN_IMAGE=np.loadtxt(input_path2)
INTENSITY_PROFILE=np.loadtxt(input_path3)
INTENSITY_PROFILE2=np.loadtxt(input_path4)



plt.figure(figsize=(5,5))
plt.plot(A_SCOPE)


plt.figure(figsize=(10,10))
#B_SCAN_IMAGE.info()
print(B_SCAN_IMAGE.shape)
plt.imshow(B_SCAN_IMAGE)



plt.figure(figsize=(20,15))
plt.subplot(2,1,1)
plt.plot(INTENSITY_PROFILE)
plt.subplot(2,1,2)
plt.plot(INTENSITY_PROFILE2)

plt.show()
