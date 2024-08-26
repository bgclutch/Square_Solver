
#ifndef SQR_SOLV_STRUCTS_H_
#define SQR_SOLV_STRUCTS_H_

#define RED     "\e[0;31m" ///< red
#define GREEN   "\e[0;32m" ///< green
#define YELLOW  "\e[0;33m" ///< yellow
#define BLUE    "\e[0;34m" ///< blue
#define DEL_COL    "\e[0m" ///< reset color

#define RED_TEXT    (...) RED __VA_ARGS__ DEL_COL
#define GREEN_TEXT  (...) GREEN __VA_ARGS__ DEL_COL
#define YELLOW_TEXT (...) YELLOW __VA_ARGS__ DEL_COL
#define BLUE_TEXT   (...) BLUE __VA_ARGS__ DEL_COL

#define EPSILON_ZERO 0.001 ///< epsolon zero
#define EPSILON_ONE 1.001  ///< epsilon one 

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

#endif // SQR_SOLV_STRUCTS_H_

