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
 
	double t, x[M], h, tn, t0, en; 
// x is an array of size M
 
	void derivs(); 
// derivs computes the derivatives
 
	int n, i, j, k;

	double x_max[3] = {0.1, 1, 10};
// maximum amplitudes which will be applied to rk2

for (k = 0; k < 3; k++)
{
	x[0] = x_max[k];
	//implements maximum amplitude

	printf("\nMaximum amplitude: %.2f\n", x[0]);
	printf(" Time   Position  Momentum\n");
	
	x[1] = 0; //initializes p = 0
	t0 = 0; 
	n = 50000; //number of steps
	h = .001; //length of each step
	t = t0;

	/*loop below identifies where the first root of the oscillating
	function is located, which can then be multiplied by four to find
	the length of its period.*/

	for (i = 0; i < n; i++)
	{
		rk2(t, x, derivs, h, M); 
		// Call RK2
		if (x[0] >= 0)
		{
			t += h;
		}
		else
			break;
	}

	/*now that the period is found, can define tn and subsequently h*/

	tn = 4 * t;
	n = 50;
	t0 = 0;
	h = (tn - t0) / n;
	t = t0;

	for (j = 0; j < n; j++)
	{
		//Calls rk2
		rk2(t, x, derivs, h, M);
		//increments time by h until full period is reached
		t += h;
		printf("%.3f   %.3f   %.3f\n", t, x[0], x[1]);
 	}
}

return 0;
}