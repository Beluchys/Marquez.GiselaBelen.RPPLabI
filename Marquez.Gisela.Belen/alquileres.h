#include "fecha.h"
#include "cliente.h"
#include "juego.h"
#include "categoria.h"

#ifndef ALQUILERES_H_INCLUDED
#define ALQUILERES_H_INCLUDED
typedef struct{
    int codigoAlq;
    int codigoJuego;
    int codigoCliente;
    eFecha fecha;
    int isEmpty;
}eAlquiler;


#endif // ALQUILERES_H_INCLUDED

/** \brief Inicializa un array de alquileres, poniendo todos los campos de isEmpty en 1
 *
 * \param aAlquileres[] eAlquiler array de alquileres
 * \param tamAlq int tamaño del array de alquileres
 * \return int retorna -1 si ERROR o 0 si pudo inicializar el array
 *
 */
int inicializarAlquileres(eAlquiler aAlquileres[], int tamAlq);
/** \brief Muestra por pantalla un alquiler
 *
 * \param unAlquiler eAlquiler el alquiler a mostrar
 * \param aClientes[] eCliente array de clientes
 * \param tamCli int tamaño del array de clientes
 * \param aJuegos[] eJuego array de juegos
 * \param tamJue int tamaño del array de juegos
 * \return void
 *
 */
void mostrarUnAlquiler(eAlquiler unAlquiler, eCliente aClientes[], int tamCli, eJuego aJuegos[], int tamJue);
/** \brief Muestra por pantalla un listado de alquileres dados de alta
 *
 * \param aAlquileres[] eAlquiler array de alquileres
 * \param tamAlq int tamaño del array de alquileres
 * \param aClientes[] eCliente array de clientes
 * \param tamCli int tamaño del array de clientes
 * \param aJuegos[] eJuego array de juegos
 * \param tamJue int tamaño del array de juegos
 * \return int retorna -1 si ERROR o 0 si pudo mostrar el array
 *
 */
int mostrarAlquileres(eAlquiler aAlquileres[], int tamAlq, eCliente aClientes[], int tamCli, eJuego aJuegos[], int tamJue);
/** \brief Busca el primer lugar libre en el array de alquileres
 *
 * \param aAlquileres[] eAlquiler array de alquileres
 * \param tamAlq int tamaño del array de alquileres
 * \return int Retorna -1 si ERROR o el indice donde se almacenara el nuevo alquiler
 *
 */
int buscarLibreAlquiler(eAlquiler aAlquileres[], int tamAlq);
/** \brief Busca un alquiler por su ID
 *
 * \param aAlquileres[] eAlquiler array de alquileres
 * \param tamAlq int tamaño del array de alquileress
 * \param codigoBuscado int id del alquiler buscado
 * \return int retorna -1 si ERROR o el indice del alquiler encontrado
 *
 */
int buscarUnAlquiler(eAlquiler aAlquileres[], int tamAlq, int codigoBuscado);
/** \brief Da de alta un nuevo alquiler pidiendo todos los datos y asignandole un ID autoincremental
 *
 * \param aAlquileres[] eAlquiler array de alquileres
 * \param tamAlq int tamaño del array de alquileres
 * \param aClientes[] eCliente array de clientes
 * \param tamCli int tamaño del array de clientes
 * \param aJuegos[] eJuego array de juegos
 * \param tamJue int tamaño del array de juegos
 * \param aCategorias[] eCategorias array de categorias
 * \param tamJue int tamaño del array de categorias
 * \param pIdAlquiler int* direccion de memoria del id a asignar
 * \return int retorna -1 si ERROR o 0 si pudo dar el alta
 *
 */
int altaAlquiler(eAlquiler aAlquileres[], int tamAlq,eCliente aClientes[], int tamCli,eJuego aJuegos[], int tamJue,
                 eCategoria aCategorias[], int tamCat, int* pIdAlquiler,eLocalidad aLocalidades[], int tamLoc);
