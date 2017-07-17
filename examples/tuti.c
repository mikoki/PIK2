/*#include <stdio.h>

int main(){
	int a;
	int sum = 0;
	while(scanf("%d", &a) > 0){
		sum += a;
	}
	printf("%d\n", sum);
	return 0;
}*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
	int b;
	int i;
	int *arr;
	arr = (int*)malloc(2*sizeof(int));
	printf("vuvedete chisla\n");
	for(i=0; i<strlen(arr); i++){
		arr = (int*)realloc(arr, (strlen(arr)+2)*sizeof(int));
		scanf("%d", &b);
		arr[i] = b;
	}
	for(i=0; i<strlen(arr); i++){
		printf("%d\n", arr[i]);
	}
	return 0;
}