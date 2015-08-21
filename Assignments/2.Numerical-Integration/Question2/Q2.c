#include<stdio.h>
#include<math.h>

double f(double x)
{
	return exp(-x)*sin(x);
}

double simp(double f(double), double a, double b, int n)
{
	double sum, h;
	int i;
	h = (b - a) / n;
	sum = f(a) + f(b);

	for (i = 0; i < n; i++){
		if (i % 2 == 0){
			sum += 2 * f(a + i * h);
		}
		else {
			sum += 4 * f(a + i * h);
		}
	}
	return h / 3 * sum;
}

int main() {
	double x, a, b, h, exact, ans, prevans, EPS, sum;
	int i, n;

	a = 0;
	b = 2.0;
	EPS = 1.e-8;
	ans = 1.e50;

	printf ("       h         ans\n");
	
	n = 1;

	while (fabs(ans - prevans) > EPS) {
		
		h = (b - a) / n;
		prevans = ans;
		
		ans = simp(f, a, b, n);
		n *= 2;
		printf("%12.9f %14.6f\n", h, ans);
	}
}



