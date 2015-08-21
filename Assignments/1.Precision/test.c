#include <stdio.h>
#include <math.h>

int main() {
float j;
float value=1;

for(j=0; j<200; j++){
	if (value < INFINITY){
		value *= 2;
		printf("%.0f %.5e\n", j, value);
	}
	else {
		break;
	}

}
}
