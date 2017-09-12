/**
 *  Name libresistance_test.h
 *  This script aims to test the libresistance library.
 *
 *  Author: Madeleine Stein
 *  Date: 2017-07-18
 */

#include <stdio.h>
#include <string.h>
#include "CUnit/Basic.h"

int init_libresistanceSuite(void);
int clean_libresistanceSuite(void);

void testlibresistance_GIVEN_twoParalellResistances_THEN_returnExpectedResistance(void);
void testlibresistance_GIVEN_twoSerialResistances_THEN_returnExpectedResistance(void);
void testlibresistance_GIVEN_negativeSerialResistance_THEN_returnErrorVal(void);
void testlibresistance_GIVEN_emptyResistanceArray_THEN_returnErrorVal(void);
void testlibresistance_GIVEN_invalidCircuitType_THEN_returnErrorVal(void);
void testlibresistance_GIVEN_negativeNumResistances_THEN_returnErrorVal(void);
