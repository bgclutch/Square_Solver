#include "sqr_solv_headers.h"

int read_nums(Equation_Coefficients_Data *coefficients)
{
    if(continue_or_finish())
    {
        int result = 0;
        result += for_input(&(coefficients->sqr_x_coef), result);
        result += for_input(&(coefficients->x_coef), result);
        result += for_input(&(coefficients->free_coef), result);
        printf("\nBuffer cleaning result %d\n\n", buff_clean_and_check());
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
            printf("Input %d coefficient again\n\n", ++counter);
            result = 0;
        }
        else if(result != 1)
        {
            printf("Input that coefficient again\n\n");
            result = 0;
        }
    }
    return result;
}

int continue_or_finish()
{
    int checker = 0;
    printf("Input '1' to continue of 'q' to finish:\n\n");

    while(checker != 1 || checker != 0)
    {
        char var_char = getchar();
        if(var_char == 'q')
        {
            checker = 0;
        }
        else if(var_char == '1')
        {
            checker = 1;
        }
        else
        {
         printf("Try again. Infinity tries left)");
         checker = -1;
        }
    }
    return checker;
}
