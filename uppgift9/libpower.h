/**
 * @file libpower.h
 * @author Madeleine Stein
 * @brief Function for calculate power
 */

#ifndef POWER_H_
#define POWER_H_

/**
 * @brief Calculate power from resistance
 * @param volt       The voltage (V)
 * @param resistance The resistance (Ohm)
 * @return The calculated power in watt (W)
 */
float calc_power_r(float volt, float resistance);

/**
 * @brief Calculate power from current
 * @param volt       The voltage (V)
 * @param current The resistance in ampere (A)
 * @return The calculated power in watt (W)
 */
float calc_power_i(float volt, float current);

#endif /* POWER_H_ */
