#include <stdio.h>
#include <stdlib.h>
#include <string.h>



typedef struct ice_cream{
	char name[20];
	double weigth;
	char type[2];
	double price;
} sl;

typedef struct List{
	sl element;
	struct List *next;
}list;

void push_front(list **ICS, sl el){
	list *new;
	new = (list*)malloc(1*sizeof(list));
	new->element = el;
	new->next = *ICS;
	*ICS = new;
}

void print_list(list *ICS){
	list *copy = ICS;

	while(copy != NULL){
		printf("%s\n", copy->element.name);
		printf("%lf\n", copy->element.weigth);
		printf("%s\n", copy->element.type);
		printf("%lf", copy->element.price);
		copy = copy->next;
	}
}


int main(){
	list *ics;
	sl sladoled;
	int ics_num, i;

	printf("Enter number of ice creams: \n");
	scanf("%d", &ics_num);
	
	for(i=0; i<ics_num; i++){
		printf("Enter name: \n");
		scanf("%s", sladoled.name);
		printf("Enter weigth: \n");
		scanf("%lf", &sladoled.weigth);
		printf("Enter type: \n");
		scanf("%s", sladoled.type);
		printf("Enter price: \n");
		scanf("%lf", &sladoled.price);
		push_front(&ics, sladoled);
	}
	print_list(ics);
	return 0;
}

/*
5:
new->element = 5;
new->next = NUll;
*first = new 
	first->element = new->element ( = 5)
	first->next = new->next = first->next(null)
3:
new->element = 3;
new->next = 5;
*first = new
	first->element = 3;
	first->next = new->next = 5
*/

/*int main(){
	sl *ic1;
	sl ic2;

	ic1 = (sl*)malloc(1*sizeof(sl));
	strcpy(ic1->name, "chocolate");
	strcpy(ic2.name, "strawberry");

	ic2.weigth = 1.78;
	strcpy(ic2.type, "C8");	

	printf("%s, %s, %s\n", ic1->name, ic2.name, ic2.type);
	return 0;
}*/

/*int main(){
	list *first = NULL;
	first = (list*)malloc(1*sizeof(list));
	strcpy(first->element.name, "chocolate");
	first->element.weigth = 1.78;
	strcpy(first->element.type, "C8");
	first->element.price = 1.66; 
	printf("%s, %lf, %s, %lf\n", first->element.name, first->element.weigth, first->element.type, first->element.price);
	first->next =(list*)malloc(1*sizeof(list));
	first->next->element.weigth = 99.9;
	printf("%lf\n", first->next->element.weigth);
	/*if(first == NULL){
		return 1;
	}


	return 0;
}*/