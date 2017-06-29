/**
 * @file main.c
 * @brief Program to test all the functionality of the shared libraries.
 */

#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>

#include "libresistance.h"
#include "libcomponent.h"
#include "libpower.h"

/**
 * @brief Read if connection is in parallell or series from stdin.
 * @return S or P depending on user's choice.
 */
static char read_conn_type(void);

/**
 * @brief Read a positive integer from stdin.
 * @return A valid integer.
 */
static int read_positive_int(void);

/**
 * @brief Extra test cases for E12 resistance.
 * @param orig_resistance The resistance to replace with E12's.
 */
static void test_case_e12(float orig_resistance);

/*
 * Main program.
 */
int main(void) {

    printf("Ange spänningskälla i V: ");
    float voltage = (float)read_positive_int();

    char conn = read_conn_type();

    printf("Antal komponenter: ");
    int nbr_components = read_positive_int();

    float *resistors = malloc(sizeof(float) * nbr_components);

    for (int i = 0; i < nbr_components; i++) {
        printf("Komponent %d ohm: ", i+1);
        resistors[i] = (float)read_positive_int();
    }

    float equiv = calc_resistance(nbr_components, conn, resistors);
    printf("Ersättningsresistans:\n%.1f ohm\n", equiv);

    float power_r = calc_power_r(voltage, equiv);
    printf("Effekt:\n%3.2f W\n", power_r);

    float *e_res = malloc(sizeof(float) * 3);
    int count = e_resistance(equiv, e_res);
    printf("Ersättningsresistanser i E12-serien kopplade i serie:\n");
    for (int i = 0; i < count; i++) {
        printf("%g\n", e_res[i]);
    }
    free(e_res);

    /* Some test cases for E12 replacements */
    /*
    printf("\n");
    test_case_e12(1398.0f);
    test_case_e12(15.0f);
    test_case_e12(11234.0f);
    test_case_e12(9.0f);
    test_case_e12(24512.0f);
    test_case_e12(14.0f);
    */

    return 0;
}

/*
 * Extra test cases for E12 resistances.
 */
static void test_case_e12(float res) {
    float *arr = malloc(sizeof(float) * 3);
    printf("Target resistance: %3.1f\n", res);
    printf("count is %d\n", e_resistance(res, arr));
    printf("\t res 1: %3.1f\n", arr[0]);
    printf("\t res 2: %3.1f\n", arr[1]);
    printf("\t res 3: %3.1f\n", arr[2]);
    printf("\t ---------------\n");
    printf("\t sum:   %3.1f\n\n", arr[0]+arr[1]+arr[2]);
    free(arr);
}

/*
 * Read integer from stdin. Not fool-proof since e.g.
 * 123abc would be accepted as 123.
 */
static int read_positive_int(void) {
    int res = 0;
    int output = -1;

    while (res <= 0 || output <= 0) {
        res = scanf("%d", &output);
        if (res == 0 || output <= 0) {
            while (fgetc(stdin) != '\n') ;
            printf("Ange ett positivt heltal: ");
        }
    }
    return output;
}

/*
 * Read charcters from stdin. Accept S or P only.
 */
static char read_conn_type(void) {
    char choice;

    do {
        printf("Ange koppling[S | P]: ");
        scanf(" %c", &choice);
        fflush(stdin);
        choice = toupper(choice);
    } while (choice != 'S' && choice != 'P');
    return choice;
}

