/*
 ============================================================================
 Name        : JuanJuarezParcial2.c
 Author      : Juarez Juan
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "controller.h"
#include "parser.h"
#include "menu.h"

int main(void) {


	setbuf(stdout, NULL);
	LinkedList* moviesList = ll_newLinkedList();
	LinkedList* moviesListDramaFilter = ll_newLinkedList();
	char movieFile[30];
	char exit = 'N';
	int flagLoadMovies = 0;

	do{
			switch (menu_main()) {
				case 1:
					printf("Ingrese nombre de archivo: ");
					fflush(stdin);
					gets(movieFile);
					if(!controller_loadMoviesFromText(movieFile, moviesList)){
						printf("No se pudo cargar el archivo.\n");
					}
					else{
						printf("Se cargaron %d peliculas.\n", ll_len(moviesList));
						flagLoadMovies = 1;
					}
					break;
				case 2:
					if(flagLoadMovies){
						controller_listMovies(moviesList);
					}
					else{
						printf("Primero debe cargar el archivo.\n");
					}
					break;
				case 3:
					if(flagLoadMovies){
						moviesList = ll_map(moviesList, movie_setDurationTime);
						controller_listMovies(moviesList);
					}
					else{
						printf("Primero debe cargar el archivo.\n");
					}
					break;
				case 4:
					if(flagLoadMovies){
						moviesListDramaFilter = ll_filter(moviesList, movie_filterDrama);
						controller_listMovies(moviesListDramaFilter);
					}
					else{
						printf("Primero debe cargar el archivo.\n");
					}
					break;
				case 5:
					if(flagLoadMovies){
						ll_sort(moviesList, movie_compareByGender, 1);
						controller_listMovies(moviesList);
					}
					else{
						printf("Primero debe cargar el archivo.\n");
					}
					break;
				case 6:
					if(flagLoadMovies){
						if(controller_saveAsText("moviesfilter.csv",moviesList)){
							printf("Archivo guardado con exito.\n");
						}
					}
					else{
						printf("Primero debe cargar el archivo.\n");
					}
					break;
				case 7:
					controller_exitProgram(&exit);
					break;
				case 8:
					printf("Error! Ingrese un numero.\n");
					break;
				default:
					printf("Opcion Invalida.\n");
					break;
			}
			system("pause");
		}while(exit != 'S');
	return EXIT_SUCCESS;
}
