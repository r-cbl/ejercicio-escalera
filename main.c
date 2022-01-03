#include "funciones.h"

int main ()
{
    int *escalones = malloc(sizeof(int));
    int *loop = malloc(sizeof(int)); 
    do
    {
        validarIngresoDatos(escalones);
        printf("Il tuo numero è %d \n",*escalones);
        printf("Il risultato è %Lf \n",calcularFormasDeSubir(escalones));
        continuar(loop);
    }while(*loop);
    printf("Ciao!");
    free(loop);
    free(escalones);
    return 0;
}
