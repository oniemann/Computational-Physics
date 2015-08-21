#include <stdio.h>
#include <math.h>
#include "verlet.h"


//function represents the force on each particle during simulation
double f(double y)
{
	return -(y + y * y + y * y * y);
}


int main(void)
{
	int N, n, i, j, t, g, T_EQ, T_RUN, bins;
	double h, f(), v_sq, N_U;
	double  v_avg, vsq_avg, vavg_min, vavg_max, v_one;


	FILE* fout;

	fout = fopen("anharmonicpositionvelocity.txt", "w");

	h = 0.02;
	T_EQ = 800;
	N_U = 1 / h;

	//User inputs parameters of program
	printf("How many molecules in the system? ");
	scanf("%d", &N);
	printf("How many timesteps? ");
	scanf("%d", &T_RUN);
	printf("Amongst how many bins should the velocities be distributed? ");
	scanf("%d", &bins);
	

	double x[N], v[N], vavg_array[T_RUN], bin_val[bins], v_bins[bins], width, gaussian[bins];
	width = 6.0 / bins;

	//gives each particle in the system an initial velocity/displacement
	for(n = 0; n < N; n++)
	{
		v[n] = sin(2*M_PI*((double)n + 1.3) / (double)N);
		x[n] = 0;
		//fprintf(fout, "%f   %f\n", x[n], v[n]);
	}
	

	//below loop puts the system into equilibrium
	for(t = 0; t <= T_EQ; t++)
	{	
		for(j = 0; j < N_U; j++)
		{
			verlet(N, h, x, v, f);
		}		
	}

	//runs the system and begins to record velocities	
	for(t = 0; t < T_RUN;  t++)
	{	
		v_one = 0;
		v_sq = 0;
		
		//updates particles' positions and velocities N_U times per second
		for(i = 0; i < N_U; i++)
		{
			verlet(N, h, x, v, f);
		}

		//distributes all velocities into the bins
		CreateBins(N, bins, width, v, bin_val, v_bins);


		//computes <v^2> for each time step
		for(i = 0; i < N; i++)
		{
			v_sq += v[i] * v[i] / (double)N;
		}
		
		//computes the average of all <v^2>
		vsq_avg += v_sq/T_RUN;
	}

	double Norm = 0, AREA_GAUSS = 0, AREA_BINS = 0;

	//finds the normalization constant to fit the outputted data to a normalized gaussian curve
	for(i = 0; i <= bins; i++)
		Norm += width * v_bins[i];

	fprintf(fout, "T = %f\nNormalization Constant = %f\n\n", vsq_avg, Norm);
	fprintf(fout, "     v        P(v)     Gaussian Fit\n");

	//Computes the gaussian fit for each bin based off <v^2> and prints normalized frequency data
	for(i = 0; i <= bins; i++)
	{
		gaussian[i] =  ((1 / sqrt(2 * M_PI * vsq_avg)) * exp(-(bin_val[i] * bin_val[i]) / (2 * vsq_avg)));

		//calculates the area underneath each normalized function for every bin
		AREA_GAUSS += gaussian[i] * width;
		AREA_BINS += (v_bins[i] / Norm) * width;

		fprintf(fout, "%f   %f    %f\n", bin_val[i], v_bins[i] / Norm, gaussian[i]);
	}

	fprintf(fout, "\nArea under normalized velocity distribution = %f\n", AREA_BINS); 
	fprintf(fout, "Area under gaussian distribution = %f\n", AREA_GAUSS);

return 0;
}