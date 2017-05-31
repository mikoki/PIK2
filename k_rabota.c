#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Contact{
	char name[30];
	char number[10];
}contact;

typedef struct List{
	contact element;
	struct List *next;
}list;

void push_front(list **contacts, contact el){
	list *copy = (list*)malloc(1*sizeof(list));
	copy->element = el;
	copy->next = *contacts;
	*contacts = copy;
}

void print_list(list *l1){
	list *l = l1;
	//FILE *fp;
	//int a, b;
	//fp = fopen("abonati.bin", "wb");
	while(l != NULL){	
		printf("%s %s \n", l->element.name, l->element.number);
		/*
		a = strlen(l->element.name);
		b = strlen(l->element.number);
		fwrite(&a, sizeof(int), 1, fp);
		fwrite(l->element.name, sizeof(char), a, fp);
		fwrite(&b, sizeof(int), 1, fp);
		fwrite(l->element.number, sizeof(char), b, fp);*/
		l = l->next;
	}
	//fclose(fp);
}

char *search(list *l1, char* name){
	list *l = l1;

	while(l != NULL){
		if(strcmp(name, l->element.name) == 0){
			return l->element.number;
		}
		l = l->next;
	}
}

int menu(){
	int opt;
	
	printf("1. Enter new contacts\n");
	printf("2. Print all contacts\n");
	printf("3. Search number by name\n");
	printf("Select an option: \n");
	scanf("%d", &opt);
	return opt;
}

int main(){
	int num, counter, option, counter2, flag;
	contact c1;
	FILE *fp;
	list *cs = NULL;
	char s_number[10];
	char s_name[30];

	option = menu();
	if(option == 1){
		cs = (list *)malloc (1*sizeof(list));
		printf("Enter number of contacts: \n");
		scanf("%d", &num);
		
		for(counter = 0; counter < num; counter++){
			printf("Enter name: ");
			scanf("%s", c1.name);
			
			printf("Enter number: ");
			scanf("%s", c1.number);

			flag = 0;
			for(counter2 = 0; counter2 < strlen(c1.number); counter2++){
				if(!(c1.number[counter2] >= '0' && c1.number[counter2] <= '9')){
					flag = 1;
					printf("ERROR: number cannot contain other symbols than digits!!!\n");
					break;
				}
			}
			if(flag == 0){
				push_front(&cs, c1);
			}
			
		} 
		option = menu();
	}
	if(option == 2){
		print_list(cs);	
		option = menu();
	}
	if(option == 3){
		printf("Enter contact's name: \n");
		scanf("%s", s_name);
		strcpy(s_number, search(cs, s_name));
		printf("\n%s\n", s_number);
	}

	return 0;
}