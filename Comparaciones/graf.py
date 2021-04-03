import numpy as np
import pandas as pd

import matplotlib.pyplot as plt

df_c = pd.read_csv('unix_tiemposCdotprod.csv', sep=',')
df_npy = pd.read_csv('unix_tiemposNPYdotprod.csv', sep=',')
df_Nsc = pd.read_csv('unix_tiemposNUMERdotprod_score.csv', sep=',')
df_Nmc = pd.read_csv('unix_tiemposNUMERdotprod_mcore.csv', sep=',')



#El N sera siempre el mismo.
#y lo rescatamos del primer dataframe
N = df_c.iloc[:,0].values

#rescatamos los valores del promedio para 
#graficar y comparar

#En C
x_c=df_c.iloc[:,1].values
x_std=df_c.iloc[:,2].values
#numpy
x_npy=df_npy.iloc[:,1].values
x_stdpy=df_npy.iloc[:,2].values
#numexpr 1 nucleo
x_ne_sc=df_Nsc.iloc[:,1].values
x_stdsc=df_Nsc.iloc[:,2].values
#numexpr 8 nucleo
x_ne_mc=df_Nmc.iloc[:,1].values
x_stdmc=df_Nmc.iloc[:,2].values



plt.errorbar(N, x_c, yerr=x_std, xerr=0, fmt=".",label='en C')

plt.errorbar(N, x_npy, yerr=x_std, xerr=0, fmt=".",label='en Numpy')
plt.errorbar(N, x_ne_sc, yerr=x_std, xerr=0, fmt=".",label='en Numexpr 1 core')
plt.errorbar(N, x_ne_mc, yerr=x_std, xerr=0, fmt=".",label='en Numexpr 8 core')

# plt.plot(N,x_c,label='en C')
# plt.plot(N,x_npy,label='en Numpy')
# plt.plot(N,x_ne_sc,label='en Numexpr 1 core')
# plt.plot(N,x_ne_mc,label='en Numexpr 8 core')
plt.legend(loc='upper left')
plt.xscale('log')
plt.grid()
plt.title('Comparacion: Producto Escalar de dos vectores \n En una Rpi3 bajo Debian')
plt.xlabel('Cantidad N de elementos de los vectores')
plt.ylabel('Tiempo de procesamiento en milisegundos')
plt.savefig("BenchmarkDotprod.png")











