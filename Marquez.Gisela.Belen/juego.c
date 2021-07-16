#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "juego.h"
#include "categoria.h"
#include "validaciones_marquez.h"


int buscarUnJuego(eJuego aJuegos[], int tamJue, int idBuscado)
{
    int indice=-1;
    if(aJuegos!=NULL && tamJue>0)
    {
        for(int i=0; i<tamJue; i++)
        {
            if(idBuscado==aJuegos[i].codigo)
            {
                indice=i;
                break;
            }
        }
    }
    return indice;
}

void mostrarUnJuego(eJuego unJuego, eCategoria aCategorias[], int tamCat)
{
    char descripcion[20];
    cargarDescripcionCategoria(unJuego.idCategoria,aCategorias,tamCat,descripcion);
    printf("%4d    %20s      %6.2f   %15s\n",unJuego.codigo,
                                            unJuego.descripcion,
                                            unJuego.importe,
                                            descripcion);
}

int mostrarJuegos(eJuego aJuegos[], int tamJue, eCategoria aCategorias[], int tamCat)
{
    int retorno=-1;
    if(aJuegos!=NULL && tamJue>0)
    {
        retorno=0;
        printf(" \n");
            printf("-----------------------------------------------------------------\n");
            printf("                      LISTA DE JUEGOS \n");
            printf("-----------------------------------------------------------------\n\n");
            printf("  ID           Descripcion       Importe        Categoria\n");
            printf("-----------------------------------------------------------------\n\n");
        for(int i=0; i<tamJue; i++)
        {
            mostrarUnJuego(aJuegos[i],aCategorias,tamCat);
        }
    }
    return retorno;
}

int cargarDescripcionJuego(int codBuscado, eJuego aJuegos[], int tamJue, char descripcion[])
{
    int retorno=0;
    if(aJuegos!=NULL && tamJue>0 && descripcion!=NULL)
    {
        for(int i=0; i<tamJue; i++)
        {
            if(aJuegos[i].codigo==codBuscado)
            {
                strcpy(descripcion, aJuegos[i].descripcion);
                retorno=1;
                break;
            }
        }
    }
    return retorno;
}

int mostrarJuegosDeCategoriaMesa(eJuego aJuegos[], int tamJue, eCategoria aCategorias[], int tamCat)
{
    int retorno=0;
    int indiceCat=-1;
    int flag=1;

    if(aJuegos!=NULL && tamJue>0 && aCategorias!=NULL && tamCat>0)
    {
        retorno=1;
        indiceCat=buscarUnaCategoria(aCategorias,tamCat,503);
        for(int i=0; i<tamJue; i++)
        {
            if(aJuegos[i].idCategoria==aCategorias[indiceCat].id)
            {
                flag=0;
            }
        }
        if(flag)
        {
            printf("No hay juegos de esta categoria.\n");
        }
        else
        {
            system("cls");
            printf("-----------------------------------------------------------------\n");
            printf("              LISTA DE JUEGOS DE LA CATEGORIA %s\n",aCategorias[indiceCat].descripcion);
            printf("-----------------------------------------------------------------\n\n");
            printf("  ID           Descripcion       Importe        Categoria\n");
            printf("-----------------------------------------------------------------\n\n");

            for(int i=0; i<tamJue; i++)
            {
                if(aJuegos[i].idCategoria==aCategorias[indiceCat].id)
                {
                    mostrarUnJuego(aJuegos[i], aCategorias, tamCat);
                    flag=0;
                }
            }
        }
    }
    return retorno;
}


