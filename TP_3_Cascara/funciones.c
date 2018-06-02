#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funciones.h"
#include "utn.h"
#define TAM 10


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
  //  EMovie movie;

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
    int i,j=0;
  //  int cantidad=20;
    char puntaje[10];
    char duracion[10];

//         <div class='row'>
		//	<!-- Repetir esto para cada pelicula -->
		cargarDesdeArchivo(lista);

		 strcat(buffer,"<!DOCTYPE html>"
            "<!-- Template by Quackit.com -->"
            "<html lang='es'>"
            "<head>"
                "<meta http-equiv='Content-Type' content='text/html; charset=ISO-8859-1'>"
                "<meta http-equiv='X-UA-Compatible' content='IE=edge'>"
                "<meta name='viewport' content='width=device-width, initial-scale=1'>"
                "<!-- The above 3 meta tags *must* come first in the head; any other head content must come *after* these tags -->"
                "<title>Lista peliculas</title>"
                "<!-- Bootstrap Core CSS -->"
                "<link href='css/bootstrap.min.css' rel='stylesheet'>"
                "<!-- Custom CSS: You can use this stylesheet to override any Bootstrap styles and/or apply your own styles -->"
                "<link href='css/custom.css' rel='stylesheet'>"
                "<!-- HTML5 Shim and Respond.js IE8 support of HTML5 elements and media queries -->"
                "<!-- WARNING: Respond.js doesn't work if you view the page via file:// -->"
                "<!--[if lt IE 9]>"
                    "<script src='https://oss.maxcdn.com/libs/html5shiv/3.7.0/html5shiv.js'></script>"
                    "<script src='https://oss.maxcdn.com/libs/respond.js/1.4.2/respond.min.js'></script>"
                "<![endif]-->"
            "</head>"
           " <body>"
                "<div class='container'><div class='row' style='padding-bottom:40px;'><div class='col-md-3' style='background-color:#000000;'></div><div col-md-4' style='background-color:#000000;color:#ffffff;'>VIDEO CLUB Ely</div><div class='col-md-5' style='background-color:#000000;'></div></div>"
                    "<div class='row'>");

            for(j=0;j<TAM;j++)
            {
             if(lista[j].id>0)
                  {
                itoa(lista[j].duracion,duracion,10);
                itoa(lista[j].puntaje,puntaje,10);

                    strcat(buffer,"<article class='col-md-4 article-intro'>"
                "<a href='#'>"
                    "<img class='img-responsive img-rounded' src='");//http://ia.media-imdb.com/images/M/MV5BMjA5NTYzMDMyM15BMl5BanBnXkFtZTgwNjU3NDU2MTE@._V1_UX182_CR0,0,182,268_AL_.jpg' alt=''>"

                    strcat(buffer,lista[j].linkImagen);
                    strcat(buffer,"'/></a>"
                    "<a href='#'></div><div class='col-md-6 article-intro'><h3>");
                    strcat(buffer,lista[j].titulo);
                    strcat(buffer,"</a>"
                    "</h3><br/>""<ul>""<li>G�nero:");

                    strcat(buffer,lista[j].genero);
					//strcat(buffer,"<li></li>");
					//strcat(buffer,"</li> <li>: ");
					strcat(buffer,"</li><li>Puntaje:");
                    strcat(buffer,puntaje);
                    strcat(buffer, "</li><li>Duracion:");
                    strcat(buffer,duracion);
                    strcat(buffer,"</li></ul><p></div><article class='col-md-12 article-intro'>");
                    strcat(buffer,lista[j].descripcion);
                     strcat(buffer,"</p>"

                        "</article></article>"

                        "<!-- Repetir esto para cada pelicula -->");
                  /*  strcat(buffer,"</p><li>");
                    strcat(buffer,"</ul>");
                    strcat(buffer,"</p></article></div><!-- /.row -->");
			//<!-- Repetir esto para cada pelicula -*/

          }//fin if
                }//fin for


         strcat(buffer,"</div>"
                "<!-- /.row -->"
                "</div>"
               " <!-- /.container -->"
                "<!-- jQuery -->"
                "<script src='js/jquery-1.11.3.min.js'></script>"
                "<!-- Bootstrap Core JavaScript -->"
                "<script src='js/bootstrap.min.js'></script>"
               "<!-- IE10 viewport bug workaround -->"
               " <script src='js/ie10-viewport-bug-workaround.js'></script>"
                "<!-- Placeholder Images -->"
                "<script src='js/holder.min.js'></script>"
            "</body>"
            "</html>");
        printf("\nSe genero la pagina pelis.html \n");
        system("pause");
        pArchHtml=fopen(nombre,"w");
        fprintf(pArchHtml,buffer);
        fclose(pArchHtml);

}
void modificarPelis(EMovie* movie, int limite)
{
    int i;
    int id,indice,punt, flag=0;
    char resp='S';
	int opcion;
	system("cls");
	cargarDesdeArchivo(movie);
	ListarPeliculas(movie,limite);
	id=PedirEntero("\nIngrese el Id de la Pelicula a modificar: ");


        for(i=0; i<limite; i++)
        {
            if(movie[i].id==id)
            {
                MostrarUnaPeli(movie[i]);
                resp=Responder("\nConfirma modificacion de esta pelicula?: (S/N) ");
                if(resp=='S')
                {
                     do
                    {
                        printf("\n\n\n  == OPCIONES DE DATOS A MODIFICAR == \n\n 1- Titulo \n 2- Genero\n 3- Duracion \n 4- Descripcion \n 5 -Puntaje\n\n 6-Salir\n");
                        scanf("%d",&opcion);
                        switch (opcion)
                        {
                            case 1:
                                printf("\nIngrese el nuevo Titulo:");
                                gets(movie[i].titulo);
                                break;
                            case 2:
                                ElegirGenero(movie,i);
                                break;
                            case 3:
                                printf("\nIngrese duracion en minutos");
                                scanf("%d",&movie[i].duracion);
                                ValidaDuracion(movie[i].duracion);
                                break;
                            case 4:
                                printf("\nIngrese la nueva descripcion");
                                gets(movie[i].descripcion);
                                break;
                            case 5:
                                 do
                                {
                                punt=PedirEntero("\nIngrese el puntaje: (1 a 10) ");
                                fflush(stdin);
                                movie[i].puntaje=punt;
                                }while(punt>10 || punt<0);


                                break;
                            case 6:
                                opcion=-1;
                                break;

                            }//fin switch
                    }while(opcion==-1);//fin while
                    resp=Responder("\nConfirma modificacion?: (S/N) ");
                    if(resp=='S')
                    {
                    printf("\nPelicula Modificada\n");
                    system("pause");
                    GuardarPelicula(movie,limite);
                    }
                    else
                    {printf("\nSe cancelo la modificacion\n");
                    system("pause");
                    system("cls");}
                    flag=1;

                }//fin if(resp)


            }//fin if (movie[i].id
             break;
        }//fin for
        if(flag==0)
            {
                printf("\nNo existe la pelicula\n");
                system("pause");
            }


}



