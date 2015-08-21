#include<stdio.h>
#include<math.h>

//declares desired function
double f(double x)
{
	return 1 / (1 + x*x*x);
}

//Simpson's rule
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

	a = 0;          //lower bound
	b = 2.0;		//upper bound
	EPS = 1.e-6;	//desired precision
	ans = 1.e50;	//starting point to keep below loop running
	
	n = 1;

	/*iterates Simpson's rule with a greater number of measuring points
	until desired precision is achieved.*/
	while (fabs(ans - prevans) > EPS) {
		
		h = (b - a) / n;
		prevans = ans;
		
		ans = simp(f, a, b, n);
		n *= 2;							
		//printf("%12.9f %14.6f \n", h, ans);
	}
	 printf("integral = %.6f \n", ans);
}