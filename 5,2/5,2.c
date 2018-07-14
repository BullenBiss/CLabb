#pragma warning(disable:4996)
#include <stdio.h>
#include <string.h>

int main(void)
{
	char vector[10];
	//vector[10] = "hej";            //Funkar ej 
	vector[5] = '\0';
	int length = strlen(vector);

	printf("Vektor 1: %s %d\n", vector, length);


	char*vector2 = malloc(10);
	vector2[5] = '\0';
	vector2 = "nej";                //Funkar
	printf("Vektor 2: %s", vector2);

	free(vector2);
}