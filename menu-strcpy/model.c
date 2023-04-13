#include <stdio.h>
#include <stdlib.h>
/*#include <curses.h>*/
//#include <conio.h>
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
		perror(strerror(-1));
	printf("FIN DEL TRACTAMENT\n");
	getchar();
	fclose(fe);
	return 0;
}

void clean_stdin(void)
{
    int c;
    do {
        c = getchar();
    } while (c != '\n' && c != EOF);
}

int menu(int nargs, char *args[])
{
	char DAT[12], d2[7] = {"010199"};
	int i = 0, j;
	do
	{
		i++;
		printf("Granges a processar --->");
		printf("\n\n	 fitxer de control (CONTROL.DAT per defecte):");

		fgets(DAT, sizeof(DAT), stdin); 
		
		if (!strlen(DAT))
			strcpy(DAT, "CONTROL.DAT");
		fp6 = fopen(DAT, "r");
	} while (!fp6 && i < 4);

	if (!fp6)
		return 0;
	
	printf("\n\n\n\t Per defecte la data inici del periode ser� la de 365 dies abans.");
	printf("\n\t Data final del periode (DDMMAA):");

	clean_stdin();
	fgets(d2, sizeof(d2), stdin);
	
	ANY[0] = d2[4];
	ANY[1] = d2[5];
	ANY[2] = '\0';
	
	printf("\n\n\t durada del periode pels calculs (dies):");
	clean_stdin();
	fgets(DAT, sizeof(DAT), stdin);
	PERIODE = atoi(DAT);
	D1 = D2 - PERIODE;

	return 1;
}