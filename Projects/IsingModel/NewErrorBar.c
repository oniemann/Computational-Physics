#include <stdio.h>
#include <math.h>
#include <time.h>
#include <stdlib.h>
#include "MonteCarlo.h"


int main()
{
	int L, T_RUNS;

	printf("How many spins in the lattice? ");
	scanf("%d", &L);
	printf("How many times should we run the Ising model? ");
	scanf("%d", &T_RUNS);

	int k, t, i, j, z, val;
	int N = L * L;			     //total number of spins in L x L lattice
	int t_eq = 4 * L * L;		 //number of sweeps for equilibriation period
	int N_UP = 4 * 4 * L * L;	 //number of sweeps for measuring period
	//double TMAX = 4; 			 //maximum temperature to be measured
	double T_Crit = 2.269;		 //given critical temperature
	
	int Temperature, MaxTemperature = 400;          //maximum temperature tested multiplied by 100
	double m_sq, m_sqarray[MaxTemperature][T_RUNS], S[L][L], avgm, m_sqavg[MaxTemperature], E, r, prob[17];
	double M_MEAS = N_UP * T_RUNS;
	srand(time(NULL));			//initializes random number generator

	FILE* fout;

	fout = fopen("isingmodel8.txt", "w");

	fprintf(fout, "Temperature   <m^2>     errorbar  errorbarx5  xaxis    yaxis\n");

clock_t start = clock();

for(Temperature = 0; Temperature < MaxTemperature; Temperature++)
{
	double currentT = (double)Temperature / 100.0 + 0.01;

	for(val = -8; val <= 8; val+=2)
	{
		prob[val + 8] = exp(-val / currentT);           //creates 9 possible values of (delta)E
	}											        //placed in this location to reduce computation time

	initialize(currentT, L, S);                         //initializes lattice

	for(k = 0; k < T_RUNS; k++)                         //loops ising model simulation T_RUNS times
	{
		m_sq = 0;

		for(z = 0; z < t_eq; z++)
			update(L, S, prob);   			//equilibriation period

		for(t = 0; t < N_UP; t++)
		{

			update(L, S, prob);   			//updates lattice using Monte Carlo technique
			avgm = avgmagnetization(N, L, S);	        //calculates average magnetization per spin

			m_sq += avgm * avgm;			        //calculates <m^2> of all updates   
		}

		m_sqarray[Temperature][k] += m_sq / M_MEAS;
		m_sqavg[Temperature] += m_sq / M_MEAS;                       //calculates <m^2> for each temperature
	}

	//fprintf(fout, "%f    %f   %f\n", currentT, m_sqavg / (N*N), sqrt((m_sqavg - m_superavg * m_superavg)/(N*N)) / sqrt(T_RUNS*N_UP - 1));

	double percentage = (double)Temperature / MaxTemperature * 100;
	//printf("%.1f%%  %f  %d    %f\n", percentage, currentT, Temperature, m_sqavg[Temperature] / (N*N));
}

printf("Test");


double s_var[MaxTemperature], errorbar[MaxTemperature];

for(j = 0; j < MaxTemperature; j++)
{
	for(i = 0; i < M_MEAS; i++)
	{
		s_var[j] += 1.0 / M_MEAS * (m_sqarray[j][i] - m_sqavg[j]) * (m_sqarray[j][i] - m_sqavg[j]);    //calculates sample variance for each temperature
	}

	errorbar[j] = s_var[j] / sqrt(M_MEAS - 1);                     //calculates error bar for each temperature

	fprintf(fout, "%f      %f     %f\n", (double)Temperature/100 + 0.01, m_sqavg[j], errorbar[j]);
} 


clock_t end = clock();
double elapsed_time = (end-start)/(double)CLOCKS_PER_SEC;
printf("Computation Time: %f.3\n", elapsed_time);             //computes time taken to run code

return 0;
}