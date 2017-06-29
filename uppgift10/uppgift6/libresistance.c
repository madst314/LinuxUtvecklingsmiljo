/**
 * @file libresistance.c
 * @author Arvid Axelsson
 * @brief Calculate equivalent resistance of several parallel or serial
 *        connected resistances.
 */
#include "libresistance.h"

static const float errorval = -1.0f;
static const float eps = 1e-5f;

static float parallel(int count, const float *array)
{
	double sum_inverses = 0.0;
	for (int i = 0; i < count; ++i) {
		if (array[i] < 0.0) return errorval;
		if (array[i] < eps) return 0.0f;
		sum_inverses += 1.0 / array[i];
	}
	return 1.0 / sum_inverses;
}

static float series(int count, const float *array)
{
	double sum = 0.0;
	for (int i = 0; i < count; ++i) {
		if (array[i] < 0.0) return errorval;
		sum += array[i];
	}
	return sum;
} 

float calc_resistance(int count, char conn, const float *array)
{
	if (!array) {
		return errorval;
	}
	float equivalent = 0.0f;

	// Parallel connection 
	if (conn == 'p' || conn == 'P') {
		equivalent = parallel(count, array);
	// Series connection
	} else if (conn == 's' || conn == 'S') {
		equivalent = series(count, array);
	} else {
		return errorval;
	}
	return equivalent;
}

