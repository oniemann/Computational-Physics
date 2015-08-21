#include <stdio.h>
#include <math.h>

int main(){

float i;
float epsilon = 1;

for (i=0; i<100; i++) {
	float x = 1 - epsilon, y = 1 - x;
	if (y > 0) {
		epsilon *= .1;
		printf("%.5e, %.5e, %.5e\n", epsilon, x, y);
	}
	else {
		break;
	}
}
printf("Floats have a precision of 1.00000e-8.\n");
}
