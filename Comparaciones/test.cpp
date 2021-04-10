
#include <stdio.h>
#include <time.h>
#include<math.h>




int N[]={2,20,30,50,100,200,500,1000,1200,1500,2000};


int **matrizA;  //declaramos un puntero de punteros
int **matrizB;
int **matrizC;

int main()
{
matrizA = (int **)malloc (N[0]*sizeof(int *));
for (int i=0;i<N[0];i++)
{
matrizA[i] = (int *) malloc (N[0]*sizeof(int));
}


matrizB = (int **)malloc (N[0]*sizeof(int *));
for (int i=0;i<N[0];i++)
{
matrizB[i] = (int *) malloc (N[0]*sizeof(int));
}

matrizC = (int **)malloc (N[0]*sizeof(int *));
for (int i=0;i<N[0];i++)
{
matrizC[i] = (int *) malloc (N[0]*sizeof(int));
}





srand(time(NULL));

for(int i=0;i<N[0];i++){
for(int j=0;j<N[0];j++){
matrizA[i][j]= rand()%100;
matrizB[i][j]=rand()%100;
}
}

for(int i=0;i<N[0];i++)
{
for(int j=0;j<N[0];j++)
{
for(int g=0;g<N[0];g++)
{
matrizC[i][j]+=matrizA[i][g]*matrizB[g][j];
}
}
}
printf("\n MATRIZ A \n");
for (int i=0;i<N[0];i++){
for (int j=0;j<N[0];j++){
printf("%d ",matrizA[i][j]);
	}
printf("\n");
}

printf("\n MATRIZ B \n");

for (int i=0;i<N[0];i++){
for (int j=0;j<N[0];j++){
printf("%d ",matrizB[i][j]);
        }
printf("\n");
}


printf("\n MATRIZ C \n");
for (int i=0;i<N[0];i++){
for (int j=0;j<N[0];j++){
printf("%d ",matrizC[i][j]);
        }
printf("\n");
}


free(matrizA);
free(matrizB);
free(matrizC);

}
