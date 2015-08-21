#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int N = 1000;

main()
{
	int k, i, j, mid, x_l, x_h;
	double x[N], y, temp, f();

	//Generates N random numbers
	for(k = 0; k < N; k++) 
		x[k] = rand() / (RAND_MAX + 1.0);
   
	//Sorts random numbers in order from least to greatest
	for(i = 0; i < N - 1; i++)
	{
		for(j = 0; j < (N - 1 - i); j++)
		{
			if(x[j] > x[j + 1])
			{
				temp = x[j];
				x[j] = x[j+1];
				x[j + 1] = temp;
			}
			else
				continue;
		}
	}

	printf("Sorted Numbers:\n");

	for (i =0; i < 5; i++)
		printf("%f\n", x[i]);

	printf("  ...  \n");

	for(i = N-5; i < N; i++)
		printf("%f\n", x[i]);

	printf("\n");

	x_l = 0;
	x_h = N-1;

	//Uses the bisection method to find which elements of the array satisfy conditions
	while(x_h - x_l > 1)
	{
		mid = (x_h + x_l) / 2;

		if (x[mid] < 0.7)
			x_l = mid + 1;

		else if(x[mid] > 0.7)
			x_h = mid - 1;
	}

	/*+= 1 in printf statements take into account that the while statement above runs one more time 
	  than needed before terminating*/
	printf("Closest number below 0.7:  %f \n", x[x_l - 1]); 
    printf("Closest number above 0.7:  %f \n", x[x_h + 1]);
		
return 0;
}