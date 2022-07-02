/*
 * menu.c
 *
 *  Created on: 1 jul. 2022
 *      Author: jjuarez
 */

#include "menu.h"

int menu_main(){
    int option;
    int sOption;
    system("cls");
    printf("1 - CARGAR ARCHIVO PELICULAS.\n");
    printf("2 - IMPRIMIR PELICULAS.\n");
    printf("3 - ASIGNAR TIEMPO.\n");
    printf("4 - FILTRAR POR TIPO.\n");
    printf("5 - MOSTRAR DURACIONES.\n");
    printf("6 - GUARDAR PELICULAS.\n");
    printf("7 - SALIR.\n\n");
    printf("Ingrese opcion: ");
    fflush(stdin);
    sOption = scanf("%d", &option);
    if(!sOption){
    	option = 8;
    }
    return option;
}
