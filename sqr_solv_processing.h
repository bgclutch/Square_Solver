#ifndef SQR_SOLV_PROCESSING_H_
#define SQR_SOLV_PROCESSING_H_

#include <stdio.h>
#include <math.h>
#include "sqr_solv_inp.h"
#include "sqr_solv_structs.h"

/**
 * @brief comparison the number with zero
 * 
 * @param comparable comparable number  
 * @return true 
 * @return false
 * @warning comparing to EPSILON_ZERO const 
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
 * @brief comparison sqr_x_coefficient with abs(1)
 *
 * @return true
 * @return false
 * @warning comparing to EPSILON_ONE const 
 */
bool is_abs_one(const double comparable);


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
 * @brief vectorized swap of numbers
 * 
 * @param *var_1 first swapping number memory address 
 * @param *var_2 second swapping number memory address
 * @param size sizeof type of variable
 */
void my_swap(void* var_1, void* var_2, unsigned long size);

#endif //SQR_SOLV_PROCESSING_H_
