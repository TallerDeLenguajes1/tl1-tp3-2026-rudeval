#include <stdio.h>
#include <stdlib.h>
#include <time.h>

char *TiposProductos[]={"Galletas","Snack","Cigarrillos","Caramelos","Bebidas"}; 
//cada elemento apunta a una cadena: TiposProductos[0] --> "galletas" (es como un arreglo 2d [][20] pero sin fijar tamaño de cada palabra)

typedef struct { 
    int ProductoID;  //Numerado en ciclo iterativo      
    int Cantidad;      // entre 1 y 10    
    char *TipoProducto;   // Algún valor del arreglo TiposProductos       
    float PrecioUnitario; // entre 10 - 100 
}tProducto;  

typedef struct {   
    int ClienteID;     // Numerado en el ciclo iterativo          
    char *NombreCliente;   // Ingresado por usuario      
    int CantidadProductosAPedir; // (aleatorio entre 1 y 5) 
    tProducto *Productos;   //El tamaño de este arreglo depende de la variable “CantidadProductosAPedir”  
}tCliente;

tCliente * crearCliente(int n);
void cargarClientes(tCliente*clientes, int n);

int main(){
    srand(time(NULL));

    int cantidadClientes;

    printf("\nCantidad de clientes: ");
        scanf("%d", &cantidadClientes);
    tCliente * clientes = crearCliente(cantidadClientes);

    cargarClientes(clientes, cantidadClientes);
    

    return 0;
}

tCliente * crearCliente(int n){
    tCliente *clientes = (tCliente *) malloc(sizeof(tCliente)*n); //reservo la memoria para la cantidad de clientes ingresada, y la asigno a un puntero tipo tCliente
    return clientes;
}

void cargarClientes(tCliente*clientes, int n){

    for (int i = 0; i < n; i++)
    {
        clientes[i].ClienteID=i+1;

        clientes[i].NombreCliente = malloc(25*sizeof(char));//reservo 25 caracteres para el nombre, para que el puntero a char apunte al comienzo de la reserva
        printf("Nombre de cliente [%d]: ", i+1);
            scanf("%s", clientes[i].NombreCliente);

        clientes[i].CantidadProductosAPedir=rand()%5+1; //5 num del 1 al 5 incluidos
        clientes[i].Productos = (tProducto *)malloc(sizeof(tProducto)*clientes[i].CantidadProductosAPedir);//reservo la memoria para el arreglo de productos
        for (int j = 0; j < clientes[i].CantidadProductosAPedir; j++)
        {
            clientes[i].Productos[j].ProductoID=j+1;
            
            clientes[i].Productos[j].Cantidad=rand()%10+1;

            int random=rand()%5; //5 elementos del arreglo (0 al 4)
            clientes[i].Productos[j].TipoProducto = TiposProductos[random];

            clientes[i].Productos[j].PrecioUnitario=rand()%(91)+10; //entre 10 y 100

        }

    }

}