import numpy as np 
import time

N=np.array([1.00000000e+06, 1.17210230e+06, 1.37382380e+06, 1.61026203e+06,
       1.88739182e+06, 2.21221629e+06, 2.59294380e+06, 3.03919538e+06,
       3.56224789e+06, 4.17531894e+06, 4.89390092e+06, 5.73615251e+06,
       6.72335754e+06, 7.88046282e+06, 9.23670857e+06, 1.08263673e+07,
       1.26896100e+07, 1.48735211e+07, 1.74332882e+07, 2.04335972e+07,
       2.39502662e+07, 2.80721620e+07, 3.29034456e+07, 3.85662042e+07,
       4.52035366e+07, 5.29831691e+07, 6.21016942e+07, 7.27895384e+07,
       8.53167852e+07, 1.00000000e+08])
t=[]
N_rep=100;


f = open ('tiemposNPYdotprod.csv','wb')

headers = ('N elementos procesados','Tiempo Promedio[ms]','STD Tiempo [ms]')
#Creamos el vector con los N elementos
for i in N:
	for j in range(0,N_rep-1):
		vectorA=np.random.rand(int(i))
		vectorB=np.random.rand(int(i))

		inicio = time.time()
		vectorC=np.dot(vectorA,vectorB)
		fin = time.time()
		t.append(inicio-fin)

	temp=np.array(t)
	
	tiempo_ms=temp.mean()
	var=temp.var()
	b=55
	print('%d'%b)
	f.write("%d"%b,fieldnames=headers)