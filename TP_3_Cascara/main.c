#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"
#include "utn.h"
#define tam 20

/*typedef struct{
    char titulo[20];
    char genero[20];
    int duracion;
    char descripcion[50];
    int puntaje;
    char linkImagen[50];
    int id;
}EMovie;*/

int main()
{
    char seguir='s';
    int opcion=0;
  //  EMovie movie;
    EMovie lista_movies[tam];
    Inicializa_Peliculas(lista_movies,tam);
    AbreArchivo(lista_movies,"pelis.dat");

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
                system("cls");
                AltaUnaxxxx(lista_movies,tam);

                break;
            case 2:
                system("cls");
                BajaPeliculas(lista_movies,tam);
                break;
            case 3:
                modificarPelis(lista_movies,tam);
                break;
            case 4:
                generarPagina(lista_movies,"Pelis.html");
               break;
            case 5:
                system("cls");
                CrearListado(lista_movies,tam);
               // ListarPeliculas(lista_movies,tam);
                break;
            case 6:
                seguir = 'n';
                break;
        }
    }

    return 0;
}
