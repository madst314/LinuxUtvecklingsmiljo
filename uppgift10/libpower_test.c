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

/** Function Definitions **/

int init_libpowerSuite(void)
{
      return CUE_SUCCESS;
}

int clean_libpowerSuite(void)
{
      return CUE_SUCCESS;
}

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
   const float current = 0.f;
   const float volt = 7.f;
   const float expectedPower = 0.f;

   const float power = calc_power_i(volt, current);

   CU_ASSERT_EQUAL(power, expectedPower);
}

void testlibpower_GIVEN_NegativeCurrent_THEN_returnInvalid(void)
{
   const float current = -0.5;
   const float volt = 7.f;
   const float expectedPower = 3.5f;

   const float power = calc_power_i(volt, current);

   CU_ASSERT_EQUAL(power, expectedPower);
}

void testlibpower_GIVEN_NegativeVoltage_THEN_returnInvalid(void)
{
   const float current = -0.5;
   const float volt = 7.f;
   const float expectedPower = 3.5f;

   const float power = calc_power_i(volt, current);

   CU_ASSERT_EQUAL(power, expectedPower);
}
int main()
{
   CU_pSuite libpowerSuite = NULL;

   /* initialize the CUnit test registry */
   if (CUE_SUCCESS != CU_initialize_registry())
      return CU_get_error();

   /* add a suite to the registry */
   libpowerSuite = CU_add_suite("libpower_Suite", init_libpowerSuite, clean_libpowerSuite);
   if (NULL == libpowerSuite) {
      CU_cleanup_registry();
      return CU_get_error();
   }

   /* add the tests to the suite */
   if ((NULL == CU_add_test(libpowerSuite, "testlibpower_GIVEN_current_THEN_returnPower", testlibpower_GIVEN_current_THEN_returnPower))
      || (NULL == CU_add_test(libpowerSuite, "testlibpower_GIVEN_ZeroCurrent_THEN_returnZero", testlibpower_GIVEN_ZeroCurrent_THEN_returnZero))
      || (NULL == CU_add_test(libpowerSuite, "testlibpower_GIVEN_ZeroVoltage_THEN_returnZero", testlibpower_GIVEN_ZeroVoltage_THEN_returnZero))
      || (NULL == CU_add_test(libpowerSuite, "testlibpower_GIVEN_NegativeCurrent_THEN_returnInvalid", testlibpower_GIVEN_NegativeCurrent_THEN_returnInvalid))
      || (NULL == CU_add_test(libpowerSuite, "testlibpower_GIVEN_NegativeVoltage_THEN_returnInvalid", testlibpower_GIVEN_NegativeVoltage_THEN_returnInvalid)))
   {
      CU_cleanup_registry();
      return CU_get_error();
   }

   /* Run all tests using the CUnit Basic interface */
   CU_basic_set_mode(CU_BRM_VERBOSE);
   CU_basic_run_tests();
   CU_cleanup_registry();
   return CU_get_error();
}
