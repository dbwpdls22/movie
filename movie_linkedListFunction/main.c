#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "movie.h"
#include "linkedList.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */


int main(int argc, char *argv[]) {
	
	FILE *fp; //FILE pointer for reading movie data 
	char name[200]; //movie name
	char country[10]; //movie country
	int runTime; //movie runtime
	float score; //movie score
	
	int exit_flag = 0; //flag variable for while loop
	int option; //user input option
	void *list, *mvInfo; //pointers for linked list and a specific structure instance for a movie data
	void *ndPtr; //void pointer for linked list node
	int count;//조건에 부합하는 LIST의 개수 
	
	fp = fopen("movie.dat", "r");// FILE open
	
	printf("Reading the data files...\n");
	
    if(fp == NULL)//파일이 비어 있으면 ERROR!출력 
	{
		printf("ERROR!\n\n");
		return -1;
	}
	
	list = list_genList();// list generation (use function list_genList())
	
	while(fscanf(fp,"%s %s %i %f",name,country,&runTime,&score) != EOF)//파일의 내용 한 줄씩 읽어와서 name,country,runTime,score에 저장 
	{	
	    mvInfo = mv_genMvInfo(name, score, runTime, country);//영화 정보를 구조체 형태로 저장 
		list_addTail(mvInfo, list);//list의 끝부분에 구조체 저장 	
	}

	fclose(fp);// FILE close/
	
	printf("Read done!\n");
	printf("%d items are read\n",list_len(list));//영화 정보가 저장된 list의 개수 출력 
		
	//2. program start
	while(exit_flag == 0) 
	{   //print menu message and get input option/
		printf("--------------------Menu--------------------\n");
		printf("1. print all the movies \n");
		printf("2. search for specific country movies \n");
		printf("3. search for specific runtime movies \n");
		printf("4. search for specific score movies \n");
		printf("5. exit \n");
		printf("--------------------Menu--------------------\n\n");
		
		printf("--select an option :");
		scanf("%d", &option);//사용자가 숫자를 선택하면 그 숫자를 option에 저장 
		
		switch(option)
		{
			case 1: //print all the movies
				printf("printing all the movies in the list.....\n\n\n");
				
				ndPtr = list;
				while (list_isEndNode(ndPtr) != 1) // repeat until the ndPtr points to the end node 
				{
				    ndPtr = list_getNextNd(ndPtr);//get the next node of the input node
				    mvInfo = list_getNdObj(ndPtr);//get object of ndPtr to mvInfo void pointer
					mv_print(mvInfo);	//print the contents of the mvInfo
					printf("--------------------------------------------\n");
				}
				
				printf("\n\n\n");
				break;
				
			case 2: //print movies of specific country
		       	
			    printf("select a country :");
		    	scanf("%s", &country);//get country name to search for
		    	printf("--------------------------------------------\n");
				count = 0; 
				
				ndPtr = list;
				while (list_isEndNode(ndPtr) != 1)// repeat until the ndPtr points to the end node
				{
					ndPtr = list_getNextNd(ndPtr);//get the next node of the input node
					mvInfo = list_getNdObj(ndPtr);//get object of ndPtr to mvInfo void pointer
					if(stricmp(mv_getCountry(mvInfo),country)==0)//구조체의 멤버인  제작국가를  추출하고 추출된 정보와 사용자가 입력한 국가가 일치하면 실행  
					{
						mv_print(mvInfo);//해당 구조체를 출력한다. 
						printf("--------------------------------------------\n");
						count = count + 1;//조건에 부합하는 list의 개수 + 1 
				    }
			    }
				printf("totally %d movies are listed!!\n\n\n\n",count);//조건에 부합한 list의 개수 출력 
				break;
				
			case 3://특정 러닝타임보다 긴 영화 출력 
			
				printf("select minimal runtime :");
				scanf("%i", &runTime);// get minimal runtime value to search for
				count = 0;
				
				ndPtr = list;
				while (list_isEndNode(ndPtr) != 1)//repeat until the ndPtr points to the end node 
				{
					ndPtr = list_getNextNd(ndPtr);//get the next node of the input node
					mvInfo = list_getNdObj(ndPtr);//get object of ndPtr to mvInfo void pointer
					if((mv_getRunTime(mvInfo))>=runTime)//구조체의 멤버인 러닝타임을 추출하고 추출된 정보가 사용자가 입력한 최소 러닝타임보다 크거나 같으면 실행 
					{
						mv_print(mvInfo);//해당 구조체를 출력 
						printf("--------------------------------------------\n");
						count = count + 1;//조건에 부합하는 list의 개수 +1 
					}
				}
				
				printf("totally %d movies are listed!!\n\n\n\n",count);//조건에 부합한 list의 개수 출력 
				
				break;
				
			case 4://특정 평점보다 높은 영화 출력 
				
				printf("select minimal score :");
				scanf("%f", &score);// get minimal score value to search for
				count = 0;
				
				ndPtr = list;
				while (list_isEndNode(ndPtr) != 1 )//repeat until the ndPtr points to the end node 
				{
				    ndPtr = list_getNextNd(ndPtr);//get the next node of the input node
					mvInfo = list_getNdObj(ndPtr);//get object of ndPtr to mvInfo void pointer
					if((mv_getScore(mvInfo))>=score)//구조체의 멤버인 평점을 추출하고 추출된 정보가 사용자가 설정한 최소 평점보다 크거나 같으면 실행 
					{
						mv_print(mvInfo);//해당 구조체 출력 
						printf("--------------------------------------------\n");
						count = count + 1;//조건에 부합하는 list의 개수 +1 
					}
				}
				printf("totally %d movies are listed!!\n\n\n\n",count);//조건에 부합하는 list의 개수 출력 
				
				break;
				
			case 5:
				printf("Bye!\n\n");
				exit_flag = 1;//메뉴판 출력 x 
				break;
				
			default:
				printf("wrong command! input again\n");
				break;
		}
	}
	
	return 0;//프로그램 종료 
}



