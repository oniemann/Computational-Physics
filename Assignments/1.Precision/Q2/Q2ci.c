#include <stdio.h>
#include <math.h>

int main() {
float j;
float value=1;

for(j=0;j<200; j++){
	if (value > 0){
		value *= .5;
		printf("%f %.5e\n", j, value);
	}
	else {
		break;
	}
}

printf("The smallest value of a float is roughly 1.40e-45.\n");
return 0;
}
