#include <stdio.h>
#include <math.h>

int main(){
float n, m, p, sum, othersum, difference;
int i, array[6] = {100, 1000, 10000, 100000, 1000000, 10000000};

for (i = 0; i<6; i++) {
	p = array[i];

	for (n = 1; n <= array[i]; n++) {
		sum += (1/n);
		}
	for (m = array[i]; m >= 1; m--) {
		othersum += (1/m);
		}
	difference = sum - othersum;
	printf("The difference (error) between S(up) and S(down) for range(1, %d) is %f.\n", array[i], difference);
}
return 0;
}
