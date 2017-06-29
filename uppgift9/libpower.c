/**
 * @file libpower.c
 * @author Madeleine Stein
 * @brief Function for calculate power.
 */

#include "libpower.h"

/* calcualte power from resistance */
float calc_power_r(float volt, float resistance){
	return (volt * volt) / resistance;
}

/* calculate power from current */
float calc_power_i(float volt, float current){
	return volt * current;
}
