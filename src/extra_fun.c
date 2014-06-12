#include<stdio.h>
#include<stdbool.h>
#include "extra_fun.h"

int read_float(char *line, int *char_counter, float *float_ptr)         
{
	char *ptr = line + *char_counter;
	unsigned char c;

	// Grab first character and increment pointer. No spaces assumed in line.
	c = *ptr++;

	// Capture initial positive/minus character
	bool isnegative = false;
	if (c == '-') {
		isnegative = true;
		c = *ptr++;
	} else if (c == '+') {
		c = *ptr++;
	}

	// Extract number into fast integer. Track decimal in terms of exponent value.
	int intval = 0;
	int exp = 0;
	int ndigit = 0;
	bool isdecimal = false;
	while(1) {
		c -= '0';
		if (c <= 9) {
			ndigit++;
			if (ndigit <= MAX_INT_DIGITS) {
				if (isdecimal) { exp--; }
				intval = (((intval << 2) + intval) << 1) + c; // intval*10 + c
			} else {
				if (!(isdecimal)) { exp++; }  // Drop overflow digits
			}
		} else if (c == (('.'-'0') & 0xff)  &&  !(isdecimal)) {
			isdecimal = true;
		} else {
			break;
		}
		c = *ptr++;
	}

	// Return if no digits have been read.
	if (!ndigit) { return(false); };

	// Convert integer into floating point.
	float fval;
	fval = (float)intval;

	// Apply decimal. Should perform no more than two floating point multiplications for the
	// expected range of E0 to E-4.
	if (fval != 0) {
		while (exp <= -2) {
			fval *= 0.01; 
			exp += 2;
		}
		if (exp < 0) { 
			fval *= 0.1; 
		} else if (exp > 0) {
			do {
				fval *= 10.0;
			} while (--exp > 0);
		} 
	}

	// Assign floating point value with correct sign.    
	if (isnegative) {
		*float_ptr = -fval;
	} else {
		*float_ptr = fval;
	}

	*char_counter = ptr - line - 1; // Set char_counter to next statement

	return(true);
}
