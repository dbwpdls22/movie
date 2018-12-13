#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "movie.h"
 
typedef struct movInfo
{
	char name[200];
	float score;
	int runTime;
	char madeIn[10];
} movInfo_t;


void* mv_genMvInfo(char* name, float score, int runTime, char* country)//영화 정보를 구조체 형태로 받는 함수 
{
	movInfo_t* mvPtr;

    mvPtr=(movInfo_t*)malloc(sizeof(movInfo_t));//영화 정보들을 구조체로 담을 메모리 영역 설정(동적할당) 
    
    strcpy(mvPtr->name,name);//파일에서 받은 영화 제목을 구조체의 name에 저장 
    
    strcpy(mvPtr->madeIn,country);//파일에서 받은 제작 국가를 구조체의 madeIn에 저장 
  
    mvPtr->score = score;//파일에서 받은 평점을 구조체의 score에 저장 
  
    mvPtr->runTime = runTime;///파일에서 받은 러닝타임을 구조체의 runTime에 저장 
	
	return (void*)mvPtr;//mvPtr로 반환 
}

void mv_print(void* obj)//구조체를 출력하는 함수 
{
	movInfo_t* mvPtr = (movInfo_t*)obj;//mvPtr은 obj를, obj는 영화 정보 구조체를 가리킴 
	
	if (mvPtr == NULL)//mvPtr이 가리키는 구조체가 없다면 
	{
		printf("[ERROR] failed to print the movie Info! (object is NULL)\n");
	}
	
	printf("Name : %s (%s)\n", mvPtr->name, mvPtr->madeIn);//구조체의 제목과 제작 국가를 출력 
	printf("running time : %i, score : %f\n", mvPtr->runTime, mvPtr->score);//구조체의 러닝타임과 평점을 출력 
	
	return;
}


//return the score value from the input instance of movInfo_t structure
float mv_getScore(void* obj)//구조체의 멤버인 평점을 추출하는 함수 
{        
	movInfo_t* mvPtr = (movInfo_t*)obj;//mvPtr은 obj를, obj는 영화 정보 구조체를 가리킴 
	
	return mvPtr->score;//구조체의 평점으로 반환	
}

//return the runtime value from the input instance of movInfo_t structure
int mv_getRunTime(void* obj)//구조체의 멤버인  러닝타임을 추출하는 함수 
{
	movInfo_t* mvPtr =(movInfo_t*)obj;//mvPtr은 obj를, obj는 영화 정보 구조체를 가리킴 	
	
	return mvPtr->runTime;//구조체의 러닝타임으로 반환	
}

//return the name string pointer from the input instance of movInfo_t structure
char* mv_getName(void* obj)//구조체의 멤버인  영화 제목을 추출하는 함수 
{
	movInfo_t* mvPtr = (movInfo_t*)obj;//mvPtr은 obj를, obj는 영화 정보 구조체를 가리킴
	
	return mvPtr->name;//구조체의 영화 제목으로 반환 
}

//return the country string pointer from the input instance of movInfo_t structure
char* mv_getCountry(void* obj)//구조체의 멤버인  제작 국가를 추출하는 함수 
{ 
	movInfo_t* mvPtr = (movInfo_t*)obj;//mvPtr은 obj를, obj는 영화 정보 구조체를 가리킴
	
	return mvPtr->madeIn;//구조체의 제작 국가로 반환 
}


