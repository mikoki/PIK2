#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int cmpfunc (const void * a, const void * b)
{
	return (*(int*)a - *(int*)b);
}

int *func (int *arr, int length){
	int i;
	int j=0;
	int *check = malloc(1000);		
	for(i=0; i<length; i++){
		if(arr[i]%2 == 0){
			arr[i]=check[j];
			j++;
		}
		i++;
	}
	qsort(check, length, sizeof(int), cmpfunc);
	return check;
}

int main(){
	int *ptr;
	int *numbers;
	int n_length, i;

	printf("Input how many numbers you would like to enter:\n");
	scanf("%d", &n_length);

	numbers = (int*)malloc((n_length+1)*sizeof(int));

	printf("Enter numbers: ");
	for(i=0; i<n_length; i++){
		scanf("%d", &numbers[i]);
	}

	ptr = func(numbers, n_length);

	printf("%d", *ptr);

	return 0;
}