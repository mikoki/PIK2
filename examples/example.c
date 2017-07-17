#include <stdio.h>
#include <stdlib.h>

int main(){
	int ID, len1, len2;
	double price;
	char *marka, *adres;
	FILE* fp; 
	
	fp = fopen("FILE1.bin", "rb");
	for(;;){
	fread(&ID, sizeof(int), 1, fp);
	fread(&len1, sizeof(int), 1, fp);
	marka = (char*) malloc((len1+1)*sizeof(char));

	fread(marka, sizeof(char), len1, fp);
	marka[len1] = '\0';
	fread(&price, sizeof(double), 1, fp);
	fread(&len2, sizeof(int), 1, fp);
	fread(adres, sizeof(char), len2, fp);
	adres[len2] = '\0';
	}
	return 0;
}