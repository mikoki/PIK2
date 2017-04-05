#include <stdio.h>
#include <stdlib.h>

int main(){
	int ID, m_lenght, a_lenght;
	char* marka;
	char* address;
	double price;
	int num;
	int i;
	FILE* f;

	f=fopen("FILE1.bin", "wb");

	printf("Num ");
	scanf("%d", &num);

	for(i=0;i<num;i++){
		printf("ID: ");
		scanf("%d", &ID);

		printf("Price: ");
		scanf("%lf", &price); 

		printf("m_lenght: ");
		scanf("%d", &m_lenght);
		marka =(char*)malloc((m_lenght+1)*sizeof(char)); 
		printf("Marka: ");
		scanf("%s", marka);



		printf("a_lenght: ");
		scanf("%d", &a_lenght);
		address =(char*)malloc((a_lenght+1)*sizeof(char));
		printf("Address: ");
		scanf("%s", address);

		/*printf("\nID = %d\n", ID);
		printf("price = %lf\n", price);
		printf("m_len = %d\n", m_lenght);
		printf("marka = %s\n", marka);
		printf("a_len = %d\n", a_lenght);
		printf("address = %s\n", address);
		*/


		fwrite(&ID, sizeof(int), 1, f);
		fwrite(&m_lenght, sizeof(int), 1, f);
		fwrite(marka, sizeof(char), (m_lenght+1), f);
		fwrite(&price, sizeof(double), 1, f);
		fwrite(&a_lenght, sizeof(int), 1, f);
		fwrite(address, sizeof(char), (a_lenght+1), f);

		free(marka);
		free(address);
	} 
	return 0;
}