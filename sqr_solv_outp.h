#ifndef SQR_SOLV_OUTP_H_
#define SQR_SOLV_OUTP_H_

#include <stdio.h>
#include <math.h>
#include "sqr_solv_processing.h"
#include "sqr_solv_structs.h"

/**
 * @brief equation printing
 * 
 * @param coefficients equation coefficients, part of Equation_Coefficients_Data 
 * @param equation_parts equation roots and discriminant, part of Equation_Attributes_Data 
 */
void equation_print(const Equation_Coefficients_Data coefficients,      
                    const Equation_Attributes_Data equation_parts);


/**
 * @brief equation roots printing
 * 
 * @param equation_parts equation_parts equation roots and discriminant, part of Equation_Attributes_Data 
 */
void result_print (const Equation_Attributes_Data equation_parts);


/**
 * @brief comparing sqr_x_coefficient to abs one (two roots)
 */
void sqr_x_coef_is_abs_one_two_roots(const Equation_Coefficients_Data coefficients);


/**
 * @brief comparing sqr_x_coefficient to abs one (one root)
 */
void sqr_x_coef_is_abs_one_one_root(const Equation_Coefficients_Data coefficients);


/**
 * @brief comparing sqr_x_coefficient to abs one (inf roots)
 */
void sqr_x_coef_is_abs_one_inf_roots(const Equation_Coefficients_Data coefficients);


/**
 * @brief comparing sqr_x_coefficient to abs one (zero roots)
 */
void sqr_x_coef_is_abs_one_zero_roots(const Equation_Coefficients_Data coefficients);


/**
 * @brief print how square solver works
 */
void print_guide();

#endif //SQR_SOLV_OUTP_H_
