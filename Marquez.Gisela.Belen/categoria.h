#ifndef CATEGORIA_H_INCLUDED
#define CATEGORIA_H_INCLUDED

typedef struct{
    int id;
    char descripcion[51];
}eCategoria;

#endif // CATEGORIA_H_INCLUDED
int buscarUnaCategoria(eCategoria aCategorias[], int tamCat, int idBuscado);
int cargarDescripcionCategoria(int idBuscado, eCategoria aCategorias[], int tamCat, char descripcion[]);
void mostrarUnaCategoria(eCategoria unaCategoria);
int mostrarCategorias(eCategoria aCategorias[], int tamCat);
