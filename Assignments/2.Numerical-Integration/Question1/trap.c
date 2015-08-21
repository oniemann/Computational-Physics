#include<stdio.h>
#include<math.h>

double trap (double f(double), double a, double b, int n)
{
double h, sum;
int i;

h = (b - a) / n;                                      
sum = 0.5 * (f(a) + f(b));                            
	for (i = 1; i < n; i++) sum += f(a + i * h);  
		return h * sum;                       
}
