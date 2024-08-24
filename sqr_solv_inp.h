#ifndef SQR_SOLV_INP_H_
#define SQR_SOLV_INP_H

#include <stdio.h>
#include <math.h>

#include "sqr_solv_structs.h"


#define EPSILON 0.001

int read_nums(Equation_Coefficients_Data *coefficients);

bool buff_clean_and_check();

int for_input(double *coef, int counter);

void greetings();

int continue_or_finish();

#endif //SQR_SOLV_INP_H_
