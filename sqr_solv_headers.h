#ifndef SQR_SOLV_HEADERS_H_
#define SQR_SOLV_HEADERS_H_

#include <stdio.h>
#include <math.h>


#define EPSILON 0.001

enum NumRoots
{
    UNEXISTING_ROOTS = 0,
    ONE_ROOT         = 1,
    TWO_ROOTS        = 2,
    INF_ROOTS        = 3,
};

struct Unit_Test_Data
{
    int test_num;
    double sqr_x_coef;
    double x_coef;
    double free_coef;
    double discr_exp;
    double root_1_exp;
    double root_2_exp;
    int root_num_exp;
};

struct Equation_Coefficients_Data
{
    double sqr_x_coef;
    double x_coef;
    double free_coef;
};

struct Equation_Attributes_Data
{
    double discr;
    double root_1;
    double root_2;
    NumRoots root_number;
};


bool is_zero(const double comparable);

void equation_print(const Equation_Coefficients_Data coefficients,      //спп хэдер ифндеф везде документация структуры или вложенные структуры + функции поправить
                    const Equation_Attributes_Data equation_parts);

void result_print (Equation_Attributes_Data equation_parts);

void square_equ_solver(const Equation_Coefficients_Data coefficients,
                       Equation_Attributes_Data *equation_parts);

void greetings();

void lineal_equ_solver(const double free_coef, const double x_coef,
                       double *root_1, Equation_Attributes_Data *equation_parts);

double fix_root_minus_zero(double root);

int read_nums(Equation_Coefficients_Data *coefficients);

bool buff_clean_and_check();

int for_input(double *coef, int counter);

int continue_or_finish();

int Solving_Tests(Unit_Test_Data test);

void Unit_Tests();

void is_min(double *root_1, double *root_2);

void my_swap(void* var_1, void* var_2, int size);

#endif // SQR_SOLV_HEADERS_H_
