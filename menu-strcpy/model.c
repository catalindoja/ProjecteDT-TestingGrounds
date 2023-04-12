#include <stdio.h>
#include <stdlib.h>
/*#include <curses.h>*/
#include <conio.h>
#include <math.h>
#include <string.h>
#include <time.h>

FILE *fp6, *fe;
char ANY[2] = "", NUMRAM[13];
int D1, D2, fece, fecbb, PERIODE = 365;

int menu(int nargs, char *args[]);

int main(int argc, char *argv[])
{
	fe = fopen("error.log", "w");
	if (menu(argc, argv))
	{
		fclose(fp6);
	}
	else
		perror(strerror(errno));
	printf("FIN DEL TRACTAMENT\n");
	getch();
	fclose(fe);
	return 0;
}

int menu(int nargs, char *args[])
{
	if(nargs > 1) { //deletion
		printf("\n!!!!!!!El programa te %d arguments!!!!!!!!\n", nargs);
		printf("\n!!!!!!!El Arg1 %s arguments!!!!!!!!\n", args[1]);
		printf("\n!!!!!!!El Arg2 %s arguments!!!!!!!!\n", args[2]);
		printf("\n!!!!!!!El Arg3 %s arguments!!!!!!!!\n", args[3]);
	}
	
	fflush(stdin);
	char DAT[12], d2[7] = {"010199"};
	int i = 0, j;
	do
	{
		i++;
		printf("Granges a processar --->");
		printf("\n\n	 fitxer de control (CONTROL.DAT per defecte):");
		if(nargs > 1) { 
			strcpy(DAT, args[1]);
			printf("\n!!!!!!!Fitxer control %s!!!!!!!!\n", DAT);
		}else{ 
			fgets(DAT, sizeof(DAT), stdin); 
		}
		if (!strlen(DAT))
			strcpy(DAT, "CONTROL.DAT");
		fp6 = fopen(DAT, "r");
	} while (!fp6 && i < 4);

	fflush(stdin);

	if (!fp6)
		return 0;
	
	printf("\n\n\n\t Per defecte la data inici del periode ser� la de 365 dies abans.");
	printf("\n\t Data final del periode (DDMMAA):");
	if(nargs > 1) { 
		strcpy(d2, args[2]);
	}else{ 
		fgets(d2, sizeof(d2), stdin);
	}
	fflush(stdin);
	ANY[0] = d2[4];
	ANY[1] = d2[5];
	ANY[2] = '\0';

	printf("\n\n\t durada del periode pels calculs (dies):");
	if(nargs > 1) { 
		strcpy(DAT, args[3]);
	}else{ 
		fgets(DAT, sizeof(DAT), stdin);
		PERIODE = atoi(DAT);
	}
	D1 = D2 - PERIODE;

	return 1;
}