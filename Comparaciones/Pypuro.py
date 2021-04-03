# -*- coding: utf-8 -*-
"""
Created on Wed Mar 31 08:54:18 2021

@author: UnseR
"""
#librerias
from timeit import default_timer as timer
import random
#declaracion de variables
N=[1.00000000e+05, 1.43844989e+05, 2.06913808e+05, 2.97635144e+05,
       4.28133240e+05, 6.15848211e+05, 8.85866790e+05, 1.27427499e+06,
       1.83298071e+06, 2.63665090e+06, 3.79269019e+06, 5.45559478e+06,
       7.84759970e+06, 1.12883789e+07, 1.62377674e+07, 2.33572147e+07,
       3.35981829e+07, 4.83293024e+07, 6.95192796e+07, 1.00000000e+08]
#Lista de enteros a usar, copia del programa de numpy
V=[]
for i in N:
    j=int(i)
    V.append(j)

#funcion para llenar los vectores vacios, argumento un entero
def llenado(n):
    x1=[]
    for i in range(n):
        x1.append(random.random()) #numeros aleatorios entre 0 y 1
    return x1

#funcion para multiplicar escalarmente dos vectores
def mult(x1,y1):
    x3=[]
    for i in range(len(x1)):
        a=x1[i]*y1[i]
        x3.append(a)
    return x3

#funcion para el promedio
def avg(t):
    s=0
    for i in t:
       s=s+i
    av=s/len(t)
    return av

#codigo principal
file=open("data.csv", "w")
file.write("N Datos,Tiempo Promedio\n")
#funcion main
for i in V:
    t=[]
    for j in range(3):
        x1=llenado(i)
        y1=llenado(i)
        s=timer()
        mult(x1,y1)
        f=timer()
        t.append(f-s)
    a=str(i)+","+str(avg(t))+"\n"
    file.writelines(a)
file.close()