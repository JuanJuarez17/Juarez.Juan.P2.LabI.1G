/*
 * movie.c
 *
 *  Created on: 1 jul. 2022
 *      Author: jjuarez
 */

#include "movie.h"

/** CONSTRUCTORS **/

sMovie* movie_new(){
	sMovie* auxMovie = NULL;
	auxMovie = (sMovie*) malloc(sizeof(sMovie));
	if(auxMovie != NULL){
		auxMovie->id = 0;
		strcpy(auxMovie->titulo, "");
		strcpy(auxMovie->genero, "");
		auxMovie->duracion = 0;
	}
	return auxMovie;
}

sMovie* movie_newWithParam(char* id, char* titulo, char* genero, char* duracion){
	sMovie* rtnMovie = movie_new();
	sMovie* auxMovie = movie_new();
	if(auxMovie != NULL
	   && rtnMovie != NULL
	   && id != NULL
	   && titulo != NULL
	   && genero != NULL
	   && duracion != NULL){
		if(movie_setId(auxMovie, atoi(id))
		&& movie_setTitle(auxMovie, titulo)
		&& movie_setGender(auxMovie, genero)
		&& movie_setDuration(auxMovie, atoi(duracion))){
			rtnMovie = auxMovie;
		}
		else{
			movie_delete(auxMovie);
		}
	}
	return rtnMovie;
}


/** DESTRUCTOR **/

void movie_delete(sMovie* this){
	free(this);
}

/** FILTERS **/

int movie_filterDrama(void* pMovie){
	int rtn = 0;
	if(pMovie != NULL){
		sMovie* auxMovie = movie_new();
		if(auxMovie != NULL){
			auxMovie = (sMovie*) pMovie;
			if(!strcmp(auxMovie->genero, "Drama")){ // strcmp devuelve 0 cuando encuentra ambos datos son iguales
				rtn = 1;
			}
		}
	}
	return rtn;
}

int movie_compareByGender(void* this1, void* this2){
	int rtn = 0;
	sMovie* auxMovie1 = (sMovie*) this1;
	sMovie* auxMovie2 = (sMovie*) this2;

	if(auxMovie1 != NULL && auxMovie2 != NULL){
		rtn = strcmp(auxMovie1->genero, auxMovie2->genero);
	}
	return rtn;
}

/*int movie_compareByGender(void* this1, void* this2){
	int rtn = 0;
	sMovie* auxMovie1 = (sMovie*) this1;
	sMovie* auxMovie2 = (sMovie*) this2;

	if(auxMovie1 != NULL && auxMovie2 != NULL){
		if(!strcmp(auxMovie1->genero, auxMovie2->genero) && auxMovie1->duracion < auxMovie2->duracion){
			rtn = 1;
		}
	}
	return rtn;
}*/

/** PRINT **/

void movie_print(sMovie* pMovie){
    printf(" %2d   %-30s %-12s    %-3d\n",
    		pMovie->id,
			pMovie->titulo,
			pMovie->genero,
			pMovie->duracion);
}


/** SETTERS **/

int movie_setId(sMovie* this, int id){
	int rtn = 0;
	if(this != NULL && id >= 1 && id <= 50){
		this->id = id;
		rtn = 1;
	}
	return rtn;
}

int movie_setTitle(sMovie* this, char* title){
	int rtn = 0;
	if(this != NULL && title != NULL){
		strcpy(this->titulo, title);
		rtn = 1;
	}
	return rtn;
}

int movie_setGender(sMovie* this, char* gender){
	int rtn = 0;
	if(this != NULL && gender != NULL){
		strcpy(this->genero, gender);
		rtn = 1;
	}
	return rtn;
}

int movie_setDuration(sMovie* this, int duration){
	int rtn = 0;
	if(this != NULL && duration >= 0 && duration <= 240){
		this->duracion = duration;
		rtn = 1;
	}
	return rtn;
}

void movie_setDurationTime(void*pMovie){
	if(pMovie != NULL){
		int min = 120;
		int max = 240;
		for(int i = min; i < max; i++){
			((sMovie*)pMovie)->duracion = (rand() % (max - min + 1) + min);
		}
	}
}




