#include <stdio.h>
#include <math.h>

int main(){
int i;
double x = 4, f_mid, f_exact, error, h = 1, a, b, c;
for (i = 1; i < 40; i++) {
	a = 1/(1 + x + h);
	b = 1/(1 + x - h);
	c = 1/(1 + x);
	f_mid = (a + b - (2*c))/(pow(h, 2)); /* 2nd derivative as defined in 5a*/
	f_exact = 2 / pow(x+1, 3);			 /* 2nd derivative derived analytically */
	error = (f_mid - f_exact)/pow(h, 2);		
	printf("The error of f_mid''(x) with value h = (%.5e) is %f. \n", h, error);
	h *= .9;
}
	
return 0;
}