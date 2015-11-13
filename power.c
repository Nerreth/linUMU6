#include <stdio.h>



float calc_power_r(float volt, float resistance){

 	float p = (volt*volt) / resistance;

	return p;
}

float calc_power_i(float volt, float current){

	float p = volt * current;

	return p;
}


