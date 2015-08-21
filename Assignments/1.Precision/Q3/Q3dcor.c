#include <stdio.h>
#include <math.h>

int main(){
float n, m;
double p, q, r, sum, othersum, sum1, othersum1, difference, difference1;
int i, array[] = {100, 1000, 10000, 100000, 1000000, 10000000, 100000000};

for (i = 0; i < 6; i++) {
	p = array[i];
	
	for (n = 1; n <= array[i]; n++) {
		sum += (1/n);
		}

	for (m = array[i]; m >= 1; m--) {
		othersum += (1/m);
		}

	for (r = array[i]; r >=1; r--) {
		othersum1 += (1/r);
		}
	
	for (q = 1; q <= array[i]; q++) {
		sum1 += (1/q);
		}

	difference1 = sum - sum1;
	difference = othersum - othersum1;

	printf("The precision of the float to the double summing from 1 to %d is %1.8e. \n", array[i], difference);	

	printf("The precision of the float to the double summing down from %d to 1 is %1.8e. \n", array[i], difference1);

}
return 0;
}
