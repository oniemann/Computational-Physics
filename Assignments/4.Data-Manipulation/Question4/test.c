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
 
	double k1[M], k2[M], k3[M], k4[M], xp[M];
	int i;

	derivs(t, x, k1); 
// compute k1[i] (= derivs at (t, x) )
 
	for (i=0; i < M; i++) 
		xp[i] = x[i] + h / 2 * k1[i]; 

	for(i=0; i<M; i++)
		xp[i] = x[i] + h / 2 * k2[i];

	for(i=0; i<M; i++)
		xp[i] = x[i] + h * k3[i];
// xp = x + h*k1

 	derivs(t+h, xp, k4); 

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


	x[0] = 1;
	//implements maximum amplitude	
	x[1] = 0; //initializes p = 0
	h = .1;
	n = 1 / h;

	for (j = 0; j < n; j++)
		{
			//Calls rk2
			rk2(t, x, derivs, h, M);
			//increments time by h until full period is reached
			t += h;
			printf("%.3f   %.3f   %.3f\n", t, x[0], x[1]);
 		}

return 0;
}