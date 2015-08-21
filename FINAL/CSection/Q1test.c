#include <stdio.h>
#include <math.h>


int  i, j, k, N;
double xdata, ydata, yerrordata, x[10], y[10], yerror[10], U[2][2], v[2], U_inv[2][2], Delta, a[2], sigma[2], f[10], chi_squared;

FILE* fout;

int main()
{
	fout = fopen("questiononedata.txt", "r");
	
	//Imports data
	while(fscanf(fout, "%lf %lf %lf", &xdata, &ydata, &yerrordata) != EOF)
	{
		x[i] = xdata;
		y[i] = ydata;
		yerror[i++] = yerrordata;
	}

	N = 10;

	//Calulates symmetric 2x2 Matrix from x values
	for(i = 0; i < 2; i++)
	{
		for(j = 0; j < 2; j++)
		{
			for(k = 0; k < N; k++)
				U[i][j] += pow(x[k], i+j) / (yerror[k]*yerror[k]);
		}

	}

	//Calculates value needed to find parameters
	for(i = 0; i < 2; i++)
	{
		for(j = 0; j < N; j++)
		{
			v[i] += y[j] * pow(x[j], i) / (yerror[j]*yerror[j]);
		}
	}

	//Determinant of above 2x2 matrix
	Delta = U[0][0]*U[1][1] - U[0][1] * U[0][1];

	//Creates inverse of the above 2x2 matrix
	U_inv[0][0] = U[1][1] / Delta;
	U_inv[0][1] = -U[0][1] / Delta;
	U_inv[1][0] = -U[0][1] / Delta;
	U_inv[1][1] = U[0][0] / Delta;

	//Calculates the two parameters from above inverted matrix and constant
	for(i = 0;  i < 2; i++)
	{
		for(j = 0; j < 2; j++)
		{
			a[i] += U_inv[i][j] * v[j];
		}
	}
	
	//Calculates the error of the parameters
	for(i = 0; i < 2; i++)
	{
		sigma[i] = sqrt(U_inv[i][i]);
	}

	printf("a = %f p/m %f\n", a[0], sigma[0]);
	printf("b = %f p/m %f\n", a[1], sigma[1]);

	//Calculates the chi-squared value per degree of freedom
	for(i = 0; i < N; i++)
	{
		f[i] = a[0] + a[1]*x[i];
		chi_squared += pow(((y[i] - f[i]) / yerror[i]),2);
	}
	
	printf("Chi^2 = %f\n", chi_squared);
	printf("d.o.f. = %d\n", (N-2));
	printf("Chi^2/d.o.f. = %f\n", chi_squared/(N-2));


	fclose(fout);
	
return 0;
}