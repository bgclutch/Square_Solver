#include <stdio.h>
#include <math.h>
#include <string.h>

#include "sqr_solv_outp.h"
#include "sqr_solv_tests.h"
#include "sqr_solv_structs.h"

int main(int argc, char *argv[])
{
    printf("Hello, I'm square solver!\n"
           "input '--h' for instructions\n\n"); //'--test' for mode

    struct Console_Parsing variables = 
    {
        .c_help = strcmp(argv[2], "--h"),
        .c_test = strcmp(argv[2], "--test")

    };
    
    if(variables.c_help == 0)
    {
        print_guide();  
    }

    else if(variables.c_test == 0)
    {
        Unit_Tests();
    }
    else
    {
        struct Equation_Coefficients_Data coefficients =
        {
            .sqr_x_coef = NAN,
            .x_coef = NAN,
            .free_coef = NAN
        };

        while (read_nums(&coefficients))  
        {

            struct Equation_Attributes_Data equation_parts =
                {
                    .discr = NAN,
                    .root_1 = NAN,
                    .root_2 = NAN,
                    .root_number = UNEXISTING_ROOTS
                };

            square_equ_solver(coefficients, &equation_parts);

            equation_print(coefficients, equation_parts);   

            result_print(equation_parts);                 
        }
    }

    printf("\n\nThanks for work!\n\n");
    return 0;
}
