#include<stdio.h>
#include<math.h>

double f(double x) {
	//double pow(double i, double j);
	//double sqrt(double i);
	return 1 / sqrt( x * (0.685 + 0.315 * pow(x,-3) + (9 * pow(10,-5)) * pow(x,-4)));
				/* where a value equals "theta," place value for theta_m */
}

double trap (double f(double), double a, double b, int n) {
double h, sum;
int i;

h = (b - a) / n;                                      
sum = 0.5 * (f(a) + f(b));                            
	for (i = 1; i < n; i++) sum += f(a + i * h);  
		return h * sum;                       
}

int main() {
	double x, a, b, h, exact, ans, prevans, EPS, sum, trap(), omega;
	int i, j, n;

	a = 0;
	b = 1;
	EPS = 1.e-7;
	ans = 1.e50;
	printf ("Integral function: %.5f\n", f(x));
	printf ("Lower Bound: %.5f\n", a);
	printf ("Upper Bound: %.5f\n", b);
	printf ("       h         ans         precision\n");
	
	n = 1;

	while (fabs(ans - prevans) > EPS) 
	{
		
		h = (b - a) / n;
		prevans = ans;
		
		ans = trap(f, a, b, n);
		n *= 2;
		
	}
	printf("%12.9f %.5f %.5e \n", h, ans, (ans - prevans));
		
}

