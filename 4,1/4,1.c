#pragma warning(disable:4996)
#include <stdio.h>
#include <math.h>


void PolarCo(float *r, float *theta, float, float);

int main(void)
{
	float x, y, r, theta;

	printf("Skriv in de koordinater du vill göra om till polära koordinater (x,y): \n");
	scanf("%f,%f", &x, &y);


	PolarCo(&x, &y, x, y);
	printf("De kartesiska polära koordinaterna blir r = %f och theta = %f rad" , x, y);
	system("pause");
	return 0;
}

void PolarCo(float *r, float *theta, float x, float y)
{

	*r = sqrt(x * x + y * y);
	*theta = atan2(y, x);

}
