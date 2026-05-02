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

    //------Menu-----
    int seleccion, id;
    char clave[25];
    do
    {
        printf("\n-----MENU-----");
        printf("\n1. Buscar nombre por ID");
        printf("\n2. Buscar nombre por Clave");
        printf("\n0. Salir");
        printf("\n\tSeleccion: ");
            scanf("%d", &seleccion);

        switch (seleccion)
        {
        case 0:
            printf("\nSaliendo del programa...");
            break;

        case 1:
            //Buscar nombre por id
            printf("\nIngrese ID (1 al 5): ");
                scanf("%d", &id);
            BuscarNombrePorId(id, nombres);
        break;

        case 2:
            //nombre por clave
            printf("\nIngrese palabra clave: ");
                scanf("%s", clave);
            int encontrado = BuscarNombrePorClave(clave,nombres);
            if (encontrado != -1)
            {
                printf("\n\tNombre encontrado: %s", nombres[encontrado]);
            }else{
                printf("\n\tNo se encontro ningun nombre");
            }
        break;
        
        default:
            printf("\nOpcion invalida");
            break;
        }

    } while (seleccion !=0);

    //liberar memoria
    for (int j = 0; j < 5; j++)
    {
        free(nombres[j]);
    }
    
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

