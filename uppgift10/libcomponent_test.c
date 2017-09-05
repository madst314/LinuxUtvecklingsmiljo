/**
 *  Name libcomponent_test.c
 *  This script aims to test the libcomponent library
 *
 *  Author: Madeleine Stein
 *  Date: 2017-06-29
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "CUnit/Basic.h"

#include "uppgift6/libcomponent.h"

#include "libcomponent_test.h"

/** Function Definitions **/

int init_libcomponentSuite(void)
{
      return CUE_SUCCESS;
}

int clean_libcomponentSuite(void)
{
      return CUE_SUCCESS;
}

/** Tests **/
void testlibcomponent_GIVEN_resistance_THEN_return_e_resistance(void)
{
   const float orig_resistance = 5000.f;
   const int expectcted_resistances = 3;
   float *res_array = malloc(sizeof(float) * 3);

   const int resistance = e_resistance(orig_resistance, res_array);
   free(res_array);

   CU_ASSERT_EQUAL(expectcted_resistances, resistance);
}

void testlibcomponent_GIVEN_zero_resistance_THEN_return_zero(void)
{
   const float orig_resistance = 0.f;
   const int expectcted_resistances = 0;
   float *res_array = malloc(sizeof(float) * 3);

   const int resistance = e_resistance(orig_resistance, res_array);
   free(res_array);

   CU_ASSERT_EQUAL(expectcted_resistances, resistance);
}

void testlibcomponent_GIVEN_negative_resistance_THEN_return_zero(void)
{
   const float orig_resistance = -110.f;
   const int expectcted_resistances = 0;
   float *res_array = malloc(sizeof(float) * 3);

   const int resistance = e_resistance(orig_resistance, res_array);
   free(res_array);

   CU_ASSERT_EQUAL(expectcted_resistances, resistance);
}
