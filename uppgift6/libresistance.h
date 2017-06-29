/**
 * @file libresistance.h
 * @author Arvid Axelsson
 * @brief Find equivalent resistance of parallel or serial connected resistances.
 */

#ifndef RESISTANCE_H
#define RESISTANCE_H

/**
 * @brief Equivalent resistance of parallel or serial connected resistances.
 * @param count The number of connected resistances.
 * @param conn Should be 'S' or 'P' to indicate serial or parallel connection.
 * @param array Array of values of the resistances.
 * @return Value of the equivalent resistance.
 */

float calc_resistance(int count, char conn, const float *array);

#endif

