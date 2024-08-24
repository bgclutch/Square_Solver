#ifndef SQR_SOLV_OUTP_H_
#define SQR_SOLV_OUTP_H_

#include <stdio.h>
#include <math.h>
#include "sqr_solv_processing.h"
#include "sqr_solv_structs.h"


void equation_print(const Equation_Coefficients_Data coefficients,      //��� ����� ������ ����� ������������ ��������� ��� ��������� ��������� + ������� ���������
                    const Equation_Attributes_Data equation_parts);

void result_print (Equation_Attributes_Data equation_parts);

#endif //SQR_SOLV_OUTP_H_
