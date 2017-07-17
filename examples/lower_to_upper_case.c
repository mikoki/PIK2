#include <stdio.h>
#include <stdlib.h>	
#include <ctype.h>
#include <string.h>

int main(){
	int a;
	int i;
	char *arr;
	arr=(char*)malloc(100*sizeof(char));
	printf("Enter text: \n");
	scanf("%s", arr);
	a = strlen(arr);
	arr = (char*)realloc(arr, a*sizeof(char));	
	printf("\nNumber of characters: %d\n", a);
	for(i=0; i<a; i++){
		putchar(toupper(arr[i]));	
	}
	return 0;
}