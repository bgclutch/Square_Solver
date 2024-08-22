#include <TXLiB.h>
#include <stdio.h>
#include <math.h>


#define EPSILON 0.001

enum NumRoots
{
    UNEXISTING_ROOTS = 0,
    ONE_ROOT         = 1,
    TWO_ROOTS        = 2,
    INF_ROOTS        = 3
};

struct for_tests
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

struct for_equation
{
    double sqr_x_coef;
    double x_coef;
    double free_coef;
};

struct for_changing
{
    double discr;
    double root_1;
    double root_2;
    NumRoots root_number;
};



bool is_zero(const double comparable);

void equation_print(const for_equation coefficients, const for_changing equation_parts);

void result_print (for_changing equation_parts);

void root_finder(const for_equation coefficients, for_changing *equation_parts);

void greetings();

void lineal_equ_solver(const double free_coef, const double x_coef, double *root_1);

double fix_root_minus_zero(double root);

int read_nums(for_equation *coefficients);

bool buff_clean_and_check();

int for_input(double *coef, int counter);

int Solving_Tests(for_tests test);

void Unit_Tests();


int main(void)
{

    greetings(); //вывод просьбы ввести коэффициенты

    struct for_equation coefficients =
        {
          .sqr_x_coef = NAN,
          .x_coef = NAN,
          .free_coef = NAN
        };
    //double sqr_x_coefficient = NAN;         //объявление переменных
    //double x_coefficient = NAN;
    //double free_coefficient = NAN;

    while (read_nums(&coefficients) == 3)  //считывание коэффициентов
    {

    struct for_changing equation_parts =
        {
          .discr = NAN,
          .root_1 = NAN,
          .root_2 = NAN,
          .root_number = UNEXISTING_ROOTS
        };

        //double discriminant = NAN;
        //double root_1 = NAN;
        //double root_2 = NAN;
        //NumRoots root_number = UNEXISTING_ROOTS;

        root_finder(coefficients, &equation_parts);

        equation_print(coefficients, equation_parts);   //вывод уравнения

        result_print(equation_parts);                 //вывод ответа


        //Unit_Tests();


    }
    printf("Спасибо за работу!\n\n");
    return 0;
}


bool is_zero(const double comparable)
{
    return (fabs(comparable) > EPSILON);
}


void equation_print(const for_equation coefficients, const for_changing equation_parts) //switch
{
    switch(equation_parts.root_number)
    {
        case(TWO_ROOTS):
        {
            printf("\nКоличество корней уравнения '%lgx^2%+lgx%+lg' = 2 \n\n", coefficients.sqr_x_coef, coefficients.x_coef, coefficients.free_coef);
            break;
        }
        case(ONE_ROOT):
        {
            printf("\nКоличество корней уравнения '%lgx^2%+lgx%+lg' = 1 \n\n", coefficients.sqr_x_coef, coefficients.x_coef, coefficients.free_coef);
            break;
        }
        case(INF_ROOTS):
        {
            printf("\nКоличество корней уравнения '%lgx^2%+lgx%+lg' = infinity \n\n", coefficients.sqr_x_coef, coefficients.x_coef, coefficients.free_coef);
            break;
        }
        case(UNEXISTING_ROOTS):
        {
            printf("\nКоличество корней уравнения '%lgx^2%+lgx%+lg' = 0 \n\n", coefficients.sqr_x_coef, coefficients.x_coef, coefficients.free_coef);
            break;
        }
        default:
        {
            assert(0 && "equation_print crashed");
            break;
        }
    }
}


void root_finder(const for_equation coefficients, for_changing *equation_parts)
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
                (*equation_parts).root_1 = (-(coefficients.x_coef) - sqrt(equation_parts->discr)) / (2 * coefficients.sqr_x_coef);
                (*equation_parts).root_2 = (-(coefficients.x_coef) + sqrt(equation_parts->discr)) / (2 * coefficients.sqr_x_coef);
                (*equation_parts).root_number = TWO_ROOTS;
            }
            else
            {
                (*equation_parts).root_number = UNEXISTING_ROOTS;
                (*equation_parts).root_1 = NAN;
                (*equation_parts).root_2 = NAN;
            }
        }
        else if(is_zero(coefficients.x_coef))
        {
            lineal_equ_solver(coefficients.free_coef, coefficients.x_coef, &(equation_parts->root_1));
            equation_parts->root_2 = NAN;
            equation_parts->root_number = ONE_ROOT;
            equation_parts->discr = coefficients.x_coef * coefficients.x_coef - 4 * coefficients.sqr_x_coef * coefficients.free_coef;
        }
        else
        {
            (*equation_parts).root_number = (is_zero(coefficients.free_coef)) ? UNEXISTING_ROOTS : INF_ROOTS;
            (*equation_parts).discr = coefficients.x_coef * coefficients.x_coef - 4 * coefficients.sqr_x_coef * coefficients.free_coef;
            (*equation_parts).root_1 = NAN;
            (*equation_parts).root_2 = NAN;
        }
}


