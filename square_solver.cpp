#include <stdio.h>
#include <math.h>
#include <string.h>

#include "sqr_solv_outp.h"
#include "sqr_solv_tests.h"
#include "sqr_solv_structs.h"

int main(int argc, char *argv[])
{
    printf("\n\nHello, I'm square solver!\n\n"
           "input '-h' in console for instructions\n\n"
           "input '--ver' in console for version information\n\n"); //'--test' for mode

    struct Console_Parsing variables = 
        {
            .c_help = "-h",
            .c_test = "--test",
            .c_ver = "--ver"
        };

    if(argc > 1)
    {
        for(int i = 0; i < argc; i++)
        {
            if(strcmp(variables.c_help, argv[i]) == 0)
            {
                print_guide();
                break; 
            }

            else if(strcmp(variables.c_test, argv[i]) == 0)
            {
                Unit_Tests();
                break;
            }
            else if(strcmp(variables.c_ver, argv[i]) == 0)
            {
                printf("program version 1.1\n\n"
                    "works good(maybe)\n\n");
                    break;   
            }
        }
    }
    else if(argc == 1)
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
    printf("\nThanks for work!\n\n");
    return 0;
}
