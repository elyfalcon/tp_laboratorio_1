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
    EMovie movie;
    EMovie lista_movies[tam];
  //  AbreArchivo(lista_movies);
    Inicializa_Peliculas(lista_movies,tam);

    while(seguir=='s')
    {
        printf("1- Agregar pelicula\n");
        printf("2- Borrar pelicula\n");
        printf("3- Generar pagina web\n");
        printf("4- Generar listado\n");
        printf("5- Salir\n");

        scanf("%d",&opcion);

        switch(opcion)
        {
            case 1:
                system("cls");
             //   AbreArchivo(lista_movies);
                AltaUnaxxxx(lista_movies,tam);
                //AgregarPeliculas(lista_movies,tam);
                break;
            case 2:
                system("cls");
                BajaPelicula(lista_movies);
                break;
            case 3:
               break;
            case 4:
                system("cls");
                ListarPeliculas(lista_movies,tam);
                break;
            case 5:
                seguir = 'n';
                break;
        }
    }

    return 0;
}
