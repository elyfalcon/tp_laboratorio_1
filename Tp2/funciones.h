#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

typedef struct {

    char nombre[50];
    int edad;
    int estado;
    int dni;

}EPersona;

/**
 * Obtiene el primer indice libre del array.
 * @param lista el array se pasa como parametro.
 * @return el primer indice disponible
 */
int obtenerEspacioLibre(EPersona lista[]);

/**
 * Obtiene el indice que coincide con el dni pasado por parametro.
 * @param lista el array se pasa como parametro.
 * @param dni el dni a ser buscado en el array.
 * @return el indice en donde se encuentra el elemento que coincide con el parametro dni
 */
int buscarPorDni(EPersona lista[], int dni);
<<<<<<< HEAD

/** \brief Se marcan todas las posiciones del array como libres
 *          colocando en cada elmento el flag de Estado en FREE
 *
 * \param lista el array se pasa como parametro
 * \param int limite es la longitud del array
 * \return int Return (-1) si hay un Error [Longitud invalida ] - (0) si Ok
 */
int Inicializa_Persona(EPersona lista[],int limite);

/** \brief realiza una pre-carga de datos en la estructura EPersona
 *
 * \param lista el array se pasa como parametro
 * \return como es una funcion void no devuelve nada
 */

void HardcodePersona(EPersona lista[]);

/** \brief pide el ingreso de un entero y valida su ingreso, llama a una funcion
 *  para validar el ingreso de dni
 * \param mensaje[], el que se muestra por pantalla al usuario
 *
 * \return int Return el entero ingresado
 *
 */
int PedirEntero(char mensaje[]);

=======
int Inicializa_Persona(EPersona lista[],int limite);
void HardcodePersona(EPersona lista[]);
>>>>>>> 8e7a25e7d94d44a909af33de63a1f5d486fb215d
void BorrarUnaPersona(EPersona lista[],int indice);
void AltaUnaPersona(EPersona lista[]);
void AltaPersonas(EPersona lista[],int cantidad);
void MostrarUnaPersona(EPersona persona);
void ListarPersonas(EPersona lista[],int cantidad);
void OrdenarListado(EPersona lista[],int cantidad);
void GraficoEdades(EPersona lista[],int cantidad);
<<<<<<< HEAD
int EsDniValido(int dato);
=======
>>>>>>> 8e7a25e7d94d44a909af33de63a1f5d486fb215d

#endif // FUNCIONES_H_INCLUDED
