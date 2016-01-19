#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

int numExperiments = 0;

void displayAll(char *experiments[], int data[10][20] ){
	printf("Selection 1\n");
	int x, y;
	for (x = 0; x < numExperiments; x++){
		printf("%s\n", experiments[x]);
		for (y = 0; y < 10; y++){
			printf("%d ", data[y][x]);
		}
		printf("\n");
	}
}

double individualAverage(char  *experiments[], int data[10][20], char *choice){
	printf("Selection 2\n");
	int line = -1, i, x;
	double average;
	double total = 0.0;
	for (i = 0; i < numExperiments; i++){
		if(!strcmp(choice, experiments[i])){
			line = i;
			break;
		}
	}	
	if (line == -1){
		return INFINITY;
	}
	for (x = 0; x < 10; x++){
		total = total + data[x][line];
	}
	average = total/10;
	return average;
}


double allAverage(int data[10][20])
{
	printf("Selection 3\n");
	double average = 0.0, total = 0.0;
	int i, j;
	int count = 0;
	for (i = 0; i < numExperiments; i++)
	{
		for (j = 0; j < 10; j++)
		{
			total = total + data[j][i];	
		}
		count++;
	}
	count = count*10;
	average = total/(double)count;
	return average;
}

void main()
{
	int i=0;
	char* experiments[20];
	char name[200];
	int data[10][20];
	int y;
	size_t size = 100;
	char case2[200];
	double average3 = 0, average2 = 0;
	for(i=0; i<20;i++)
	{
		gets(name);
		if (!strcmp(name,"*** END ***") || !strcmp(name,"***END***"))
		{
			break;
		}
		experiments[i] = strdup(name);
		scanf("%d%d%d%d%d%d%d%d%d%d",&data[0][i],&data[1][i],&data[2][i],&data[3][i],&data[4][i],&data[5][i],&data[6][i],&data[7][i],&data[8][i],&data[9][i]);
		scanf("\n",NULL);
		numExperiments++;
	}
	freopen( "/dev/tty", "r", stdin);
	printf("DATA SET ANALYSIS\n");
	printf("1. Show all the data\n");
	printf("2. Calculate the average for an experiment\n");
	printf("3. Calculate the average across all experiments\n");
	printf("4. Quit\n");
	printf("Selection: ");
	char choice[99];
	fgets(choice,100,stdin);
	int h;
	h = atoi(choice);
		while (h!= 4)
		{
			switch(h)
			{
				case 1:
					displayAll(experiments, data);
					break;
				case 2:
					printf("Please select the name of the experiement you would like to use: ");
					scanf("%[^\n]s", case2);
					char c = getchar();  
					average2 = individualAverage(experiments, data, case2 );		
					if (average2 == INFINITY)
					{
						printf("Invalid experiment name\n\n");
						break;
					}
					printf("The average for your experiement is %f\n", average2);
					break;
				case 3:
					average3 = allAverage(data);
					printf("The overall average is %f\n", average3);
					break;
				default:
					printf("Invalid entry, please enter ");
					printf("one value from 1-4 from the menu.\n");
					break;
			}
			printf("DATA SET ANALYSIS\n");
			printf("1. Show all the data\n");
			printf("2. Calculate the average for an experiment\n");
	  		printf("3. Calculate the average across all experiments\n");
	       		printf("4. Quit\n");
			printf("Selection: ");
			fgets(choice,100,stdin);
			h = atoi(choice);
	
		}    
	                                     
	}

