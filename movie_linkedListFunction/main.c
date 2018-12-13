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
	int count;//���ǿ� �����ϴ� LIST�� ���� 
	
	fp = fopen("movie.dat", "r");// FILE open
	
	printf("Reading the data files...\n");
	
    if(fp == NULL)//������ ��� ������ ERROR!��� 
	{
		printf("ERROR!\n\n");
		return -1;
	}
	
	list = list_genList();// list generation (use function list_genList())
	
	while(fscanf(fp,"%s %s %i %f",name,country,&runTime,&score) != EOF)//������ ���� �� �پ� �о�ͼ� name,country,runTime,score�� ���� 
	{	
	    mvInfo = mv_genMvInfo(name, score, runTime, country);//��ȭ ������ ����ü ���·� ���� 
		list_addTail(mvInfo, list);//list�� ���κп� ����ü ���� 	
	}

	fclose(fp);// FILE close/
	
	printf("Read done!\n");
	printf("%d items are read\n",list_len(list));//��ȭ ������ ����� list�� ���� ��� 
		
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
		scanf("%d", &option);//����ڰ� ���ڸ� �����ϸ� �� ���ڸ� option�� ���� 
		
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
					if(stricmp(mv_getCountry(mvInfo),country)==0)//����ü�� �����  ���۱�����  �����ϰ� ����� ������ ����ڰ� �Է��� ������ ��ġ�ϸ� ����  
					{
						mv_print(mvInfo);//�ش� ����ü�� ����Ѵ�. 
						printf("--------------------------------------------\n");
						count = count + 1;//���ǿ� �����ϴ� list�� ���� + 1 
				    }
			    }
				printf("totally %d movies are listed!!\n\n\n\n",count);//���ǿ� ������ list�� ���� ��� 
				break;
				
			case 3://Ư�� ����Ÿ�Ӻ��� �� ��ȭ ��� 
			
				printf("select minimal runtime :");
				scanf("%i", &runTime);// get minimal runtime value to search for
				count = 0;
				
				ndPtr = list;
				while (list_isEndNode(ndPtr) != 1)//repeat until the ndPtr points to the end node 
				{
					ndPtr = list_getNextNd(ndPtr);//get the next node of the input node
					mvInfo = list_getNdObj(ndPtr);//get object of ndPtr to mvInfo void pointer
					if((mv_getRunTime(mvInfo))>=runTime)//����ü�� ����� ����Ÿ���� �����ϰ� ����� ������ ����ڰ� �Է��� �ּ� ����Ÿ�Ӻ��� ũ�ų� ������ ���� 
					{
						mv_print(mvInfo);//�ش� ����ü�� ��� 
						printf("--------------------------------------------\n");
						count = count + 1;//���ǿ� �����ϴ� list�� ���� +1 
					}
				}
				
				printf("totally %d movies are listed!!\n\n\n\n",count);//���ǿ� ������ list�� ���� ��� 
				
				break;
				
			case 4://Ư�� �������� ���� ��ȭ ��� 
				
				printf("select minimal score :");
				scanf("%f", &score);// get minimal score value to search for
				count = 0;
				
				ndPtr = list;
				while (list_isEndNode(ndPtr) != 1 )//repeat until the ndPtr points to the end node 
				{
				    ndPtr = list_getNextNd(ndPtr);//get the next node of the input node
					mvInfo = list_getNdObj(ndPtr);//get object of ndPtr to mvInfo void pointer
					if((mv_getScore(mvInfo))>=score)//����ü�� ����� ������ �����ϰ� ����� ������ ����ڰ� ������ �ּ� �������� ũ�ų� ������ ���� 
					{
						mv_print(mvInfo);//�ش� ����ü ��� 
						printf("--------------------------------------------\n");
						count = count + 1;//���ǿ� �����ϴ� list�� ���� +1 
					}
				}
				printf("totally %d movies are listed!!\n\n\n\n",count);//���ǿ� �����ϴ� list�� ���� ��� 
				
				break;
				
			case 5:
				printf("Bye!\n\n");
				exit_flag = 1;//�޴��� ��� x 
				break;
				
			default:
				printf("wrong command! input again\n");
				break;
		}
	}
	
	return 0;//���α׷� ���� 
}



