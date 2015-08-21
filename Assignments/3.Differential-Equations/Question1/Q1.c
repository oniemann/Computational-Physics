#include<stdio.h>
#include<math.h>

/* Defines Function */
double f(double x){
	return (x * x * x - 5 * x + 3);
}

int main()
{
	double x_l, x_u, f(), x, y;

	x_l = .5;
	x_u = 1.5;
	printf("1st Root         f(x)\n");

/* Using bisection method, function loops until desired precision is met */
	/*Finding first positive root to e^-4 precision*/
	while (fabs(f(x)) > 1.e-4)
	{
	x = .5 * (x_l + x_u);
		if (f(x) > 0)
			x_l = x;
		else
			x_u = x;

	printf("%f      %.5e\n", x_l, f(x_l));
	}

	x_l = 1.5;
	x_u = 2;
	x = .5 * (x_l + x_u);
	printf("2nd Root         f(x)\n");
	/*Finding second positive root to e^-4 precision*/
	while (fabs(f(x)) > 1.e-4)
	{
	x = .5 * (x_l + x_u);
		if (f(x) < 0)
			x_l = x;
		else
			x_u = x;

	printf("%f      %.5e\n", x_l, f(x_l));
	}

return 0;

}