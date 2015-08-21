#include <stdio.h>
#include <time.h>
#include <math.h>
#include <stdlib.h>

int main()
{
	double x, a, b, exact, favg, f2avg, error, nsigma, denominator, term, ans;
	int i, j, NPOINTS;

	NPOINTS = 100000;
	b = 2.0;					//upper bound
	a = 0;					//lower bound
	srand(time(NULL));			//initializes random number generator 

	favg = 0;
	f2avg = 0;

	for(i = 0; i < NPOINTS; i++)
	{
		denominator = 0;

		for(j = 0; j < 8; j++)
		{		
			x = a + (b - a) * rand() / (RAND_MAX + 1.);	//computes random values for x
			denominator += x;
		}

		term = 1 / (1 + denominator);
		//computes the values for <f> and <f>^2
		favg += term;
		f2avg += term * term;
	}	

	favg /= NPOINTS;
	f2avg /= NPOINTS;

	error = pow(2,8) * sqrt((f2avg - favg*favg)/ (NPOINTS - 1)); //error bar

	ans = favg * pow(2,8);

	printf("number of points = %d\n", NPOINTS);
	printf("computational answer = %f\n", ans);
	printf("error bar = %f\n", error);

return 0;
}