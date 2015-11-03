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

p = volt * current;

return p;
}

int main(int argc, const char * argv[]){
float v,r,c, result;
char power;

printf("Enter R or I: \n");
scanf("%c", &power);

if(power == 'R' || 'r'){

	printf("Enter v and r to calculate p: \n");
	scanf("%f%f", &v, &r);
	result = calc_power_r(v,r);
	printf("p = %f\n", result);
}else if(power == 'I' || 'i'){
	printf("Enter volt and current to calculate p: \n");
	scanf("%f%f", &v, &c);
	result = calc_power_i(v,c);
	printf("p = %f\n", result);
 
}  

}
