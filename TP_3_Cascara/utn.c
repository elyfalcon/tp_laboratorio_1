#include <stdio.h>
#include <stdlib.h>
#include<ctype.h>
#include<conio.h>
#include "funciones.h"


void ValidaMenu(int opcion,int limite_inferior,int limite_superior)
{
     if(opcion <limite_inferior || opcion >limite_superior)

        printf("Debe elegir una opcion entre %d y %d: \n",limite_inferior,limite_superior);

}
int PedirEntero(char mensaje[])
{
    int auxiliar;

    do
    {
    printf("%s",mensaje);
    fflush(stdin);
    }while(scanf("%d",&auxiliar)==0);
    return auxiliar;
}

char Responder(char mensaje[])
{
    char resp;
    //int flag=-1;
    printf("%s",mensaje);
    fflush(stdin);
    scanf("%s",&resp);
    resp=toupper(resp);

    while(resp!='S'&& resp!='N')
    {
      printf("\nDebe ingresar S(si) N(no)\n");
      scanf("%s",&resp);
      resp=toupper(resp);
    }

    return resp;
}

int obtenerEspacioLibre(EMovie lista_movies[],int cantidad)
{
int i;
int posicion=-1;

if(cantidad>0 && lista_movies !=NULL)
{
    for(i=0;i<cantidad;i++)
    {
        if(lista_movies[i].id==0)
        {
            posicion=i;
            break;
        }
    }
}
 return posicion;
}


void AltaUnaxxxx(EMovie movie[],int cantidad)
{
   int indice;
   int flag=-1;
   int cant=0;
   char resp='S';

        while(resp=='S')
        {
           indice=obtenerEspacioLibre(movie,cantidad);
            if(indice>=0) //hay lugar
            {
            printf("\n-----------ALTA DE PELICULAS-------\n");
            movie[indice].id=indice+1;
            printf("Ingrese el Titulo de la pelicula: ");
            fflush(stdin);
            gets(movie[indice].titulo);
            printf("Ingrese la descripcion de la pelicula: ");
            fflush(stdin);
            gets(movie[indice].descripcion);
            printf("Ingrese el genero: ");
            fflush(stdin);
            gets(movie[indice].genero);
            printf("Ingrese la duracioin: ");
            scanf("%d",&movie[indice].duracion);
            printf("Ingrese el puntaje:");
            fflush(stdin);
            scanf("%d",&movie[indice].puntaje);
            movie[indice].estado=1;
            flag=1;
            cant++;
            resp=Responder("\nContinua ingresando otra movie?: (S/N)");
        }//fin if
        else
        {
            printf("\n--------No hay mas lugar, no se pudo ingresar:");
        }

        }//fin while
            AgregarPeliculas(movie,cantidad,cant);
}
int Inicializa_Peliculas(EMovie lista_movies[],int limite)
{
   int i;
   int retorno=-1;

   if(limite >0 && lista_movies !=NULL)
   {
    for(i=0;i<limite;i++)
       {
           retorno=0;
           lista_movies[i].id=0;
        }
   }
    return retorno;

}

int buscarPorId(EMovie lista_peliculas[], int id,int cantidad)
{
    int i;
    int flag=-1;
    if(lista_peliculas!=NULL)
  {
        for(i=0;i<cantidad;i++)
        {
            if(id==lista_peliculas[i].id)
            {
              //  printf("La persona buscada es:\n");
              //  printf("\nID:%d Nombre: %s Direccion: %s Nro Tarjeta: %s\n",lista_propietario[i].idPropietario,lista_propietario[i].nombre_prop,lista_propietario[i].direccion,lista_propietario[i].tarjeta);
               // system("pause");
                flag=i;
                break;
            }
        }
  }
  return flag;
}

void AbreArchivo(EMovie movie[])
{
    FILE *pArch;

    if((pArch=fopen("pelis.dat","rb"))==NULL)
    {
        if((pArch=fopen("pelis.dat","wb"))==NULL)
        {
            printf("\El archivo no pudo ser abierto");
        }
        //aca deberia crearlo
        printf("\nSe creo el archivo");
    }
}
void MostrarUnaPeli(EMovie movie)
{
     printf("\n ID: %d  Titulo: %s ", movie.id,movie.titulo);
     printf("\n\t Genero: %s Duracion: %d Puntaje: %d",movie.genero,movie.duracion,movie.puntaje);
     printf("\n\t Descripcion: %s  ", movie.descripcion);
     printf("\n\t Link Imagen: %s  \n", movie.linkImagen);
     printf("\n\t Estado: %d  \n", movie.estado);
}
void ListarPeliculas(EMovie lista_pelis[],int limite)
{
   // int retorno = -1;
    int i;
   // system("cls");

    if(limite > 0 && lista_pelis != NULL)
    {
        for(i=0; i<limite; i++)
        {
            if(lista_pelis[i].id!=0 && lista_pelis[i].estado!=-1)
            {
                MostrarUnaPeli(lista_pelis[i]);
            }
        }

    }
}

void BajaPelicula(EMovie* movies)
{
	int id, flag=0,i;
	int ent=0;
	char opcion;
	int tam=20;
	EMovie lista[20];
	ListarPeliculas(lista,tam);
	system("pause");
	ent=PedirEntero("\nIngrese el id de la pelicula a dar de baja:");

	for(i=0; i<tam; i++)
	{
		if(ent==movies[i].id)
		{
			printf("Datos a eliminar:\n");
			MostrarUnaPeli(movies[i]);
			printf("\nSeguro desea dar de baja?");
			opcion=getche();
		//	break;
			if(opcion=='s')
			{
				movies[i].id=0;
				movies[i].estado=-1;
				printf("\n��Registro eliminado!!");
                borrarPelicula(movies[i]);
			}
			else
			{
				printf("\nEl registro no fue eliminado!");
			}
			flag=1;
			break;
		}
	}
	if(flag==0)
	{
		printf("Pelicula inexistente");
		getch();
	}
}
