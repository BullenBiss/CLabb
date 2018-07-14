#pragma warning(disable:4996)
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

char * checkChar(unsigned char);

int main(void)
{

		unsigned char letter;
		char*check;
		printf("Skriv in ett tecken du vill kolla\n");
		scanf("%c", &letter);

		check = checkChar(letter);

		printf("%c %s\n", letter, check);
		system("pause");
}

char * checkChar(unsigned char tecken)
{
	if (isalpha(tecken))
	{
		if (isupper(tecken))
			return " �r en versal bokstav";
		else if (islower(tecken))
			return " �r en gemen bokstav";
	}
	else if (isdigit(tecken))
	{
		return " �r en siffra";
	}
	else if (ispunct(tecken))
	{
		return " �r en punktsymbol";
	}
	else if (isspace(tecken))
	{
		return " �r ett vitt tecken";
	}
	else
	{
		return " �r ett felaktigt tecken";
	}
}
