#pragma warning(disable:4996)
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "simpio.h"

typedef char* string;

int palindromeTest(char*);
char* readFile(string);
void stringConvert(unsigned char functext2[], char*);

int main(void)
{
	int tralse;                            
	unsigned char text[50], textConvert[50], *tp, *svar;

	tp = textConvert;
	FILE*fileR = fopen("palindrom.txt", "r");
	FILE*fileW = fopen("testad.txt", "w");
	while (fgets(text, 50, fileR) != NULL)        //L�ser fr�n textfilen och skriver till en ny textfil
	{
		stringConvert(text, tp);
		tralse = palindromeTest(textConvert);
		if (tralse)
		{
			svar = "�r ett palindrom";
		}
		else
		{
			svar = "�r inte ett palindrom";
		}

		fprintf(fileW, "%s %s\n\n\n", text, svar);
	}
	fclose(fileR);
	fclose(fileW);

}

int palindromeTest(char* tp)
{

	/*
	*Testar om en string �r ett palindrom, retunerar boolskt v�rde
	*/

	int length = strlen(tp);

	for (int i = 0; i < length; i++)
	{
		if (tp[i] != tp[length - 1 - i])
		{
			return 0;
		}
	}
	return 1;
}

void stringConvert(unsigned char functext2[], char*tp)
{

	/*
	*Tar bort vita tecken och g�r om stora till sm� bokst�ver
	*/

	int loopVar = 0;
	int length = strlen(functext2);

	for (int j = 0; j <= length; j++)
	{
		if (isalpha(functext2[j]))                            //Tar bort eventuella vita tecken
		{
			tp[loopVar] = functext2[j];

			if (isupper(functext2[j]))                        //G�r om versaler till gemener
			{
				tp[loopVar] = tolower(functext2[j]);
			}
			loopVar++;
		}

		if (j == length)
		{
			tp[loopVar] = '\0';
		}
	}

}