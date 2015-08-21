#include <stdio.h>
#include <math.h>
#include <time.h>
#include <stdlib.h>

int main()
{
	int i, t, NUMSTEPS;
	srand(time(NULL));
	float array[10] = {10, 50, 100, 200, 500, 1000, 10000, 100000, 1000000, 10000000};
	double xavg[10], x2avg[10], epsilon;

	for( i = 0; i < 10; i ++)
	{
		NUMSTEPS = array[i];                      //sets number of steps

		for(t = 0; t < NUMSTEPS; t++)
		{
			epsilon = rand()/(RAND_MAX + 1.0);    //generates random number

			if(epsilon < 0.5)
				epsilon = -1.0;		
			else if(epsilon > 0.5)			//decides whether to take a step to left/right
				epsilon = 1.0;
			else
				continue;

			xavg[i] += epsilon;      //calculates <x> per number of steps
			x2avg[i] += epsilon * epsilon;      //calculates <x^2>

		}
	}

	printf("# Steps        <x>         <x>/Steps          <x^2>\n");
	
	for(i = 0; i < 10; i++)
	{
		printf("%.0f         %f           %f         %.0f\n", array[i], xavg[i], xavg[i] / array[i], x2avg[i]);
	}

return 0;	
}