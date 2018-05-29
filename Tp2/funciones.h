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
 * \return int Return el entero ingresado
 */
int PedirEntero(char mensaje[]);


/** \brief pide el ingreso de un dni, valida que exista y hace un borrado logico
 * \param el array lista se pasa como parámetro
 * \param
 * \return es una funcion void
 */
void BorrarUnaPersona(EPersona lista[]);


/** \brief llama a la funcion PedirEntero y a la funcion EsDniValido y da de alta una persona
 * \param array de tipo Epersona se pasa como parametro
 * \param
 * \return es una funcion void
 */
void AltaUnaPersona(EPersona lista[]);



/** \brief pregunta al usuario cuantos ingresos quiere hacer y llama a la funcion AltaUnaPersona para dar el alta
 *
 * \param un array de tipo EPersona
 * \param un entero que es el tamanio del array
 * \return es una funcion void
 */
void AltaPersonas(EPersona lista[],int cantidad);

/** \brief muestra los datos de la persona que coincide con el nombre de la persona
 *
 * \param una variable de tipo Epersona
 * \return es una funcion void
 */
void MostrarUnaPersona(EPersona persona);


/** \brief Lista las todas las personas ingresadas y no borradas
 *
 * \param lista el array se pasa como parametro
 * \param entero cantidad es la longitud del array
 * \return es una funcion void
 */
void ListarPersonas(EPersona lista[],int cantidad);


/** \brief Ordena la estructura por nombre
 * \param lista el array se pasa como parametro
 * \param el entero cantidad es la longitud del array
 * \return es una funcion void
 */
void OrdenarListado(EPersona lista[],int cantidad);

/** \brief Hace un grafico de barras mostrando la cantidad de personas que existen en los rangos <18,
* entre 18 y 35 y mayores de 35
 * \param lista el array se pasa como parametro
 * \param el entero cantidad es la longitud del array
 * \return es una funcion void
 */
void GraficoEdades(EPersona lista[],int cantidad);

/** \brief Valida que el dni ingresado se encuentre dentro del rango de los dni vigentes en Argentina
 * \param el numero de dni que se ingresa
 * \return int Return 1 si es valido, int Return 0 si es invalido
 */
int EsDniValido(int dato);

/** \brief Pide una respuesta por (S/N) por si o no
 *
 * \param  La pregunta a responder por el usuario
 * \return  un char S o N
 *
 */
char Responder(char mensaje[]);


#endif // FUNCIONES_H_INCLUDED
