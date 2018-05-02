#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funciones.h"
#define FREE 0
#define OCUPADO 1

int obtenerEspacioLibre(EPersona lista[])
{
int i,lim;
int posicion;

if(lim>0 && lista !=NULL)
{
    for(i=0;i<lim;i++)
    {
        if(lista[i].estado==FREE)
        {
            posicion=i;
            break;
        }
    }
}
 return posicion;
}
void AltaUnaPersona(EPersona lista[])
{
   int indice;
  /* if(lista != NULL)*/

       indice=obtenerEspacioLibre(lista);

        if(indice>0)
        {
        printf("Ingrese el nombre: ");
        fflush(stdin);
        gets(lista[indice].nombre);
        printf("\nIngrese la edad: ");
        fflush(stdin);
        scanf("%d",&lista[indice].edad);
        printf("\nIngrese el DNI: ");
        scanf("%d",&lista[indice].dni);
        lista[indice].estado=OCUPADO;
        }

}
void AltaPersonas(EPersona lista[],int cantidad)
{
    int limite=0,i;
    printf("Cuantas personas desea ingresar? ");
    fflush(stdin);
    scanf("%d",&limite);
    printf("%d",limite);

    if(limite<=cantidad)
    {
        for(i=0;i<limite;i++)
        {
        AltaUnaPersona(lista);
        }
    }
}

int buscarPorDni(EPersona lista[], int dni)
{
    int i;
    int flag=-1;
    int TAMANIO=20;

    if(lista!=NULL)
  {
        for(i=0;i<TAMANIO;i++)
        {
            if(dni==lista[i].dni)
            {
                printf("La persona buscada es:");
                printf("\n%d %s %d\n",lista[i].dni,lista[i].nombre,lista[i].estado);
                flag=1;
                break;
            }
        }
  }
  return i;
}
void BorrarUnaPersona(EPersona lista[],int indice)
{
   int LIBRE=0;
   if(lista!=NULL)
        {
        lista[indice].estado=LIBRE;
        }
}
void MostrarUnaPersona(EPersona persona)
{
    printf("\nNombre: %s  Edad: %d DNI: %d Estado: %d\n",persona.nombre,persona.edad,persona.dni,persona.estado);
   // printf("------------------------------------------------------\n");
}
void ListarPersonas(EPersona lista[],int cantidad)
{
    int i;
    if(lista !=NULL)
    {
        for(i=0;i<cantidad;i++)
        {
            if(lista[i].estado==OCUPADO)
            {
            //    OrdenarListado(lista[i],cantidad);
                MostrarUnaPersona(lista[i]);
            }

        }
    }

}
void OrdenarListado(EPersona lista[],int cantidad)
{
int i,j;
EPersona aux[cantidad];

for(i=0;i<cantidad-1;i++)
{
    for(j=i+1;j<cantidad;j++)
    {
        if(stricmp(lista[i].nombre,lista[j].nombre)>0)
        {
            strcpy(aux[i].nombre,lista[i].nombre);
            aux[i].edad=lista[i].edad;
            aux[i].dni=lista[i].dni;
            aux[i].estado=lista[i].estado;
            strcpy(lista[i].nombre,lista[j].nombre);
            lista[i].edad=lista[j].edad;
            lista[i].dni=lista[j].dni;
            lista[i].estado=lista[j].estado;
            strcpy(lista[j].nombre,aux[i].nombre);
            lista[j].edad=aux[i].edad;
            lista[j].dni=aux[i].dni;
            lista[j].estado=aux[i].estado;
        }
    }

}

}

