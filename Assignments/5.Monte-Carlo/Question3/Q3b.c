#include <stdio.h>
#include <time.h>
#include <math.h>
#include <stdlib.h>

//defines function to be integrated
double f(double x)
{
	return log(x);
}

int main()
{
	double x, a, b, exact, favg, f2avg, error, nsigma;
	int i, NPOINTS;

	NPOINTS = 10;
	exact = log(4.0) - 1.0;      //exact answer
	b = 2.0;					//upper bound
	a = 1.0;					//lower bound
	srand(time(NULL));			//initializes random number generator 

	favg = 0;
	f2avg = 0;

	for(i = 0; i < NPOINTS; i++)
	{
		x = a + (b - a) * rand() / RAND_MAX;	//computes random values for x
		favg += f(x);							//computes f(x)
		f2avg += f(x) * f(x);					//computes f(x)^2
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