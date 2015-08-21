#include <stdio.h>
#include <math.h>

double f(double x)
{
	return log10(x);
}

main()
{
	int i, exponent, argument = 50000;
	double factorial, logfactorial, mantissa;

	//computes log base 10 of the factorial
	for(i = argument; i > 0; i--)
	{
		logfactorial += f(i);         
	}

	
	printf("log(%d!) = %f  \n", argument, logfactorial);

	exponent = logfactorial;                 //computes the exponent of scientific notation 
	mantissa = logfactorial - exponent;		 //finds what's "left over" after subtracting exponent from log
	factorial = pow(10, mantissa);			//raises  the "leftovers" by a power of 10 to find coefficient

	printf("%d! = %f + 10^%d\n", argument, factorial, exponent);

return 0;
}