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


/*void* mv_genMvInfo(char* name, float score, int runTime, char* country)
{
	movInfo_t* mvPtr;
	
	while(mvPtr != NULL){
		float mv_getScore(score);
		mv_getRunTime(runTime);
		mv_getName(name);
		mv_getCountry(country);
	}
	//allocate memory and set the member variables 메모리를 할당하고 멤버 변수를 설정한다.
	
	return (void*)mvPtr;
}*/

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
/*float mv_getScore(float* obj)
{
	movInfo_t* mvPtr;
	
	mvPtr =(movInfo_t*)malloc(sizeof(movInfo_t));
	if(mvPtr == NULL)
	{
		printf("ERROR\n");
		return 0;
	}
	
	mvPtr->score = obj;
	
	return mvPtr;
}*/

//return the runtime value from the input instance of movInfo_t structure
int mv_getRunTime(void* obj)
{
	movInfo_t* mvPtr;
	
	mvPtr =(movInfo_t*)malloc(sizeof(movInfo_t));
	if(mvPtr == NULL)
	{
		printf("ERROR\n");
		return NULL;
	}
	
	mvPtr->runTime = obj;
	
	return mvPtr;
	
}

//return the name string pointer from the input instance of movInfo_t structure
char* mv_getName(void* obj)
{
	movInfo_t* mvPtr;
	
	mvPtr =(movInfo_t*)malloc(sizeof(movInfo_t));
	if(mvPtr == NULL)
	{
		printf("ERROR\n");
		return NULL;
	}
	
	mvPtr->name[200] = obj;
	
	return mvPtr;
}

//return the country string pointer from the input instance of movInfo_t structure
char* mv_getCountry(void* obj)
{
	movInfo_t* mvPtr;
	
	mvPtr =(movInfo_t*)malloc(sizeof(movInfo_t));
	if(mvPtr == NULL)
	{
		printf("ERROR\n");
		return NULL;
	}
	
	mvPtr->madeIn[10] = obj;
	
	return mvPtr;
}


