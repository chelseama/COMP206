#include <stdio.h>
void main(int argc, char *argv[]){
	//argc is the number of arguments passed into the program from the              // command line,including the name of the program.If the argc<=1,               // it means the user only type the program name,which is the first way

	if(argc <=1){    
		printf("Welcome to ASCII:\n");
		char x;
	       //Get input from the user
		scanf("%c",&x);
               //Keep asking the user for characters,
               //when the input is not the number0(A=48)
	       // Then print out the translated reslts on the screen
		while(x!=48){
			printf("ascii: %d\n",x);
			getchar();
			scanf("%c",&x);
		}
	       //If the input is zero, the program goes to here
		printf("ascii: %d\n",x);
	}


  	// Second way to input:from within the program, i.e. the number of argc
 	//is greatr than 1
 	else{ 
		// Translate every non-filename argument to ascii,
		//Print out the inputs and reslts on the screen
		int c;
                for(c=1; c<argc; c++){
			printf("%c\n", *argv[c]);
                        printf("ascii: %d\n",*argv[c]);
                }
        }
	  printf("Done \n");
}

