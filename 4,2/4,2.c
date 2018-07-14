#pragma warning(disable:4996)
#include <stdio.h>
#include <math.h>

typedef struct {
	float x, y, polr, poltheta;
}coord;


coord coordConv(coord);

int main(void)
{

	coord k;

	printf("Skriv in de polära koordinaterna (r, theta): \n");
	scanf("%f, %f", &k.polr, &k.poltheta);

	k = coordConv(k);
	printf("x=%.3f och y=%.3f\n", k.x, k.y);

	system("pause");
	return 0;

}

coord coordConv(coord p)
{
	p.x = p.polr * cos(p.poltheta);
	p.y = p.polr * sin(p.poltheta);
	return p;
}