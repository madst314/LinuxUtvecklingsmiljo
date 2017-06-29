/**
 * @file libcomponent.h
 * @author Marcus Valtonen Örnhag
 * @brief Function for counting resistance.
 */

#ifndef COMPONENT_H_
#define COMPONENT_H_

/**
 * @def NBR_E12 61
 * @brief The total number of resistors available in the E12 set.
 */
#define NBR_E12 61

/**
 * @brief Get the closest E12 replacement resistance with up to 3 resistors.
 * @param orig_resistance The resistance to approximate.
 * @param res_array The resulting array of resistances (out param)
 * @return The number of resistors used (between 0-3).
 */
int e_resistance(float orig_resistance, float *res_array );

#endif
