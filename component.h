/*
 * Filename: component.h
 * Project: linUMU6
 * Description: Headerfile :)
 *
 * Created on: Nov 6, 2015
 * Author: Fredrik Vestberg
 *
 */

#ifndef COMPONENT_H_ // Guard
#define COMPONENT_H_

	// Returns the number of objects in res_array and sets res_array
	// with (up to three) E12 resistors needed to replace original resistance
	extern int e_resistance(float orig_resistance, float *res_array);

#endif /* COMPONENT_H_ */
