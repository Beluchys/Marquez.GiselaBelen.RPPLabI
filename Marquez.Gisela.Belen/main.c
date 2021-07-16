#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "validaciones_marquez.h"
#include "dataWarehouse.h"
#include "cliente.h"
#include "alquileres.h"

#define TAMJUE 9
#define TAMCAT 5
#define TAM 10
#define TAMALQ 22
#define TAMLOC 5

int main()
{
    int option = 0;
    int idClientes=1010;
    int idAlquiler=40021;
    int flagCliente=0;
    eJuego juegos[TAMJUE];
    eCategoria categorias[TAMCAT];
    eCliente clientes[TAM];
    eAlquiler alquileres[TAMALQ];
    eLocalidad localidades[TAMLOC];

    inicializarClientes(clientes,TAM);
    inicializarAlquileres(alquileres,TAMALQ);
    hardcodearJuegos(juegos,TAMJUE);
    hardcodearCategorias(categorias,TAMCAT);
    hardcodearClientes(clientes, 10);
    hardcodearAlquileres(alquileres,18);
    hardcodearLocalidades(localidades,TAMLOC);

    do
    {
        switch(menuOpciones())
        {
        case 1:
            if(altaCliente(clientes,TAM,&idClientes,localidades,TAMLOC))
            {
                printf("---------------------------------------------------------------\n");
                printf("                       ALTA EXITOSA!\n");
                printf("---------------------------------------------------------------\n");
                flagCliente=1;
            }
            else
            {
                printf("---------------------------------------------------------------\n");
                printf("                HUBO UN ERROR AL DAR DE ALTA!\n");
                printf("---------------------------------------------------------------\n");
            }
            system("pause");
            break;
        case 2:
            if(flagCliente)
            {
                modificarUnCliente(clientes,TAM,localidades,TAMLOC);
            }
            else
            {
                printf("---------------------------------------------------------------\n");
                printf("              PRIMERO DEBE CARGAR UN CLIENTE!\n");
                printf("---------------------------------------------------------------\n");
            }
            system("pause");
            break;
        case 3:
            if(flagCliente)
            {
                bajaClienteYAlquileres(clientes,TAM,alquileres,TAMALQ,localidades,TAMLOC);

            }
            else
            {
                printf("---------------------------------------------------------------\n");
                printf("              PRIMERO DEBE CARGAR UN CLIENTE!\n");
                printf("---------------------------------------------------------------\n");
            }
            system("pause");
            break;
        case 4:

            mostrarClientes(clientes,TAM,localidades,TAMLOC);
            system("pause");
            break;
        case 5:
            if(flagCliente)
            {
                altaAlquiler(alquileres,TAMALQ,clientes,TAM,juegos,TAMJUE,categorias,TAMCAT,&idAlquiler,localidades,TAMLOC);
            }
            else
            {
                printf("---------------------------------------------------------------\n");
                printf("              PRIMERO DEBE CARGAR UN CLIENTE!\n");
                printf("---------------------------------------------------------------\n");
            }
            system("pause");
            break;
        case 6:
            system("cls");
            mostrarJuegos(juegos,TAMJUE,categorias,TAMCAT);
            system("pause");
            break;
        case 7:
            system("cls");
            mostrarCategorias(categorias,TAMCAT);
            system("pause");
            break;
        case 8:
            system("cls");
            mostrarAlquileres(alquileres,TAMALQ,clientes,TAM,juegos,TAMJUE);
            system("pause");
            break;
        case 9:
            mostrarJuegosDeCategoriaMesa(juegos,TAMJUE,categorias,TAMCAT);
            system("pause");
            break;
        case 10:
            mostrarAlquileresDeUnCliente(alquileres,TAMALQ,clientes,TAMALQ,juegos,TAMJUE,categorias,TAMCAT,localidades,TAMLOC);
            system("pause");
            break;
        case 11:
            pagosDeCliente(alquileres,TAMALQ,clientes,TAMALQ,juegos,TAMJUE,categorias,TAMCAT,localidades,TAMLOC);
            system("pause");
            break;
        case 12:
            system("cls");
            mostrarClientesSinAlquileres(alquileres,TAMALQ,clientes,TAM,localidades,TAMLOC);
            system("pause");
            break;
        case 13:
            system("cls");
            mostrarJuegosSinAlquileres(alquileres,TAMALQ,juegos,TAMJUE,categorias,TAMCAT);
            system("pause");
            break;
        case 14:
            system("cls");
            listarTelefonosClientesPorFechaDeAlquiler(alquileres,TAMALQ,clientes,TAM);
            system("pause");
            break;
        case 15:
            system("cls");
            listarJuegosAlquiladosPorMujeres(alquileres,TAMALQ,clientes,TAM,juegos,TAMJUE,categorias,TAMCAT,localidades,TAMLOC);
            system("pause");
            break;
        case 16:
            system("cls");
            juegosMasAlquiladosPorHombres(alquileres,TAMALQ,clientes,TAM,juegos,TAMJUE,categorias,TAMCAT);
            system("pause");
            break;
        case 17:
            system("cls");
            clientesQueAlquilaronJuegoEspecifico(alquileres,TAMALQ,clientes,TAM,juegos,TAMJUE,categorias,TAMCAT,localidades,TAMLOC);
            system("pause");
            break;
        case 18:
            system("pause");
            break;
        case 19:
            system("cls");
            listarClientesDeUnaLocalidad(clientes,TAM,localidades,TAMLOC);
            system("pause");
            break;
        case 20:
            system("cls");
            mostrarLocalidadConMasClientes(clientes,TAM,localidades,TAMLOC);
            system("pause");
            break;
        case 21:
            system("cls");
            mostrarLocalidadConMenosClientes(clientes,TAM,localidades,TAMLOC);
            system("pause");
            break;
        case 22:
            system("cls");
            bajaAlquiler(alquileres,TAMALQ,clientes,TAM,juegos,TAMJUE,categorias,TAMCAT,localidades,TAMLOC);
            system("pause");
            break;
        case 23:
            system("cls");
            ordenarClientesPorApellidoYNombre(clientes,TAM);
            mostrarClientes(clientes,TAM,localidades,TAMLOC);
            system("pause");
            break;
        case 24:
            system("cls");
            ordenarClientesPorNombreYApellido(clientes,TAM);
            mostrarClientes(clientes,TAM,localidades,TAMLOC);
            system("pause");
            break;
        case 25:
            system("cls");
            juegosMasAlquiladosPorMujeres(alquileres,TAMALQ,clientes,TAM,juegos,TAMJUE,categorias,TAMCAT);
            system("pause");
            break;
        }
    }
    while(option != 26);

    return 0;
}
