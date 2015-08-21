#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>

int main()
{
	int i, N = 100000;
	double x[N], value[N], prob;
	srand(time(NULL));

	prob = 0;

	for(i = 0; i < N; i++)
	{
		x[i] = rand() / (RAND_MAX + 1.0);
	

		value[i] = tan(M_PI * x[i]);

		//printf("%f    %f\n", x[i], value[i]);

		if(value[i] < 1.0 && value[i] > -1.0)
			prob += 1.0 / N;
	}

	printf("probability |x| < 1: %f percent\n", prob);
}