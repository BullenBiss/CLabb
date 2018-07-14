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
			return " är en versal bokstav";
		else if (islower(tecken))
			return " är en gemen bokstav";
	}
	else if (isdigit(tecken))
	{
		return " är en siffra";
	}
	else if (ispunct(tecken))
	{
		return " är en punktsymbol";
	}
	else if (isspace(tecken))
	{
		return " är ett vitt tecken";
	}
	else
	{
		return " är ett felaktigt tecken";
	}
}
