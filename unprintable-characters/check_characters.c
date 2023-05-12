#include <stdio.h>
#include <stdlib.h>
/*#include <curses.h>*/
//#include <conio.h>
#include <math.h>
#include <string.h>
#include <time.h>
#include <ctype.h>

FILE *fp6, *fe;
char ANY[2] = "", NUMRAM[13], Ram[13] = "Meda1.VSI\0"; //"ASDWE.VSI\0";
int D1, D2, fece, fecbb, PERIODE = 365;

int menu(int nargs, char *args[]);

int censor_file(char line[130]);

int main(int argc, char *argv[])
{
    int count = 0;
	fe = fopen("error.log", "w");
    char line[130];
    char current;
	if (menu(argc, argv))
	{
        if ((fp6 = fopen(Ram, "rb")) == NULL)
            return -1; /*- Fitxer granja    --*/
        

        while (fgets(line, sizeof(line), fp6)) {
            
            count++;
            for(int i = 0; i < strlen(line); i++)
            {
                current = line[i];
                if(iscntrl(current))
                    fprintf(fe, "Sam, we've got a problem in line %d and in character position %d\n", count, i);
            }


            //censor_file(line);
        }
        
		fclose(fp6);
	}
	else
		perror(strerror(-1));
	printf("FIN DEL TRACTAMENT\n");
	getchar();
	fclose(fe);
	return 0;
}

/**
 * @brief This function cleans the stdin.
 * It's a fflush function basically, but for linux.
 */
void clean_stdin(void)
{
    int c;
    do {
        c = getchar();
    } while (c != '\n' && c != EOF);
}

/**
 * @brief This function is a mock of the menu.
 * @param nargs The number of arguments that menu will receive.
 * @param args The array of arguments that menu will receive.
 * @return int 
 */
int menu(int nargs, char *args[])
{
    return 1;
}

/**
 * @brief This function censors a whole file.
 * It is mainly used because we don't want to upload sensitive files on github.
 * @param line The line to censor.
 * @return int 
 */
int censor_file(char line[130])
{
    for(int i = 0; i < strlen(line); i++)
    {
        if(line[i] != ' ' && line[i] != '\t' && line[i] != '\n' && line[i] != '\r' && line[i] != '\0'){
            line[i] = 'X';
        }
    }
    fprintf(fe, "%s", line);
}