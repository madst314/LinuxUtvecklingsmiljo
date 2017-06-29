/**
 * @file libcomponent.c
 * @author Marcus Valtonen Örnhag
 * @brief Function for counting resistance.
 */

#include "libcomponent.h"

/* All values available in E12 series (range from 10 Ohm to 1 MOhm) */
float e12_resistors[NBR_E12] =
    {10e0, 12e0, 15e0, 18e0, 22e0, 27e0, 33e0, 39e0, 47e0, 56e0, 68e0, 82e0,
     10e1, 12e1, 15e1, 18e1, 22e1, 27e1, 33e1, 39e1, 47e1, 56e1, 68e1, 82e1,
     10e2, 12e2, 15e2, 18e2, 22e2, 27e2, 33e2, 39e2, 47e2, 56e2, 68e2, 82e2,
     10e3, 12e3, 15e3, 18e3, 22e3, 27e3, 33e3, 39e3, 47e3, 56e3, 68e3, 82e3,
     10e4, 12e4, 15e4, 18e4, 22e4, 27e4, 33e4, 39e4, 47e4, 56e4, 68e4, 82e4,
     10e5};

/**
 * @brief Get the closest e12 resistance.
 * @param resistance The resistance to approximate.
 * @param closest The closest (but not larger) resistance (out param)
 * @return 0 if resistance found, -1 otherwise
 */
static int find_closest_e12(float resistance, float *closest) {
    int ret = -1;

    for (int i = NBR_E12-1; i >= 0; i--) {
        if (e12_resistors[i] <= resistance) {
            *closest = e12_resistors[i];
            ret = 0;
            break;
        }
    }

    return ret;
}

/*
 * Calculate replacement resistance of up to three E12 resistors in series.
 */
int e_resistance(float orig_resistance, float *res_array ) {

    /*
     * The algorithm below is very basic and always returns a value lower
     * than or equal to the replacement resistance. It is a naive approach
     * but very straight forward.
     *
     * Algorithm:
     * Pick the element closest to the replacement resistance without
     * exceeding it. Then pick the closest one to the remainder, etc. If the
     * sum of the resistances at some point is equal stop.
     *
     * Floating point precision is not taken into account in the calculations.
     */

    int used_resistors = 0;

    int ret = 0;
    float remainder = orig_resistance;

    while (ret >= 0 && remainder > e12_resistors[0]) {
        ret = find_closest_e12(remainder, &res_array[used_resistors]);
        remainder -= res_array[used_resistors];
        used_resistors++;
    }

    /*
     * Check if we did not need all resistors, then fill up the remaining
     * with zeros.
     */
    for (int i = used_resistors; i < 3; i++) {
        res_array[i] = 0;
    }

    return used_resistors;
}
