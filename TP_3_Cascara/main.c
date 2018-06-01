#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"
#include "utn.h"
#define TAM 10



int main()
{
    char seguir='s';
    int opcion=0;
  //  EMovie movie;
    EMovie lista_movies[TAM];
    Inicializa_Peliculas(lista_movies,TAM);
   // AbreArchivo(lista_movies,"pelis.dat");
   cargarDesdeArchivo(lista_movies,TAM);

    while(seguir=='s')
    {
        printf("1- Agregar pelicula\n");
        printf("2- Borrar pelicula\n");
        printf("3- Modificar pelicula\n");
        printf("4- Generar pagina web\n");
        printf("5- Generar listado\n");
        printf("6- Salir\n");

        scanf("%d",&opcion);

        switch(opcion)
        {
            case 1:
                AltaUnaxxxx(lista_movies,TAM);
                system("cls");
                break;
            case 2:

                BajaPeliculas(lista_movies,TAM);
                system("cls");
                break;
            case 3:
                system("cls");
                modificarPelis(lista_movies,TAM);
                break;
            case 4:
                generarPagina(lista_movies,"Pelis.html");
               break;
            case 5:
                system("cls");
               // CrearListado(lista_movies,TAM);
                ListarPeliculas(lista_movies,TAM);

                break;
            case 6:
                seguir = 'n';
                break;
        }
    }

    return 0;
}