/** \brief Realiza la baja logica de un cliente y todos sus alquileres
 *
 * \param aClientes[] eCliente array de clientes
 * \param tamCli int tamaño del array de clientes
 * \param aAlquileres[] eAlquiler array de alquileres
 * \param tamAlq int tamaño del array de alquileres
 * \return int retorna -1 si ERROR o 0 si pudo realizar la baja
 *
 */
int bajaClienteYAlquileres(eCliente aClientes[], int tamCli, eAlquiler aAlquileres[], int tamAlq, eLocalidad aLocalidades[], int tamLoc);
/** \brief Baja un alquiler y   cliente
 *
 * \param aAlquileres[] eAlquiler
 * \param tamAlq int
 * \param codCliente int
 * \return int
 *
 */
int bajaAlquileresXCliente(eAlquiler aAlquileres[], int tamAlq, int codCliente);
/** \brief hace la baja de un alquiler de manera individual
 *
 * \param aAlquileres[] eAlquiler
 * \param tamAlq int
 * \param aClientes[] eCliente
 * \param tamCli int
 * \param aJuegos[] eJuego
 * \param tamJue int
 * \return int
 *
 */
int bajaAlquilerIndividual(eAlquiler aAlquileres[], int tamAlq, eCliente aClientes[], int tamCli, eJuego aJuegos[], int tamJue);
/** \brief lista los alquileres de un cliente en especifico
 *
 * \param aAlquileres[] eAlquiler
 * \param tamAlq int
 * \param aClientes[] eCliente
 * \param tamCli int
 * \param aJuegos[] eJuego
 * \param tamJue int
 * \param aCategorias[] eCategoria
 * \param tamCat int
 * \param aLocalidades[] eLocalidad
 * \param tamLoc int
 * \return int
 *
 */
int mostrarAlquileresDeUnCliente(eAlquiler aAlquileres[], int tamAlq, eCliente aClientes[], int tamCli, eJuego aJuegos[], int tamJue, eCategoria aCategorias[], int tamCat, eLocalidad aLocalidades[], int tamLoc);
/** \brief muestra el pago por un cliente en especifico
 *
 * \param aAlquileres[] eAlquiler
 * \param tamAlq int
 * \param aClientes[] eCliente
 * \param tamCli int
 * \param aJuegos[] eJuego
 * \param tamJue int
 * \param aCategorias[] eCategoria
 * \param tamCat int
 * \param aLocalidades[] eLocalidad
 * \param tamLoc int
 * \return int
 *
 */
int pagosDeCliente(eAlquiler aAlquileres[], int tamAlq, eCliente aClientes[], int tamCli, eJuego aJuegos[], int tamJue, eCategoria aCategorias[], int tamCat, eLocalidad aLocalidades[], int tamLoc);
/** \brief lista los cliente que no poseen alquileres
 *
 * \param aAlquileres[] eAlquiler
 * \param tamAlq int
 * \param aClientes[] eCliente
 * \param tamCli int
 * \param aLocalidades[] eLocalidad
 * \param tamLoc int
 * \return int
 *
 */
int mostrarClientesSinAlquileres(eAlquiler aAlquileres[], int tamAlq, eCliente aClientes[], int tamCli, eLocalidad aLocalidades[], int tamLoc);
/** \brief muestra los juegos que no fueron alquilados
 *
 * \param aAlquileres[] eAlquiler
 * \param tamAlq int
 * \param aJuegos[] eJuego
 * \param tamJue int
 * \param aCategorias[] eCategoria
 * \param tamCat int
 * \return int
 *
 */
int mostrarJuegosSinAlquileres(eAlquiler aAlquileres[], int tamAlq, eJuego aJuegos[], int tamJue, eCategoria aCategorias[], int tamCat);
/** \brief lista telefonos de lciente por fecha de alquiler
 *
 * \param aAlquileres[] eAlquiler
 * \param tamAlq int
 * \param aClientes[] eCliente
 * \param tamCli int
 * \return int
 *
 */
