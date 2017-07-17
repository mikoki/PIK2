#include <stdio.h>
#include <stdlib.h>



int cmpfunc (const void * a, const void * b)
{
	return (*(int*)a - *(int*)b);
}

int main()
{
	int *arr;
	int i;
	int j;
	int sum=0;

	printf("Enter the number of elements you wish to sort: \n");
	scanf("%d", &j);

	arr = (int*)malloc(j*sizeof (int));
	for(i=0; i<j; i++){	
		scanf("%d", &arr[i]);
		sum+=arr[i];
	}
	printf("You have entered: \n");
	for(i=0; i<j; i++){
		printf("%d\t ", arr[i]);
	}

	qsort(arr, j, sizeof(int), cmpfunc);
	
	printf("\nAfter sorting the list is: \n");
	for( i = 0 ; i < j; i++ ) {   
		printf("%d \t", arr[i]);
	}
	printf("\nAverage: %lf\n", (double)sum/(double)j);

	return(0);
}