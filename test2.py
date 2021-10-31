import matplotlib.pyplot as plt
import pandas as pd
import numpy as np

path="/home/changwan/GPR/B_SCAN_IMAGE_GPR.txt"

data = np.loadtxt(path)

print(data.shape)

plt.imshow(data[500:800,:])
plt.show()
