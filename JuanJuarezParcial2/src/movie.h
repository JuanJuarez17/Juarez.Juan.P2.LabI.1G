/*
 * movie.h
 *
 *  Created on: 1 jul. 2022
 *      Author: jjuarez
 */

#ifndef MOVIE_H_
#define MOVIE_H_
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "time.h"

typedef struct{
	int id;
	char titulo[30];
	char genero[20];
	int duracion;
}sMovie;


#endif /* MOVIE_H_ */

/** CONSTRUCTORS **/

sMovie* movie_new();
sMovie* movie_newWithParam(char* id, char* titulo, char* genero, char* duracion);

/** DESTRUCTOR **/

void movie_delete(sMovie* this);

/** FILTERS **/

int movie_filterDrama(void* pMovie);
int movie_compareByGender(void* this1, void* this2);

/** PRINT **/

void movie_print(sMovie* pMovie);


/** SETTERS **/

int movie_setId(sMovie* this, int id);

int movie_setTitle(sMovie* this, char* title);

int movie_setGender(sMovie* this, char* gender);

int movie_setDuration(sMovie* this, int duration);

void movie_setDurationTime(void*pMovie);
