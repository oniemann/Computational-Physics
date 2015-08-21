#include<stdio.h>
#include<math.h>

//Establishes the value f(y) for given differential equation dy/dx
double f(double y)
{
	return (pow(y,2) + 1);
}

int main()
{
	double y2, y1, y0, h, k1, k2, f(), b, a, exact;
	int i, n;

	//limits of integration
	a = 0;
	b = M_PI_4;
	//condition for y=0
	y0 = 0;
	//analytical value of integral
	exact = 1;

	printf(" Value of Integral    Precision        n\n");


	for (n = 1; n < 100000; n*=2)
	{
		h = (b - a) / n;
		//establishes first iteration by euler's method
		y2 = y0 + (h * f(y0));

		for (i = 1; i < n; i++)
		{
			//Runge-Kutta Method 2
			y1 = y2;	               //creates recursive relationship
			k1 = f(y1);				   //defines k1
			k2 = f(y1 + h * k1);	   //defines k2
			y2 = y1 + h/2 * (k1 + k2); //evaluates higher precision value for y
		}
		printf("   %.8f          %.2e        %d\n", y2, fabs((y2 - exact)/pow(h, 2)), n);

	}

return 0;
}