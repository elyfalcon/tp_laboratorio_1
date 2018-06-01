#ifndef UTN_H_INCLUDED
#define UTN_H_INCLUDED
#define TAM 10



/** \brief Valida el rango de opciones para el ingreso al Menu
 * \param entero que es la opcion que ingresa el usuario
 * \param numero entero que es el limite inferior del rango del Menu
 * \param numero entero, limite superior del rango del Menu
 * \return
 */

void ValidaMenu(int opcion,int limite_inferior,int limite_superior);



/** \brief Solicita el ingreso de un entero y valida el valor ingresado
 * \param un mensaje de texto que se muestra .... y valida el ingreso
 * \return el entero ingresado.
 */
int PedirEntero(char mensaje[]);


/** \brief Pide una respuesta por Si o por No (S o N), pasa las letras a mayusculas y realiza la validacion del ingreso
 * \param un char, que es el mensaje que se muestra pidiendo una respuesta
 * \return Devuelve un char S por si y N por no.
 */
char Responder(char mensaje[]);


/** \brief Permite el ingreso de nuevas peliculas
 * \param vector de tipo Emovie
 * \param tamaño del vector
 * \return
 */

void AltaUnaxxxx(EMovie lista[],int);


/** \brief Inicializa colocando en 0 el id de la estructura Emovie
 * \param array de tipo EMovie
 * \param entero que es el tamanio del arry
 * \return
 */
int Inicializa_Peliculas(EMovie lista_movies[],int);


/** \brief Busca el primer lugar disponible
 * \param array de tipo EMovie
 * \param entero que representa el tamanio del array
 * \return el numero del indice disponible
 */
int obtenerEspacioLibre(EMovie lista_movies[],int);


/** \brief Da de baja una pelicula solicitando el titulo que se quiere borrar
 * \param array de tipo movie
 * \return
 */
void BajaPeliculas(EMovie movies[],int);


/** \brief Busca una pelicula por id
 * \param array de tipo Emovie
 * \param entero que representa al id de la pelicula
 * \param tamanio del array
 * \return el id del dato buscado
 *
 */
int buscarPorId(EMovie lista_peliculas[], int,int);

/** \brief Abre el archivo para trabajar
 * \param la estructura Emovie
 * \return
 */

void AbreArchivo(EMovie movie[],char nombre[]);


/** \brief Guarda la estructura en el archivo binario
 * \param vector de la estructura
 * \param tamaño del vector
 * \return
 */
int GuardarPelicula(EMovie movie[],int);



/** \brief Muestra por pantalla una pelicula
 * \param variable de la estructur
 * \return
 */
void MostrarUnaPeli(EMovie movie);

/** \brief Muestra el listado de las peliculas ingresadas por pantalla
 * \param vector de tipo Emovie
 * \param tamaño del vector
 * \return
 */

void ListarPeliculas(EMovie lista_pelis[],int);


/** \brief Valida el formato del campo duracion de la pelicula
 * \param entero para la hora (entre
 * \param entero para los minutos
 * \return un char de la forma HH:MM
 */
char ValidaDuracion(int);

/** \brief Crea un listado de peliculas en un archivo txt
 * \param puntero a la estructura Emovie
 * \return Genera un listado.txt
 */
void CrearListado(EMovie *,int cant);


/** \brief Carga las peliculas desde un archivo
 * \param puntero a la estructura
 * \return un entero que indica si hubo error o si pudo cargar las peliculas
 */
int CargaDesdeArchivo(EMovie *,int);



/** \brief Muestra un menu con los distintos generos de peliculas para seleccionar
 * \param Puntero a la Estructura
 * \param la opcion que se eligio
 * \return
 */
void ElegirGenero(EMovie *,int);


/** \brief Valida el ingreso de las opciones del menu
 * \param la opcion elegida
 * \param el primer valor de opcion del menu
 * \param el ultimo valor de la opcion del menu
 * \return
 */
void ValidaMenu(int opcion,int limite_inferior,int limite_superior);



#endif // UTN_H_INCLUDED
