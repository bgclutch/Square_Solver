#ifndef SQR_SOLV_PROCESSING_H_
#define SQR_SOLV_PROCESSING_H_

#include <stdio.h>
#include <math.h>
#include "sqr_solv_inp.h"
#include "sqr_solv_structs.h"

/**
 * @brief checking a digit to zero
 * 
 * @param comparable comparable digit  
 * @return true 
 * @return false
 * @warning comparing to 0.001 const 
 */
bool is_zero(const double comparable);

/**
 * @brief square equation solving
 * 
 * @param coefficients equation coefficients, part of Equation_Coefficients_Data  
 * @param *equation_parts memory address of equation parts, part of Equation_Attributes_Data
 */
void square_equ_solver(const Equation_Coefficients_Data coefficients,
                       Equation_Attributes_Data *equation_parts);

/**
 * @brief lineal equation solving
 * 
 * @param free_coef free coef of equation 
 * @param x_coef coefficient belongs x 
 * @param *root_1 memory address of root  
 * @param *equation_parts memory address of equation parts, part of Equation_Attributes_Data 
 */
void lineal_equ_solver(const double free_coef, const double x_coef,
                       double *root_1, Equation_Attributes_Data *equation_parts);

/**
 * @brief fix -0 root
 * 
 * @param root checking variable  
 * @return fixed root
 */
double fix_root_minus_zero(double root);

/**
 * @brief placing smaller root to root_1
 * 
 * @param *root_1 address of root_1 
 * @param *root_2 address of root_2 
 */
void is_min(double *root_1, double *root_2);

/**
 * @brief swapping digits by byte blocks
 * 
 * @param *var_1 first swapping digit memory address 
 * @param *var_2 second swapping digit memory address
 * @param size sizeof type of variable
 */
void my_swap(void* var_1, void* var_2, int size);

#endif //SQR_SOLV_PROCESSING_H_
