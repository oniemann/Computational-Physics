#include<stdio.h>
#include<math.h>

double f(double x)
{
	return -pow(x, 3);
}

int main()
{
	int i, j, n;
	double x, v, T, t, h, exact, en, f();
	printf("\nTime    Energy    Deviation\n");

	x = 1; // initializes x = 1
	v = 0; //initializes v = 0
	T = 7.416; //Taken from assignment 3, question 6
	h = 0.02 * T; //defines the time steps
	int period[3] = {1, 10, 100}; //how many periods which will be run
	exact = 0.25;

	for (i = 0; i < 3; i++)
	{
		n = period[i] * T / h;

		printf("Number of periods: %d\n", period[i]);
		
		t = 0;

		for(j = 0; j < n; j++)
		{
			if(en < pow(2,31) -1)
			{ 
				x += .5 * h * v;
				v += h * f(x);
				x += .5 * h * v;

				en = .5 * pow(v, 2) + .25 * pow(x, 4);
				t += h;
				printf("%.5f   %.5e   %.5e\n",  t, en, (en-exact));
			}
			else
				break;
		}
	}

return 0;
}