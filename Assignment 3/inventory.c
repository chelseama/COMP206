#include <stdio.h>
#include <string.h>
#include <stdlib.h>

FILE *input;

int parse_commandline(int argc, char* argv[]);
void list();
void reorder();
void deduct(char* element);
void add(char* element, int quantity, int minimum, double price);
void usage();
int mustReorder(char* record);
void printRecord(char* record);
int onRecord(char* element);



int main(int argc, char *argv[]){
	input = fopen("inventory.csv", "r");
	
	return parse_commandline(argc, argv);
	fclose (input);

}






void list(){ 
	printf("\tITEM\tQTY\tREORDER PRICE\n");
	char record[100];
	while(fgets(record, 100, input) != NULL){
		printRecord(record);
	}
	printf("\n");
}

void reorder(){ 
	printf("\tMUST PURCHASE THE FOLLOWING ITEMS\n");
	printf("\tITEM\tQTY\tREORDER PRICE\n");

	char record[100];
	char recordCopy[100];
	while(fgets(record, 100, input) != NULL){
		strcpy(recordCopy, record);
		if(mustReorder(record)){
			printRecord(recordCopy);
		}
	}
	printf("\n");
}

void deduct(char *element){
	if(onRecord(element)){
		input = fopen("inventory.csv", "r+");
		char record[100];
		char *field;
		char *newRecord;
		int quantity;
		int minimum;
		double price;

		
		char command[100];
		strcpy(command, "sed -i '/");
		strcat(command, element);
		strcat(command, "/d' inventory.csv");

		while(fgets(record, 100, input) != NULL){
			if (strstr(record, element) != NULL)
			{
				field = strtok(record, ",");
				quantity = atoi(strtok('\0', ","));
				minimum = atoi(strtok('\0', ","));
				price = strtof(strtok('\0', ","), NULL);
				
				system(command);
				
				add(element, quantity-1, minimum, price);
			}
		}
	}
	else{
		printf("Element %s does not exist in the database.\n", element);
	}
}

void add(char* element, int quantity, int minimum, double price){ 
	if(onRecord(element)){
		printf("Element %s has already been added to you inventory.\n", element);
	}
	else{
		FILE *pappend;
		pappend = fopen("inventory.csv", "a");
		fprintf(pappend, "%s,%d,%d,%.2f\n", element, quantity, minimum, price);
		fclose(pappend);
	}
}




int parse_commandline(int argc, char* argv[]){ 
	if (argc == 1){
		usage();
		return (1);
	}
	
	if(strcmp(argv[1],"list") == 0){
		list();
	}
	else if(strcmp(argv[1], "reorder") == 0){
		reorder();
	}
	else if(strcmp(argv[1], "deduct") == 0 && argc == 3){
		char *element = argv[2];
		deduct(element);
	}
	else if(strcmp(argv[1], "add") == 0 && argc == 6){
		char *element = argv[2];
		int quantity = atoi(argv[3]);
		int minimum = atoi(argv[4]);
		double price = strtod(argv[5], NULL);
		
		if(quantity == 0 || minimum == 0 || price == 0.0){
			usage();
			return 1;
		}
		
		add(element, quantity, minimum, price);
		
	}
	else{
		usage();
	}
}


int mustReorder(char* record){
	
	char* field = strtok(record, ",");
	int quantity = atoi(strtok('\0', ","));
	int minimum = atoi(strtok('\0', ","));
	int junk = strtof(strtok('\0', ","), NULL);

	return (quantity <= minimum);
}

void printRecord(char* record){
	char* field = strtok(record, ",");
	while(field != NULL){
		printf("\t%.7s", field); 
		field = strtok('\0', ",");
	}
}

int onRecord(char* element){
	char record[100];
	int found = 0;

	while(fgets(record, 100, input) != NULL){
		if(strstr(record,element)){
			char *field = strtok(record, ",");
			if(strcmp(field, element) == 0){
				
				found = 1;
			}
		}
	}
	return found;
}


void usage(){
	printf("Usage: ./inv COMMAND [ARGUMENTS]\n");
	printf("Commands: list, reorder, deduct, add\n");
	printf("Example:\n");
	printf("\t./inv add product_name quantity_in_stock reorder_limit_number unit_cost \n");
	printf("\t./inv deduct product_name\n");
	printf("\t./inv reorder\n");
	printf("\t./inv list\n");
	printf("ATTENTION: 0 is NOT a valid argument\n");
}