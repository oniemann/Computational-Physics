#include<stdio.h>
#include<math.h>

void rk2(double t, double x, double p, double h)
{

	double k1x, k1p, k2x, k2p;

	k1x = p;
	k1p = -pow(x,3);
	k2x = k1x + h * k1p;
	k2p = (k1p + h*k1x);
	x += .5 * h * (k1x + k2x);
	p += .5 * h * (k1p + k2p);
}



main()
{
	double t, x, p, h, tn, t0, xnew;
	int n, i, j;
	void rk2();

	t0 = 0;
	n = 20;
	h = 0.1;
	x = .1;
	p = 0;
	t = t0;

	for (i = 0; i < n; i++)
	{
		rk2(t, x, p, h);

		if (x > 0)
		{
			t += h;
			printf("%f\n", t);
		}
		else
			return t;
	}

printf("%f", t);


return 0;
}