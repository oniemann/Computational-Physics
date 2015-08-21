#include<stdio.h>
#include<math.h>

//Establishes the value f(y) for given differential equation dy/dx
double f(double y, double x)
{
	return sqrt(y + x * x);
}

int main()
{
	double y, y2, y1, y0, h, k1, k2, f(), b, a, exact,x, EPS;
	int i, n;

	//limits of integration
	a = 0;
	b = 2;
	//condition for y=0
	y0 = 1;
	//analytical value of integral
	exact = 1;
	EPS = 10.e-6;
	n = 1;
	y2 = 1000;
	y1 = 1;
	printf(" Value of Integral    Precision        n\n");


	while(fabs(y2 - y1) > EPS)
	{
		y1 = y2;
		h = (b - a) / n;
		x = 0;
		y = y0;

		for (i = 1; i < n; i++)
		{
			//Runge-Kutta Method 2
			k1 = f(y, x);				   //defines k1
			x += h;
			k2 = f(y + h * k1, x);	   //defines k2
			y += h/2 * (k1 + k2); //evaluates higher precision value for y'
		}

		y2 = y;
		n *= 2;
	}

	printf("y(2) = %.4f\n", y2);

return 0;
}