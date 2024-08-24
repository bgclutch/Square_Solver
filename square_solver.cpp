#include <stdio.h>
#include <math.h>

#include "sqr_solv_outp.h"
#include "sqr_solv_tests.h"
#include "sqr_solv_structs.h"

int main(void)
{
    printf("Choose the release mode:\n"
           "input 't' for test mode or 'c' for common mode\n\n");

    int mode_choose = 2;

    while(mode_choose != 1 && mode_choose != 0)
    {
        int g_char = getchar();
        if(g_char == 't')
        {
            g_char = buff_clean_and_check();
            mode_choose = 0;
        }
        else if(g_char == 'c')
        {
            g_char = buff_clean_and_check();
            mode_choose = 1;
        }
        else
        {
            printf("Try again\n\n");
        }
    }

    if(mode_choose)
    {
        struct Equation_Coefficients_Data coefficients =
            {
              .sqr_x_coef = NAN,
              .x_coef = NAN,
              .free_coef = NAN
            };

        while (read_nums(&coefficients))  //���������� �������������
        {

            struct Equation_Attributes_Data equation_parts =
                {
                  .discr = NAN,
                  .root_1 = NAN,
                  .root_2 = NAN,
                  .root_number = UNEXISTING_ROOTS
                };

            square_equ_solver(coefficients, &equation_parts);

            equation_print(coefficients, equation_parts);   //����� ���������

            result_print(equation_parts);                 //����� ������
        }
    }
    else
    {
        Unit_Tests();
    }

    printf("\n\nThanks for work!\n\n");
    return 0;
}

// D:\bvols\Documents\square_solver\Square_Solver g++ square_solver.cpp sqr_solv_inp.cpp sqr_solv_outp.cpp sqr_solv_tests.cpp sqr_solv_processing.cpp
