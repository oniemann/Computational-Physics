#include <stdio.h>
#include <math.h>

int main(){
double i;
double value=1;

for(i=0;i<1076; i++){
	if (value > 0){
		value *= .5;
		printf("%f %.5e\n", i, value);
	}
	else {
		break;
	}
}
printf("The smallest value of a double is roughly 4.94e-324.\n");

return 0;
}
