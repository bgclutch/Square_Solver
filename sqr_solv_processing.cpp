#include <stdio.h>
#include <math.h>
#include <inttypes.h>
#include <assert.h>

#include "sqr_solv_processing.h"

bool is_zero(const double comparable)
{
    return (fabs(comparable) > EPSILON);
}


void lineal_equ_solver(const double free_coef, const double x_coef, double *root_1, Equation_Attributes_Data *equation_parts)
{
    assert(root_1 && "&root_1 is 0");
    assert(isnan(*root_1) && "root_1 is not NAN");
    *root_1 = -free_coef / x_coef;
    equation_parts->root_number = ONE_ROOT;
}


double fix_root_minus_zero(double root)
{
    return !is_zero(root) ?  0 : root;
}


void is_min(double *root_1, double *root_2)
{
    if(*root_1 > *root_2)
    {
        my_swap(root_1, root_2, sizeof(*root_1));
    }
}


void square_equ_solver(const Equation_Coefficients_Data coefficients, Equation_Attributes_Data *equation_parts)
{
    assert((&(*equation_parts).root_number) && "&root_num is 0");
    assert((&(*equation_parts).discr) && "&discr is 0");
    assert((&(*equation_parts).root_1) && "&root_1 is 0");
    assert((&(*equation_parts).root_2) && "&root_2 is 0");
    assert(isnan(equation_parts->discr) && "discr is not NAN");
    assert(isnan(equation_parts->root_1) && "root_1 is not NAN");
    assert(isnan(equation_parts->root_2) && "root_2 is not NAN");

    if(is_zero(coefficients.sqr_x_coef))
        {
            equation_parts->discr = coefficients.x_coef * coefficients.x_coef - 4 * coefficients.sqr_x_coef * coefficients.free_coef;
            if(!is_zero(equation_parts->discr))
            {
                equation_parts->root_1 = -(coefficients.x_coef) / (2 * coefficients.sqr_x_coef);
                equation_parts->root_number = ONE_ROOT;
            }
            else if(equation_parts->discr > EPSILON)
            {
                assert(equation_parts->discr > EPSILON && "discr is negative");//discr
                equation_parts->root_1 = (-(coefficients.x_coef) - sqrt(equation_parts->discr)) / (2 * coefficients.sqr_x_coef);
                equation_parts->root_2 = (-(coefficients.x_coef) + sqrt(equation_parts->discr)) / (2 * coefficients.sqr_x_coef);
                is_min(&(equation_parts->root_1), &(equation_parts->root_2));
                equation_parts->root_number = TWO_ROOTS;
            }
            else
            {
                equation_parts->root_number = UNEXISTING_ROOTS;
            }
        }
        else if(is_zero(coefficients.x_coef))
        {
            lineal_equ_solver(coefficients.free_coef, coefficients.x_coef, &(equation_parts->root_1), equation_parts);
        }
        else
        {
            equation_parts->root_number = (is_zero(coefficients.free_coef)) ? UNEXISTING_ROOTS : INF_ROOTS;
        }
}


void my_swap(void* var_1, void* var_2, unsigned long size)//���������� ����
{
    unsigned long add_bytes = 0;

    uint64_t *ptr_var_long_1 = (uint64_t*)var_1;
    uint64_t *ptr_var_long_2 = (uint64_t*)var_2;
    //printf("start swapping: %p %p\n", ptr_var_long_1, ptr_var_long_2);

    for(; size >= sizeof(uint64_t); ptr_var_long_1++, ptr_var_long_2++, size -= sizeof(uint64_t), add_bytes += sizeof(uint64_t))
    {
        uint64_t imba = *ptr_var_long_1;
        *ptr_var_long_1 = *ptr_var_long_2;
        *ptr_var_long_2 = imba;
        //printf("swap in long start: %p %p %d\n", ptr_var_long_1, ptr_var_long_2, size);
    }
    //printf("swap in long finish: %p %p\n\n", ptr_var_long_1 + add_bytes, ptr_var_long_2 + add_bytes);

    uint32_t *ptr_var_int_1 = (uint32_t*)(var_1) + add_bytes;
    uint32_t *ptr_var_int_2 = (uint32_t*)(var_2) + add_bytes;

    if(size / sizeof(uint32_t) == 1)
    {
        uint32_t imba = *ptr_var_int_1;
        *ptr_var_int_1 = *ptr_var_int_2;
        *ptr_var_int_2 = imba;
        size %= sizeof(uint32_t);
        add_bytes += sizeof(uint32_t);
        //printf("swap in int start: %p %p\n", ptr_var_int_1, ptr_var_int_2);
        //printf("swap in int finish: %p %p\n\n", ptr_var_int_1 + add_bytes,
               // ptr_var_int_2 + add_bytes);
    }

    uint16_t *ptr_var_short_1 = (uint16_t*)(var_1) + add_bytes;
    uint16_t *ptr_var_short_2 = (uint16_t*)(var_2) + add_bytes;

    if(size / sizeof(uint16_t) == 1)
    {
        uint16_t imba = *ptr_var_short_1;
        *ptr_var_short_1 = *ptr_var_short_2;
        *ptr_var_short_2 = imba;
        size %= sizeof(uint16_t);
        add_bytes += sizeof(uint16_t);
        //printf("swap in short start: %p %p\n", ptr_var_short_1, ptr_var_short_2);
        //printf("swap in int finish: %p %p\n\n", ptr_var_short_1 + add_bytes,
                //ptr_var_short_2 + add_bytes);
    }

    uint8_t *ptr_var_char_1 = (uint8_t*)var_1 + add_bytes;
    uint8_t *ptr_var_char_2 = (uint8_t*)var_2 + add_bytes;

    if(size / sizeof(uint8_t) == 1)
    {
        uint8_t imba = *ptr_var_char_1;
        *ptr_var_char_1 = *ptr_var_char_2;
        *ptr_var_char_2 = imba;
        size %= sizeof(uint8_t);
        add_bytes += sizeof(uint8_t);
        //printf("swap in char start: %p %p\n", ptr_var_char_1, ptr_var_char_2);
        //printf("swap in int finish: %p %p\n\n", ptr_var_char_1 + add_bytes,
               // ptr_var_char_2 + add_bytes);
    }
}

