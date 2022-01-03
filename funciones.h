#ifndef _FUNCIONES
#define _FUNCIONES

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#define tamanio 256

u_int8_t esNumero(char entrada[])
{
    if(entrada[0]=='e' || entrada[0]=='E')
        exit(2);
    for(int i = 0; i<strlen(entrada);i++)
    {
        if(!isdigit(entrada[i]))
            return 0;
    }
    return 1;
}
void validarIngresoDatos(int *escalones)
{
    char entrada [256];
    printf("Inseri il numero di passi, 'e' per uscire\n");
    scanf("%s", entrada);
    while(!esNumero(entrada)){
        printf("Errore. Inseri un numero valido, 'e' per uscire: \n");
        scanf(" %s", entrada);
    }
    *escalones = atoi(entrada);
}
long double factorial(int numero)
{
    long double calculo = 1;
    for(int i =1;i<=numero;i++)
    {
        calculo*=i;
    }
    return calculo;
}
long double calcularFormasDeSubir(int *escalones)
{
    if(*escalones<=3)
        return *escalones;
    //modifico el inicio del calculo segun la paridad
    int inicio = (*escalones%2)? (*escalones+1)/2: *escalones/2 +1;
    int fin = (*escalones%2)? *escalones-1: *escalones-2;
    int sumador = (*escalones%2)? -1: *escalones+1;
    long double calculo = 0;
    long double factorialAnterior = factorial(inicio-1);
    for(int i = inicio; i<=fin; i++)
    {
        long double factorialActual = factorialAnterior*i;
        //lo divido para llegar al factorial de i-2
        calculo += factorialActual/(factorialActual/(i*(i-1))); 
        factorialAnterior = factorialActual;
    }
    return calculo/2 + sumador;
}

void continuar(int *loop)
{
    char c;
    printf("'Y' per ingresare un'altro numero \n");
    scanf(" %c", &c);
    *loop = (toupper(c)=='Y')? 1: 0;
}

#endif