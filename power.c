#include <stdio.h>
#include <math.h>

float p;

float calc_power_r(float volt, float resistance){
float x;
x = powf(volt ,2.00);

p = (float)(x / resistance);

return p;
}

float calc_power_i(float volt, float current){

return 0;
}

int main(int argc, const char * argv[]){
float v,r, result;
char power = 'R';

if(power == 'R'){

	printf("Enter v and r to calculate p: \n");
	scanf("%f%f", &v, &r);
	result = calc_power_r(v,r);
	printf("%f\n", result);
}  

}
