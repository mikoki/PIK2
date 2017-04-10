#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Car{
	int ID, m_length, a_length, u_b_length;
	char *marka, *address;
	double price;
}car;

int main(){
	char **u_brands;
	int check;
	int c_cycle=0, i=0, j=0;
	double price;
	int size=0;
	FILE *f, *fM;
	f=fopen("FILE1.bin", "rb");
	u_brands=(char**)malloc(2*sizeof(char*));

	car *c1 = NULL;

	while(1){
		c1 = (car*)realloc(c1,(c_cycle+1)*sizeof(car));
		if(fread(&c1[c_cycle].ID, sizeof(int), 1, f) != 1){
			break;
		}
		fread(&c1[c_cycle].m_length, sizeof(int), 1, f);
		c1[c_cycle].marka = (char*)malloc((c1[c_cycle].m_length+1)*sizeof(char));
		//c1[c_cycle].marka[c1.[c_cycle].m_length] = '\0';
		fread(c1[c_cycle].marka, sizeof(char), c1[c_cycle].m_length+1, f);
		fread(&c1[c_cycle].price, sizeof(double), 1, f);
		fread(&c1[c_cycle].a_length, sizeof(int), 1, f);
		c1[c_cycle].address = (char*)malloc((c1[c_cycle].a_length+1)*sizeof(char));
		fread(c1[c_cycle].address, sizeof(char), c1[c_cycle].a_length+1, f);

		u_brands[c_cycle] = (char*)malloc((c1[i].m_length+1)*sizeof(char));
		u_brands=(char**)realloc(u_brands, (c_cycle+2)*sizeof(char*));
		u_brands[c_cycle]=c1[c_cycle].marka;
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
	fclose(fM);
	/*
	fM = fopen("result.bin", "rb");
	i=0;
	while(1){
		if(fread(&size, sizeof(int), 1, fM)!=1){
			break;
		}
		u_brands[i] = (char*)malloc(size*sizeof(char));
		fread(u_brands[i], sizeof(char), size, fM);
		printf("%s\n", u_brands[i]);
		i++;
	}
	*/
	
	return 0;
}