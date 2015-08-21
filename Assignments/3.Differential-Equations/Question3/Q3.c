#include<stdio.h>
#include<math.h>

/*function used for this question*/
double f(double x)
{
	return (x - tanh(2*x));
}

main()
{
	double x, f(), x_n, x_m, EPS;

	x_n = 0.5;  /*x_(n-1)*/
	x_m = 1.5;  /*x_n*/
	EPS = 1.e-12;   /*desired precision*/
	x= 1;

	printf("    x          |f(x)|\n");

	/*Using the secant method, loops the given function for its root until 
	desired precision is achieved*/
	while (fabs(f(x)) > EPS)
	{
		x = x_m - f(x_m)*(x_m - x_n)/(f(x_m) - f(x_n));
		x_n = x_m;
		x_m = x;
		printf("%f     %.5e\n", x, fabs(f(x)));

	}
}