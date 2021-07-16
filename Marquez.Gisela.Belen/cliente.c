#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "cliente.h"
#include "validaciones_marquez.h"

int inicializarClientes(eCliente aClientes[], int tamCli)
{
    int retorno=-1;
    if(aClientes!=NULL && tamCli>0)
    {
        retorno=0;
        for(int i=0; i<tamCli; i++)
        {
            aClientes[i].isEmpty=1;
        }
    }
    return retorno;
}
//**********************************************************************//
int altaCliente(eCliente aClientes[], int tamCli, int* pId, eLocalidad aLocalidades[], int tamLoc)
{
    int retorno=-1;
    int indice;
    eCliente nuevoCliente;

    if(aClientes!=NULL && tamCli>0 && pId!=NULL && aLocalidades!=NULL && tamLoc>0)
    {
        system("cls");
        printf("---------------------------------\n");
        printf("    **** ALTA CLIENTE ****   \n");
        printf("---------------------------------\n\n");
        indice = buscarLibreCliente(aClientes,tamCli);
        if(indice!=-1)
        {
            printf("Codigo: %d\n",*pId);
            utn_getNombre(nuevoCliente.nombre,51,"Ingrese nombre: ","Error.\n",3);
            utn_getNombre(nuevoCliente.apellido,51,"Ingrese apellido: ","Error.\n",3);
            utn_getCaracter(&nuevoCliente.sexo,"Ingrese sexo: ","Error.\n",'f','m',3);
            utn_getTextoEspecial(nuevoCliente.telefono,"Ingrese telefono: ","Error.\n",21,3);
            mostrarLocalidades(aLocalidades,tamLoc);
            utn_getNumero(&nuevoCliente.idLocalidad,"\nIngrese el ID de la localidad: ","Error.\n",90001,90005,3);

            aClientes[indice]=nuevoCliente;
            aClientes[indice].isEmpty=0;
            aClientes[indice].codigo = *pId;
            *pId = (*pId)+1; //ACTUALIZAMOS EL PROXIMO ID
            retorno=1;
        }
        else
        {
            printf("-----------------------------------------\n");
            printf("    NO HAY LUGAR PARA MAS CLIENTES   \n");
            printf("-----------------------------------------\n\n");
        }
    }
    return retorno;
}
//**********************************************************************//
int buscarLibreCliente(eCliente aClientes[], int tamCli)
{
    int indice=-1;
    if(aClientes!=NULL && tamCli>0)
    {
        for(int i=0; i<tamCli; i++)
        {
            if(aClientes[i].isEmpty)
            {
                indice=i;
                break;
            }
        }
    }
    return indice;
}
//**********************************************************************//
int buscarUnCliente(eCliente aClientes[], int tamCli, int codigoBuscado)
{
    int indice=-1;
    if(aClientes!=NULL && tamCli>0)
    {
        for(int i=0; i<tamCli; i++)
        {
            if(codigoBuscado==aClientes[i].codigo && !aClientes[i].isEmpty)
            {
                indice=i;
                break;
            }
        }
    }
    return indice;
}
//**********************************************************************//
void mostrarClienteUnico(eCliente unCliente, eLocalidad aLocalidades[], int tamLoc)
{
    char descripcion[21];
    cargarDescripcionLocalidad(unCliente.idLocalidad,aLocalidades,tamLoc,descripcion);
    printf("   %5d     %10s    %10s       %c   %13s  %13s\n",unCliente.codigo,
           unCliente.nombre,
           unCliente.apellido,
           unCliente.sexo,
           unCliente.telefono,
           descripcion);
}
//**********************************************************************//
int mostrarClientes(eCliente aClientes[], int tamCli, eLocalidad aLocalidades[], int tamLoc)
{
    int retorno=-1;
    int flag=0;
    if(aClientes!=NULL && tamCli>0 && aLocalidades!=NULL && tamLoc>0)
    {
        retorno=0;
        for(int i=0; i<tamCli; i++)
        {
            if(!aClientes[i].isEmpty)
            {
                flag=1;
                break;
            }
        }
        if(flag)
        {
            system("cls");
            printf("-------------------------------------------------------------------------------\n");
            printf("                         **** LISTA DE CLIENTES ****       \n");
            printf("-------------------------------------------------------------------------------\n");
            printf("\n");
            printf(" N. Cliente      Nombre       Apellido     Sexo     Telefono      Localidad\n\n");
            printf("-------------------------------------------------------------------------------\n");
        }
        else
        {
            printf("-----------------------------------------\n");
            printf("         NO HAY CLIENTES CARGADOS  \n");
            printf("-----------------------------------------\n\n");
        }
        for(int i=0; i<tamCli; i++)
        {
            if(!aClientes[i].isEmpty)
            {
                mostrarClienteUnico(aClientes[i],aLocalidades,tamLoc);
            }
        }
    }
    return retorno;
}
//**********************************************************************//
int modificarUnCliente(eCliente aClientes[], int tamCli, eLocalidad aLocalidades[], int tamLoc)
{
    int retorno=-1;
    int indice;
    int opcion;
    int codigo;
    eCliente auxCliente;
    int flagNombre=1;
    int flagApellido=1;
    int flagTelefono=1;

    if(aClientes!=NULL && tamCli>0 && aLocalidades!=NULL && tamLoc>0)
    {
        mostrarClientes(aClientes,tamCli,aLocalidades,tamLoc);
        utn_getNumero(&codigo,"\nIngrese codigo del cliente: ","ERROR. ", 1000,3000,3);
        indice = buscarUnCliente(aClientes,tamCli,codigo);
        if(indice==-1)
        {
            printf("\n----------------------------------------------------\n");
            printf("         NO SE ENCONTRO CLIENTE CON ESE CODIGO  \n");
            printf("----------------------------------------------------\n\n");
        }
        else
        {
            printf("-----------------------------------------------------------------------------\n");
            printf("                           CLIENTE ENCONTRADO  \n");
            printf("-----------------------------------------------------------------------------\n\n");
            printf(" N. Cliente      Nombre       Apellido     Sexo     Telefono      Localidad\n\n");
            printf("-----------------------------------------------------------------------------\n");
            mostrarClienteUnico(aClientes[indice],aLocalidades,tamLoc);

            do
            {
                opcion=menuModificaciones();
                switch(opcion)
                {
                case 1:
                    flagNombre = utn_getNombre(auxCliente.nombre,51,"Ingrese nuevo nombre: ","Error. ",3);
                    strcpy(aClientes[indice].nombre,auxCliente.nombre);
                    break;
                case 2:
                    flagApellido = utn_getNombre(auxCliente.apellido,51,"Ingrese nuevo apellido: ","Error. ",3);
                    strcpy(aClientes[indice].apellido,auxCliente.apellido);
                    break;
                case 3:
                    flagTelefono = utn_getTextoEspecial(auxCliente.telefono,"Ingrese nuevo telefono: ","Error. ",21,3);
                    strcpy(aClientes[indice].telefono,auxCliente.telefono);
                    break;
                case 4:
                    printf("----------------------------------------------------\n");
                    printf("              CLIENTE MODIFICADO  \n");
                    printf("----------------------------------------------------\n\n");
                    mostrarClienteUnico(aClientes[indice],aLocalidades,tamLoc);
                    retorno=0;
                    break;
                case 5:
                    printf("----------------------------------------------------\n");
                    printf("                ACCION CANCELADA  \n");
                    printf("----------------------------------------------------\n\n");
                    break;
                }
            }
            while(opcion!=4 && opcion!=5);
        }
    }
    return retorno;
}
//**********************************************************************//
int ordenarClientesPorNombreYApellido(eCliente aClientes[], int tamCli)
{
    int retorno=-1;
    eCliente auxCliente;
    if(aClientes!=NULL && tamCli>0)
    {
        retorno=0;
        for(int i=0; i<tamCli-1 && !aClientes[i].isEmpty; i++)
        {
            for(int j=i+1; j<tamCli && !aClientes[j].isEmpty; j++)
            {
                if(strcmp(aClientes[i].nombre, aClientes[j].nombre)>0 || (strcmp(aClientes[i].nombre, aClientes[j].nombre)==0 && strcmp(aClientes[i].apellido, aClientes[j].apellido)>0))
                {
                    auxCliente = aClientes[i];
                    aClientes[i] = aClientes[j];
                    aClientes[j] = auxCliente;
                }
            }
        }
    }
    return retorno;
}
//**********************************************************************//
int ordenarClientesPorApellidoYNombre(eCliente aClientes[], int tamCli)
{
    int retorno=-1;
    eCliente auxCliente;
    if(aClientes!=NULL && tamCli>0)
    {
        retorno=0;
        for(int i=0; i<tamCli-1 && !aClientes[i].isEmpty; i++)
        {
            for(int j=i+1; j<tamCli && !aClientes[j].isEmpty; j++)
            {
                if(strcmp(aClientes[i].apellido, aClientes[j].apellido)>0 || (strcmp(aClientes[i].apellido, aClientes[j].apellido)==0 && strcmp(aClientes[i].nombre, aClientes[j].nombre)>0))
                {
                    auxCliente = aClientes[i];
                    aClientes[i] = aClientes[j];
                    aClientes[j] = auxCliente;
                }
            }
        }
    }
    return retorno;
}
//**********************************************************************//
int cargarNombreApellidoPorCodigo(int codBuscado, eCliente aClientes[], int tamCli, char nombre[], char apellido[])
{
    int retorno=0;
    if(aClientes!=NULL && tamCli>0 && nombre!=NULL && apellido!=NULL)
    {
        for(int i=0; i<tamCli; i++)
        {
            if(aClientes[i].codigo==codBuscado)
            {
                strcpy(nombre, aClientes[i].nombre);
                strcpy(apellido, aClientes[i].apellido);
                retorno=1;
                break;
            }
        }
    }
    return retorno;
}
//**********************************************************************//
int listarClientesDeUnaLocalidad(eCliente aClientes[], int tamCli, eLocalidad aLocalidades[], int tamLoc)
{
    int retorno=0;
    int idBuscado=-1;
    if(aClientes!=NULL && tamCli>0 && aLocalidades!=NULL && tamLoc>0)
    {
        retorno=1;
        mostrarLocalidades(aLocalidades,tamLoc);
        utn_getNumero(&idBuscado,"\nElija una localidad: ", "Error. ",90001,90005,3);

        printf("\n");
        printf("-------------------------------------------------------------------------------\n");
        printf(" N. Cliente      Nombre       Apellido     Sexo     Telefono      Localidad\n\n");
        printf("-------------------------------------------------------------------------------\n");
        for(int i=0; i<tamCli; i++)
        {
            if(aClientes[i].idLocalidad==idBuscado)
            {
                mostrarClienteUnico(aClientes[i],aLocalidades,tamLoc);
            }
        }

    }

    return retorno;
}
//**********************************************************************//
int mostrarLocalidadConMasClientes(eCliente aClientes[], int tamCli, eLocalidad aLocalidades[], int tamLoc)
{
    int retorno=0;
    int arrayContador[tamLoc];
    int maximo;
    if(aClientes!=NULL && tamCli>0 && aLocalidades!=NULL && tamLoc>0)
    {
        retorno=1;
        for(int i=0; i<tamLoc; i++)
        {
            arrayContador[i]=0;
            for(int j=0; j<tamCli; j++)
            {
                if(aClientes[j].idLocalidad==aLocalidades[i].id)
                {
                    arrayContador[i]++;
                }
            }
        }
        maximo=arrayContador[0];
        for(int i=0; i<tamLoc; i++)
        {
            if(maximo<arrayContador[i])
            {
                maximo=arrayContador[i];
            }
        }

        printf("---------------------------------------------------------------------------------\n");
        printf("                            LOCALIDADES CON MAS CLIENTES \n");
        printf("---------------------------------------------------------------------------------\n\n");
        for(int i=0; i<tamLoc; i++)
        {
            if(arrayContador[i]==maximo)
            {
                printf("\n\n%s\n", aLocalidades[i].descripcion);
            }
        }

    }

    return retorno;
}
/**********************************************************************/

int mostrarLocalidadConMenosClientes(eCliente aClientes[], int tamCli, eLocalidad aLocalidades[], int tamLoc)
{
    int retorno=0;
    int arrayContador[tamLoc];
    int maximo;
    if(aClientes!=NULL && tamCli>0 && aLocalidades!=NULL && tamLoc>0)
    {
        retorno=1;
        for(int i=0; i<tamLoc; i++)
        {
            arrayContador[i]=0;
            for(int j=0; j<tamCli; j++)
            {
                if(aClientes[j].idLocalidad==aLocalidades[i].id)
                {
                    arrayContador[i]++;
                }
            }
        }
        maximo=arrayContador[0];
        for(int i=0; i<tamLoc; i++)
        {
            if(maximo>arrayContador[i])
            {
                maximo=arrayContador[i];
            }
        }

        printf("---------------------------------------------------------------------------------\n");
        printf("                            LOCALIDADES CON MENOS CLIENTES \n");
        printf("---------------------------------------------------------------------------------\n\n");
        for(int i=0; i<tamLoc; i++)
        {
            if(arrayContador[i]==maximo)
            {
                printf("\n\n%s\n", aLocalidades[i].descripcion);
            }
        }

    }

    return retorno;
}
