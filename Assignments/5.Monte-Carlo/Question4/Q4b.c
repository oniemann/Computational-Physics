#include <stdio.h>
#include <time.h>
#include <math.h>
#include <stdlib.h>

//defines function to be integrated
double f(double x)
{
	return x * x;
}

double g(double x)
{
	return x;
}

int main()
{
	int i, j, NPOINTS, NCOMPS = 10;
	double a, b, exact, error, nsigma, Integral;
	double x, favg, f2avg, gavg, g2avg;
	NPOINTS = 1000;
	exact = 155 / 6;      //exact answer
	b = 1.0;					//upper bound
	a = 0;					//lower bound
	srand(time(NULL));			//initializes random number generator

	for(i = 0; i < NPOINTS; i++)
	{
		x = a + (b - a) * rand() / RAND_MAX;	//computes random values for x
		favg += f(x);							//computes f(x)
		f2avg += f(x) * f(x);                   //computes f(x)^2
		gavg += g(x);
		g2avg += g(x) * g(x);
	}	

	favg /= NPOINTS;
	f2avg /= NPOINTS;
	
	Integral += 10 * favg;

	gavg /= NPOINTS;
	g2avg /= NPOINTS;
	
	Integral += 90 * gavg * gavg; 


	//error = sqrt((f2avg - favg*favg)/ (NPOINTS - 1)); //error bar

	printf("number of points = %d\n", NPOINTS);
	printf("analytic answer = %f\n", exact);
	printf("computational answer = %f\n", Integral);
	//printf("error bar = %f\n", error);
	//printf("standard deviation = %fsigma\n", fabs((favg - exact) / error));

return 0;
}