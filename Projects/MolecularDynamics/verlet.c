#include<stdio.h>
#include<math.h>

verlet(int N, double h, double x[], double v[], double f(double))
{
	int i;

	//half steps of x
	for(i = 0; i < N; i++)
	{
		x[i] += 0.5 * h * v[i];
	}

	//Because v[N] = v[0], need to run both v[0] and v[N-1] outside of the "for" loop
	v[0] += h * (f(x[0] - x[1]) - f(x[N-1] - x[0]));
	
	for(i = 1; i < N - 1; i++)
	{
		v[i] += h * (f(x[i] - x[i+1]) - f(x[i-1] - x[i]));
	}
	
	v[N-1] += h * (f(x[N-1] - x[0]) - f(x[N-2] - x[N-1]));

	//Finds position x[i] with updates on velocity v[i]
	for(i = 0; i < N; i++)
	{
		x[i] += h * v[i]; 
	}
}

double v2(double v_sq, double v[])
{
	int i, N;

	N = 30;
	//computes <v^2> for each time step
	for(i = 0; i < N; i++)
	{
		v_sq += v[i]*v[i];
	}

	return v_sq/N;
}
