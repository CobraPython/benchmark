// Este programa soluciona el producto escalar de dos vectores
// de distintos tamanos y calcula el tiempo de computo.

 
#include <stdio.h>
#include <time.h>
#include<math.h>
#include <windows.h>




//Se necesitan declarar 2 vectores
//con un tamano maximo de 1^8

//double n[] ={2,3,4,5,6,7,8,9,10};   //un array que declara las potencias de 10 que tendra N
double N[]={1.00000000e+05, 1.43844989e+05, 2.06913808e+05, 2.97635144e+05,
       4.28133240e+05, 6.15848211e+05, 8.85866790e+05, 1.27427499e+06,
       1.83298071e+06, 2.63665090e+06, 3.79269019e+06, 5.45559478e+06,
       7.84759970e+06, 1.12883789e+07, 1.62377674e+07, 2.33572147e+07,
       3.35981829e+07, 4.83293024e+07, 6.95192796e+07, 1.00000000e+08};
int N_rep=100;
double temp[100];


int* vectorA;
int* vectorB;
double valorC;



double promedio; 
double varianza;

LARGE_INTEGER t_ini, t_fin;
double secs;


FILE *fp;

/* retorna "a - b" en segundos */
double performancecounter_diff(LARGE_INTEGER *a, LARGE_INTEGER *b)
{
  LARGE_INTEGER freq;
  QueryPerformanceFrequency(&freq);
  return (double)(a->QuadPart - b->QuadPart) / (double)freq.QuadPart;
}


int main()
{


fp = fopen ( "tiemposCdotprod.csv", "w" );        

//Ahora se procede a crear los vectores que tendran distinto tamanho 
//con numeros generados aleatoreamente. Para lo cual vemos necesario
//el uso de memoria dinámica -> el primer calculo sera con 1000 datos
//y el final con 10 millones por lo cual para evitar un probable y posible
//volteo de memoria creamos y liberamos espacio para cada caso de calculo


//El tiempo obtenido, no es necesariamente el mismo cuando se repite el calculo para 
//algun N. Por lo cual se repite 30 veces y se calcula el estimador promedio
//como su desviación estandar.


printf("# N elementos procesados,Tiempo Promedio[ms],STD Tiempo [ms] \n");
fprintf(fp,"# N elementos procesados,Tiempo Promedio[ms],STD Tiempo [ms] \n");
 for(int i=0;i<20;i++)
 {
 vectorA = (int*)malloc(N[i]*sizeof(int));
 vectorB = (int*)malloc(N[i]*sizeof(int));
 if(vectorA==NULL && vectorB==NULL)
 	{
 	perror("Problemas reservando memoria");
 	exit (1);
 	}

srand(time(NULL)); //Iniciamos la generación de números pseudoaleatorios con un seed
	
for(int k=0;k<N_rep;k++)
	{
// Llenamos los vectores A y B con aleatoreos.
	for(int j=0;j<N[i];j++)
 		{
 		vectorA[j]= rand();	
 		vectorB[j]= rand();	
 		}
//Tomamos el tiempo inicial para calcular  el tiempo de proceso
  	
	valorC=0;
	QueryPerformanceCounter(&t_ini);
  /* ...hacer algo... */  	

	
//realizamos la operación del producto escalar.
  	for(int j=0;j<N[i];j++)
  		{
 			valorC+=vectorA[j]*vectorB[j];
 		}

 	 QueryPerformanceCounter(&t_fin);


 	temp[k]= 1000*performancecounter_diff(&t_fin, &t_ini);  //*1000 para que el valor sea ms
 	}

	free (vectorA);
	free (vectorB);

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

 	printf("%.0f,%.5f,%.5f\n",N[i],promedio,varianza);
 	fprintf(fp,"%.0f,%.5f,%.5f\n",N[i],promedio,varianza);

  }


fclose (fp);
return 0;
}
