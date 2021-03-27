#include<stdio.h>
#include <time.h>
#include<math.h>

int main()
{



clock_t tiempo_inicio, tiempo_final;
double segundos;

tiempo_inicio = clock();
/*operación a medir tiempos, operación básica del código, normalmente bucles*/
printf("programa corriendo \n");



for(int i=0; i<2000000; i++) 
    { 
       float a = log(pow(i, 4)); 
    } 
tiempo_final = clock();
segundos = (double)(tiempo_final - tiempo_inicio) / CLOCKS_PER_SEC; /*según que estes midiendo el tiempo en segundos es demasiado grande*/

printf("%.9f\n",segundos); 
printf("*-*-*-*-*-*-*-\n");
printf("%ld\n", CLOCKS_PER_SEC); 
printf("%ld\n", tiempo_inicio); 
printf("%ld\n", tiempo_final); 


}
