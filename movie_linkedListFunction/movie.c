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

    (movInfo_t*)malloc(sizeof(movInfo_t->name))=(char*)malloc(sizeof(char));
    (movInfo_t*)malloc(sizeof(movInfo_t))->score=(float*)malloc(sizeof(float));
    (movInfo_t*)malloc(sizeof(movInfo_t))->runTime=(int*)malloc(sizeof(int));
    (movInfo_t*)malloc(sizeof(movInfo_t))->country=(char*)malloc(sizeof(char));
	//allocate memory and set the member variables 메모리를 할당하고 멤버 변수를 설정한다.
	
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
	scanf("%f",obj);
	
	return obj;
}

//return the runtime value from the input instance of movInfo_t structure
int mv_getRunTime(void* obj)
{
/*	scanf("%f",&obj);
    mvPtr.runtime = obj;
	
	return mvPtr.runtime;*/
	scanf("%i",obj);

	
	return obj;
}

//return the name string pointer from the input instance of movInfo_t structure
char* mv_getName(void* obj)
{
	gets_s(obj,99);
	
	return obj;

}

//return the country string pointer from the input instance of movInfo_t structure
char* mv_getCountry(void* obj)
{
	/*gets_s(obj,9);
	strcpy(mvPtr.madeIn, obj);
	
	return mvPtr.madeIn;*/
	gets_s(obj,9);
	
	return obj;
	 
}


