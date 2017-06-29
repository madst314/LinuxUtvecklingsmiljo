/**
 *  * Name uppgift6_test.c
 *   * This script aims to test the application in uppgift6
 *    *
 *     * Author: Madeleine Stein
 *      * Date: 2017-06-29
 *       */

#include <stdio.h>
#include <string.h>
#include "CUnit/Basic.h"

#include "uppgift6/libcomponent.h"
#include "uppgift6/libpower.h"
#include "uppgift6/libresistance.h"

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
   const float volt = 7;
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
   libpowerSuite = CU_add_suite("Suite_1", init_libpowerSuite, clean_libpowerSuite);
   if (NULL == libpowerSuite) {
      CU_cleanup_registry();
      return CU_get_error();
   }

   /* add the tests to the suite */
   /* NOTE - ORDER IS IMPORTANT - MUST TEST fread() AFTER fprintf() */
   if ((NULL == CU_add_test(libpowerSuite, "test 1", testlibpower_GIVEN_current_THEN_returnPower)))
      //||
      //       //(NULL == CU_add_test(libpowerSuite, "test of fread()", testFREAD)))
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
