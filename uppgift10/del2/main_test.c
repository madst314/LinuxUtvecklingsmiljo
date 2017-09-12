
#include <stdio.h>
#include <string.h>
#include <CUnit/Basic.h>
#include <CUnit/TestDB.h>

#include "libpower_test.h"
#include "libresistance_test.h"
#include "libcomponent_test.h"

int main()
{
   /* initialize the CUnit test registry */
   if (CUE_SUCCESS != CU_initialize_registry())
      return CU_get_error();

   /* add the tests to the suite */
   CU_TestInfo libpower_tests[] = {
      {"testlibpower_GIVEN_current_THEN_returnPower", testlibpower_GIVEN_current_THEN_returnPower},
      {"testlibpower_GIVEN_ZeroCurrent_THEN_returnZero", testlibpower_GIVEN_ZeroCurrent_THEN_returnZero},
      {"testlibpower_GIVEN_ZeroVoltage_THEN_returnZero", testlibpower_GIVEN_ZeroVoltage_THEN_returnZero},
      {"testlibpower_GIVEN_NegativeCurrent_THEN_returnInvalid", testlibpower_GIVEN_NegativeCurrent_THEN_returnInvalid},
      {"testlibpower_GIVEN_NegativeVoltage_THEN_returnInvalid", testlibpower_GIVEN_NegativeVoltage_THEN_returnInvalid},
      {"testlibpower_GIVEN_voltage_AND_resistance_THEN_returnPower", testlibpower_GIVEN_voltage_AND_resistance_THEN_returnPower},
      {"testlibpower_GIVEN_voltage_AND_ZeroResistance_THEN_returnInvalid",testlibpower_GIVEN_voltage_AND_ZeroResistance_THEN_returnInvalid},
      {"testlibpower_GIVEN_resistance_AND_ZeroVoltage_THEN_returnZero", testlibpower_GIVEN_resistance_AND_ZeroVoltage_THEN_returnZero},
      {"testlibpower_GIVEN_voltage_AND_NegativeResistance_THEN_returnInvalid", testlibpower_GIVEN_voltage_AND_NegativeResistance_THEN_returnInvalid},
      {"testlibpower_GIVEN_resistance_AND_NegativeVoltage_THEN_returnInvalid", testlibpower_GIVEN_resistance_AND_NegativeVoltage_THEN_returnInvalid},
      CU_TEST_INFO_NULL,
   };

   CU_TestInfo libresistance_tests[] = {
      {"testlibresistance_GIVEN_twoParalellResistances_THEN_returnExpectedResistance",
         testlibresistance_GIVEN_twoParalellResistances_THEN_returnExpectedResistance},
      {"testlibresistance_GIVEN_twoSerialResistances_THEN_returnExpectedResistance",
         testlibresistance_GIVEN_twoSerialResistances_THEN_returnExpectedResistance},
      {"testlibresistance_GIVEN_negativeSerialResistance_THEN_returnErrorVal",
         testlibresistance_GIVEN_negativeSerialResistance_THEN_returnErrorVal},
      {"testlibresistance_GIVEN_emptyResistanceArray_THEN_returnErrorVal",
         testlibresistance_GIVEN_negativeSerialResistance_THEN_returnErrorVal},
      {"testlibresistance_GIVEN_invalidCircuitType_THEN_returnErrorVal",
         testlibresistance_GIVEN_invalidCircuitType_THEN_returnErrorVal},
      {"testlibresistance_GIVEN_negativeNumResistances_THEN_returnErrorVal",
         testlibresistance_GIVEN_negativeNumResistances_THEN_returnErrorVal},
      CU_TEST_INFO_NULL,
   };

   CU_TestInfo libcomponent_tests[] = {
      {"testlibcomponent_GIVEN_resistance_THEN_return_e_resistance", testlibcomponent_GIVEN_resistance_THEN_return_e_resistance},
      {"testlibcomponent_GIVEN_zero_resistance_THEN_return_zero", testlibcomponent_GIVEN_zero_resistance_THEN_return_zero},
      {"testlibcomponent_GIVEN_negative_resistance_THEN_return_zero", testlibcomponent_GIVEN_negative_resistance_THEN_return_zero},
      CU_TEST_INFO_NULL,
   };


   /* add a suite to the registry */
   CU_SuiteInfo suites[] = {
      {"libpower_Suite", init_libpowerSuite, clean_libpowerSuite, libpower_tests},
      {"libresistance_Suite", init_libresistanceSuite, clean_libresistanceSuite, libresistance_tests},
      {"libcomponent_Suite", init_libcomponentSuite, clean_libcomponentSuite, libcomponent_tests},
      CU_SUITE_INFO_NULL,
   };

   /* Run all tests using the CUnit Basic interface */
   CU_register_suites(suites);
   CU_basic_set_mode(CU_BRM_VERBOSE);
   CU_basic_run_tests();
   CU_cleanup_registry();
   return CU_get_error();
}
