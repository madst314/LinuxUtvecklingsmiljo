/**
 *  Name libresistance_test.c
 *  This script aims to test the libresistance library.
 *
 *  Author: Madeleine Stein
 *  Date: 2017-07-18
 */

#include <stdio.h>
#include <string.h>
#include "CUnit/Basic.h"

#include "uppgift6/libresistance.h"

/** Function Definitions **/

int init_libresistanceSuite(void)
{
      return CUE_SUCCESS;
}

int clean_libresistanceSuite(void)
{
      return CUE_SUCCESS;
}

void testlibresistance_GIVEN_twoParalellResistances_THEN_returnExpectedResistance(void)
{
   const float count = 2;
   const char conn = 'p';
   const float array[2] = {2.0f, 4.0f};
   const float expectedresistance = 0.75f;

   const float resistance = calc_resistance(count, conn, &array[0]);

   CU_ASSERT_EQUAL(resistance, expectedresistance);
}

int main()
{
   CU_pSuite libresistanceSuite = NULL;

   /* initialize the CUnit test registry */
   if (CUE_SUCCESS != CU_initialize_registry())
      return CU_get_error();

   /* add a suite to the registry */
   libresistanceSuite = CU_add_suite("libresistance_Suite", init_libresistanceSuite, clean_libresistanceSuite);
   if (NULL == libresistanceSuite) {
      CU_cleanup_registry();
      return CU_get_error();
   }

   /* add the tests to the suite */
   if ((NULL == CU_add_test(libresistanceSuite, "testlibresistance_GIVEN_current_THEN_returnresistance", testlibresistance_GIVEN_twoParalellResistances_THEN_returnExpectedResistance)))
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
