


void menu_printing (void) {
	
	int i	;
	char menu[5][50] = {
	
		"Print all the schedules",
		"Search for schedules in the month",
		"Search for schedules in the place",
		"Search for specific type schedule",
		"Exit",
		}	;
		
	for (i=0; i<5 ; i++)
		printf("%d. %s\n", i, menu[i])	;
		

}
