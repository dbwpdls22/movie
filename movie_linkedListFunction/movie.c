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
	mv_getRunTime(runTime);
    mv_getScore(score);
	
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
float mv_getScore(void* obj)
{      
    /*movInfo_t* mvPtr;
	mvPtr.score = (float*)malloc(sizeof(float));      
 
	return obj;*/
	return malloc(sizeof(float));
}

//return the runtime value from the input instance of movInfo_t structure
int mv_getRunTime(void* obj)
{
    /*movInfo_t* mvPtr;
	mvPtr.runTime = (int*)malloc(sizeof(int));      
	
	return mvPtr;*/
	return malloc(sizeof(int));
}

//return the name string pointer from the input instance of movInfo_t structure
char* mv_getName(void* obj)
{
	/*movInfo_t* mvPtr;
	mvPtr.name = (char*)malloc(sizeof(char));    
		
	return mvPtr;*/
	struct movInfo_t *mvPtr = malloc(sizeof(movInfo_t));    
	return mvPtr;
}

//return the country string pointer from the input instance of movInfo_t structure
char* mv_getCountry(void* obj)
{
	return malloc(sizeof(char));
}


