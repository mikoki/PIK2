#include <stdio.h>
#include <stdlib.h>
#include <stdio.h>

typedef struct Contact{
	int phone_number[10];
	char name[40];
}contact;

int main(){
	int contact_num, counter_cycle;
	printf("Enter the number of contacts");
	scanf("%d", &contact_num);
	contact contacts = (*contact)malloc((contact_num+1)*sizeof(contact));
	for(counter_cycle=0; counter_cycle<contact_num, counter_cycle++){
		contact[counter_cycle]
	}
	return 0;
}