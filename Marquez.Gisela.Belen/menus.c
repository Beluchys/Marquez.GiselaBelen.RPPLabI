#include "menus.h"

int menuOpciones()
{
    int opcion;
    system("cls");
    printf("---------------------------------------------------\n");
    printf("            **** ABM JUEGOS INFANTILES *** \n");
    printf("---------------------------------------------------\n");
    printf("\n");
    printf("1) Alta cliente.\n");
    printf("2) Modificar cliente.\n");
    printf("3) Baja cliente.\n");
    printf("4) Listar clientes.\n");
    printf("5) Alta Alquiler.\n");
    printf("6) Mostrar Juegos.\n");
    printf("7) Mostrar Categorias.\n");
    printf("8) Mostrar Alquileres.\n");
    printf("9) Mostrar juegos de categoria de mesa.\n");
    printf("10) Mostrar alquileres efectuados por algun cliente.\n");
    printf("11) Mostrar el total de todos los importes pagados por cliente.\n");
    printf("12) Clientes que no tienen alquiler.\n");
    printf("13) Juegos que no han sido alquilados.\n");
    printf("14) Listar los telefonos de los clientes que alquilaron juegos en una determinada fecha.\n");
    printf("15) Listar los juegos alquilados por mujeres.\n");
    printf("16) Mostrar el o los juegos mas alquilados por hombres.\n");
    printf("17) Listar los clientes que alquilaron un determinado juego.\n");
    printf("18) Mostrar la recaudación de una fecha en particular.\n");
    printf("19) Listar los clientes de una localidad determinada. (INFORME)\n");
    printf("20) Mostrar localidad/es con mas clientes. (INFORME)\n");
    printf("21) Mostrar localidad/es con menos clientes. (INFORME)\n");
    printf("22) Baja solo Alquiler.\n");
    printf("23) Ordenar Clientes por Apellido (Ascendente) (INFORME)\n");
    printf("24) Ordenar Clientes por Nombre (Ascendente) (INFORME)\n");
    printf("25) Mostrar el o los juegos mas alquilados por Mujeres. (INFORME)\n");
    printf("26) Salir.\n");
    printf("\n");
    printf("---------------------------------------------------\n");

    utn_getNumero(&opcion, "\nOpcion: ", "Error, opcion incorrecta.", 1, 26, 3);

    return opcion;
}

int menuModificaciones()
{
    int opcion=0;
    printf("---------------------------------------------------\n");
    printf("            **** MENU DE MODIFICACIONES *** \n");
    printf("---------------------------------------------------\n\n");
    printf("1) Nombre.\n");
    printf("2) Apellido.\n");
    printf("3) Telefono.\n");
    printf("4) Guardar cambios y salir.\n");
    printf("5) Descartar cambios y salir.\n");

    utn_getNumero(&opcion, "\nOpcion: ", "Error, opcion incorrecta.", 1, 5, 3);
    return opcion;
}
