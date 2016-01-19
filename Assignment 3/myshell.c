#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 

int main(void) 
{ 
	char x[100]; 
	do 
	{ 
		printf(">> "); 
		gets(x); 	
			if (strcmp(x,"done")==0) 
			break; 
		system(x); 
} 

	while(1) ;
 
	printf("Thank you for using mysh!"); 
	return 0; 
}
