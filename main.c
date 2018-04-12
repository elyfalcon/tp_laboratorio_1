/*Trabajo Practico Nº 1, Programación I, Laboratorio I - Calculadora
Autor: Elizabeth Falcón  */
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include "funciones.h"

int main()
{

    char seguir='s';
    int opcion=0;
    int numero1,numero2,resultado,suma,resta,mult,factor;
    numero1=0,numero2=0;
    float divid;
    int flag1,flag2=0;


    while(seguir=='s' || (opcion <1 || opcion >9))
    {

        printf("1- Ingresar 1er operando (A=%d )\n", numero1);
        printf("2- Ingresar 2do operando (B= %d)\n",numero2);
        printf("3- Calcular la suma (%d+%d)\n",numero1,numero2);
        printf("4- Calcular la resta (%d-%d)\n",numero1,numero2);
        printf("5- Calcular la division (%d/%d)\n",numero1,numero2);
        printf("6- Calcular la multiplicacion (%d*%d)\n",numero1,numero2);
        printf("7- Calcular el factorial (%d!)\n",numero1);
        printf("8- Calcular todas las operaciones\n");
        printf("9- Salir\n");

        scanf("%d",&opcion);

        switch(opcion)
        {
            case 1:
            numero1=pedir_y_leer_numero(); // llama a la funcion
            flag1=1;
                break;
            case 2:
            numero2=pedir_y_leer_numero(); //llama a la funcion pedir_y_leer_numero
            flag2=1;
                break;
            case 3:
            if(flag1==1 && flag2==1) // onctrola que se hayan ingresado los 2 numeros
             {
              resultado=sumar(numero1,numero2); //llama a la funcion sumar
              printf(" %d + %d = %d \n \n", numero1,numero2,resultado);
             }
             else
             {
                 printf("Debe ingresar los 2 operandos \n");
             }
                break;
            case 4:
              if(flag1==1 && flag2==1) // onctrola que se hayan ingresado los 2 numeros
               {
                resultado=restar(numero1,numero2);
                printf("%d - %d = %d \n \n", numero1,numero2,resultado);
               }
              else
              {
                  printf("Debe ingresar los dos operandos\n");
              }
                break;
            case 5:
            if(flag1==1 && flag2==1)// onctrola que se hayan ingresado los 2 numeros
            {
              if(numero2!=0) //verificamos que el divisor no sea 0antes de llamar a la funcion dividir
              {
              divid=dividir(numero1,numero2);
              printf("%d / %d = %f \n",numero1,numero2,divid);
              }
               else
               {
                   printf("no se puede dividir por 0\n"); //si el divisor ingresado es 0
               }

            }
             else
             {
                printf("Debe ingresar los dos operandos\n");
             }
                break;
            case 6:
            if(flag1==1 && flag2==1) // onctrola que se hayan ingresado los 2 numeros
            {
              resultado=multiplicar(numero1,numero2); //llama a la funcion dividor
              printf(" %d * %d = %d \n",numero1,numero2,resultado);
            }
            else
            {
                printf("Debe ingresar los dos operandos\n");
            }
                break;
            case 7:
            resultado=factorial(numero1);
            if(numero1<=12) //si el numero es mayor a 12 no calcula el factorial por overflow
                {
                printf(" %d! = %d \n",numero1,resultado);
                }
            else
                {
                printf("Debe ingresar un numero menor a 13\n");
                }
                break;
            case 8:
            printf("\n TODAS LAS OPERACIONES\n\n");
            if(flag1==1) //controlo el ingreso del primer numero para el factorial
            {
                if(numero1<=12) //controla que sea menor o igual a 12
                {
                   factor=factorial(numero1);
                   printf(" %d!= %d\n\n",numero1,factor);
                }
                else
                {
                    printf("Debe ingresar un numero menor a 13 para calcular factorial\n\n");
                }
            }
            if(flag1==1 && flag2==1) // onctrola que se hayan ingresado los 2 numeros
            {
                suma=sumar(numero1,numero2);
                resta=restar(numero1,numero2);
                mult=multiplicar(numero1,numero2);
                if(numero2!=0) //si el divisosr no es 0 cacula la division
                {
                    divid=dividir(numero1,numero2);
                    printf(" %d / %d = %f\n",numero1,numero2,divid);
                }
                else
                {
                    printf("No se puede dividir por 0 \n");
                }


                printf(" %d + %d = %d\n",numero1,numero2,suma);
                printf(" %d - %d= %d\n",numero1,numero2,resta);
                printf(" %d * %d = %d\n",numero1,numero2,mult);

            }
            else
            {
                printf("Debe ingresar los dos operandos para +, -, / y *    ");
            }
                break;
            case 9:
                seguir = 'n';
                break;
        }
        system("pause");
        system("cls");


}


    return 0;
}
