#include<stdio.h>
#include<math.h>

double f(double x), 
{
	return 1 / (1+x);
}

double trap (double f(double), double a, double b, int n)
{
double h, sum;
int l;

h = (b - a) / n;                                      
sum = 0.5 * (f(a) + f(b));                            
	for (l = 1; l < 5; l++) sum += f(a + l * h);  
		return  = h * sum;                       
}


int main()
{
	double x, a, b, h, exact, ans;
	int i, j, k, l;

	b = 1.0;
	a = 0;
	int array[5][5];
	T(i, j) = 4 * (array[i][j-1] - array[i-1][j-1])/(pow(4, i) - 1)

	for (k = 0; k < 5; k++)
		table [k][0] = trap(f, a, b, n)
	for (j = 1; j < 5; j++){
		for (i = j ; i <  5; i++)
			array[i][j] = T(i, j)

	}
printf ("%d \n", array[i][j])
}


	for (iter = 0; iter < ITERMAX; iter++) {
		h = (b - a) / n;
		ans = trap (f, a, b, n);
		n *= 2;
		printf ("%12.5f %12.5f%12.5f \n", h, ans, (ans-exact)/(h*h));
	}
}
