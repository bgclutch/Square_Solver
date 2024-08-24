#ifndef SQR_SOLV_INP_H_
#define SQR_SOLV_INP_H

#include <stdio.h>
#include <math.h>

#include "sqr_solv_structs.h"


#define EPSILON 0.001

/**
 * @brief reading equations coefficients    
 * 
 * @param *coefficients address of equation coefficients from Equation_Coefficients_Data 
 * @return '3' for right input
 * 
 * '0' for stop program
 */
int read_nums(Equation_Coefficients_Data *coefficients);

/**
 * @brief returning buffer cleaning result
 *   
 * '0' code means cleaning operations
 *  
 * '1' code means cleaning operations    
 * 
 * @return true 
 * @return false 
 */
bool buff_clean_and_check();

/**
 * @brief checking input 
 * 
 * @param *coef coefficient's placement in memory
 * @param counter number of input iteration 
 * @return number of right inputed coefficients
 */
int for_input(double *coef, int counter);

/**
 * @brief greetings output 
 * 
 */
void greetings();

/**
 * @brief asking for continue or finish symbol 
 * 
 * @return digit-code of continue or finish  
 */
int continue_or_finish();

#endif //SQR_SOLV_INP_H_
