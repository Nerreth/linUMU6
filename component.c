/*
 * Filename: component.c
 * Project: linUMU6
 * Description: a function which calculates which (up to three) resistors in
 * 				series of the E12-series are the best replacement for a given
 * 				resistance.
 *
 * Created on: Nov 5, 2015
 * Author: Fredrik Vestberg
 *
 */

#include "component.h"


// Prototypes
int getMultiplier(float remaining_resistance);

/*
 * e_resistance takes the supplied orig_resistance and finds up to three E12 resistors
 * that will be able to replace the original, or at least somewhat close enough.
 * @param orig_resistance (float)The original resistance, which we want to replace.
 * @param *res_array (pointer)The E12 resistors used to replace the original.
 * @return (int)The number of E12 resistors used.
 */
int e_resistance(float orig_resistance, float *res_array)
{
	// Declare and initiate variables
	float e12resistors[12] = { 1.0, 1.2, 1.5, 1.8, 2.2, 2.7, 3.3, 3.9, 4.7, 5.6, 6.8, 8.2 }; // E12 resistors 1-8.2 ohm
	int e12resistorsInt[12] = { 10, 12, 15, 18, 22, 27, 33, 39, 47, 56, 68, 82 }; // E12 resistors > 10-82 ohm
	int multiplier = 1; // E12 comes in series in the power of 10
	float replaced_resistance = 0; // Replaced resistance
	float remaining_resistance = orig_resistance; // Remaining resistance
	int arrayindex = 0; // The index of the array
	int resistor = 0; // Resistor number(index)
	int resistors = 0; // Number of E12 resistors used

	// Loop though the number of E12 resistors we are allowed to use(3)
	// Unable to use (int)(sizeof(res_array) / sizeof(res_array[0])) since res_array is just a pointer and would only give size of the pointer itself
	for (resistor = 0; resistor < 3; resistor++)
	{
		// Values used in the nested loop, let's set them here to have them reset on every cycle
		replaced_resistance = 0; // The resistance of the highest matching E12 resistor we used
		multiplier = getMultiplier(remaining_resistance); // Get the highest possible multiplier we can fit within the remaining resistance

		// Loop to find which E12 resistor we will use
		for (arrayindex = 0; arrayindex < (int)(sizeof(e12resistors) / sizeof(e12resistors[0])); arrayindex++)
		{
			// Ugly hack because float is not exact and math.h is c99
			if (multiplier >= 10)
			{
				// Check if this resistor will fit within the remaining resistance
				if (e12resistorsInt[arrayindex] * multiplier / 10 <= remaining_resistance) // e12resistorsInt is power of 10, lets divide by 10 to get normal
				{
					// It fits, lets set the replaced_resistance to it's resistance
					replaced_resistance = e12resistorsInt[arrayindex] * multiplier / 10; // e12resistorsInt is power of 10, lets divide by 10 to get normal
				}
				else // We can not find any more E12 resistors that would fit within the remaining resistance
				{
					// We are done here, exit the loop
					break;
				}
			}
			else // No need for float precision hack here
			{
				// Check if this resistor will fit within the remaining resistance
				if (e12resistors[arrayindex] * multiplier <= remaining_resistance)
				{
					// It fits, lets set the replaced_resistance to it's resistance
					replaced_resistance = e12resistors[arrayindex] * multiplier;
				}
				else
				{
					// We are done here, exit the loop
					break;
				}
			}
		}
		// Set the array position 'resistor' to the value of the E12 resistor we found would fit
		res_array[resistor] = replaced_resistance;
		// Subtract the resistance from the E12 resistor we found would fit, from the remaining resistance
		remaining_resistance -= replaced_resistance;
	}

	// Loop to count the number of resistors used, value '0' is a resistor not used
	for (resistor = 0; resistor < 3; resistor++)
	{
		// Check if we used this resistor
		if (res_array[resistor] > 0)
		{
			// We did use this resistor, increment the counter
			resistors++;
		}
	}
	// Return the number of resistors
	return resistors;
}

/*
 * Checks how high multiplier(power of 10) that can be used with the remaining
 * resistance, and then returns the result
 * @param remaining_resistance (float)The remaining resistance
 * @return (int)The multiplier that will be used(1, 10, 100, 1000 etc)
 */
int getMultiplier(float remaining_resistance)
{
	// Declare and initiate
	int multiplier = 1; // Starting point

	// Loop to find highest possible multiplier
	while (multiplier < remaining_resistance)
	{
		// Check if we can go higher
		if (multiplier * 10 <= remaining_resistance)
		{
			// We could, set the new multiplier
			multiplier *= 10;
		}
		else // We could not go higher
		{
			// We are done here, exit the loop
			break;
		}
	}
	// Return the multiplier
	return multiplier;
}
