#ifndef SQR_SOLV_OUTP_H_
#define SQR_SOLV_OUTP_H_

#include <stdio.h>
#include <math.h>
#include "sqr_solv_processing.h"
#include "sqr_solv_structs.h"

/**
 * @brief equation printing
 * 
 * @param coefficients equation coefficiens, part of Equation_Coefficients_Data 
 * @param equation_parts equation roots and discriminant, part of Equation_Attributes_Data 
 */
void equation_print(const Equation_Coefficients_Data coefficients,      
                    const Equation_Attributes_Data equation_parts);
/**
 * @brief equation roots printing
 * 
 * @param equation_parts equation_parts equation roots and discriminant, part of Equation_Attributes_Data 
 */
void result_print (Equation_Attributes_Data equation_parts);

#endif //SQR_SOLV_OUTP_H_
