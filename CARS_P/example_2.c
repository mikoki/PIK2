#include <stdio.h>
#include <stdlib.h>

int main(){
	int ID, m_lenght, a_lenght;
	char* marka;
	char* address;
	double price;
	int i;
	size_t eof_check;
	FILE* f;

	f=fopen("FILE1.bin", "rb");
	while(!feof(f)){
		eof_check = fread(&ID, sizeof(int), 1, f);
		if(eof_check == 0){
			break;
		}
		fread(&m_lenght, sizeof(int), 1, f);
		marka = (char*)malloc((m_lenght+1)*sizeof(char));
		fread(marka, sizeof(char), m_lenght+1, f);
		fread(&price, sizeof(double), 1, f);
		fread(&a_lenght, sizeof(int), 1, f);
		address = (char*)malloc((a_lenght+1)*sizeof(char));
		fread(address, sizeof(char), (a_lenght+1), f);

		printf("ID: %d\n", ID);
		printf("m_lenght: %d\n", m_lenght);
		printf("Marka: %s\n", marka);
		printf("Price: %lf\n", price);
		printf("a_lenght: %d\n", a_lenght);
		printf("address: %s\n", address);
		printf("\n");
		printf("\n");

		free(marka);
		free(address);
		/*ID=0; 
		m_lenght=0;
		a_lenght=0;
		price=0.0;
		*/
	}

	return 0;
}