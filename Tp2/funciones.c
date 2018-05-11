#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "funciones.h"
#define FREE 0
#define OCUPADO 1

int Inicializa_Persona(EPersona lista[],int limite)
{
   int i;
   int retorno=-1;
   if(limite >0 && lista !=NULL)
   {
       for(i=0;i<limite;i++)
       {
           retorno=0;
           lista[i].estado=FREE;
        }
   }
    return retorno;
}
int EsDniValido(int dato)
{
  if(dato>=1000000 && dato<=99999999)
    return 1;

  return 0;
}

int obtenerEspacioLibre(EPersona lista[])
{
int i;
int lim=20;
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
int PedirEntero(char mensaje[])
{
    int auxiliar;
    int ok=0;
    int valor=0;

    do
    {
    printf("%s",mensaje);
    fflush(stdin);
    ok=scanf("%d",&auxiliar);
    valor=EsDniValido(auxiliar);
    }while(!(ok && valor));

    return auxiliar;
}


void AltaUnaPersona(EPersona lista[])
{
   int indice;
   long int dni=0;
   int SiExiste=0;

        dni=PedirEntero("Ingrese el dni: "); //llama a la funcion Pedir entero para el ingreso
        SiExiste=buscarPorDni(lista,dni);

    if(SiExiste=-1)
        {
       indice=obtenerEspacioLibre(lista);

            if(indice>0)
            {
            printf("Ingrese el nombre: ");
            fflush(stdin);
            gets(lista[indice].nombre);
            printf("\nIngrese la edad: ");
            fflush(stdin);
            scanf("%d",&lista[indice].edad);
            lista[indice].dni=dni;
            lista[indice].estado=OCUPADO;
        }
        }
        else
        {
            printf("\nEl Dni ya esta ingresado: \n");
            system("pause");
        }
}
void AltaPersonas(EPersona lista[],int cantidad)
{
    int limite=0,i;
    system("cls");
    printf("Cuantas personas desea ingresar? ");
    fflush(stdin);
    scanf("%d",&limite);

    if(limite<=cantidad)
    {
        for(i=0;i<limite;i++)
        {
        AltaUnaPersona(lista);
        }
    }
    system("pause");
    system("cls");
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
                flag=i;
                break;
            }
        }
  }
  return flag;
}
void BorrarUnaPersona(EPersona lista[])
{
    int i;
    int index;
    char resp='S';

    system("cls");
    i=PedirEntero("Ingrese el DNI: ");
    index= buscarPorDni(lista,i);

  if(index !=-1 && resp=='S')
    {
       system("pause");
       lista[index].estado=0;
       lista[index].dni=0;
    }
    else
    {
      printf("Persona no encontrada!!!\n");
      system("pause");
     }
system("cls");

}
void MostrarUnaPersona(EPersona persona)
{
    printf("\nNombre: %s  Edad: %d DNI: %d Estado: %d\n",persona.nombre,persona.edad,persona.dni,persona.estado);

}

void ListarPersonas(EPersona lista[],int cantidad)
{
    int i;
    system("cls");
    if(cantidad >0 && lista !=NULL)
    {
        OrdenarListado(lista,cantidad);

        for(i=0;i<cantidad;i++)
        {
            if(lista[i].estado==1)
              MostrarUnaPersona(lista[i]);
        }
    }
    system("pause");
    system("cls");
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
void HardcodePersona(EPersona lista[])
{
       int i;
       char nombre[][20]= {"Juan","Luis","Maria","Jose"};
       int dni[]= {25963258,22897451,17852369,45896321};
       int edad[]={21,18,45,15};
       int estado[]={OCUPADO,OCUPADO,OCUPADO,OCUPADO};

      for(i=0;i<4;i++)
      {
          strcpy(lista[i].nombre,nombre[i]);
          lista[i].dni=dni[i];
          lista[i].edad=edad[i];
          lista[i].estado=estado[i];
      }


}
void GraficoEdades(EPersona lista[],int cantidad)
{
 int i,j;
 int vecontador[4];
 int men=0;
 int entre=0;
 int may=0;
 int max;

 system("cls");

 for(i=0;i<4;i++)
 {
     vecontador[i]=0;

 }

    if(cantidad>0 && lista!=NULL)
    {
        for(i=0;i<cantidad;i++)
        {
            if(lista[i].edad <18 && lista[i].edad >0)
                {
                men++;
                }

            if(lista[i].edad >=19 && lista[i].edad <=35)
            {
                entre++;
            }
            else
            if(lista[i].edad >=35 && lista[i].edad <100)
            {
                may++;
            }

        }
    }
  //ahora grafico a partir de los vectores que contienen los rangos de edad


//Inicializo el array

int auxiliar[3]={men,entre,may};
//cargo el array con los contadores
for(i=0;i<3;i++)
{
    vecontador[i]=auxiliar[i];
    }
 //Busco el mayor
 max=vecontador[0];

      for(i=0;i<3;i++)
      {
          if(vecontador[i]>max)
          {
              max=vecontador[i];
          }
      }

     for(i=max;i>0;i--)
      {
         for(j=0;j<3;j++)
         {
            if(vecontador[j]>=i)
            {
                 printf("   *");
            }
            else{
            printf("   ");
            printf("\n");
            }
        }

      }

printf("\n<18  >19<35  >35\n\n");
printf("\nGrafico de Columnas que muestra la cantidad de personas por rango de edades\n");
system("pause");
system("cls");
}
