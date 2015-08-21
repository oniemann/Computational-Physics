#include <stdio.h>
#include <math.h>

int main() {
	double n, phi_0 = 1, phi_1 = (sqrt(5)-1)/2, phi_ho; 
	for (n = 0; n < 50; n++) {
		if (n < 1){       /* Defines the phi raised to the zeroeth power */
			phi_ho = phi_0;
		}
		else if (n < 2){
			phi_ho = phi_1;
		}
		else {
			phi_ho = phi_0 - phi_1;   /* Establishes recursive relationship*/
			phi_0 = phi_1;
			phi_1 = phi_ho;
		}
		printf("The recursive formula yields %.5e for term %.0f. \n", phi_ho, n+1);
	}
}