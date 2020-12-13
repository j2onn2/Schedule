#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "schedule.h"


void menu_printing (void) {
	
	int i	;
	char menu[5][50] = {								//use array for print menu
	
		"Print all the schedules",
		"Search for schedules in the month",
		"Search for schedules in the place",
		"Search for specific type schedule",
		"Exit",
		}	;
		
	for (i=0; i<5 ; i++)
		printf("%d. %s\n", i+1, menu[i])	;
		

}

//print dash line
void dash_printing () {

	printf("----------------------------------\n")	;
	
}
