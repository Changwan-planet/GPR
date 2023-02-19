import matplotlib.pyplot as plt
import pandas as pd
import numpy as np

path="/home/changwan/GPR/B_SCAN_IMAGE_GPR.txt"

data = np.loadtxt(path)
#data_2 = pd.DataFrame(data)

print(data.shape)
print("RESHAPE THE MATRIX")
print("TYPE THE SHAPE THAT YOU WANT TO MAKE")

i = input("TYPE THE ROW = ")
j = input("TYPE THE COLUMN = ")

print("i=", i)
print("j=", j)

i = int(i)
j = int(j)

data=data.reshape(i,j)
print(data.shape)

plt.imshow(data)
plt.show()
