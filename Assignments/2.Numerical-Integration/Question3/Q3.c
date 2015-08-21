#include<stdio.h>
#include<math.h>
#include<stdlib.h>

double f(double x)
{
	return exp(-(x*x)/2);
}


double trap (double f(double), double a, double b, int n)
{
	double h, sum;
	int i, l;

	h = (b - a) / n;                                      
	sum = 0.5 * (f(a) + f(b));                            
	for (l = 1; l < n; l++) sum += f(a + l * h);  
		return h * sum;                     
}

int main()
{
	double x, a, b, h, exact, ans, prevans, EPS, array[20][20], trap();
	int i, j, k, l, n;

	b = 1.0;
	a = 0;

	
	n = 1;
	k = 1;
	ans = 1.e5;
	EPS = 1.e-12;

while (fabs(ans - prevans) > EPS){
	prevans = ans;
	for (j = 0; j < k; j++)
	{
		if (j == 0)
		{
			array[k][0] = trap(f, a, b, n);
			printf("n=%d: %.7e  " n, array[k][0]);
		}
		else
		{
			array[k][j] = (pow(4,j)*array[k][j-1] - array[k-1][j-1])/(pow(4, j)-1); 
			printf("%.7e      %.5e", array[k][j], (ans-prevans));
		}
	ans  = array[k][j];
	}
	n *= 2;
	k ++;
	printf("\n");
	}	

return 0;
}