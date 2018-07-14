#pragma warning(disable:4996)
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define MIN_NUMB 5
#define MAX_NUMB 10

typedef char* string;

void createFile(int, string);
int checkLength(string);
void readFile(int funcVektor[], string);
void printFile(int funcVektor2[], int, string);

int main(void)
{
	int fileLength, *vektor = NULL;


	//Skapa en textfil med alla nummer
	srand((int)time(NULL));
	int list_length = rand() % MAX_NUMB + MIN_NUMB;
	createFile(list_length, "datafil.txt");


	//Läs första raden av textfilen för att få ut hur många tal som filen innehåller
	fileLength = checkLength("datafil.txt");

	//Fyll en array med de talen som finns i "data-fil.txt"
	vektor = malloc(fileLength * sizeof(int));
	readFile(vektor, "datafil.txt");

	//Skriv ut filen med alla nummer
	printFile(vektor, fileLength, "klartext.txt");
}

void createFile(int length, string name)
{
	FILE *f1 = fopen(name, "w");
	fprintf(f1, "%d\n", length);

	for (int i = 0; i < length; i++)
	{
		int numb_domain = rand() % 9 + 1;
		fprintf(f1, "%d\n", numb_domain);
	}
	fclose(f1);
}

int checkLength(string fil)
{
	int checkedLength;
	FILE *f2 = fopen(fil, "r");
	fscanf(f2, "%d", &checkedLength);
	fclose(f2);

	return checkedLength;
}

void readFile(int funcVektor[], string fileName)
{
	int length, tal;
	FILE*f3 = fopen(fileName, "r");
	fscanf(f3, "%d", &length);

	for (int i = 0; i < length; i++)
	{
		fscanf(f3, "%d", &tal);
		funcVektor[i] = tal;
	}
	fclose(f3);
}

void printFile(int funcVektor2[], int funcFileLength, string fileName2)
{
	int maxTal = 0, loopVar = 0;

	for (int i = 0; i < funcFileLength; i++)        //Kolla vad största talet är i vektorn
	{
		if (funcVektor2[i] > maxTal)
			maxTal = funcVektor2[i];
	}

	int nTal = 0;

	FILE *fil = fopen(fileName2, "w");
	for (int i = 1; i <= maxTal; i++, nTal = 0)
	{
		for (int j = 0; j <= funcFileLength; j++)
		{
			if (i == funcVektor2[j])
			{
				nTal++;
			}
		}
		if (nTal != 0)
		{
			fprintf(fil, "%d %d\n", i, nTal);
		}
	}
	fclose(fil);
}
