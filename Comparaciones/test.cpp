
#include <stdio.h>
#include <time.h>
#include<math.h>



int N[]={2,20,30,50,100,200,500,1000,1200,1500};

int N_rep=10;
double temp[10];

struct timespec begin, end;

FILE *fp;



int **matrizA;  //declaramos un puntero de punteros
int **matrizB;
int **matrizC;

float promedio;
float varianza;




int main()
{


fp = fopen ( "tiemposmatmult.csv", "w" );
fprintf(fp,"# N elementos procesados,Tiempo Promedio[ms],STD Tiempo [ms] \n");


for(int r=0;r<10;r++)
{

matrizA = (int **)malloc (N[r]*sizeof(int *));
for (int i=0;i<N[r];i++)
{
matrizA[i] = (int *) malloc (N[r]*sizeof(int));
}


matrizB = (int **)malloc (N[r]*sizeof(int *));
for (int i=0;i<N[r];i++)
{
matrizB[i] = (int *) malloc (N[r]*sizeof(int));
}

matrizC = (int **)malloc (N[r]*sizeof(int *));
for (int i=0;i<N[r];i++)
{
matrizC[i] = (int *) malloc (N[r]*sizeof(int));
}



srand(time(NULL));

for(int i=0;i<N[r];i++){
for(int j=0;j<N[r];j++){
matrizA[i][j]= rand()%100;
matrizB[i][j]=rand()%100;
}
}


for(int y=0;y<N_rep;y++)
{

clock_gettime(CLOCK_REALTIME, &begin);


for(int i=0;i<N[r];i++)
{
for(int j=0;j<N[r];j++)
{
for(int g=0;g<N[r];g++)
{
matrizC[i][j]+=matrizA[i][g]*matrizB[g][j];
}
}
}

clock_gettime(CLOCK_REALTIME, &end);


long seconds = end.tv_sec - begin.tv_sec;
long nanoseconds = end.tv_nsec - begin.tv_nsec;
double elapsed = 1000*seconds + nanoseconds*1e-6;

temp[y]=elapsed;
}


free(matrizA);
free(matrizB);
free(matrizC);




float secs=0;

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

fprintf(fp,"%d,%.5f,%.5f\n",N[r],promedio,varianza);

}
fclose(fp);
return 0;
}
