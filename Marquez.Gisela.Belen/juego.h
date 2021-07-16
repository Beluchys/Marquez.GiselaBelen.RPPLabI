#include "categoria.h"

#ifndef JUEGO_H_INCLUDED
#define JUEGO_H_INCLUDED

typedef struct{
    int codigo;
    char descripcion[30];
    float importe;
    int idCategoria;
}eJuego;

#endif // JUEGO_H_INCLUDED
/** \brief
 *
 * \param aJuegos[] eJuego
 * \param tamJue int
 * \param idBuscado int
 * \return int
 *
 */
int buscarUnJuego(eJuego aJuegos[], int tamJue, int idBuscado);
/** \brief
 *
 * \param unJuego eJuego
 * \param aCategorias[] eCategoria
 * \param tamCat int
 * \return void
 *
 */
void mostrarUnJuego(eJuego unJuego, eCategoria aCategorias[], int tamCat);
/** \brief
 *
 * \param aJuegos[] eJuego
 * \param tamJue int
 * \param aCategorias[] eCategoria
 * \param tamCat int
 * \return int
 *
 */
int mostrarJuegos(eJuego aJuegos[], int tamJue, eCategoria aCategorias[], int tamCat);
/** \brief
 *
 * \param codBuscado int
 * \param aJuegos[] eJuego
 * \param tamJue int
 * \param descripcion[] char
 * \return int
 *
 */
int cargarDescripcionJuego(int codBuscado, eJuego aJuegos[], int tamJue, char descripcion[]);
/** \brief
 *
 * \param aJuegos[] eJuego
 * \param tamJue int
 * \param aCategorias[] eCategoria
 * \param tamCat int
 * \return int
 *
 */
int mostrarJuegosDeCategoriaMesa(eJuego aJuegos[], int tamJue, eCategoria aCategorias[], int tamCat);

