#include "sqr_solv_headers.h"
#include <assert.h>

void greetings()
{
    printf("Input 3 coefficients through 'space':\n\n"
           "_x^2 + _x + _\n\n"
           "Or input 'q' to finish\n\n");
}

void equation_print(const Equation_Coefficients_Data coefficients, const Equation_Attributes_Data equation_parts) //switch
{
    switch(equation_parts.root_number)
    {
        case(TWO_ROOTS):
        {
            printf("\nNumber of roots in '%lgx^2%+lgx%+lg' square equation = 2 \n\n", coefficients.sqr_x_coef, coefficients.x_coef, coefficients.free_coef);
            break;
        }
        case(ONE_ROOT):
        {
            printf("\nNumber of roots in '%lgx^2%+lgx%+lg' square equation = 1 \n\n", coefficients.sqr_x_coef, coefficients.x_coef, coefficients.free_coef);
            break;
        }
        case(INF_ROOTS):
        {
            printf("\nNumber of roots in '%lgx^2%+lgx%+lg' square equation = infinity \n\n", coefficients.sqr_x_coef, coefficients.x_coef, coefficients.free_coef);
            break;
        }
        case(UNEXISTING_ROOTS):
        {
            printf("\nNumber of roots in '%lgx^2%+lgx%+lg' square equation = 0 \n\n", coefficients.sqr_x_coef, coefficients.x_coef, coefficients.free_coef);
            break;
        }
        default:
        {
            assert(0 && "equation_print crashed");
            break;
        }
    }
}

void result_print(const Equation_Attributes_Data equation_parts)
{
    switch(equation_parts.root_number)
    {
        case(TWO_ROOTS):
        {
            assert(!isnan(equation_parts.root_1) && "root_1 is NAN");
            assert(!isnan(equation_parts.root_2) && "root_2 is NAN");
            printf("Equation roots: x_1 = %.3lg, x_2 = %.3lg\n\n", fix_root_minus_zero(equation_parts.root_1),
                   fix_root_minus_zero(equation_parts.root_2));
            break;
        }
        case(ONE_ROOT):
        {
            assert(!isnan(equation_parts.root_1) && "root_1 is NAN");
            printf("Equation root x = %.3lg\n\n", fix_root_minus_zero(equation_parts.root_1));
            break;
        }
        case(UNEXISTING_ROOTS):
        {
            printf("No roots\n\n");
            break;
        }
        case(INF_ROOTS):
        {
            printf("x belong infinity\n\n");
            break;
        }
        default:
        {
            assert(0 && "result_print crashed");
            break;
        }
    }
}
