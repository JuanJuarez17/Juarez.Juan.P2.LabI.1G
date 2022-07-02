/*
 * controller.c
 *
 *  Created on: 1 jul. 2022
 *      Author: jjuarez
 */

#include "controller.h"

int controller_loadMoviesFromText(char* path , LinkedList* pArrayListMovies){
	int rtn = 0;
	FILE* file = NULL;
	if(path != NULL && pArrayListMovies != NULL){
		file = fopen(path, "r");
		if(file != NULL){
			if(parser_movieFromText(file, pArrayListMovies)){
				printf("Carga de archivo exitosa.\n");
				rtn = 1;
			}
			else{
				printf("Error! No se pudo cargar el archivo.\n");
			}
		}
	}
    return rtn;
}

int controller_listMovies(LinkedList* pArrayListMovies){
	int rtn = 0;
	int len;
	sMovie* auxMovie = NULL;
	if(pArrayListMovies != NULL){
		len = ll_len(pArrayListMovies);
		printf("----------------------------------------------------------\n");
		printf(" ID   TITULO                         GENERO       DURACION\n");
		printf("----------------------------------------------------------\n");
		for(int i = 0; i < len; i++){
			auxMovie = (sMovie*)ll_get(pArrayListMovies, i);
			if(auxMovie != NULL){
				movie_print(auxMovie);
				rtn = 1;
			}
		}
	}
	return rtn;
}

void controller_exitProgram(char *pExit){
	if (pExit != NULL) {
		printf("Confirma salida? (S/N): ");
		fflush(stdin);
		scanf("%c", pExit);
		*pExit = toupper(*pExit);

		while(!(input_validateCharOpt(*pExit, 'S', 'N'))){
            printf("Error! Confirma salida? (S/N): ");
            fflush(stdin);
            scanf("%c", pExit);
            *pExit = toupper(*pExit);
		}
	}
}

int input_validateCharOpt(char cEvaluate, char option1, char option2){
	int rtn = 0;
        if(cEvaluate == option1 || cEvaluate == option2){
            rtn = 1;
        }
	return rtn;
}

int controller_saveAsText(char* path , LinkedList* pArrayListMovies)
{
	int rtn = 0;
	FILE* auxFile = NULL;
	sMovie* auxMovie = NULL;
	if(path != NULL && pArrayListMovies != NULL){
		auxFile = fopen(path, "w");
		if(auxFile != NULL){
			fprintf(auxFile, "id_peli,titulo,genero,duracion\n");
			for(int i = 0; i < ll_len(pArrayListMovies); i++){
				auxMovie = (sMovie*) ll_get(pArrayListMovies, i);
				if(auxMovie != NULL){
					fprintf(auxFile, "%d,%s,%s,%d\n",
							auxMovie->id,
							auxMovie->titulo,
							auxMovie->genero,
							auxMovie->duracion);
					rtn = 1;
				}
				else{
					movie_delete(auxMovie);
				}
			}
		}
		fclose(auxFile);
	}
    return rtn;
}
