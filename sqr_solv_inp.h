#ifndef SQR_SOLV_INP_H_
#define SQR_SOLV_INP_H

#include <stdio.h>
#include <math.h>

#define EPSILON 0.001

enum NumRoots
{
    UNEXISTING_ROOTS = 0,
    ONE_ROOT         = 1,
    TWO_ROOTS        = 2,
    INF_ROOTS        = 3,
};

struct Unit_Test_Data
{
    int test_num;
    double sqr_x_coef;
    double x_coef;
    double free_coef;
    double discr_exp;
    double root_1_exp;
    double root_2_exp;
    int root_num_exp;
};

struct Equation_Coefficients_Data
{
    double sqr_x_coef;
    double x_coef;
    double free_coef;
};

struct Equation_Attributes_Data
{
    double discr;
    double root_1;
    double root_2;
    NumRoots root_number;
};

int read_nums(Equation_Coefficients_Data *coefficients);

bool buff_clean_and_check();

int for_input(double *coef, int counter);

int continue_or_finish();

#endif //SQR_SOLV_INP_H_
