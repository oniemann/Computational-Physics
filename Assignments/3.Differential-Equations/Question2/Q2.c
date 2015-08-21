#include<stdio.h>
#include<math.h>

/*original function from question 1 was placed here*/
double f(double x)
{
	return (x*x*x - 5 * x + 3);
}

/*derivative of the function from question 1*/
double g(double x)
{
	return (3*x*x - 5);
}

int main()
{
	double x, f(), g(), EPS;

	/*desired precision*/
	EPS = 1.e-14;
	/*value of first root using bisection method*/
	x = 0.656616;
	printf("        x               f(x)\n");
	printf("1st root:\n");
	/*loops Newton-Raphson method until desired precision is achieved*/
	while (fabs(f(x)) > EPS)
	{
			x -= (f(x)/g(x));
			printf(" %.14f    %e \n", x, f(x));

	}
	printf("\n2nd root:\n");
	x = 1.834229;
	while (fabs(f(x)) > EPS)
	{
		x -= (f(x)/g(x));
		printf(" %.14f    %e \n", x, f(x));
	}
}