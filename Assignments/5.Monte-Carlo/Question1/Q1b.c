#include <stdio.h>
#include <math.h>
#include <stdlib.h>


int main()
{
	int N = 12;
	int M = 10000;
	int i, j, k;
	double x[N], Y, moment;

for(k = 1; k < 7; k ++)
{
	moment = 0;

	for( j = 0; j < M; j++)
	{
		Y = 0;

		for(i = 0; i < N; i++)
		{
			x[i] = rand() / (RAND_MAX + 1.0);

			Y += sqrt(12 / N) * (x[i] - 0.5);
		}

		moment += pow(Y, k) / M;
	}
	
	printf("<X^%d> = %f\n", k, moment);
}

return 0;
}