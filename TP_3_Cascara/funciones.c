#include <stdio.h>
#include <stdlib.h>
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
<article class="col-md-4 article-intro">
                <a href="#">
                    <img class="img-responsive img-rounded" src="http://ia.media-imdb.com/images/M/MV5BMjA5NTYzMDMyM15BMl5BanBnXkFtZTgwNjU3NDU2MTE@._V1_UX182_CR0,0,182,268_AL_.jpg" alt="">
                </a>
                <h3>
                    <a href="#">Back to the future</a>
                </h3>
				<ul>
					<li>G�nero:Aventura</li>
					<li>Puntaje:86</li>
					<li>Duraci�n:116</li>
				</ul>
                <p>A young man is accidentally sent thirty years into the past in a time-traveling DeLorean invented by his friend, Dr. Emmett Brown, and must make sure his high-school-age parents unite in order to save his own existence.</p>
            </article>


}

*/

