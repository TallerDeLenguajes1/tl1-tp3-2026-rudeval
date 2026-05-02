#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void MostrarPersonas(char *nombres[]);
int BuscarNombre(char clave[],char *nombres[]);

int main (){

    char buff[50];
    char * nombres[5]; //arreglo de punteros a cada espacio de memoria dinamica

    for (int i = 0; i < 5; i++)
    {
        printf("\nIngrese nombre %d: ", i +1);
            scanf("%s", buff);
        int tama = strlen(buff); // no considera el caracter nulo por lo tanto devuelve 10
   
        nombres[i] = (char *) malloc (sizeof(char) * tama + 1); // Reserva de memoria para la cadena pero aumento 1 byte para el carcter nulo
        strcpy(nombres[i], buff); 
    }

    MostrarPersonas(nombres);

    //nombre por clave
    char clave[25];
    printf("\nIngrese palabra clave: ");
        scanf("%s", clave);
    int encontrado = BuscarNombre(clave,nombres);
    if (encontrado != -1)
    {
        printf("\n\tNombre encontrado: %s", nombres[encontrado]);
    }else{
        printf("\n\tNo se encontro ningun nombre");
    }

    //liberar memoria
    return 0;
}

void MostrarPersonas(char *nombres[]){
    for (int i = 0; i < 5; i++){
        printf("\n%s",nombres[i]);
    }
}

int BuscarNombre(char clave[],char *nombres[]){

    for (int i = 0; i < 5; i++)
    {
        if (strstr(nombres[i], clave) != NULL)
        {
           return i;
        }
        
    }

    return -1; 
    

}

