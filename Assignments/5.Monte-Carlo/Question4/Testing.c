#include <stdio.h>
#include <time.h>
#include <math.h>
#include <stdlib.h>

int main()
{
	double x[10], a, b, exact, favg, f2avg, error, nsigma;
	int i, j, NPOINTS;

	NPOINTS = 100000;
	exact = 155 / 6.0;      //exact answer
	b = 1.0;					//upper bound
	a = 0;					//lower bound
	srand(time(NULL));			//initializes random number generator 

	favg = 0;
	f2avg = 0;

	for(i = 0; i < NPOINTS; i++)
	{
		for(j = 0; j < 10; j++)
		{		
			x[j] = a + (b - a) * rand() / RAND_MAX;	//computes random values for x
		}

		//computes the values for <f> and <f>^2
		favg += pow(x[0] + x[1] + x[2] + x[3] + x[4] + x[5] + x[6] + x[7] + x[8] + x[9], 2);
		f2avg += pow(pow(x[0] + x[1] + x[2] + x[3] + x[4] + x[5] + x[6] + x[7] + x[8] + x[9], 2),2);
	}	

	favg /= NPOINTS;
	f2avg /= NPOINTS;

	error = sqrt((f2avg - favg*favg)/ (NPOINTS - 1)); //error bar

	printf("number of points = %d\n", NPOINTS);
	printf("analytic answer = %f\n", exact);
	printf("computational answer = %f\n", (b - a) * favg);
	printf("error bar = %f\n", error);
	printf("standard deviation = %fsigma\n", fabs((favg - exact) / error));

return 0;
}