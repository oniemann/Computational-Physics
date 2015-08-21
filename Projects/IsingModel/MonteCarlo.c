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
	int N = L * L;			             //total number of spins in L x L lattice
	int t_eq = 4 * L * L;		         //number of sweeps for equilibriation period
	int N_UP = 4 * 4 * L * L;	         //number of sweeps for measuring period
	double TMAX = 4; 			         //maximum temperature to be measured
	double T_Crit = 2.269;		         //given critical temperature
	double M_MEAS = N_UP * T_RUNS;       //total times <m^2> is measured for each temperature

	double m_sq, m_squ, S[L][L], avgm, m_sqavg, m_frth, m_frthavg, E, currentT, r, prob[17];
	
	srand(time(NULL));			//initializes random number generator

	FILE* fout;

	fout = fopen("isingmodel16.txt", "w");

	fprintf(fout, "Temperature   <m^2>     errorbar  errorbarx5  xaxis    yaxis\n");

clock_t start = clock();

for(currentT = 0.01; currentT <= TMAX; currentT += 0.01)
{
	for(val = -8; val <= 8; val+=2)
	{
		prob[val + 8] = exp(-val / currentT);    //creates 9 possible values of (delta)E
	}											//placed in this location to reduce computation time

	initialize(currentT, L, S);                       //initializes lattice
	m_sqavg = 0;
	m_frthavg = 0;

	for(k = 0; k < T_RUNS; k++)                 //loops ising model simulation T_RUNS times
	{
		m_squ = 0;
		m_frth = 0;

		for(z = 0; z < t_eq; z++)
			update(L, S, prob);   			//equilibriation period

		for(t = 0; t < N_UP; t++)
		{
			update(L, S, prob);   			     //updates lattice using Monte Carlo technique
			m_sq = avgmagnetization(N, L, S);	 //calculates average magnetization per spin

			m_squ += m_sq / N_UP;			     //calculates m^2 of all updates
			m_frth += m_sq * m_sq / N_UP;  
		}
		m_sqavg += m_squ / T_RUNS;               //calculates <m^2> for each temperature
		m_frthavg += m_frth / T_RUNS;            //calculates <m^4> for each temperature
	}

	//prints T, <m^2>, and each error bar 
	fprintf(fout, "%f    %f   %f\n", currentT, m_sqavg / (N*N), sqrt((m_frthavg/(N*N*N*N) - m_sqavg * m_sqavg/(N*N*N*N))/ sqrt(T_RUNS*N_UP - 1)));

	double percentage = currentT / TMAX * 100;
	printf("%.1f%%\n", percentage);
}

clock_t end = clock();
double elapsed_time = (end-start)/(double)CLOCKS_PER_SEC;
printf("Computation Time: %f.3\n", elapsed_time);             //computes time taken to run code

return 0;
}