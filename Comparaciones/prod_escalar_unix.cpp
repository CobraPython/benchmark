//El calculo de tiempo es mas complejo en C
//debido a que contiene metodos y formas
//distintas para cada plataforma.

//Este programa esta pensado para correrse bajo
//sistema Linux en RaspberryPi3

//El concepto temporal que se esta aplicando merece
// una descripción mas amplia.
// Se pueden medir dos tiempos de procesamiento
// el tiempo de pared y el tiempo de cpu 

// El tiempo de pared mide a modo de cronómetro el inicio 
// final de un procedimiento.
// El tiempo de cpu mide unicamente el tiempo de procesamiento
// sin contar el tiempo de E/S de lso byters del registro de datos

//En este sentido se mide el tiempo de pared incluyendo
//el tiempo del registro en E/S. Convenientemente eso 
//mide en python la libreria time


 // El siguiente ejemplo mide el tiempo de pared,
 // pero puede modificarlo para medir el tiempo
 // de CPU simplemente reemplazando la constante 
 // CLOCK_REALTIMEcon CLOCK_PROCESS_CPUTIME_ID.

#include <stdio.h>
#include <time.h>
#include<math.h>


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


double secs;


FILE *fp;
struct timespec begin, end; 

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

clock_gettime(CLOCK_REALTIME, &begin);
	
//realizamos la operación del producto escalar.
  	for(int j=0;j<N[i];j++)
  		{
 			valorC+=vectorA[j]*vectorB[j];
 		}

 clock_gettime(CLOCK_REALTIME, &end);

 long seconds = end.tv_sec - begin.tv_sec;
 long nanoseconds = end.tv_nsec - begin.tv_nsec;
 double elapsed = 1000*seconds + nanoseconds*1e-6;
    
 temp[k]= elapsed;
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
