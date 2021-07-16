#ifndef CATEGORIA_H_INCLUDED
#define CATEGORIA_H_INCLUDED

typedef struct{
    int id;
    char descripcion[51];
}eCategoria;

#endif // CATEGORIA_H_INCLUDED
/** \brief Busca una categoria de juego por ID
 *
 * \param aCategorias[] eCategoria
 * \param tamCat int
 * \param idBuscado int
 * \return int
 *
 */
int buscarUnaCategoria(eCategoria aCategorias[], int tamCat, int idBuscado);
/** \brief Carga la descripcion de la categoria
 *
 * \param idBuscado int
 * \param aCategorias[] eCategoria
 * \param tamCat int
 * \param descripcion[] char
 * \return int
 *
 */
int cargarDescripcionCategoria(int idBuscado, eCategoria aCategorias[], int tamCat, char descripcion[]);
/** \brief nos muestra solo una categoria
 *
 * \param unaCategoria eCategoria
 * \return void
 *
 */
void mostrarUnaCategoria(eCategoria unaCategoria);
/** \brief Muestra el listado de categorias
 *
 * \param aCategorias[] eCategoria
 * \param tamCat int
 * \return int
 *
 */
int mostrarCategorias(eCategoria aCategorias[], int tamCat);
