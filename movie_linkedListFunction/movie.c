#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "movie.h"

typedef struct movInfo{
	char name[200];
	float score;
	int runTime;
	char madeIn[10];
} movInfo_t;


void* mv_genMvInfo(char* name, float score, int runTime, char* country)
{
	movInfo_t* mvPtr;
	
	mv_getName(name);
	mv_getCountry(country);
    int* mv_getRunTime(runTime);
    float* mv_getScore(score);
	
	return (void*)mvPtr;
}

void mv_print(void* obj)
{
	movInfo_t* mvPtr = (movInfo_t*)obj;
	
	if (mvPtr == NULL)
	{
		printf("[ERROR] failed to print the movie Info! (object is NULL)\n");
	}
	
	printf("Name : %s (%s)\n", mvPtr->name, mvPtr->madeIn);
	printf("running time : %i, score : %f\n", mvPtr->runTime, mvPtr->score);
	
	return;
}


//return the score value from the input instance of movInfo_t structure
float* mv_getScore(float* obj)
{      
    float* mvPtr = malloc(sizeof(float));
	
	mvPtr = obj;
	
	return obj;
}

//return the runtime value from the input instance of movInfo_t structure
int* mv_getRunTime(int* obj)
{
    int *mvPtr = malloc(sizeof(int));
	
	mvPtr = obj;
	
	return obj;
}

//return the name string pointer from the input instance of movInfo_t structure
char* mv_getName(void* obj)
{
	char *mvPtr = malloc(sizeof(char));
	
	strcpy(obj,mvPtr);
	
	return obj;
}

//return the country string pointer from the input instance of movInfo_t structure
char* mv_getCountry(void* obj)
{ 
	char *mvPtr = malloc(sizeof(char));
	
	strcpy(obj,mvPtr);
	
	return obj;
	
}


