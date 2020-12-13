#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "schedule.h"
#include "linkedList.h"
#include "elsefunction.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	
	int exit_flag = 0;
	FILE *fp;
	

	char name[200];
	char place[100], typeName[100];	
	size_t size;
	int month;
	int day;
	int type;
	void *list;
	void *ndPtr;
	void *schedInfo;
	int option;
	int cnt;
	
	//1. FILE pointer open & error handling

	fp = fopen("schedule.dat", "r")	;													//schedule file open with read mode  
	
	if ( fp == NULL)																	//if file has nothing print error
	{
		printf("Error to open file\n")	;
		return -1	;
	}
	
	//initializing the list
	printf("Reading the data files... \n");
	list = (void*)list_genList();
	

	
	//2. read from the file
	while ( !(feof(fp) ) )																//until the file finish
	{	
		if(fscanf(fp, "%s %s %d %d %d", name, place, &type, &month, &day)>0){	; 		//use fscanf to get from file , when file has value fscanf's return value will over 0 (so skip blank) 
		
		schedInfo = sched_genSchedInfo(name, place, type, month, day)	;				//use sched_genSchedInfo to make sched_Info, put variables from fscanf 
		
		list_addTail(schedInfo, list);
		}
	}
		
	fclose (fp)	;																		//use fclose to close file pointer
	
	printf("\n Read done! %i schedules are read\n", list_len(list));
		
	//program starts
	while(exit_flag == 0) 
	{
		//3. menu printing
		printf("\n\n\n")	;
		menu_printing ()	;															//use menu_printing function
		
		
		//4. get option from keyboard
		printf("\n Select an option : ")	;
		scanf("%d", &option) ; 
		
		
		switch(option)
		{
			case 1: 																	//print all the schedules
				printf("printing all the schedules in the scheduler.....\n\n\n");
				
				ndPtr = list;
				cnt =1	;																//use cnt to count
				while (list_isEndNode(ndPtr) == 0)
				{										
					dash_printing ()	;												//print dash  line
					
					ndPtr = list_getNextNd(ndPtr); 										//get the next node from the list
					printf("%d. ", cnt)	;												//print count
					
					schedInfo = list_getNdObj(ndPtr); 									//get the object (scheduling info)
					sched_print (schedInfo)	;											//print scheduling info element load from schedInfo
										
					cnt++	;															//when finish count up														
				}
				
				dash_printing ()	;
				
				break;
				
			case 2:
				printf("which month ? : ");
				scanf("%i", &month);
				
				
				ndPtr = list;
				cnt = 1	;																//use cnt to count up
				while (list_isEndNode(ndPtr) == 0)
				{					
					if (sched_getMonth(schedInfo) == month){							//use sched_getMonth function to match to the month	
						printf("----------------------------------\n%d. ", cnt)	;		//print count
						sched_print(schedInfo)	;
						cnt++	;
					}	
									
					ndPtr = list_getNextNd(ndPtr);										//get the next node from the list
					schedInfo = list_getNdObj(ndPtr); 									//get the object (scheduling info)													
				}
				dash_printing ()	;
				break;
				
			case 3:
				printf("which place ? : ");
				scanf("%s", place);
				
				
				
				ndPtr = list;
				cnt = 1	;																//use cnt to count up
				while (list_isEndNode(ndPtr) == 0)
				{					
					ndPtr = list_getNextNd(ndPtr); 										//get the next node from the list
					schedInfo = list_getNdObj(ndPtr); 									//get the object (scheduling info)
										
					if(strcmp(sched_getPlace(schedInfo), place) == 0) {					//place is letter so use strcmp to match with place , when match it will zero			
						dash_printing ()	;											//print dash line
						printf("%d.", cnt)	;											//print count
						sched_print(schedInfo)	;										//print the right schedule
						cnt++	;														//count up
					}
					
				}
				dash_printing()	;
				break;
				
			case 4:
				printf("which type ?\n");
				sched_printTypes();
				printf("your choice : ");
				scanf("%s", typeName);
				
				type = sched_convertType(typeName)	;									//variables for converting the type received in letters to numbers
			
				if (type>=0 && type <=6  )												// Run when the type is 0~6
				{
					ndPtr = list;
					cnt = 1	;															//use cnt to count up
					
					while (list_isEndNode(ndPtr) == 0)
					{
						ndPtr = list_getNextNd(ndPtr);									//get the next node from the list
						schedInfo = list_getNdObj(ndPtr); 								//get the object (scheduling info)
						
						if(sched_getType(schedInfo) == type)	{
							printf("----------------------------------\n%d.", cnt)	;	//print count
							sched_print(schedInfo)	;									//print right schedule
							cnt++	;													//count up
						}
						//fill code this part - end
					}
					dash_printing ()	;
				} 
				else
				{
					printf("wrong type name!\n");
				} 
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
