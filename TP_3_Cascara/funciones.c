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
            printf("\El archivo no pudo ser abierto");
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
    int limite=20;

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

/*void generarPagina(EMovie lista[], char nombre[])
{
    File*
    char var[50];
    char buffer[1080]={};

    strcat(buffer,var);

    strcat(buffer)


    strcat(buffer,"<html lang='en'><head><meta charset='utf-8'><meta http-equiv='X-UA-Compatible' content='IE=edge'>"

       " <meta name='viewport' content='width=device-width, initial-scale=1'>"

        "<!-- The above 3 meta tags *must* come first in the head; any other head content must come *after* these tags -->"

        "<title>Lista peliculas</title>"

        "<!-- Bootstrap Core CSS -->"

        "<link href='css/bootstrap.min.css' rel='stylesheet'>"

        "<!-- Custom CSS: You can use this stylesheet to override any Bootstrap styles and/or apply your own styles -->"

        "<link href='css/custom.css' rel='stylesheet'>"

        "<!-- HTML5 Shim and Respond.js IE8 support of HTML5 elements and media queries -->"

        "<!-- WARNING: Respond.js doesn't work if you view the page via file:// -->"

        "<!--[if lt IE 9]>"

        "    <script src='https://oss.maxcdn.com/libs/html5shiv/3.7.0/html5shiv.js'></script>"

         " <script src='https://oss.maxcdn.com/libs/respond.js/1.4.2/respond.min.js'></script>"

        "<![endif]-->"

        "</head>"

        "<body><div class='container'><div class='row'>");

        strcat(buffer, "<article class='col-md-4 article-intro'> <a href='#'>"

        " <img class='img-responsive img-rounded' src='");//http://ia.media-imdb.com/images/M/MV5BMjA5NTYzMDMyM15BMl5BanBnXkFtZTgwNjU3NDU2MTE@._V1_UX182_CR0,0,182,268_AL_.jpg

        strcat(buffer,peliculass[i].linkImagen);

        strcat(buffer,"'alt=''>"

        "</a><h3> <a href='#'>");

        strcat(buffer,peliculass[i].titulo);

        strcat(buffer,"</a>  </h3>  <ul>   <li>");

        strcat(buffer,"Género: ");

        strcat(buffer,peliculass[i].genero);

        strcat(buffer,"</li> <li>Puntaje: ");

        sprintf(puntaje, "%g", peliculass[i].puntaje);

        strcat(buffer,puntaje);

        strcat(buffer,"</li><li>Duración:");

        sprintf(auxDuracion, "%g", peliculass[i].duracion);

        strcat(buffer,"</li></ul><p>");

        strcat(buffer,peliculass[i].descripcion);

        strcat(buffer,"</p>"

            "</article>"

            "<!-- Repetir esto para cada pelicula -->"

            "</div><!-- /.row --></div><!-- /.container --><!-- jQuery --><script src='js/jquery-1.11.3.min.js'></script><!-- Bootstrap Core JavaScript --><script src='js/bootstrap.min.js'></script>"

            "<!-- IE10 viewport bug workaround -->"

            "<script src='js/ie10-viewport-bug-workaround.js'></script>"

            "<!-- Placeholder Images -->"

            "<script src='js/holder.min.js'></script>"

            "</body>"



            "</html>");
}

*/

