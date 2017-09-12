/**
 *  Name libpower_test.h
 *  This script aims to test the libpower library
 *
 *  Author: Madeleine Stein
 *  Date: 2017-06-29
 */

#include <stdio.h>
#include <string.h>
#include "CUnit/Basic.h"

int init_libpowerSuite(void);
int clean_libpowerSuite(void);

void testlibpower_GIVEN_current_THEN_returnPower(void);
void testlibpower_GIVEN_ZeroCurrent_THEN_returnZero(void);
void testlibpower_GIVEN_ZeroVoltage_THEN_returnZero(void);
void testlibpower_GIVEN_NegativeCurrent_THEN_returnInvalid(void);
void testlibpower_GIVEN_NegativeVoltage_THEN_returnInvalid(void);
void testlibpower_GIVEN_voltage_AND_resistance_THEN_returnPower(void);
void testlibpower_GIVEN_voltage_AND_ZeroResistance_THEN_returnInvalid(void);
void testlibpower_GIVEN_resistance_AND_ZeroVoltage_THEN_returnZero(void);
void testlibpower_GIVEN_voltage_AND_NegativeResistance_THEN_returnInvalid(void);
void testlibpower_GIVEN_resistance_AND_NegativeVoltage_THEN_returnInvalid(void);
