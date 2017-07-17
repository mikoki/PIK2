#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main()
{

    int ID,len1,len2,i,counter=0,lenM;
    char *marka,*adres,*Mmarka;
    double price,sum=0;
    FILE *fp=NULL;
    fp=fopen("FILE1.bin","rb");

    for(;;)
   {
    if(fread(&ID,sizeof(int),1,fp)!=1)break;
    //chetene
    fread(&len1,sizeof(int),1,fp);
    marka=(char*) malloc((len1+1)*sizeof(char));
    fread(marka,sizeof(char),len1,fp);
    marka[len1]='\0';
    fread(&price,sizeof(double),1,fp);
    fread(&len2,sizeof(int),1,fp);
    adres=(char*) malloc((len2+1)*sizeof(char));
    fread(adres,sizeof(char),len2,fp);
    adres[len2]='\0';
    //subirane na sumata
    sum+=price;
    counter++;
    //tursene v marka
    int fl=0;
    FILE *fpM = fopen("Marka.bin","rb");

    if(fpM!=NULL)
    for(;;)
    {
        if(fread(&lenM,sizeof(int),1,fpM)!=1)break;
    Mmarka=(char*) malloc((lenM+1)*sizeof(char));
    fread(Mmarka,sizeof(char),lenM,fpM);
    Mmarka[lenM]='\0';
    //sravnqvame
    if(strcmp(marka,Mmarka)==0){fl=1;break;}
    free(Mmarka);
    }

    fclose(fpM);
    //ako ne sme sre6tnali povtorenie
    if(fl==0)
        {//zapisvame vuv faila novata marka
         fpM=fopen("Marka.bin","ab+");
          fwrite(&len1,sizeof(int),1,fpM);
          fwrite(marka,sizeof(char),len1,fpM);
          fclose(fpM);
        }
    free(marka);
    free(adres);
   }
   //pro4itame pak vsi4ko i izkarvame samo po golemite ot srednoaritmeti4noto
   sum/=counter;

fp=fopen("FILE1.bin","rb");
FILE *fpA=fopen("ADRES.bin","wb");
    for(;;)
   {
    if(fread(&ID,sizeof(int),1,fp)!=1)break;
    //chetene
    fread(&len1,sizeof(int),1,fp);
    marka=(char*) malloc((len1+1)*sizeof(char));
    fread(marka,sizeof(char),len1,fp);
    marka[len1]='\0';
    fread(&price,sizeof(double),1,fp);
    fread(&len2,sizeof(int),1,fp);
    adres=(char*) malloc((len2+1)*sizeof(char));
    fread(adres,sizeof(char),len2,fp);
    adres[len2]='\0';
    if(price>sum)
    {
        fwrite(&len2,sizeof(int),1,fpA);
          fwrite(adres,sizeof(char),len2,fpA);
    }
    free(marka);
    free(adres);
   }
return 0;
}
