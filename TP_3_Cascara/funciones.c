#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funciones.h"
#include "utn.h"


int agregarPelicula(EMovie movie)
{
    FILE *pArch;
    int i;
    int retorno=0;

    fwrite(&movie,sizeof(EMovie),i,pArch);
    retorno=1;
      //  fclose(pArch);
      return i;
}

int AgregarPeliculas(EMovie lista[],int limite)
{
    FILE *pArch;
    int i;
    int retorno=0;
    EMovie movie;

    if((pArch=fopen("pelis.dat","rb"))==NULL)
    {
        if((pArch=fopen("pelis.dat","wb"))==NULL)
        {
            printf("\nEl archivo no pudo ser abierto");
            retorno=-1;
        }

        printf("\nSe creo el archivo");
        retorno=1;
            fwrite(&lista,sizeof(EMovie),limite,pArch);
            fclose(pArch);

    }
    return i;
}
int borrarPelicula(EMovie movie)
{
    FILE *pArch;
    EMovie peli;
    int i;
    int retorno=0;
    int cant=0;

    pArch=fopen("pelis.dat","r+b");
    if(pArch!=NULL)
    {
        while(!feof(pArch))
        {
            if(feof(pArch))
            {
                 break;
                 retorno=-1;
            }

            cant=fread(&peli,sizeof(EMovie),1,pArch);
            retorno=0;
            if(peli.id==movie.id)
            {
             peli.estado=-1; //boreado logico
             fwrite(&peli,sizeof(EMovie),1,pArch);
            }

        }
        fclose(pArch);
    }
    return retorno;
}

void generarPagina(EMovie lista[], char nombre[])
{
    FILE *pArchHtml;
    char var[50];
    char buffer[5000]={};
    int i,j;
    int cantidad=20;

          //  AbreArchivo(lista,nombre);
  //  for(i=0;i<20;i++)  //esto se repite
        //    ListarPeliculas(lista,2);
       //     i=PedirEntero("Ingrese el id de la pelicula: \n");

       //  <div class='row'>
		//	<!-- Repetir esto para cada pelicula -->
            for(j=0;j<2;j++)
            {
                strcat(buffer,"<article class='col-md-4 article-intro'>"
                "<a href='#'>"
                    "<img class='img-responsive img-rounded' src='" );//http://ia.media-imdb.com/images/M/MV5BMjA5NTYzMDMyM15BMl5BanBnXkFtZTgwNjU3NDU2MTE@._V1_UX182_CR0,0,182,268_AL_.jpg' alt=''>);
                    strcat(buffer,lista[i].linkImagen);
                    strcat(buffer,"</a> <h3>"
                    "<a href='#'>");//lista[i]/*Back to the future*/</a>
                    strcat(buffer,lista[i].titulo);
                    strcat(buffer,"</h3><ul>");
                    strcat(buffer,"Género: ");
                    strcat(buffer,lista[i].genero);
					strcat(buffer,"<li></li>");
					strcat(buffer,"</li> <li>: ");
                    strcat(buffer,lista[i].puntaje);
                     strcat(buffer,lista[i].duracion);
                    strcat(buffer,"</li></ul><p>");
                    strcat(buffer,lista[i].descripcion);
                    strcat(buffer,"</p><li>");
                    strcat(buffer,"</ul>");
                    strcat(buffer,"</p></article></div><!-- /.row -->");
			//<!-- Repetir esto para cada pelicula -
   // }
}
        pArchHtml=fopen(nombre,"w");
        fprintf(pArchHtml,buffer);
        fclose(pArchHtml);
       // GuardarPelicula(lista,cantidad);

}void modificarPelis(EMovie* movie, int limite)
{
    int i;
    int id,indice,num,punt, flag=0;
    char resp='S';

	int opcion;
	system("cls");
	ListarPeliculas(movie,limite);
	id=PedirEntero("\nIngrese el Id de la Pelicula a modificar: ");
	//indice=buscarPorId(movie,id,limite);
	//if(indice >=0)
   // {
        for(i=0; i<limite; i++)
        {
            if(movie[i].id==id)
            {
                MostrarUnaPeli(movie[i]);
                resp=Responder("\nConfirma modificacion de esta pelicula?: (S/N)");
                if(resp=='S')
                {
                     do
                    {
                        printf("\n\n\n  == OPCIONES DE DATOS A MODIFICAR == \n\n 1- Titulo \n 2- Genero\n 3- Duracion \n 4- Descripcion \n5 -Puntaje\n 6-Salir");
                        scanf("%d",&opcion);
                        switch (opcion)
                        {
                            case 1:
                            printf("\nIngrese el nuevo Titulo");
                            gets(movie[id].titulo);
                            break;
                            case 2:
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

                                    strcpy(movie[id].genero,"COMEDIA");
                                    break;
                                case 2:
                                    strcpy(movie[id].genero,"DRAMA");
                                    break;
                                    case 3:
                                    strcpy(movie[id].genero,"CIENCIA FICCION");
                                    break;
                                case 4:
                                    strcpy(movie[id].genero,"AVENTURA");
                                    break;
                                case 5:
                                    strcpy(movie[id].genero,"TERROR");
                                    break;
                                default:
                                    printf("Ingrese una opcion correcta: \n");
                                    num=-1;
                                    break;
                                }//fin switch genero
                                }while(num==-1);
                                case 3:
                                    printf("\nIngrese duracion en minutos");
                                    scanf("%d",movie[id].duracion);
                                    break;
                                case 4:
                                    printf("\nIngrese la nueva descripcion");
                                    gets(movie[id].descripcion);
                                    break;
                                case 5:
                                    punt=PedirEntero("Ingrese el puntaje: (1 a 10)");
                                    movie[id].puntaje=punt;
                                    break;
                                case 6:
                                    opcion=-1;
                                    break;

                            }//fin switch
                    }while(opcion==-1);//fin while
                    printf("\nPelicula Modificada");
                    GuardarPelicula(movie,limite);
                }//fin if(resp)
                   else
                    printf("\Se cancelo la modificacion");

            }//fin if
        }//fin for
 //   }//fin if indice



}



