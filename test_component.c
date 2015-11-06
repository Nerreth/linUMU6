/*
 * Filename: test_component.c
 * Project: linUMU6
 * Description: Module to test the libcomponent.so library
 *
 * Created on: Nov 6, 2015
 * Author: Fredrik Vestberg
 *
 * Compile instructions:
 * 		gcc -Wall -shared -fPIC -o libcomponent.so component.c
 * 		gcc -Wall -L. -o test_component test_component.c -lcomponent
 * 		export LD_LIBRARY_PATH=/home/fredrik/workspace/linUMU6:$LD_LIBRARY_PATH
 * 								^^^^^^^^^^^^^^^^^^^^^^^^^^^^^---> change this path
 */

#include <stdio.h> // Needed for printf
#include <stdlib.h> // Needed for the exit code

#include "component.h"

/*
 * A small testing module to test the libcomponent library by asking it to replace a resistance with E12 resistors
 * This is done ten times, and the result is printed in the format
 *
 * Original resistance: 1398		New resistance: 1398
 * res_array[0]: 1200
 * res_array[1]: 180
 * res_array[2]: 18
 * Number of resistors: 3
 *
 * @params - No parameters
 * @return (int)Returns the exit-code, always '0' for now
 */
int main()
{
	// The resistances we want to verify
	float orig_resistance[10] = { 9.9, 2.5, 120, 0, -5, 0.5, 15874, 875998, 1120, 1398 };
	int test = 0; // The number of resistance to verify(index)

	// Loop through the orig_resistance array
	for (test = 0; test < (sizeof(orig_resistance) / sizeof(orig_resistance[0])); test++)
	{
		// Declare and initialize variables
		float res_array[3] = { 0 }; // Storage for the three resistors
		int i = 0; // The individual E12 resistors resistor values(index)
		int count = 0; // The number of E12 resistors used

		// Call the e_resistance function to get back the number of E12 resistors used
		// e_resistance will also store the individual resistors in res_array
		count = e_resistance(orig_resistance[test], res_array);

		// Print the results
		printf("Original resistance: %g\t\tNew resistance: %g\n", orig_resistance[test], res_array[0] + res_array[1] + res_array[2]);
		for (i = 0; i < (sizeof(res_array) / sizeof(res_array[0])); i++)
		{
			printf("res_array[%d]: %g\n", i, res_array[i]);
		}
		printf("Number of resistors: %d\n---------------------------------\n", count);
	}
	exit(EXIT_SUCCESS);
}
