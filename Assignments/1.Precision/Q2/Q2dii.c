#include <stdio.h>
#include <math.h>

int main(){

double i;
double epsilon = 1;

for (i=0; i<100; i++) {
	double x = 1 - epsilon;
	double y = 1 - x;
	if (y > 0) {
		epsilon *= .1;
		printf("%.5e, %.5e, %.5e\n", epsilon, x, y);
	}
	else {
		break;
	}
}
printf("Doubles have a precision of about 1.00000e-17.\n");
}
