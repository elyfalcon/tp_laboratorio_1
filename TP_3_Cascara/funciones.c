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
    int cantidad=20;
    char puntaje[10];
    char duracion[10];

          //  AbreArchivo(lista,nombre);
  //  for(i=0;i<20;i++)  //esto se repite
        //    ListarPeliculas(lista,2);
       //     i=PedirEntero("Ingrese el id de la pelicula: \n");

       //  <div class='row'>
		//	<!-- Repetir esto para cada pelicula -->
		 strcat(buffer,"<!DOCTYPE html>"
            "<!-- Template by Quackit.com -->"
            "<html lang='es'>"
            "<head>"
                "<meta http-equiv='Content-Type' content='text/html; charset=ISO-8859-1'>"

                //"<meta http-equiv='X-UA-Compatible' content='IE=edge'>"
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
                "<div class='container'><div class='row' style='padding-bottom:40px;'><div class='col-md-3' style='background-color:#000000;'></div><div col-md-4' style='background-color:#000000;'><img class='img-responsive center' src='img/peliculas.jpg'></div><div class='col-md-5' style='background-color:#000000;'></div></div>"
                    "<div class='row'>");

            for(j=0;j<2;j++)
            {
                itoa(lista[j].duracion,duracion,10);
                itoa(lista[j].puntaje,puntaje,10);
                strcat(buffer,"<article class='col-md-4 article-intro'>"
                "<a href='#'>"
                    "<img class='img-responsive img-rounded' src='" );//http://ia.media-imdb.com/images/M/MV5BMjA5NTYzMDMyM15BMl5BanBnXkFtZTgwNjU3NDU2MTE@._V1_UX182_CR0,0,182,268_AL_.jpg' alt=''>);
<<<<<<< HEAD
                    strcat(buffer,lista[j].linkImagen);
=======
                    strcat(buffer,lista[i].linkImagen);
>>>>>>> 17dab460daf640aa8151dc710d00f7feed74b67f
                    strcat(buffer,"</a> <h3>"
                    "<a href='#'>");//lista[i]/*Back to the future*/</a>
                    strcat(buffer,lista[j].titulo);
                    strcat(buffer,"</h3><ul>");
                    strcat(buffer,"<li>Género: ");
                    strcat(buffer,lista[j].genero);
					strcat(buffer,"<li></li>");
					strcat(buffer,"</li> <li>: ");
<<<<<<< HEAD
					strcat(buffer,"</li><li>Puntaje:");
					//sprintf(puntaje, "%d", lista[i].puntaje);
                    strcat(buffer,puntaje);
                //    strcat(buffer, "</li><li>Duracion:");
                //    sprintf(duracion, "%d", lista[j].duracion);
                    strcat(buffer,duracion);
=======
                    strcat(buffer,lista[i].puntaje);
                     strcat(buffer,lista[i].duracion);
>>>>>>> 17dab460daf640aa8151dc710d00f7feed74b67f
                    strcat(buffer,"</li></ul><p>");
                    strcat(buffer,lista[j].descripcion);
                    strcat(buffer,"</p><li>");
                    strcat(buffer,"</ul>");
                    strcat(buffer,"</p></article></div><!-- /.row -->");
			//<!-- Repetir esto para cada pelicula -
   // }
}
<<<<<<< HEAD
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


=======
>>>>>>> 17dab460daf640aa8151dc710d00f7feed74b67f
        pArchHtml=fopen(nombre,"w");
        fprintf(pArchHtml,buffer);
        fclose(pArchHtml);
       // GuardarPelicula(lista,cantidad);

}void modificarPelis(EMovie* movie, int limite)
{
    int i;
    int id,indice,num,punt, flag=0;
    char resp='S';
<<<<<<< HEAD
=======

>>>>>>> 17dab460daf640aa8151dc710d00f7feed74b67f
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
<<<<<<< HEAD
                                    scanf("%d",&movie[id].duracion);
=======
                                    scanf("%d",movie[id].duracion);
>>>>>>> 17dab460daf640aa8151dc710d00f7feed74b67f
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
<<<<<<< HEAD
                    printf("\nSe cancelo la modificacion");
=======
                    printf("\Se cancelo la modificacion");
>>>>>>> 17dab460daf640aa8151dc710d00f7feed74b67f

            }//fin if
        }//fin for
 //   }//fin if indice



}



