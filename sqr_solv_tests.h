#ifndef SQR_SOLV_TESTS_H_
#define SQR_SOLV_TESTS_H_

#include <stdio.h>
#include <math.h>
#include "sqr_solv_processing.h"
#include "sqr_solv_structs.h"


struct Unit_Test_Data
{
    int test_num;      ///<
    double sqr_x_coef; ///<
    double x_coef;     ///<
    double free_coef;  ///<
    double discr_exp;  ///<
    double root_1_exp; ///<
    double root_2_exp; ///<
    int root_num_exp;  ///<
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
