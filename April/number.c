
/*#include <stdio.h>
#include <stdlib.h>

int main(){
	int a, i, n;
	int count = 1;
	char *number;
	printf("Input positive number: ");
	scanf("%d", &a);
	n=a;
	while(n>9){
		n/=10;
		count++;
	}
	printf("%d\n", count);
	number = (char*)malloc((count+1)*sizeof(char));
	snprintf(number, count+1, "%d", a);
	printf("%s", number);
	free(number);
	return 0;
}
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
	int a, size;
	char *number;
	printf("Input string: ");
	number = (char*)malloc(1000*sizeof(char));
	scanf("%s", number);
	size =strlen(number);
	number = (char*)realloc(number, size*sizeof(char));
	printf("%s\n", number);
	a = strtoll(number, NULL, 10);
	printf("The number you have entered multiplied by two is: %d\n", a*2);
	free(number);
	return 0;
}