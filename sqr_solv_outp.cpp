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
            if()
            {


            }
            else if()
            {


            }
            else
            {

            }
            printf("\nNumber of roots in " blue "'%lgx^2%+lgx%+lg' " delcol "square equation = " green "2 \n\n" del_col, coefficients.sqr_x_coef, coefficients.x_coef, coefficients.free_coef);
            break;
        }
        case(ONE_ROOT):
        {
            printf("\nNumber of roots in " blue "'%lgx^2%+lgx%+lg' " delcol "square equation = " green "1 \n\n" del_col, coefficients.sqr_x_coef, coefficients.x_coef, coefficients.free_coef);
            break;
        }
        case(INF_ROOTS):
        {
            printf("\nNumber of roots in " blue "'%lgx^2%+lgx%+lg' " delcol "square equation = " yellow "infinity \n\n" del_col, coefficients.sqr_x_coef, coefficients.x_coef, coefficients.free_coef);
            break;
        }
        case(UNEXISTING_ROOTS):
        {
            printf("\nNumber of roots in " blue "'%lgx^2%+lgx%+lg' " delcol "square equation = " yellow "0 \n\n" del_col, coefficients.sqr_x_coef, coefficients.x_coef, coefficients.free_coef);
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
            printf("Equation roots: " blue "x_1 = " green "%.3lg " blue ", x_2 = " green "%.3lg\n\n" del_col, fix_root_minus_zero(equation_parts.root_1),
                   fix_root_minus_zero(equation_parts.root_2));
            break;
        }
        case(ONE_ROOT):
        {
            assert(!isnan(equation_parts.root_1) && "root_1 is NAN");
            printf("Equation root " blue "x = " green "%.3lg\n\n" del_col, fix_root_minus_zero(equation_parts.root_1));
            break;
        }
        case(UNEXISTING_ROOTS):
        {
            printf(blue "No roots\n\n" del_col);
            break;
        }
        case(INF_ROOTS):
        {
            printf(blue "x " del_col "belongs " yellow "infinity\n\n" del_col);
            break;
        }
        default:
        {
            assert(0 && "result_print crashed");
            break;
        }
    }
}
