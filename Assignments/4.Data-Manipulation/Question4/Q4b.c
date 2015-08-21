#include<stdio.h>
#include<math.h>

double f(double p)    //1st order derivative function
{
	return p;
}

double g(double x)    //2nd order derivative function
{
	return -1 * M_PI * M_PI * x;
}

double rk4(double t, double h, double x1, double x2, double p1, double p2, double f(double), double g(double))
{
	double k1x, k1p, k2x, k2p, k3x, k3p, k4x, k4p;

	x1 = x2;	
	p1 = p2;                    /*creates recursive relationship*/
	k1x = g(x1);
	k1p = f(p1);
	k2x = g(x1) + h / 2 * k1p;	    /*defines k2*/
	k2p = f(p1) + h / 2 * k1x;
	k3x = g(x1) + h / 2 * k2p;		/*defines k3*/
	k3p = f(p1) + h / 2 * k2x;
	k4x = g(x1) + h * k3p;			/*defines k4*/
	k4p = f(p1) + h * k3x;
	x2 = x1 + h / 6.0 * (k1x + 2*k2x + 2*k3x + k4x); 
	p2 = p1 + h / 6.0 * (k1p + 2*k2p + 2*k3p + k4p);
	return x2, p2;
}

int main()
{
	double h, x, x0, x1, x2, p0, p1, p2, f(), g(), k1x, k2x, k3x, k4x, k1p, k2p, k3p, k4p;
	int i, j, n, a, b;
	double hvalue[3] = {.2, .1, .05};

	printf("   x            f(x)           f'(x)\n");

	for(j = 0; j < 3; j++)
	{
		a = 0;
		b = 1;
		x0 = 0;
		p0 = 1.0;			//Sets initial values
		h = hvalue[j];
		n = b / h;
		x2 = x0;
		p2 = p0;

		printf("h = %.2f\n", hvalue[j]);
		printf("%f      %f      %f\n", x, x2, p2);

		for (i = 0; i < n; i++)
		{
			x1 = x2;
			p1 = p2;
			k1x = f(p1);
			k1p = g(x1);
			k2x = f(p1 + h / 2.0 * k1p);
			k2p = g(x1 + h / 2.0 * k1x);
			k3x = f(p1 + h / 2.0 * k2p);    //Runga Kutta 4 Method
			k3p = g(x1 + h / 2.0 * k2x);
			k4x = f(p1 + h * k3p);
			k4p = g(x1 + h * k3x);
			x2 = x1 + h / 6.0 * (k1x + 2.0*k2x + 2.0*k3x + k4x); 
			p2 = p1 + h / 6.0 * (k1p + 2.0*k2p + 2.0*k3p + k4p);
			x += h;
		}
		printf("%f      %f     %f\n", x, x2, p2);
	}

return 0;
}
