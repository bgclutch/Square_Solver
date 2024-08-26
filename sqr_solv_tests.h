#ifndef SQR_SOLV_TESTS_H_
#define SQR_SOLV_TESTS_H_

#include <stdio.h>
#include <math.h>
#include "sqr_solv_processing.h"
#include "sqr_solv_structs.h"

/**
 * @brief data for unit tests  
 */
struct Unit_Test_Data
{
    int test_num;      ///< number of test
    double sqr_x_coef; ///< sqr_x_coef
    double x_coef;     ///< x_coef
    double free_coef;  ///< free_coef
    double discr_exp;  ///< expected discriminant
    double root_1_exp; ///< expected root_1
    double root_2_exp; ///< expected root_2
    int root_num_exp;  ///< expected number of roots
};

/**
 * @brief testing function with sructures 
 * 
 * @param test structure array from Unit_Test_Data  
 * @return digit-code 
 */
int Solving_Tests(Unit_Test_Data test);

/**
 * @brief calls for solving tests, contains structure array  
 * 
 */
void Unit_Tests();


#endif //SQR_SOLV_TESTS_H_
