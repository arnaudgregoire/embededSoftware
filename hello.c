#include <stdio.h>
#include <stdlib.h>
#include <limits.h>


int main(int argc, char const *argv[]) {

	FILE *fp;
	fp=fopen("16040118.ubx", "rb");

	FILE *fpw;
	fpw=fopen("time.csv","w+");
	fprintf(fpw,"jour,mois,anne,heure,minute,seconde,milliseconde,nanoseconde,validite\n");

	if(!fp){
		printf("%s\n", "probleme dans l'ouverture du fichier");
	}

	unsigned char id;
	unsigned int length;
	unsigned char payload[length];
	unsigned int CK_A = 0;
	unsigned int CK_B = 0;

	while(fread(&id,sizeof(char),1,fp)){


		if (id == 0xb5)  
		{
		fread(&id,sizeof(char),1,fp);
			if (id == 0x62)
			{
				fread(&id,sizeof(char),1,fp);
				//CK_A += id;
				//CK_B += CK_A;  
				// début d'un nouveau message

				if (id == 0x01)  
				{
				fread(&id,sizeof(char),1,fp);
					if (id == 0x21)
					{
						fread(&id,sizeof(char),1,fp);	
						length	= id;

						fread(&id,sizeof(char),1,fp);
						length = length | id << 8;

						fread(&payload, sizeof(char),length, fp);
						
						//jour	
						fprintf(fpw,"%d,",payload[15]);
						//mois
						fprintf(fpw,"%d,",payload[14]);
						//année
						fprintf(fpw,"%d,",payload[13] << 8 | payload[12]);
						//heure
						fprintf(fpw,"%d,",payload[16]);
						//minute
						fprintf(fpw,"%d,",payload[17]);
						//seconde
						fprintf(fpw,"%d,",payload[18]);
						//milliseconde
						fprintf(fpw,"%d,", payload[3]<<24 | payload[2]<<16 | payload[1]<<8 | payload[0]);
						//nanoseconde
						fprintf(fpw,"%d,", payload[11]<<24 | payload[10]<<16 | payload[9]<<8 | payload[8]);
						//validity
						fprintf(fpw,"%d\n", payload[19]);


					}
					/*
					fread(&id,sizeof(char),1,fp);
					if (CK_A == id)
					{
						printf("%s\n", " CK_A OK");
					}
					fread(&id,sizeof(char),1,fp);
					if (CK_B == id)
					{
						printf("%s\n", " CK_B OK");
					}
					*/
				}	
			}	
		}	
	}
	

	fclose(fp);
	fclose(fpw);

	return 0;
}
