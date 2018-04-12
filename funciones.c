#include<stdio.h>
#include<stdlib.h>
#include "funciones.h"

/*Función pedir_y_leer_numero
Descripcion: pide un numero al usuario y lo lee .
Argumentos: es void
Valor retornado: numeroUno entero
Advertencia: se controla que solo se ingresen numeros*/
int pedir_y_leer_numero(void)
{

int numeroUno;
do
{
    printf("\n Tipee un numero:\n");
    fflush(stdin);

 }while(scanf("%d",&numeroUno)==0);

return  numeroUno;
}

/*Función sumar
Descripcion: calcula la suma de dos numeros enteros.
Argumentos: numero1 entero
            numero2 entero
Valor retornado: resultado entero*/
int sumar(int numero1, int numero2)
{
    int resultado;
    fflush(stdin);
    resultado=numero1+numero2;

    return resultado;
}

/*Función restar
Descripcion: calcula la resta de dos numeros enteros.
Argumentos: numero1 entero
            numero2 entero
Valor retornado: resta entero*/
int restar(int numero1,int numero2)
{
    int resta;
    resta=numero1 - numero2;
    return resta;

}

/*Función multiplicar
Descripcion: calcula el producto de dos numeros enteros.
Argumentos: numero1 entero
            numero2 entero
Valor retornado: multiplica*/
int multiplicar(int numero1,int numero2)
{
    int multiplica;
    multiplica=numero1 * numero2;
    return multiplica;
}

/*Función dividir
Descripcion: calcula la division de dos numeros enteros.
Argumentos: numero1 entero
            numero2 entero
 Se hardcodea la division porque la division de 2 enteros puede ser float.
 Valor retornado: division float
 Advertencia: En caso que el divisor (numero2 en nuestro caso) sea 0, no se realiza la division y se pide al usuario
 que no se puede efectuar la misma*/
float dividir(int numero1,int numero2)
{
    float division;
    if(numero2 != 0)
    {
        division=(float) numero1 / numero2;
    }
    else
    {
        printf("Ingrese un numero distinto de 0\n\n");
    }
    return(division);
}


/*Función factorial
Descripcion: calcula el factorial de un entero.
Argumentos: numero1 entero
Valor retornado: result entero
Advertencia: Si el numero es mayor que 12 no se puede realizar la operacion porque causaria overflow*/
float factorial(int numero1)
{
    int i;
    numero1=(int)numero1;
    float result=1;


     for(i=numero1;i>1;i--)
       {
         result=result*i;
       }

    return result;
}
