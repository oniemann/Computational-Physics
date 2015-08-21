#include<stdio.h>
#include<math.h>

/*defines function*/
double f(double x)
{
	return (x - sin(3*x));
}

main()
{
	double f(), x, xn, xp, EPS, n;

	x = 0.5;  /*x_(n-1)*/
	xn = 1.5;  /*x_n*/
	EPS = 1.e-3;   /*desired precision*/
	n = 0;

	/*Using the secant method, loops the given function for its root until 
	desired precision is achieved*/
	while (fabs(xn - x) >= EPS)
	{
		n++;
		xp = x;
		x = xn;
		xn = x - f(x) * (x - xp) / (f(x)-f(xp));
	}

	printf("positive root = %.3f\n", x);
}