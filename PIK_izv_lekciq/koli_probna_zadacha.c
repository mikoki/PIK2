#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){

	int check;
	int c_cycle=0, i=0, j=0;
	double price;
	int size=0;
	FILE *f, *fM;
	f=fopen("FILE1.bin", "rb");
	u_brands=(char**)malloc(2*sizeof(char*));

	while(1){
		if(fread(&ID, sizeof(int), 1, f) != 1){
			break;
		}
		fread(&m_length, sizeof(int), 1, f);
		marka = (char*)malloc((m_length+1)*sizeof(char));
		fread(marka, sizeof(char), m_length+1, f);
		fread(&price, sizeof(double), 1, f);
		fread(&a_length, sizeof(int), 1, f);
		address = (char*)malloc((a_length+1)*sizeof(char));
		fread(address, sizeof(char), a_length+1, f);

		u_brands[c_cycle] = (char*)malloc((m_length+1)*sizeof(char));
		u_brands=(char**)realloc(u_brands, (c_cycle+2)*sizeof(char*));
		u_brands[c_cycle]=marka;
		c_cycle++;
	}

	fM = fopen("result.bin", "wb");

	for(i = 0; i < c_cycle; i++){
		for(j = 0; j < i; j++){
			if(strcmp(u_brands[i], u_brands[j]) == 0){
				free(u_brands[i]);
				break;
			}
		}

		size = strlen(u_brands[i]);
			
		fwrite(&size, sizeof(int), 1, fM);
		fwrite(u_brands[i], sizeof(char), size, fM);
		printf("%s\n", u_brands[i]);
	}
	return 0;
}