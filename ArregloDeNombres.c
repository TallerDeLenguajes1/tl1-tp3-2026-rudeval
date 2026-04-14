#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main (){

    char buff[50];
    char * Cadena[5]; 

    for (int i = 0; i < 6; i++)
    {
        printf("Ingrese nombre %d", i +1);
        scanf("%s", buff);
        int tamanioDeCadenaIngresadaPorUsuario = strlen(buff); // no considera el caracter nulo por lo tanto devuelve 10
   
        Cadena[i] = (char *) malloc (sizeof(char) * tamanioDeCadenaIngresadaPorUsuario + 1); // Reserva de memoria para la cadena pero aumento 1 byte para el carcter nulo
        strcpy(Cadena[i], buff); 
    }
    
     
    printf("%s",Cadena);
    
    getchar(); //?  

    return 0;
}