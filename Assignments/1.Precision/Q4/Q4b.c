#include <stdio.h>
#include <math.h>

int main() {
	float n, phi_0 = 1, phi_1 = (sqrt(5)-1)/2, phi_ho; 
	for (n = 1; n<=50; n++) {
		if (n <= 1){
			phi_ho = n;
		}
		else {
			phi_ho = phi_0 - phi_1;
			phi_0 = phi_1;
			phi_1 = phi_ho;
		}
		printf("The recursive formula shows %f for the %fth term. \n", phi_ho, n);
	}
}