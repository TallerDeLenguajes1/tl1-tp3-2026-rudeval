#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void MostrarPersonas(char *nombres[]);
void BuscarNombrePorId (int id, char *nombres[]);
int BuscarNombrePorClave(char clave[],char *nombres[]);

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

    //Buscar nombre por id
    int id;
    printf("\nIngrese ID (1 al 5): ");
        scanf("%d", &id);
    BuscarNombre(id, nombres);
        
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

void BuscarNombrePorId (int id, char *nombres[]){
    if (id>=1 && id<=5)
    {
        id = id-1;
        printf("\n\tNombre encontrado: %s", nombres[id]); 
    }else{
        printf("\nNo se encontro el valor buscado"); 
    }
    
}


int BuscarNombrePorClave(char clave[],char *nombres[]){

    for (int i = 0; i < 5; i++)
    {
        if (strstr(nombres[i], clave) != NULL)
        {
           return i;
        }
        
    }

    return -1; 
    

}

