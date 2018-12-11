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
	int count;
	
	//1. reading the movie.dat-----------------------------/
	fp = fopen("movie.dat", "r");//1.1 FILE open
	
	printf("Reading the data files...\n");
	
    if(fp == NULL){
		printf("ERROR!\n\n");
		return -1;
	}
	
	//1.2 list generation (use function list_genList() )
	list = list_genList();
	
	//1.3 read each movie data from the file and add it to the linked list
	while(fscanf(fp,"%s %s %i %f",name,country,&runTime,&score) != EOF/* read name, country, runtime and score*/ )
	{	
	    mvInfo = mv_genMvInfo(name, score, runTime, country);
		 //generate a movie info instance(mvInfo) with function mv_genMvInfo()
		list_addTail(mvInfo, list);
//	 	list_addNext(mvInfo, list);	
		 
		 		
	}

	fclose(fp);//1.4 FILE close/
	
	printf("Read done!\n");
	printf("%d items are read\n",list_len(list));
		
	//2. program start
	while(exit_flag == 0) 
	{   //2.1 print menu message and get input option/
		printf("--------------------Menu--------------------\n");
		printf("1. print all the movies \n");
		printf("2. search for specific country movies \n");
		printf("3. search for specific runtime movies \n");
		printf("4. search for specific score movies \n");
		printf("5. exit \n");
		printf("--------------------Menu--------------------\n\n");
		
		printf("--select an option :");
		scanf("%d", &option);
		
		switch(option)
		{
			case 1: //print all the movies
				printf("printing all the movies in the list.....\n\n\n");
				
				ndPtr = list;
				while (list_isEndNode(ndPtr) != 1/* repeat until the ndPtr points to the end node */)
				{
					//2.2 print a movie data : use functions of movie.c and linkedList.c
					//ndPtr = the next node of the ndPtr;
					//get object of ndPtr to mvInfo void pointer
					//print the contents of the mvInfo
				    ndPtr = list_getNextNd(ndPtr);
				    mvInfo = list_getNdObj(ndPtr);
				  /*mv_getScore(mvInfo);
				    mv_getRunTime(mvInfo);
                    mv_getName(mvInfo);
                    mv_getCountry(mvInfo);*/
					mv_print(mvInfo);	
					printf("--------------------------------------------\n");
					
				}
				
				printf("\n\n\n");
				break;
				
			case 2: //print movies of specific country
		       	//2.3.1 get country name to search for/
			    printf("select a country :");
		    	scanf("%s", &country);
		    	printf("--------------------------------------------\n");
				count = 0;
				
				ndPtr = list;
					while (list_isEndNode(ndPtr) != 1/* repeat until the ndPtr points to the end node */)
				{
					//2.3.2 print a movie data : use functions of movie.c and linkedList.c
					//ndPtr = the next node of the ndPtr;
					//get object of ndPtr to mvInfo void pointer
					//if the input country matches to the country of the movie,
					//then print the contents of the mvInfo
					ndPtr = list_getNextNd(ndPtr);
					mvInfo = list_getNdObj(ndPtr);
					//list_getIndexNd(country, list);
					if(stricmp(mv_getCountry(mvInfo),country)==0)
					{
						mv_print(mvInfo);
						printf("--------------------------------------------\n");
						count = count + 1;
				    }
					
					
				//	mvInfo = list_getNdObj(list);
				//	mv_getCountry(mvInfo);
				//	list_srchNd((mv_getCountry(mvInfo)==country)(mv_getCountry(mvInfo), country),country,list); 
				//	mv_print(mvInfo);
				//	ndPtr = list_getIndexNd(country, list);
				//	list_srchNd((mvInfo, country), country, list);
				//	mv_print(mvInfo);
			    }
				printf("totally %d movies are listed!!\n\n\n\n",count);
				break;
				
			case 3:
				//2.4.1 get minimal 0runtime value to search for
				printf("select minimal runtime :");
				scanf("%i", &runTime);
				count = 0;
				
				ndPtr = list;
				while (list_isEndNode(ndPtr) != 1/* repeat until the ndPtr points to the end node */)
				{
					//2.4.2 print a movie data : use functions of movie.c and linkedList.c
					//ndPtr = the next node of the ndPtr;
					//get object of ndPtr to mvInfo void pointer
					//if the input runtime is lower than the runtime of the movie,
					//then print the contents of the mvInfo
					ndPtr = list_getNextNd(ndPtr);
					mvInfo = list_getNdObj(ndPtr);
					if((mv_getRunTime(mvInfo))>=runTime)
					{
						mv_print(mvInfo);
						printf("--------------------------------------------\n");
						count = count + 1;
					}
					//mv_getRunTime(mvInfo);
				//	list_srchNd((mv_getRunTime(mvInfo)>=runTime)(mv_getRunTime(mvInfo), runTime), runTime, list);
					
	
				}
				
				printf("totally %d movies are listed!!\n\n\n\n",count);
				
				break;
				
			case 4:
				//2.5.1 get minimal score value to search for
				printf("select minimal score :");
				scanf("%f", &score);
				count = 0;
				
				ndPtr = list;
					while (list_isEndNode(ndPtr) != 1 /*repeat until the ndPtr points to the end node */)
				{
					//2.5.2 print a movie data : use functions of movie.c and linkedList.c
					//ndPtr = the next node of the ndPtr;
					//get object of ndPtr to mvInfo void pointer
					//if the input score is lower than the score of the movie,
					//then print the contents of the mvInfo
					ndPtr = list_getNextNd(ndPtr);
					mvInfo = list_getNdObj(ndPtr);
					if((mv_getScore(mvInfo))>=score)
					{
						mv_print(mvInfo);
						printf("--------------------------------------------\n");
						count = count + 1;
					}
				}
				printf("totally %d movies are listed!!\n\n\n\n",count);
				
				break;
				
			case 5:
				printf("Bye!\n\n");
				exit_flag = 1;
				break;
				
			default:
				printf("wrong command! input again\n");
				break;
		}
	}
	
	return 0;
}



