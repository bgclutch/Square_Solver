#include <stdio.h>
#include <math.h>
#include <assert.h>

#include "sqr_solv_inp.h"

int read_nums(Equation_Coefficients_Data *coefficients)
{
    if(continue_or_finish())
    {
        int result = 0;
        result += for_input(&(coefficients->sqr_x_coef), result);
        result += for_input(&(coefficients->x_coef), result);
        result += for_input(&(coefficients->free_coef), result);
        printf(yellow "\nBuffer cleaning result %d\n\n" del_col, buff_clean_and_check());
        return result;
    }
    else
    {
        return 0;
    }
}

bool buff_clean_and_check()
{
    bool is_error = 0;
    while(getchar() != '\n')
    {
        is_error = 1;
    }
    return is_error;
}


int for_input(double *coef, int counter)
{
    int result = 0;
    while((result = scanf("%lg", coef)) != 1)
    {
        if(buff_clean_and_check())
        {
            printf(yellow "Input %d coefficient again\n\n" del_col, ++counter);
            result = 0;
        }
        else if(result != 1)
        {
            printf(yellow "Input that coefficient again\n\n" del_col);
            result = 0;
        }
    }
    return result;
}

void greetings()
{
    printf("\nInput " blue "3 " del_col"coefficients " yellow "through " blue "'space':\n\n" del_col
           "_x^2 + _x + _\n\n");
}

int continue_or_finish()
{
    int checker = 3;
    printf("Input " green "'1' " del_col "to start solving your equation or " red "'q' " del_col "to finish:\n\n");

    while(checker != 1 && checker != 0)
    {
        int var_char = getchar();
        if(var_char == 'q')
        {
            checker = 0;
        }
        else if(var_char == '1')
        {
            greetings();
            checker = 1;
        }
        else
        {
         printf("Try again. " blue "Infinity " del_col "tries left)\n\n");
         checker = -1;
        }
    }
    return checker;
}
