#include <stdio.h>

int c;
int sum(int a1, int b1){
	return a1+b1+c;
}


int main(){
	c=5;
	int a = 5;
	int b = 4;
	int result;
	result=sum(a,b);
	printf("%d", result);
	printf("%d\n", c);
	return 0;
}