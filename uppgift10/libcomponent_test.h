/**
 *  Name libcomponent_test.h
 *  This script aims to test the libcomponent library
 *
 *  Author: Madeleine Stein
 *  Date: 2017-06-29
 */

#include <stdio.h>
#include <string.h>
#include "CUnit/Basic.h"

int init_libcomponentSuite(void);
int clean_libcomponentSuite(void);

void testlibcomponent_GIVEN_resistance_THEN_return_e_resistance(void);
void testlibcomponent_GIVEN_zero_resistance_THEN_return_zero(void);
void testlibcomponent_GIVEN_negative_resistance_THEN_return_zero(void);
