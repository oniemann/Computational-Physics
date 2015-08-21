#include<stdio.h>
#include<math.h>

/*function whose root is the square root of 2*/
double f(double x)
{
	return (2 - pow(x,2));
}

/*derivative of the above function*/
double g(double x)
{
	return (-2*x);
}

int main()
{
	double x, f(), g(), EPS;

	/*desired precision*/
	EPS = 1.e-14;
	x = 1.5;
	
	printf("        x               |f(x)|\n");
	
	/*loops NR method on defined function until desired precision is achieved*/
	while (fabs(f(x)) > EPS)
	{
			x -= (f(x)/g(x));
			printf(" %.14f    %e \n", x, fabs(f(x)));

	}
return 0;
}