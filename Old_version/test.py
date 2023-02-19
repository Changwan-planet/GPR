import matplotlib.pyplot as plt
import pandas as pd
import numpy as np

path="/home/changwan/GPR/A_SCOPE_GPR.txt"

data = np.loadtxt(path)
data_2 = pd.DataFrame(data)


plt.plot(data_2.loc[:,0])
plt.show()
