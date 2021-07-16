#ifndef LOCALIDAD_H_INCLUDED
#define LOCALIDAD_H_INCLUDED

typedef struct{
    int id;
    char descripcion[21];
}eLocalidad;


#endif // LOCALIDAD_H_INCLUDED
/** \brief
 *
 * \param aLocalidades[] eLocalidad
 * \param tamLoc int
 * \param idBuscado int
 * \return int
 *
 */
int buscarUnaLocalidad(eLocalidad aLocalidades[], int tamLoc, int idBuscado);
/** \brief
 *
 * \param idBuscado int
 * \param aLocalidades[] eLocalidad
 * \param tamLoc int
 * \param descripcion[] char
 * \return int
 *
 */
int cargarDescripcionLocalidad(int idBuscado, eLocalidad aLocalidades[], int tamLoc, char descripcion[]);
/** \brief
 *
 * \param unaLocalidad eLocalidad
 * \return void
 *
 */
void mostrarUnaLocalidad(eLocalidad unaLocalidad);
/** \brief
 *
 * \param aLocalidades[] eLocalidad
 * \param tamLoc int
 * \return int
 *
 */
int mostrarLocalidades(eLocalidad aLocalidades[], int tamLoc);
