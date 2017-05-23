#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct List{
	int a;
	struct List *ptr_next_el;
} list;

list *first;
list *current;

list *new_element(){
	list *result = NULL;
	result = (list*)malloc(1*sizeof(list));
	printf("Enter new element's value: \n");
	scanf("%d", &result->a);
	result->ptr_next_el = NULL;
	return result;
}

list *new_list(int number){
	list *result_root = NULL;
	list *current = NULL;
	int i;
	for(i=0; i<number; i++){
		current = new_element();
		current->ptr_next_el = result_root;
		result_root = current;
	}
	return result_root;
}


int main(){
	int number;
	list *asd;
	printf("Enter the number of elements you wish to enter :\n");
	scanf("%d", &number);
	asd = new_list(number);
	current = first;
	while(asd != NULL){
		printf("%d\n", asd->a);
		asd = asd->ptr_next_el;
		//current = asd->ptr_next_el;
	}

	return 0;
}