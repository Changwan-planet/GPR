import numpy as np
import matplotlib.pyplot as plt
import pandas as pd
from pandas import Series, DataFrame 


input_path1="/home/changwan/GPR/A_scope_output.txt"
input_path2="/home/changwan/GPR/B_SCAN_IMAGE_output.txt"



A_SCOPE=np.loadtxt(input_path1)
B_SCAN_IMAGE=np.loadtxt(input_path2)

A_SCOPE_2=pd.DataFrame(A_SCOPE)
B_SCAN_IMAGE_2=pd.DataFrame(B_SCAN_IMAGE)



plt.figure(figsize=(5,5))
plt.plot(A_SCOPE)


plt.figure(figsize=(10,10))

#B_SCAN_IMAGE_2.info()
print(B_SCAN_IMAGE_2.shape)

#B_SCAN_IMAGE=np.transpose(B_SCAN_IMAGE)

#B_SCAN_IMAGE_2.info()
print(B_SCAN_IMAGE_2.shape)

plt.imshow(B_SCAN_IMAGE)
plt.show()


