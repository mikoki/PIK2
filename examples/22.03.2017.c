#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Student{
	char* Name;
	int fnum;
	double avg;
} student;

int main(){
	char *name;
	char a;
	int i=0;
	student asd[5];

	printf("vuvedete ime:\n");
	name = (char*)malloc(2*sizeof(char));
	
	while ((a = getchar()) != '\n'){
		name = (char*)realloc(name, (strlen(name)+1) * sizeof(char));
		name[i]=a;
		i++;
	}
	asd[0].Name = name;
	asd[0].fnum = 121216145;
	asd[0].avg = 3.25;

	asd[1].Name = name;
	asd[1].fnum = 13455666;
	asd[1].avg = 5.00;


	printf("\nime: %s\nfakulteten nomer: %d\nsreden uspeh: %f\n", asd[0].Name, asd[0].fnum, asd[0].avg);
	printf("\nime: %s\nfakulteten nomer: %d\nsreden uspeh: %f\n", asd[1].Name, asd[1].fnum, asd[1].avg);
	free(name);
	return 0;
}