#include "sqr_solv_headers.h"


int main(void)
{

    //Unit_Tests();

    greetings(); //вывод просьбы ввести коэффициенты

    struct Equation_Coefficients_Data coefficients =
        {
          .sqr_x_coef = NAN,
          .x_coef = NAN,
          .free_coef = NAN
        };

    while (read_nums(&coefficients))  //считывание коэффициентов
    {

        struct Equation_Attributes_Data equation_parts =
            {
              .discr = NAN,
              .root_1 = NAN,
              .root_2 = NAN,
              .root_number = UNEXISTING_ROOTS
            };

        square_equ_solver(coefficients, &equation_parts);

        equation_print(coefficients, equation_parts);   //вывод уравнения

        result_print(equation_parts);                 //вывод ответа
    }

    printf("Thanks for work!\n\n");
    return 0;
}

// D:\bvols\Documents\squre_solver\Square_Solver g++ square_solver.cpp sqr_solv_inp.cpp sqr_solv_outp.cpp sqr_solv_tests.cpp sqr_solv_processing.cpp
