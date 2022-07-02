/*
 * parser.c
 *
 *  Created on: 1 jul. 2022
 *      Author: jjuarez
 */
#include "parser.h"

int parser_movieFromText(FILE* pFile , LinkedList* pArrayListMovies)
{
	int rtn = 0;
	char buffer[4][50];
	char fileHeader[100];
	sMovie* auxMovie;
	if(pFile != NULL && pArrayListMovies != NULL){
		fscanf(pFile, "%[^\n]\n", fileHeader);
		while(!feof(pFile)){
			if(fscanf(pFile, "%[^,],%[^,],%[^,],%[^\n]\n",
					buffer[0],
					buffer[1],
					buffer[2],
					buffer[3]) == 4){
				auxMovie = movie_newWithParam(buffer[0], buffer[1], buffer[2], buffer[3]);
			}
			if(auxMovie != NULL){
				if(!ll_add(pArrayListMovies, (sMovie*) auxMovie) && ll_len(pArrayListMovies) < 1500){
					rtn = 1;
				}
			}
		}
	}
	fclose(pFile);
    return rtn;
}
