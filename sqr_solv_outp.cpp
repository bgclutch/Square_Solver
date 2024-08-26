#include <stdio.h>
#include <math.h>
#include <assert.h>

#include "sqr_solv_outp.h"

void equation_print(const Equation_Coefficients_Data coefficients, const Equation_Attributes_Data equation_parts) //switch
{
    switch(equation_parts.root_number)
    {
        case(TWO_ROOTS):
        {
            sqr_x_coef_is_abs_one_two_roots(coefficients);
            break;
        }
        case(ONE_ROOT):
        {
            sqr_x_coef_is_abs_one_one_root(coefficients);
            break;
        }
        case(INF_ROOTS):
        {
            sqr_x_coef_is_abs_one_inf_roots(coefficients);
            break;
        }
        case(UNEXISTING_ROOTS):
        {
            sqr_x_coef_is_abs_one_zero_roots(coefficients);
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
            printf("Equation roots: " BLUE_TEXT("x_1 = ") GREEN_TEXT("%.3lg ") BLUE_TEXT(", x_2 = ") GREEN_TEXT("%.3lg") "\n\n", fix_root_minus_zero(equation_parts.root_1),
                   fix_root_minus_zero(equation_parts.root_2));
            break;
        }
        case(ONE_ROOT):
        {
            assert(!isnan(equation_parts.root_1) && "root_1 is NAN");
            printf("Equation root " BLUE_TEXT("x = ") GREEN_TEXT("%.3lg") "\n\n", fix_root_minus_zero(equation_parts.root_1));
            break;
        }
        case(UNEXISTING_ROOTS):
        {
            printf(BLUE_TEXT("No roots") "\n\n");
            break;
        }
        case(INF_ROOTS):
        {
            printf(BLUE_TEXT("x") " belongs " YELLOW_TEXT("infinity") "\n\n");
            break;
        }
        default:
        {
            assert(0 && "result_print crashed");
            break;
        }
    }
}

void sqr_x_coef_is_abs_one_two_roots(const Equation_Coefficients_Data coefficients)
{
    if(is_abs_one(coefficients.sqr_x_coef))
            {
                if(coefficients.sqr_x_coef > 0)
                {
                    printf("\nNumber of roots in " BLUE_TEXT("'x^2%+lgx%+lg'") "square equation = " GREEN_TEXT("2") "\n\n", coefficients.x_coef, coefficients.free_coef);      
                }
                else
                {
                    printf("\nNumber of roots in " BLUE_TEXT("'-x^2%+lgx%+lg'") " square equation = " GREEN_TEXT("2") "\n\n", coefficients.x_coef, coefficients.free_coef);
                }
            }
            else
            {
                printf("\nNumber of roots in " BLUE_TEXT("'%lgx^2%+lgx%+lg'") " square equation = " GREEN_TEXT("2") "\n\n", coefficients.sqr_x_coef, coefficients.x_coef, coefficients.free_coef);
            }
}

void sqr_x_coef_is_abs_one_one_root(const Equation_Coefficients_Data coefficients)
{
    if(is_abs_one(coefficients.sqr_x_coef))
            {
                if(coefficients.sqr_x_coef > 0)
                {
                    printf("\nNumber of roots in " BLUE_TEXT("'x^2%+lgx%+lg'") "square equation = " GREEN_TEXT("1") "\n\n", coefficients.x_coef, coefficients.free_coef);      
                }
                else
                {
                    printf("\nNumber of roots in " BLUE_TEXT("'-x^2%+lgx%+lg'") " square equation = " GREEN_TEXT("1") "\n\n", coefficients.x_coef, coefficients.free_coef);
                }
            }
            else
            {
                printf("\nNumber of roots in " BLUE_TEXT("'%lgx^2%+lgx%+lg'") " square equation = " GREEN_TEXT("1") "\n\n", coefficients.sqr_x_coef, coefficients.x_coef, coefficients.free_coef);
            }
}

void sqr_x_coef_is_abs_one_zero_roots(const Equation_Coefficients_Data coefficients)
{
    if(is_abs_one(coefficients.sqr_x_coef))
            {
                if(coefficients.sqr_x_coef > 0)
                {
                    printf("\nNumber of roots in " BLUE_TEXT("'x^2%+lgx%+lg'") "square equation = " YELLOW_TEXT("0") "\n\n", coefficients.x_coef, coefficients.free_coef);      
                }
                else
                {
                    printf("\nNumber of roots in " BLUE_TEXT("'-x^2%+lgx%+lg'") " square equation = " YELLOW_TEXT("0") "\n\n", coefficients.x_coef, coefficients.free_coef);
                }
            }
            else
            {
                printf("\nNumber of roots in " BLUE_TEXT("'%lgx^2%+lgx%+lg'") " square equation = " YELLOW_TEXT("0") "\n\n", coefficients.sqr_x_coef, coefficients.x_coef, coefficients.free_coef);
            }
}

void sqr_x_coef_is_abs_one_inf_roots(const Equation_Coefficients_Data coefficients)
{
    if(is_abs_one(coefficients.sqr_x_coef))
            {
                if(coefficients.sqr_x_coef > 0)
                {
                    printf("\nNumber of roots in " BLUE_TEXT("'x^2%+lgx%+lg'") "square equation = " YELLOW_TEXT("infinity") "\n\n", coefficients.x_coef, coefficients.free_coef);      
                }
                else
                {
                    printf("\nNumber of roots in " BLUE_TEXT("'-x^2%+lgx%+lg'") " square equation = " YELLOW_TEXT("infinity") "\n\n", coefficients.x_coef, coefficients.free_coef);
                }
            }
            else
            {
                printf("\nNumber of roots in " BLUE_TEXT("'%lgx^2%+lgx%+lg'") " square equation = " YELLOW_TEXT("infinity") "\n\n", coefficients.sqr_x_coef, coefficients.x_coef, coefficients.free_coef);
            }
}

void print_guide()
{
    printf("Hello! There's a Square Solver guide."
           "Input 3 coefficient of square equation.\n\n If you want to solve lineal equation input zero ('0') first.\n\n"
           "If you input non-numbers, program will not working, try it)\n\n"
           "Good luck!\n\n");
}