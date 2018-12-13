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


void* mv_genMvInfo(char* name, float score, int runTime, char* country)//��ȭ ������ ����ü ���·� �޴� �Լ� 
{
	movInfo_t* mvPtr;

    mvPtr=(movInfo_t*)malloc(sizeof(movInfo_t));//��ȭ �������� ����ü�� ���� �޸� ���� ����(�����Ҵ�) 
    
    strcpy(mvPtr->name,name);//���Ͽ��� ���� ��ȭ ������ ����ü�� name�� ���� 
    
    strcpy(mvPtr->madeIn,country);//���Ͽ��� ���� ���� ������ ����ü�� madeIn�� ���� 
  
    mvPtr->score = score;//���Ͽ��� ���� ������ ����ü�� score�� ���� 
  
    mvPtr->runTime = runTime;///���Ͽ��� ���� ����Ÿ���� ����ü�� runTime�� ���� 
	
	return (void*)mvPtr;//mvPtr�� ��ȯ 
}

void mv_print(void* obj)//����ü�� ����ϴ� �Լ� 
{
	movInfo_t* mvPtr = (movInfo_t*)obj;//mvPtr�� obj��, obj�� ��ȭ ���� ����ü�� ����Ŵ 
	
	if (mvPtr == NULL)//mvPtr�� ����Ű�� ����ü�� ���ٸ� 
	{
		printf("[ERROR] failed to print the movie Info! (object is NULL)\n");
	}
	
	printf("Name : %s (%s)\n", mvPtr->name, mvPtr->madeIn);//����ü�� ����� ���� ������ ��� 
	printf("running time : %i, score : %f\n", mvPtr->runTime, mvPtr->score);//����ü�� ����Ÿ�Ӱ� ������ ��� 
	
	return;
}


//return the score value from the input instance of movInfo_t structure
float mv_getScore(void* obj)//����ü�� ����� ������ �����ϴ� �Լ� 
{        
	movInfo_t* mvPtr = (movInfo_t*)obj;//mvPtr�� obj��, obj�� ��ȭ ���� ����ü�� ����Ŵ 
	
	return mvPtr->score;//����ü�� �������� ��ȯ	
}

//return the runtime value from the input instance of movInfo_t structure
int mv_getRunTime(void* obj)//����ü�� �����  ����Ÿ���� �����ϴ� �Լ� 
{
	movInfo_t* mvPtr =(movInfo_t*)obj;//mvPtr�� obj��, obj�� ��ȭ ���� ����ü�� ����Ŵ 	
	
	return mvPtr->runTime;//����ü�� ����Ÿ������ ��ȯ	
}

//return the name string pointer from the input instance of movInfo_t structure
char* mv_getName(void* obj)//����ü�� �����  ��ȭ ������ �����ϴ� �Լ� 
{
	movInfo_t* mvPtr = (movInfo_t*)obj;//mvPtr�� obj��, obj�� ��ȭ ���� ����ü�� ����Ŵ
	
	return mvPtr->name;//����ü�� ��ȭ �������� ��ȯ 
}

//return the country string pointer from the input instance of movInfo_t structure
char* mv_getCountry(void* obj)//����ü�� �����  ���� ������ �����ϴ� �Լ� 
{ 
	movInfo_t* mvPtr = (movInfo_t*)obj;//mvPtr�� obj��, obj�� ��ȭ ���� ����ü�� ����Ŵ
	
	return mvPtr->madeIn;//����ü�� ���� ������ ��ȯ 
}


