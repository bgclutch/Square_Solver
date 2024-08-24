#ifndef SQR_SOLV_PROCESSING_H_
#define SQR_SOLV_PROCESSING_H_

#include <stdio.h>
#include <math.h>
#include "sqr_solv_inp.h"
#include "sqr_solv_structs.h"

bool is_zero(const double comparable);

void square_equ_solver(const Equation_Coefficients_Data coefficients,
                       Equation_Attributes_Data *equation_parts);

void lineal_equ_solver(const double free_coef, const double x_coef,
                       double *root_1, Equation_Attributes_Data *equation_parts);

double fix_root_minus_zero(double root);

void is_min(double *root_1, double *root_2);

void my_swap(void* var_1, void* var_2, int size);

#endif //SQR_SOLV_PROCESSING_H_