void result_print(const for_changing equation_parts)
{
    switch(equation_parts.root_number)
    {
        case(TWO_ROOTS):
        {
            assert(!isnan(equation_parts.root_1) && "root_1 is NAN");
            assert(!isnan(equation_parts.root_2) && "root_2 is NAN");
            printf("Корни уравнения: x_1 = %.3lg, x_2 = %.3lg\n\n", fix_root_minus_zero(equation_parts.root_1), fix_root_minus_zero(equation_parts.root_2));
            break;
        }
        case(ONE_ROOT):
        {
            assert(!isnan(equation_parts.root_1) && "root_1 is NAN");
            printf("Корень уравнения x = %.3lg\n\n", fix_root_minus_zero(equation_parts.root_1));
            break;
        }
        case(UNEXISTING_ROOTS):
        {
            printf("Нет корней\n\n");
            break;
        }
        case(INF_ROOTS):
        {
            printf("x - любое\n\n");
            break;
        }
        default:
        {
            assert(0 && "result_print crashed");
            break;
        }
    }
}

//assert(0 && "Abx")

void greetings()
{
    printf("Введи 3 коэффициента через пробел:\n\n"
           "_x^2 + _x + _\n\n"
           "Или введи 'q' для окончания работы\n\n");
}


void lineal_equ_solver(const double free_coef, const double x_coef, double *root_1)
{
    assert(root_1 && "&root_1 is 0");
    assert(isnan(*root_1) && "root_1 is not NAN");
    *root_1 = -free_coef / x_coef;
}


//to do
//структуры вход/выход в мейне и др.
//завершение работы q


double fix_root_minus_zero(double root)
{
    return !is_zero(root) ?  0 : root;
}

int read_nums(for_equation *coefficients)
{
    int result = 0;
    result += for_input(&(coefficients->sqr_x_coef), result);
    result += for_input(&(coefficients->x_coef), result);
    result += for_input(&(coefficients->free_coef), result);
    printf("\nРезультат очистки буфера %d\n\n", buff_clean_and_check());
    return result;
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
            printf("Повторите ввод, начиная с %d числа\n\n", ++counter);
            result = 0;
        }
        else if(result != 1)
        {
            printf("Повторите ввод данного числа\n\n");
            result = 0;
        }
    }
    return result;
}



int Solving_Tests(for_tests test)
{
    struct for_equation coefficients =
        {
          .sqr_x_coef = test.sqr_x_coef,
          .x_coef = test.x_coef,
          .free_coef = test.free_coef
        };

    struct for_changing equation_parts =
    {
      .discr = NAN,
      .root_1 = NAN,
      .root_2 = NAN,
      .root_number = UNEXISTING_ROOTS
    };
    root_finder(coefficients, &equation_parts);

    if(test.root_num_exp != equation_parts.root_number || fabs(equation_parts.discr - test.discr_exp) > EPSILON || (equation_parts.root_1 - test.root_1_exp) > EPSILON ||
      (equation_parts.root_2 - test.root_2_exp) > EPSILON)
    {
        printf("Calculation error in test %d:\nwith sqr_x_coef = %lg\nx_coef = %lg\nfree_coef = %lg\n\nexpected:\n"
               "discriminant = %lg\nroot number = %d\nroot_1 = %lg\nroot_2 = %lg\n\n"
               "printed:\ndiscriminant = %lg\nroot_number = %d\nroot_1 = %lg\nroot_2 = %lg\n",
               test.test_num, test.sqr_x_coef, test.x_coef, test.free_coef, test.discr_exp, test.root_num_exp,
               test.root_1_exp, test.root_2_exp,
               equation_parts.discr, equation_parts.root_number, equation_parts.root_1, equation_parts.root_2);
        return 0;
    }
    else
    {
        printf("Test %d is done\n", test.test_num);
        return 1;
    }
}


