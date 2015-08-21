#include <stdio.h>
#include <math.h>

int main(){
double i, j, phi;

for (i=1; i <= 51; i++){  /* Set n equal to the desired term */
	if (i <= 1) {
		j= i;
	}
	else {
	phi= (sqrt(5)-1)/2;
	j *= phi;
	}
	printf("The value of the golden mean to the power of %.0f is %.5e.\n", i-1, j);
}

}
