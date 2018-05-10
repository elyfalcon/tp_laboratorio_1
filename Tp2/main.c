#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"
#define TAMANIO 20


int main()
{
    char seguir='s';
    int opcion=0;
    int dni,i;
    //Se crea el array de personas y se lo inicializa inicializa
    EPersona lista[TAMANIO];
    Inicializa_Persona(lista,TAMANIO);
    // Carga datos de test
    HardcodePersona(lista);

    while(seguir=='s')
    {
        printf("1- Agregar persona\n");
        printf("2- Borrar persona\n");
        printf("3- Imprimir lista ordenada por  nombre\n");
        printf("4- Imprimir grafico de edades\n\n");
        printf("5- Salir\n\n");

        scanf("%d",&opcion);


        switch(opcion)
        {
            case 1:
                AltaPersonas(lista,TAMANIO);
                break;
            case 2:
                BorrarUnaPersona(lista,dni);
                break;
            case 3:
                ListarPersonas(lista,TAMANIO);
                break;
            case 4:
                GraficoEdades(lista,TAMANIO);
                break;
            case 5:
                seguir = 'n';
                break;
            default:
                printf("\nDebe ingresar una opcion correcta: ");
                break;
        }
    }

    return 0;
}
