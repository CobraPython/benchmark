import numpy as np
import pandas as pd

import matplotlib.pyplot as plt

df_c = pd.read_csv('tiemposmatmultC.csv', sep=',')
df_npy = pd.read_csv('tiemposmatmultPY.csv', sep=',')


N = df_c.iloc[:,0].values


#En C
x_c=df_c.iloc[:,1].values
x_std=df_c.iloc[:,2].values
#numpy
x_npy=df_npy.iloc[:,1].values
x_stdpy=df_npy.iloc[:,2].values

plt.errorbar(N, x_c, yerr=x_std, xerr=0, fmt=".",label='en C')

plt.errorbar(N, x_npy, yerr=x_stdpy, xerr=0, fmt=".",label='en Numpy')
plt.legend(loc='upper left')
plt.xscale('log')
plt.grid()

plt.title('Comparación: Producto Matricial Bidimensional \n en un sistema Windows 10 Intel i7700 HQ')
#plt.title('Comparación: Producto Matricial Bidimensional \n en un sistema Debian sobre RaspberryPi3')


plt.xlabel('Cantidad N de elementos nxn')
plt.ylabel('Tiempo de procesamiento en milisegundos')

#plt.savefig("unix_Benchmarkmatmult.png")
plt.savefig("Benchmarkmatmult.png")



