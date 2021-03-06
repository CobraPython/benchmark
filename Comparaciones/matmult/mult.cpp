//en este programa se realiza el tiempo de computo en la multiplicación
//de matrices. 



#include <stdio.h>
#include <time.h>
#include<math.h>
#include <windows.h>




int N[]={2,20,30,50,100,200,500,1000,1200,1500};  //N representa la dimension nxn de una matriz cuadrada


int N_rep=10; //repeticiones para tener la estadística
//    |
//    | 
double temp[10]; //Un vector que almacena los tiempos de cada repetición 
//para luego obtener el promedio y la varianza

//Se busca cuidar la gestión de memoria, por lo cual se necesita reservar 
//espacio y liberarlo. En el caso de un vector es trivial.

//Para el caso de matrices bidimensionales que necesitan un tamano que vaya cambiando
//y no tener problemas de memoria, la reserva dinamica de memoria 
//se realiza en dos partes:

    // Asignar memoria a una matriz de punteros, cuyos elementos referencian 
//cada una de las filas de la matriz de dos dimensiones que se desea crear.

    // Asignar memoria para cada una de las filas. El número de elementos de 
//cada fila puede ser variable.


//En este caso específico usamos matrices cuadradas, es decir, filas = columnas
// por lo que unsamos el N 


int **matrizA;  //declaramos un puntero de punteros
int **matrizB;
int **matrizC;

float promedio; 
float varianza;



LARGE_INTEGER t_ini, t_fin;
float secs;

FILE *fp;



double performancecounter_diff(LARGE_INTEGER *a, LARGE_INTEGER *b)
{
  LARGE_INTEGER freq;
  QueryPerformanceFrequency(&freq);
  return (double)(a->QuadPart - b->QuadPart) / (double)freq.QuadPart;
}



int main()
{
fp = fopen ( "tiemposmatmultC.csv", "w" );    
fprintf(fp,"# N elementos procesados,Tiempo Promedio[ms],STD Tiempo [ms] \n");

for(int k=0;k<10;k++)     //este bucle es para cada valor de N[k]
{

matrizA = (int **)malloc (N[k]*sizeof(int *));
for (int i=0;i<N[k];i++)
{
matrizA[i] = (int *) malloc (N[k]*sizeof(int));
}

matrizB = (int **)malloc (N[k]*sizeof(int *));
for (int i=0;i<N[k];i++)
{
matrizB[i] = (int *) malloc (N[k]*sizeof(int));
}

matrizC = (int **)malloc (N[k]*sizeof(int *));
for (int i=0;i<N[k];i++)
{
matrizC[i] = (int *) malloc (N[k]*sizeof(int));
}


srand(time(NULL));
int i,j;
for(i=0;i<N[k];i++){
for(j=0;j<N[k];j++){
matrizA[i][j]= rand()%100;
matrizB[i][j]= rand()%100;
}
}


for(int m=0;m<N_rep;m++)  // Este bucle es para hacer la estadistica con N_rep 
{


	QueryPerformanceCounter(&t_ini);
  /* ...hacer algo... */  	
	for(int i=0;i<N[k];i++)
	{
		for(int j=0;j<N[k];j++)
		{
			for(int g=0;g<N[k];g++)
			{
			matrizC[i][j]+=matrizA[i][g]*matrizB[g][j];	
			}
			
		}
	}
  	 QueryPerformanceCounter(&t_fin);
  
  	temp[m]= 1000*performancecounter_diff(&t_fin, &t_ini);  //*1000 para que el valor sea ms
 }

 free (matrizA);
 free (matrizB);
 free (matrizC);

secs=0;
for(int j=0;j<N_rep;j++)
{
secs+=temp[j];
}

promedio=secs/N_rep; // Calcula el tiempo promedio.

secs=0;
for(int j=0;j<N_rep;j++)
{
secs+=pow(temp[j]-promedio,2);
}

varianza = sqrt(secs/(N_rep-1));   //calcula la varianza

fprintf(fp,"%.0d,%.5f,%.5f\n",N[k],promedio,varianza);
}
fclose (fp);
return 0;
}