void Unit_Tests()
{
    struct for_tests test_1 = {.test_num = 1, .sqr_x_coef = 0, .x_coef = 0, .free_coef = 0, .discr_exp = 0, .root_1_exp = NAN,
                               .root_2_exp = NAN, .root_num_exp = 0};

    struct for_tests test_2 = {.test_num = 2, .sqr_x_coef = 0, .x_coef = 0, .free_coef = 3, .discr_exp = 0 , .root_1_exp = INF_ROOTS,
                               .root_2_exp = INF_ROOTS, .root_num_exp = UNEXISTING_ROOTS};

    struct for_tests test_3 = {.test_num = 3, .sqr_x_coef = -4, .x_coef = 3, .free_coef = 8, .discr_exp = 137, .root_1_exp = 1.838,
                               .root_2_exp = -1.088, .root_num_exp = 2};

    struct for_tests test_4 = {.test_num = 4, .sqr_x_coef = 1, .x_coef = 6, .free_coef = 9, .discr_exp = 0, .root_1_exp = -3,
                               .root_2_exp = NAN, .root_num_exp = 1};

    struct for_tests test_5 = {.test_num = 5, .sqr_x_coef = 1, .x_coef = 0, .free_coef = -16, .discr_exp = 64, .root_1_exp = -4,
                               .root_2_exp = 4, .root_num_exp = 2};

    struct for_tests test_6 = {.test_num = 6, .sqr_x_coef = 1.674, .x_coef = 673.5, .free_coef = -5, .discr_exp = 453635.73, .root_1_exp = -402.337,
                               .root_2_exp = 0.007, .root_num_exp = 2};

    struct for_tests test_7 = {.test_num = 7, .sqr_x_coef = 16, .x_coef = 128, .free_coef = -872.7, .discr_exp = 72236.8, .root_1_exp = -12.399,
                               .root_2_exp = 4.399, .root_num_exp = 2};

    struct for_tests test_8 = {.test_num = 8, .sqr_x_coef = 10, .x_coef = -57, .free_coef = -672, .discr_exp = 30129, .root_1_exp = -5.829,
                               .root_2_exp = 11.529, .root_num_exp = 2};

    struct for_tests test_9 = {.test_num = 9, .sqr_x_coef = 10, .x_coef = -57, .free_coef = 672, .discr_exp = -23631, .root_1_exp = NAN,
                               .root_2_exp = NAN, .root_num_exp = 0};

    struct for_tests test_10 = {.test_num = 10, .sqr_x_coef = 0, .x_coef = 5, .free_coef = -45.72, .discr_exp = 25, .root_1_exp = 9.144,
                                .root_2_exp = NAN, .root_num_exp = 1};


    int test_counter = 0;

    printf("result %lg means not existing root\n\n"         //unit tests
           "result %d means ifinity of roots\n\n", NAN, INF_ROOTS);


    test_counter += Solving_Tests(test_1); //все коэффициенты равны 0
    printf("\n\n");

    test_counter += Solving_Tests(test_2); // коэффициенты при переменных равны 0
    printf("\n\n");

    test_counter += Solving_Tests(test_3); //коэфф при x^2 отрицателен, остальные положительны
    printf("\n\n");

    test_counter += Solving_Tests(test_4);  //дискр == 0, 1 корень
    printf("\n\n");

    test_counter += Solving_Tests(test_5);  // коэфф x отсутствует, 2 корня
    printf("\n\n");

    test_counter += Solving_Tests(test_6); // дробные коэффициенты
    printf("\n\n");

    test_counter += Solving_Tests(test_7); //отрицательный и дробный свободный коэфф
    printf("\n\n");

    test_counter += Solving_Tests(test_8); //отрицательные коэфф x и свободный коэфф
    printf("\n\n");

    test_counter += Solving_Tests(test_9); //дискриминант меньше 0
    printf("\n\n");

    test_counter += Solving_Tests(test_10); // линейное уравнение
    printf("\n\n");


    printf("%d out of 10 tests done correct ", test_counter);
}
