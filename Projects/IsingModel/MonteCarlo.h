#include <stdio.h>
#include <math.h>
#include <time.h>
#include <stdlib.h>


//initializes spin lattice
double initialize(double currentT, int L, double S[L][L])
{
	double T_Crit =2.269;
	int i, j;

	if(currentT < T_Crit)               //if T < critical temperature, all spins are parallel
	{
		for(i = 0; i < L; i++)
		{
			for(j = 0; j < L; j++)
			{
				S[i][j] = 1.;
			}
		}
	}
	
	else                          //if T > crit temp, randomizes all spins
	{
		for(i = 0; i < L; i++)
		{
			for(j = 0; j < L; j++)
			{
				if(rand() / RAND_MAX < 0.5)
					S[i][j] = 1.;
				else
					S[i][j] = -1.;
			}	
		}
		
	}
}

//calculates the average magnetization of the lattice at any given timestep
double avgmagnetization(int N, int L, double S[L][L]) 
{
	int i, j;
	double m_avg = 0;

	for(i = 0; i < L; i++)
		for(j = 0; j < L; j++)
			m_avg += 1. * S[i][j];
	
	double m_sq = m_avg * m_avg;

	return m_sq; 
}

//updates the lattice, which has periodic boundary conditions for both i and j axes
double update(int L, double S[L][L], double prob[17])
{
	int ir, i, il, ju, j, jd, val, E;
	double r;

	il = L - 2;
	i = L - 1;
	ju = L - 2;
	j = L - 1;


	for(ir = 0; ir < L; ir++)      //loops through, updating each spin state in the lattice
	{
		for(jd = 0; jd < L; jd++)
		{
			r = rand() / (RAND_MAX + 1.);
			E = 2 * S[i][j] * (S[ir][j] + S[il][j] + S[i][jd] + S[i][ju]);

			if(r < prob[E + 8])            //compares generated random number to the implemented detailed balance condition
			{
				S[i][j] = -S[i][j];
			}

			ju = j;
			j = jd;
		}


		il = i;
		i = ir;
	}
}