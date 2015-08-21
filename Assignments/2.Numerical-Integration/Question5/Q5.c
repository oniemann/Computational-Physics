#include<stdio.h>
#include<math.h>

double f(double x)    /* declares function */
{
	return  2 * sin(x*x) / (x*x);
}

double midpt(double f (double), double a, double b, double n)
{
	double h, sum;
	int i;

	h = (b - a) / n;
	sum = 0;
	for (i = 0; i < n; i++)
	{
		sum += f(a + (h / 2) + i * h);    /* sums each step starting from their midpoints */
	}
	return h * sum;
}

int main() {
	double x, a, b, h, exact, ans, prevans, EPS, sum, midpt();
	int i, n;

	a = 0;
	b = 1.0;
	EPS = 1.e-4;
	ans = 1.e50;

	printf ("       h         ans         (ans - prevans)/h^4\n");
	
	n = 1;

	while (fabs(ans - prevans) > EPS) {      /* compares current and previous result repeatedly until
												desired  precision is achieved */
		h = (b - a) / n;
		prevans = ans;
		
		ans = midpt(f, a, b, n);
		n *= 2;
		printf("%12.9f %14.10f   %.5e \n", h, ans, (ans - prevans));
	}
}