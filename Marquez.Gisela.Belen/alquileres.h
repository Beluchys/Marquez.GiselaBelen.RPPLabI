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

/** \brief Inicializa Alquieres
 *
 * \param aAlquileres[] eAlquiler
 * \param tamAlq int
 * \return int
 *
 */
int inicializarAlquileres(eAlquiler aAlquileres[], int tamAlq);
/** \brief  Nos muestra solo un alquiler
 *
 * \param unAlquiler eAlquiler
 * \param aClientes[] eCliente
 * \param tamCli int
 * \param aJuegos[] eJuego
 * \param tamJue int
 * \return void
 *
 */
void mostrarUnAlquiler(eAlquiler unAlquiler, eCliente aClientes[], int tamCli, eJuego aJuegos[], int tamJue);
/** \brief Nos muestra todos los alquileres
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
int mostrarAlquileres(eAlquiler aAlquileres[], int tamAlq, eCliente aClientes[], int tamCli, eJuego aJuegos[], int tamJue);
/** \brief Busca espacio en el array para mas alquileres
 *
 * \param aAlquileres[] eAlquiler
 * \param tamAlq int
 * \return int
 *
 */
int buscarLibreAlquiler(eAlquiler aAlquileres[], int tamAlq);
/** \brief Busca un alquiler
 *
 * \param aAlquileres[] eAlquiler
 * \param tamAlq int
 * \param codigoBuscado int
 * \return int
 *
 */
int buscarUnAlquiler(eAlquiler aAlquileres[], int tamAlq, int codigoBuscado);
/** \brief Da de alta alquileres
 *
 * \param
 * \param
 * \return
 *
 */
int altaAlquiler(eAlquiler aAlquileres[], int tamAlq,eCliente aClientes[], int tamCli,eJuego aJuegos[], int tamJue,
                 eCategoria aCategorias[], int tamCat, int* pIdAlquiler,eLocalidad aLocalidades[], int tamLoc);
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
int bajaAlquilerIndividual(eAlquiler aAlquileres[], int tamAlq, eCliente aClientes[], int tamCli, eJuego aJuegos[], int tamJue);
int mostrarAlquileresDeUnCliente(eAlquiler aAlquileres[], int tamAlq, eCliente aClientes[], int tamCli, eJuego aJuegos[], int tamJue, eCategoria aCategorias[], int tamCat, eLocalidad aLocalidades[], int tamLoc);
int pagosDeCliente(eAlquiler aAlquileres[], int tamAlq, eCliente aClientes[], int tamCli, eJuego aJuegos[], int tamJue, eCategoria aCategorias[], int tamCat, eLocalidad aLocalidades[], int tamLoc);
int mostrarClientesSinAlquileres(eAlquiler aAlquileres[], int tamAlq, eCliente aClientes[], int tamCli, eLocalidad aLocalidades[], int tamLoc);
int mostrarJuegosSinAlquileres(eAlquiler aAlquileres[], int tamAlq, eJuego aJuegos[], int tamJue, eCategoria aCategorias[], int tamCat);
int listarTelefonosClientesPorFechaDeAlquiler(eAlquiler aAlquileres[], int tamAlq, eCliente aClientes[], int tamCli);
int listarJuegosAlquiladosPorMujeres(eAlquiler aAlquileres[], int tamAlq, eCliente aClientes[], int tamCli, eJuego aJuegos[], int tamJue, eCategoria aCategorias[], int tamCat, eLocalidad aLocalidades[], int tamLoc);
int juegosMasAlquiladosPorHombres(eAlquiler aAlquileres[], int tamAlq, eCliente aClientes[], int tamCli, eJuego aJuegos[], int tamJue, eCategoria aCategorias[], int tamCat);
int clientesQueAlquilaronJuegoEspecifico(eAlquiler aAlquileres[], int tamAlq, eCliente aClientes[], int tamCli, eJuego aJuegos[], int tamJue, eCategoria aCategorias[], int tamCat, eLocalidad aLocalidades[], int tamLoc);
int juegosMasAlquiladosPorMujeres(eAlquiler aAlquileres[], int tamAlq, eCliente aClientes[], int tamCli, eJuego aJuegos[], int tamJue, eCategoria aCategorias[], int tamCat);
int buscarAquiler(eAlquiler alquileres[], int tamAlq, int idAlquiler);
int bajaAlquiler(eAlquiler aAlquileres[], int tamAlq, eCliente aClientes[], int tamCli,eJuego aJuegos[], int tamJue, eCategoria aCategorias[], int tamCat, eLocalidad aLocalidades[], int tamLoc );
