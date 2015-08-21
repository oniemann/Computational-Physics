#include<stdio.h>
#include<math.h>

double f(double x)
{

	return 2 * (14 / 22) * (1 + pow(sin(.1/2), 2)*sin(x) + 3 / 8 * pow(sin(.1/2), 4) * pow(sin(x), 2));
}

double trap (double f(double), double a, double b, int n)
{
double h, sum;
int i, j;

h = (b - a) / n;                                      
sum = 0.5 * (f(a) + f(b));                            
	for (i = 1; i < n; i++) sum += f(a + i * h);  
		return h * sum;                       
}

int main()
{
	int j, n;
	double array[5] = {0.1, 0.2, 22 / 28, 22/14, 66 / 28};
	double ans, prevans, a, b, h, EPS, trap(), theta_m, sum;
	printf("   h       answer       precision \n")
;
		
		a = 0;
		b = 22 / 14;

		n = 1;
		EPS = 1.e-4;
		ans = 1.e5;

		while (fabs (ans-prevans) > EPS)
		{
			h = (b - a) / n;
			prevans = ans;

			ans = trap(f, a, b, n);
			n *= 2;
		}
		printf("%f   %f   %.5e \n", h, ans, (ans-prevans));


return 0;
}



(28 / 22) * (1 + pow(sin(.1/2), 2) * sin(x) + 3 / 8 * pow(sin(.1/2), 4) * pow(sin(x), 2)

(14 / 22) * (1 + sin(.1/2)*sin(theta_m/2)*sin(x) + 3 / 8 * sin(theta_m/2)*sin(theta_m/2)*sin(theta_m/2)*sin(theta_m/2)* sin(x)*sin(x));

(14 / 22) * (1 + sin(.1/2)*sin(.1/2)*sin(x) + 3 / 8 * sin(.1/2)*sin(.1/2)*sin(.1/2)*sin(.1/2)*sin(x)*sin(x))