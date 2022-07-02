/*
 * controller.h
 *
 *  Created on: 1 jul. 2022
 *      Author: jjuarez
 */

#ifndef CONTROLLER_H_
#define CONTROLLER_H_
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "LinkedList.h"
#include "parser.h"


#endif /* CONTROLLER_H_ */

int controller_loadMoviesFromText(char* path , LinkedList* pArrayListMovies);
int controller_listMovies(LinkedList* pArrayListMovies);
void controller_exitProgram(char *pExit);
int input_validateCharOpt(char cEvaluate, char option1, char option2);
int controller_saveAsText(char* path , LinkedList* pArrayListMovies);
