#include <stdio.h>
#include <stdlib.h>
#include<ctype.h>
#include<conio.h>
#include <string.h>
#include "funciones.h"
#define TAM 10



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
char ValidaDuracion(int minutos)
{
    int h,m;

        if(minutos>0)
        {
            h=(minutos/60);
            m=minutos - h*60;
        }

    printf("H:%d M:%d",h,m);
    return m;
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
   int indice,num,puntaje;
   int flag=-1;
   char resp='S';


        while(resp=='S')
        {
           indice=obtenerEspacioLibre(movie,cantidad);
            if(indice>=0) //hay lugar
            {
            printf("\n-----------ALTA DE PELICULAS-------\n\n");
            movie[indice].id=indice+1;
            printf("Ingrese el Titulo de la pelicula: ");
            fflush(stdin);
            gets(movie[indice].titulo);
            printf("Ingrese la descripcion de la pelicula: ");
            fflush(stdin);
            gets(movie[indice].descripcion);
            printf("Ingrese el genero: "); //hacer un case
            fflush(stdin);
            printf("\n");
            do
            {
            printf("\n1- COMEDIA");
            printf("\n2- DRAMA");
            printf("\n3- CIENCIA FICCION");
            printf("\n4- AVENTURA");
            printf("\n5- TERROR\n\n");
            fflush(stdin);
            scanf("%d",&num);

            switch (num)
            {
            case 1:
            //movie[indice].genero={"COMEDIA"};
            strcpy(movie[indice].genero,"COMEDIA");
            break;
        case 2:
        strcpy(movie[indice].genero,"DRAMA");
        break;
        case 3:
        strcpy(movie[indice].genero,"CIENCIA FICCION");
          break;
        case 4:
        strcpy(movie[indice].genero,"AVENTURA");
        break;
        case 5:
        strcpy(movie[indice].genero,"TERROR");
        break;
        default:
        printf("Ingrese una opcion correcta: \n");
        break;
    }
     }while(num==-1);
          //  gets(movie[indice].genero);
            printf("Ingrese la duracion en minutos: \n");//limitar el tiempo y  el formato
            scanf("%d",&movie[indice].duracion);
            ValidaDuracion(movie[indice].duracion);
            do
            {
             puntaje=PedirEntero("\nIngrese el puntaje: (1 a 10) ");
            //printf("Ingrese el puntaje: 1 a 10"); //validar de 1 a 10
             fflush(stdin);
          //  scanf("%d",&movie[indice].puntaje);
            movie[indice].puntaje=puntaje;
            }while(puntaje>10 || puntaje<0);

            printf("Ingrese la imagen:");
            gets(movie[indice].linkImagen);
            movie[indice].estado=1;
            flag=1;
            resp=Responder("\nContinua ingresando otra movie?: (S/N)");
        }//fin if
        else
        {
            printf("\n--------No hay mas lugar, no se pudo ingresar:");
        }

        }//fin while

            GuardarPelicula(movie,cantidad);
            system("cls");
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

void AbreArchivo(EMovie movie[],char nombre[])
{
    FILE *pArch;

    if((pArch=fopen(nombre,"rb"))==NULL)
    {
        if((pArch=fopen(nombre,"wb"))==NULL)
        {
            printf("\nEl archivo no pudo ser abierto");

        }
        //aca deberia crearlo
        printf("\nSe creo el archivo\n");
        fclose(pArch);
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

void BajaPeliculas(EMovie movies[],int tam)
{
	int flag=0,i;
	int ent=0;
	char opcion;
	ListarPeliculas(movies,tam);
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

			if(opcion=='s')
			{
				movies[i].id=0;
				movies[i].estado=-1;
				printf("\n­­Registro eliminado!!");
                GuardarPelicula(movies,tam);
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
int GuardarPelicula(EMovie movie[],int cantidad)
{
    FILE *pArch;
    int retorno=0;


 //   if((pArch=fopen("pelis.dat","rb"))==NULL)
    {
        if((pArch=fopen("pelis.dat","wb"))==NULL)
        {
            printf("\nEl archivo no pudo ser abierto");
        }
        fwrite(&movie,sizeof(EMovie),cantidad,pArch);
        retorno=1;
        fclose(pArch);
    }
    return retorno;
}
void CrearListado(EMovie *peli,int cant)
{
     int i;
     FILE *f;
     f=fopen("Peliculas.txt", "w");

     if(f == NULL)
     {
          printf("No se pudo abrir el archivo\n");
     }
     else
     {
         fprintf(f,"Listado de Peliculas\n\n\n");
         fprintf(f,"-----------------------------------------------------------------\n");
         fprintf(f,"Titulo             Descripcion       Genero       Duracion       Puntaje \n");
         fprintf(f,"-----------------------------------------------------------------\n");

         for(i=0; i<cant; i++)
         {
                  if(peli[i].id != 0)
                  {
                  fprintf(f,"%s\t    %s %s\t\%d\t%d\n", peli[i].titulo, peli[i].descripcion, peli[i].genero, peli[i].duracion,peli[i].puntaje);
                  }
         }
      }

      fclose(f);
      printf("Listado creado con exito\n");
      system("pause");
}
int cargarDesdeArchivo(EMovie *movie)
{
	int flag = 0;
	FILE *pArchivo;

	pArchivo=fopen("pelis.dat", "rb");
	if(pArchivo==NULL)
	{
		pArchivo= fopen("pelis.dat", "wb");
		if(pArchivo==NULL)
		{
			return 1;
		}
		flag=1;
	}

	if(flag ==0)
	{
	fread(pArchivo,sizeof(EMovie),TAM,pArchivo);
    }

	fclose(pArchivo);
	return 0;

}
void ElegirGenero(EMovie *movie,int indice)
{
     int num;
     printf("Ingrese el genero: "); //hacer un case
            fflush(stdin);
            printf("\n");
            do
            {
            printf("\n1- COMEDIA");
            printf("\n2- DRAMA");
            printf("\n3- CIENCIA FICCION");
            printf("\n4- AVENTURA");
            printf("\n5- TERROR\n\n");
            fflush(stdin);
            scanf("%d",&num);

            switch (num)
            {
            case 1:
                strcpy(movie[indice].genero,"COMEDIA");
                break;
            case 2:
                strcpy(movie[indice].genero,"DRAMA");
                break;
            case 3:
                strcpy(movie[indice].genero,"CIENCIA FICCION");
                break;
            case 4:
                strcpy(movie[indice].genero,"AVENTURA");
                break;
            case 5:
                strcpy(movie[indice].genero,"TERROR");
                break;
            default:
                printf("Ingrese una opcion correcta: \n");
                break;
            }// fin switch
        }while(num==-1);

}
