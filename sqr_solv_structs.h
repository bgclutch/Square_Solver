
#ifndef SQR_SOLV_STRUCTS_H_
#define SQR_SOLV_STRUCTS_H_

enum NumRoots
{
    UNEXISTING_ROOTS = 0,
    ONE_ROOT         = 1,
    TWO_ROOTS        = 2,
    INF_ROOTS        = 3,
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

//спп хэдер ифндеф везде документация структуры или вложенные структуры


#endif // SQR_SOLV_STRUCTS_H_

