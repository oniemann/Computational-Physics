#include<stdio.h>
#include<math.h>

#include<stdio.h>
#include<math.h>

//establishes function for the derivatives of x and p
void derivs(double t, double x[], double dxdt[])
{
	dxdt[0] = x[1];           //dxdt = p
	dxdt[1] = -x[0]*x[0]*x[0];  //dpdt = -x^3
}

//establishes function for Runge-Kutta Method  2
void rk2 (double t, double x[], void derivs(double, double[], double[]), double h, int M) 
{
 
	double k1[M], k2[M], xp[M];
	int i;

	derivs(t, x, k1); 
// compute k1[i] (= derivs at (t, x) )
 
	for (i=0; i < M; i++) 
		xp[i] = x[i] + h * k1[i]; 
// xp = x + h*k1

 	derivs(t+h, xp, k2); 

// compute k2[i] (= derivs at (t+h, x+h*k1) )
 
	for(i=0; i < M; i++) 
		x[i] += 0.5 * h * (k1[i] + k2[i]); 
// compute x[i]
}

main()
{
 
	int M = 2; 
// specify the no. of variables
 
	double x[M], h, T, t, n, total_time, en, exact; 
// x is an array of size M
 
	void derivs(); 
// derivs computes the derivatives
 
	int i, j;

// maximum amplitudes which will be applied to rk2

	printf("\nTime    Energy    Deviation\n");

	x[0] = 1;
	x[1] = 0; //initializes p = 0
	T = 7.416; //Taken from assignment 3, question 6
	h = 0.02 * T; //defines the time steps
	n = T / h;
	int period[3] = {1, 10, 100}; //how many periods which will be run
	exact = 0.25;

	for (i = 0; i < 3; i++)
	{
		n = period[i] * T / h;
		printf("Number of periods: %d\n", period[i]);
		t = 0;

		for(j = 0; j < n; j++)
		{
			if(en < 2e31 -1)
			{ 
			rk2(t, x, derivs, h, M);
			en = .5*x[1]*x[1] + .25*pow(x[0], 4);
			t += h;
			printf("%.5f   %.5e   %.5e\n",  t, en, (en-exact));
			}
			else
				break;
		}
	}

return 0;
}