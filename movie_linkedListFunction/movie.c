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
	
/*	mv_getName(name);
	float* mv_getScore(score);
    int* mv_getRunTime(runTime);
    mv_getCountry(country);*/
   /* mvPtr->name;
    mvPtr->score;
    mvPtr->runTime;
    mvPtr->madeIn;*/
    mvPtr->name[200] = (char*)malloc(sizeof(char));
    mvPtr->score = (float*)malloc(sizeof(float));
    mvPtr->runTime = (int*)malloc(sizeof(int));
    mvPtr->madeIn[10] = (char*)malloc(sizeof(char));
	
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
   /* movInfo_t* mvPtr;
    mvPtr = (movInfo_t*)malloc(sizeof(movInfo_t));
     
    mvPtr->score=obj;
     
    return mvPtr;*/
    /*float* mvPtr = malloc(sizeof(float));
	
	mvPtr = obj;
	
	return obj;*/
    //movInfo_t* mvPtr = (movInfo_t*)obj;
    
    //obj = (movInfo_t*)malloc(sizeof(movInfo_t));
 
	//return obj;
	/*movInfo_t *add = (movInfo_t*)malloc(sizeof(movInfo_t));
	
	add = obj;
	
	return obj;*/
	/*movInfo_t* mvPtr = (movInfo_t*)malloc(sizeof(movInfo_t));

	
	return obj;*/
	/*movInfo_t *mvPtr;
	mvPtr = (movInfo_t*)malloc(sizeof(movInfo_t));
	//(float)obj=mvPtr->score:
	
	return mvPtr;*/
	movInfo_t* mvPtr = (movInfo_t*)obj;
	
	return mvPtr->score;
	
}

//return the runtime value from the input instance of movInfo_t structure
int mv_getRunTime(void* obj)
{
	/*movInfo_t* mvPtr;
    mvPtr = (movInfo_t*)malloc(sizeof(movInfo_t));
     
    mvPtr->runTime=obj;
     
    return mvPtr;*/
/*    int *mvPtr = malloc(sizeof(int));
	
	mvPtr = obj;
	
	return obj;*/
   // movInfo_t* mvPtr = (movInfo_t*)obj;
    
    //mvPtr->runTime=obj;
    
   // obj = (movInfo_t*)malloc(sizeof(movInfo_t));
 
	//return obj;
	/*movInfo_t *add = (movInfo_t*)malloc(sizeof(movInfo_t));
	
	add = obj;
	
	return obj;*/
/*	movInfo_t* mvPtr;
    mvPtr = (int*)malloc(sizeof(int));
    mvPtr->score=obj;

	
	return obj;
	/*movInfo_t *mvPtr;
	*mvPtr = (float*)malloc(sizeof(movInfo_t));
	(float)obj = mvPtr->score;*/
	movInfo_t* mvPtr = (movInfo_t*)obj;
	
	return mvPtr->runTime;	
}

//return the name string pointer from the input instance of movInfo_t structure
char* mv_getName(void* obj)
{
/*	movInfo_t* mvPtr;
    mvPtr = (movInfo_t*)malloc(sizeof(movInfo_t));
     
    mvPtr->name[200]=obj;
     
    return mvPtr;*/
	/*char *mvPtr = malloc(sizeof(char));
	
	strcpy(obj,mvPtr);
	
	return obj;*/
	//movInfo_t* mvPtr = (movInfo_t*)obj;
    
    //obj = (movInfo_t*)malloc(sizeof(movInfo_t));
    
 
	//return obj;
	/* movInfo_t* mvPtr = (movInfo_t*)malloc(sizeof(movInfo_t));

	
	return obj;*/
/*	movInfo_t *mvPtr;
	mvPtr = (char*)malloc(sizeof(char));
	strcpy(mvPtr->name, obj);
	
	return obj;*/
	movInfo_t* mvPtr = (movInfo_t*)obj;
	
	return mvPtr->name;
}

//return the country string pointer from the input instance of movInfo_t structure
char* mv_getCountry(void* obj)
{ 
    /* movInfo_t* mvPtr;
    mvPtr = (movInfo_t*)malloc(sizeof(movInfo_t));
     
    mvPtr->madeIn[10]=obj;
     
    return mvPtr;*/
	/*char *mvPtr = malloc(sizeof(char));
	
	strcpy(obj,mvPtr);
	
	return obj;*/
	//char *mvPtr = malloc(sizeof(char));
   
    //movInfo_t* mvPtr = (movInfo_t*)obj;
    
    //obj = (movInfo_t*)malloc(sizeof(movInfo_t));
 
	//return obj;
	
    /*movInfo_t* mvPtr = (movInfo_t*)malloc(sizeof(movInfo_t));

	
	return obj;*/
/*	movInfo_t *mvPtr;	
	
	mvPtr->obj;
	
	strcpy(obj, mvPtr->madeIn);
	
	//fgets(obj,sizeof(obj),stdin);*/

	
	movInfo_t* mvPtr = (movInfo_t*)obj;
	
	return mvPtr->madeIn;
}


