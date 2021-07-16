#include "localidad.h"

#ifndef CLIENTE_H_INCLUDED
#define CLIENTE_H_INCLUDED

typedef struct{
    int codigo;
    char nombre[51];
    char apellido[51];
    char sexo;
    char telefono[21];
    int idLocalidad;
    int isEmpty;
}eCliente;

#endif // CLIENTE_H_INCLUDED

int inicializarClientes(eCliente aClientes[], int tamCli);
int altaCliente(eCliente aClientes[], int tamCli, int* pId, eLocalidad aLocalidades[], int tamLoc);
int buscarLibreCliente(eCliente aClientes[], int tamCli);
int buscarUnCliente(eCliente aClientes[], int tamCli, int codigoBuscado);
void mostrarClienteUnico(eCliente unCliente, eLocalidad aLocalidades[], int tamLoc);
int mostrarClientes(eCliente aClientes[], int tamCli, eLocalidad aLocalidades[], int tamLoc);
int modificarUnCliente(eCliente aClientes[], int tamCli, eLocalidad aLocalidades[], int tamLoc);
int ordenarClientesPorNombreYApellido(eCliente aClientes[], int tamCli);
int ordenarClientesPorApellidoYNombre(eCliente aClientes[], int tamCli);
int cargarNombreApellidoPorCodigo(int codBuscado, eCliente aClientes[], int tamCli, char nombre[], char apellido[]);
int listarClientesDeUnaLocalidad(eCliente aClientes[], int tamCli, eLocalidad aLocalidades[], int tamLoc);
int mostrarLocalidadConMasClientes(eCliente aClientes[], int tamCli, eLocalidad aLocalidades[], int tamLoc);
