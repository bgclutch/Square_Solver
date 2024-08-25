
#ifndef SQR_SOLV_STRUCTS_H_
#define SQR_SOLV_STRUCTS_H_
#include <string.h>

enum NumRoots
{
    UNEXISTING_ROOTS = 0, ///< no roots
    ONE_ROOT         = 1, ///< one root
    TWO_ROOTS        = 2, ///< two roots
    INF_ROOTS        = 3, ///< infinity roots
};

struct Equation_Coefficients_Data
{
    double sqr_x_coef; ///< coefficient belongs x^2
    double x_coef;     ///< coefficient belongs x
    double free_coef;  ///< free coefficient 
};

struct Equation_Attributes_Data
{
    double discr;         ///< discriminant
    double root_1;        ///< first (or one for lineal equation) root
    double root_2;        ///< second root
    NumRoots root_number; ///< number of roots
};

struct Colorized_Output colors = 
{
    string red =   "\e[0;31m", ///< red
    string green = "\e[0;32m", ///< green
    string blue =  "\e[0;34m", ///< blue
    string del_col =  "\e[0m"  ///< reset color
};

#endif // SQR_SOLV_STRUCTS_H_

