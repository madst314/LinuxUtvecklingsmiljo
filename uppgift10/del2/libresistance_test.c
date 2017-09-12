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

#include "libresistance_test.h"
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
   const float sum_inverses = (1.f / array[0]) + (1.f / array[1]);
   const float expectedresistance = 1.f / sum_inverses;

   const float resistance = calc_resistance(count, conn, &array[0]);
   CU_ASSERT_EQUAL(resistance, expectedresistance);
}

void testlibresistance_GIVEN_twoSerialResistances_THEN_returnExpectedResistance(void)
{
   const float count = 2;
   const char conn = 's';
   const float array[2] = {2.0f, 4.0f};
   const float expectedresistance = 6.f;

   const float resistance = calc_resistance(count, conn, &array[0]);

   CU_ASSERT_EQUAL(resistance, expectedresistance);
}

void testlibresistance_GIVEN_negativeParallelResistance_THEN_returnErrorVal(void)
{
   const float count = 2;
   const char conn = 'p';
   const float array[2] = {-2.0f, 4.0f};
   const float expectedresistance = -1.0f;

   const float resistance = calc_resistance(count, conn, &array[0]);

   CU_ASSERT_EQUAL(resistance, expectedresistance);
}

void testlibresistance_GIVEN_negativeSerialResistance_THEN_returnErrorVal(void)
{
   const float count = 2;
   const char conn = 's';
   const float array[2] = {-2.0f, 4.0f};
   const float expectedresistance = -1.0f;

   const float resistance = calc_resistance(count, conn, &array[0]);

   CU_ASSERT_EQUAL(resistance, expectedresistance);
}

void testlibresistance_GIVEN_emptyResistanceArray_THEN_returnErrorVal(void)
{
   const float count = 2;
   const char conn = 's';
   const float *array = NULL;
   const float expectedresistance = -1.0f;

   const float resistance = calc_resistance(count, conn, &array[0]);

   CU_ASSERT_EQUAL(resistance, expectedresistance);
}

void testlibresistance_GIVEN_invalidCircuitType_THEN_returnErrorVal(void)
{
   const float count = 2;
   const char conn = 'i';
   const float array[2] = {2.0f, 4.0f};
   const float expectedresistance = -1.0f;

   const float resistance = calc_resistance(count, conn, &array[0]);

   CU_ASSERT_EQUAL(resistance, expectedresistance);
}

void testlibresistance_GIVEN_negativeNumResistances_THEN_returnErrorVal(void)
{
   const float count = -2;
   const char conn = 's';
   const float array[2] = {2.0f, 4.0f};
   const float expectedresistance = -1.0f;

   const float resistance = calc_resistance(count, conn, &array[0]);

   CU_ASSERT_EQUAL(resistance, expectedresistance);
}
