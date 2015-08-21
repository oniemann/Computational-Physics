#include<stdio.h>
#include<math.h>

double f(double x, double y)
{
	return -(x / pow(x*x + y*y, 1.5));
}

double g(double x, double y)
{
	return -(y / pow(x*x + y*y, 1.5));
}

double leapfrogx(double n, double h, double x, double y, double v_x, double f(double, double))
{
	x += .5 * h * v_x;
	v_x += h * f(x, y);
	x += .5 * h * v_x;
}

double leapfrogy(double n, double h, double x, double y, double v_y, double g(double, double))
{
	y += .5 * h * v_y;
	v_y += h * g(x, y);
	y += .5 * h * v_y;
}


int main()
{
	int i, j;
	double L, en, r, t, period, h, n, x, y, v_x, v_y, f(), g(), leapfrogy(), leapfrogx();
	FILE* fout;

	fout = fopen("wienerslolololo.txt", "w");  //exports output to .txt
	x = 1;
	y = 0; 
	v_x = 0;                             //initial conditions
	v_y = 0.7;
	period = 2 * M_PI / 1.8555;
	h = 0.002 * period;                          //time step
	n = period / h;                      //number of time steps
	t = 0;
	fprintf(fout, "%f\n", n);
	fprintf(fout,"t          ang. momentum \n");

	for (i = 0; i < n; i++)
	{
		x += .5 * h * v_x;            //leapfrog for both x and y components
		y += .5 * h * v_y;
		v_x += h * f(x, y);
		v_y += h * g(x, y);
		x += .5 * h * v_x;
		y += .5 * h * v_y;

		r = pow(x*x  + y*y, 0.5);      //changes coordinates to r
		en = .5 * (v_x*v_x + v_y*v_y) + 1 / r;           //energy
		t += h;
		L = x * v_y - y * v_x;

		fprintf(fout,"%f   %.16f\n", t, L);
	}
	fclose(fout);
}