int listarTelefonosClientesPorFechaDeAlquiler(eAlquiler aAlquileres[], int tamAlq, eCliente aClientes[], int tamCli);
/** \brief lista todos los juegos alquilados por mujeres
 *
 * \param aAlquileres[] eAlquiler
 * \param tamAlq int
 * \param aClientes[] eCliente
 * \param tamCli int
 * \param aJuegos[] eJuego
 * \param tamJue int
 * \param aCategorias[] eCategoria
 * \param tamCat int
 * \param aLocalidades[] eLocalidad
 * \param tamLoc int
 * \return int
 *
 */
int listarJuegosAlquiladosPorMujeres(eAlquiler aAlquileres[], int tamAlq, eCliente aClientes[], int tamCli, eJuego aJuegos[], int tamJue, eCategoria aCategorias[], int tamCat, eLocalidad aLocalidades[], int tamLoc);
/** \brief lista los juegos mas alquilados por hombres
 *
 * \param aAlquileres[] eAlquiler
 * \param tamAlq int
 * \param aClientes[] eCliente
 * \param tamCli int
 * \param aJuegos[] eJuego
 * \param tamJue int
 * \param aCategorias[] eCategoria
 * \param tamCat int
 * \return int
 *
 */
int juegosMasAlquiladosPorHombres(eAlquiler aAlquileres[], int tamAlq, eCliente aClientes[], int tamCli, eJuego aJuegos[], int tamJue, eCategoria aCategorias[], int tamCat);
/** \brief lista los clientes que alquilaron un juego en especifico
 *
 * \param aAlquileres[] eAlquiler
 * \param tamAlq int
 * \param aClientes[] eCliente
 * \param tamCli int
 * \param aJuegos[] eJuego
 * \param tamJue int
 * \param aCategorias[] eCategoria
 * \param tamCat int
 * \param aLocalidades[] eLocalidad
 * \param tamLoc int
 * \return int
 *
 */
int clientesQueAlquilaronJuegoEspecifico(eAlquiler aAlquileres[], int tamAlq, eCliente aClientes[], int tamCli, eJuego aJuegos[], int tamJue, eCategoria aCategorias[], int tamCat, eLocalidad aLocalidades[], int tamLoc);
/** \brief lista los juegos mas alquilados por mujeres
 *
 * \param aAlquileres[] eAlquiler
 * \param tamAlq int
 * \param aClientes[] eCliente
 * \param tamCli int
 * \param aJuegos[] eJuego
 * \param tamJue int
 * \param aCategorias[] eCategoria
 * \param tamCat int
 * \return int
 *
 */
int juegosMasAlquiladosPorMujeres(eAlquiler aAlquileres[], int tamAlq, eCliente aClientes[], int tamCli, eJuego aJuegos[], int tamJue, eCategoria aCategorias[], int tamCat);
/** \brief busca un alquiler por id
 *
 * \param alquileres[] eAlquiler
 * \param tamAlq int
 * \param idAlquiler int
 * \return int
 *
 */
int buscarAquiler(eAlquiler alquileres[], int tamAlq, int idAlquiler);
/** \brief baja solo un alquiler
 *
 * \param aAlquileres[] eAlquiler
 * \param tamAlq int
 * \param aClientes[] eCliente
 * \param tamCli int
 * \param aJuegos[] eJuego
 * \param tamJue int
 * \param aCategorias[] eCategoria
 * \param tamCat int
 * \param aLocalidades[] eLocalidad
 * \param tamLoc int
 * \return int
 *
 */
int bajaAlquiler(eAlquiler aAlquileres[], int tamAlq, eCliente aClientes[], int tamCli,eJuego aJuegos[], int tamJue, eCategoria aCategorias[], int tamCat, eLocalidad aLocalidades[], int tamLoc );
