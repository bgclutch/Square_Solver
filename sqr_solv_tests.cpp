#include <stdio.h>
#include <math.h>

#include "sqr_solv_tests.h"

int Solving_Tests(Unit_Test_Data test)
{
    struct Equation_Coefficients_Data coefficients =
        {
          .sqr_x_coef = test.sqr_x_coef,
          .x_coef = test.x_coef,
          .free_coef = test.free_coef
        };

    struct Equation_Attributes_Data equation_parts =
        {
          .discr = NAN,
          .root_1 = NAN,
          .root_2 = NAN,
          .root_number = UNEXISTING_ROOTS
        };

    square_equ_solver(coefficients, &equation_parts);

    if(test.root_num_exp != equation_parts.root_number || fabs(equation_parts.discr - test.discr_exp) > EPSILON || (equation_parts.root_1 - test.root_1_exp) > EPSILON ||
      (equation_parts.root_2 - test.root_2_exp) > EPSILON)
    {
        printf(YELLOW_TEXT("Calculation error in test ") RED_TEXT("%d") BLUE_TEXT(":\nwith sqr_x_coef = ") GREEN_TEXT("%lg ") 
               BLUE_TEXT("\nx_coef = ") GREEN_TEXT("%lg ") BLUE_TEXT("\nfree_coef = ") GREEN_TEXT("%lg ") BLUE_TEXT ("\n\n") YELLOW_TEXT("expected:") "\n"
               BLUE_TEXT("discriminant = ") GREEN_TEXT("%lg ") BLUE_TEXT("\nroot number = ") GREEN_TEXT("%d ") BLUE_TEXT("\nroot_1 = ") GREEN_TEXT("%lg ") BLUE_TEXT("\nroot_2 = ") GREEN_TEXT("%lg ") "\n\n"
               YELLOW_TEXT("printed:\n") BLUE_TEXT("discriminant = ") RED_TEXT("%lg ") BLUE_TEXT("\nroot_number = ") RED_TEXT("%d ") BLUE_TEXT("\nroot_1 = ") RED_TEXT("%lg ") BLUE_TEXT("\nroot_2 = ") RED_TEXT("%lg") "\n",
               test.test_num, test.sqr_x_coef, test.x_coef, test.free_coef, test.discr_exp, test.root_num_exp,
               test.root_1_exp, test.root_2_exp,
               equation_parts.discr, equation_parts.root_number, equation_parts.root_1, equation_parts.root_2);
        return 0;
    }
    else
    {
        printf(BLUE_TEXT("Test %d is ") GREEN_TEXT("done") "\n", test.test_num);
        return 1;
    }
}


void Unit_Tests()
{
    struct Unit_Test_Data testing_data_array[] =
    {  //  #,    x^2,    x,  fr_co,         D,        x1,        x2,         root_num
         { 1,     0,     0,      0,       NAN,       NAN,       NAN,        INF_ROOTS},
         { 2,     0,     0,      3,       NAN, INF_ROOTS, INF_ROOTS, UNEXISTING_ROOTS},
         { 3,    -4,     3,      8,       137,    -1.088,     1.838,                2},
         { 4,     1,     6,      9,         0,        -3,       NAN,                1},
         { 5,     1,     0,    -16,        64,        -4,         4,                2},
         { 6, 1.674, 673.5,     -5, 453635.73,  -402.337,     0.007,                2},
         { 7,    16,   128, -872.7,   72236.8, -  12.399,     4.399,                2},
         { 8,    10,   -57,   -672,     30129,    -5.829,    11.529,                2},
         { 9,    10,   -57,    672,    -23631,       NAN,       NAN,                0},
         {10,     0,     5, -45.72,       NAN,     9.144,       NAN,                1} //'0' instead of '1'
    };

    printf(BLUE_TEXT("result ") RED_TEXT("%lg ") BLUE_TEXT("means ") YELLOW_TEXT("not existing root") "\n\n"    //unit tests
           BLUE_TEXT("result ") RED_TEXT("%d ") BLUE_TEXT("means ") YELLOW_TEXT("infinity of roots") "\n\n", NAN, INF_ROOTS);
    int test_counter = 0;

    for(unsigned int array_index = 0; array_index < sizeof(testing_data_array) / sizeof(testing_data_array[0]); array_index++)
    {
        test_counter += Solving_Tests(testing_data_array[array_index]);
        printf("\n");
    }


    printf(BLUE_TEXT("%d ") "out of " GREEN_TEXT("%lu ") "tests " GREEN_TEXT("done correct"), test_counter, sizeof(testing_data_array)/sizeof(testing_data_array[0]));
}
