/**
 *  Name libpower_test.c
 *  This script aims to test the libpower library
 *
 *  Author: Madeleine Stein
 *  Date: 2017-06-29
 */

#include <stdio.h>
#include <string.h>
#include "CUnit/Basic.h"

#include "uppgift6/libpower.h"

#include "libpower_test.h"

/** Function Definitions **/

int init_libpowerSuite(void)
{
      return CUE_SUCCESS;
}

int clean_libpowerSuite(void)
{
      return CUE_SUCCESS;
}

/** Test of calc_power_i **/
void testlibpower_GIVEN_current_THEN_returnPower(void)
{
   const float current = 0.5;
   const float volt = 7.f;
   const float expectedPower = 3.5f;

   const float power = calc_power_i(volt, current);

   CU_ASSERT_EQUAL(power, expectedPower);
}

void testlibpower_GIVEN_ZeroCurrent_THEN_returnZero(void)
{
   const float current = 0.f;
   const float volt = 7.f;
   const float expectedPower = 0.f;

   const float power = calc_power_i(volt, current);

   CU_ASSERT_EQUAL(power, expectedPower);
}

void testlibpower_GIVEN_ZeroVoltage_THEN_returnZero(void)
{
   const float current = 0.5f;
   const float volt = 0.f;
   const float expectedPower = 0.f;

   const float power = calc_power_i(volt, current);

   CU_ASSERT_EQUAL(power, expectedPower);
}

void testlibpower_GIVEN_NegativeCurrent_THEN_returnInvalid(void)
{
   const float current = -0.5;
   const float volt = 7.f;
   const float expectedPower = 0.f;

   const float power = calc_power_i(volt, current);

   CU_ASSERT_EQUAL(power, expectedPower);
}

void testlibpower_GIVEN_NegativeVoltage_THEN_returnInvalid(void)
{
   const float current = 0.5;
   const float volt = -7.f;
   const float expectedPower = 0.f;

   const float power = calc_power_i(volt, current);

   CU_ASSERT_EQUAL(power, expectedPower);
}

/** Test of calc_power_r **/
void testlibpower_GIVEN_voltage_AND_resistance_THEN_returnPower(void)
{
   const float resistance = 2.f;
   const float volt = 7.f;
   const float expectedPower = 24.5f;

   const float power = calc_power_r(volt, resistance);

   CU_ASSERT_EQUAL(power, expectedPower);
}

void testlibpower_GIVEN_voltage_AND_ZeroResistance_THEN_returnInvalid(void)
{
   const float resistance = 0.f;
   const float volt = 7.f;
   const float expectedPower = 0.f;

   const float power = calc_power_r(volt, resistance);

   CU_ASSERT_EQUAL(power, expectedPower);
}

void testlibpower_GIVEN_resistance_AND_ZeroVoltage_THEN_returnZero(void)
{
   const float resistance = 0.5f;
   const float volt = 0.f;
   const float expectedPower = 0.f;

   const float power = calc_power_r(volt, resistance);

   CU_ASSERT_EQUAL(power, expectedPower);
}

void testlibpower_GIVEN_voltage_AND_NegativeResistance_THEN_returnInvalid(void)
{
   const float resistance = -0.5;
   const float volt = 7.f;
   const float expectedPower = 0.f;

   const float power = calc_power_r(volt, resistance);

   CU_ASSERT_EQUAL(power, expectedPower);
}

void testlibpower_GIVEN_resistance_AND_NegativeVoltage_THEN_returnInvalid(void)
{
   const float resistance = 0.5;
   const float volt = -7.f;
   const float expectedPower = 0.f;

   const float power = calc_power_r(volt, resistance);

   CU_ASSERT_EQUAL(power, expectedPower);
}
