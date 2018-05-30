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

void generarPagina(EMovie lista[], char nombre[])
{
    FILE *pArch;
    char var[50];
    char buffer[5000]={};
    int i,j;
    int cantidad=20;

            AbreArchivo(lista,nombre);
  //  for(i=0;i<20;i++)  //esto se repite
            ListarPeliculas(lista,2);
            i=PedirEntero("Ingrese el id de la pelicula: \n");

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
                    sprintf(buffer,lista[i].puntaje);
                     sprintf(buffer, "%g", lista[i].duracion);
                    strcat(buffer,"</li></ul><p>");
                    strcat(buffer,lista[i].descripcion);
                    strcat(buffer,"</p><li>");
                    strcat(buffer,"</ul>");
                    strcat(buffer,"</p>"
            "</article>"
			//<!-- Repetir esto para cada pelicula -->
        "</div><!-- /.row -->");
   // }
}
        GuardarPelicula(lista,cantidad);

}



