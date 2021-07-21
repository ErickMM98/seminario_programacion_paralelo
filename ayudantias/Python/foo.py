import numpy as np
import pandas as pd 
import matplotlib.pyplot as plt 
import sklearn

df = sklearn.datasets.load_iris()

#plt.style.use('fivethirtyeight')
#fig, ax = plt.subplots()

#x = np.linspace(-10,10, 150)
#y = np.sin(x)

#ax.plot(x,y, marker ='s', color = 'pink')

#plt.show()

df = sklearn.datasets.load_iris()
print(df.head())