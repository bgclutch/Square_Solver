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


bool is_zero(const double comparable);

void equation_print(const NumRoots root_number, const double sqr_x_coef, const double x_coef, const double free_coef);

void result_print(const NumRoots root_counter, const double root_1, const double root_2);

void root_finder(NumRoots *root_num, const double sqr_x_coef, const double x_coef, const double free_coef,                      // const
                 double *discr, double *root_1, double *root_2);

void greetings();

void lineal_equ_solver(const double free_coef, const double x_coef, double *root_1);

void print_discriminant(const double discr);

double fix_root_minus_zero(double root);

int read_nums(double *sqr_x_coef, double *x_coef, double *free_coef);

bool buff_clean_and_check();

int for_input(double *coef, int counter);

int Solving_Tests(const int test_num, const double sqr_x_coef, const double x_coef, const double free_coef,
                  const double discr_exp, const double root_1_exp, const double root_2_exp,
                  const int root_number_exp);


int main(void)
{
    /*
    greetings(); //вывод просьбы ввести коэффициенты


    double sqr_x_coefficient = NAN;         //объявление переменных
    double x_coefficient = NAN;
    double free_coefficient = NAN;

    while (read_nums(&sqr_x_coefficient, &x_coefficient, &free_coefficient) == 3)  //считывание коэффициентов
    {

        double discriminant = NAN;
        double root_1 = NAN;
        double root_2 = NAN;
        NumRoots root_number = UNEXISTING_ROOTS;

        root_finder(&root_number, sqr_x_coefficient, x_coefficient, free_coefficient, &discriminant, &root_1, &root_2);

        equation_print(root_number, sqr_x_coefficient, x_coefficient, free_coefficient);   //вывод уравнения

        result_print(root_number, root_1, root_2);                 //вывод ответа

         */
        int test_counter = 0;
        printf("result %lg means not existing root\n\n"         //unit tests
               "result %d means ifinity of roots\n\n", NAN, INF_ROOTS);


        test_counter += Solving_Tests(1, 0, 0, 0, 0, isnan(NAN), isnan(NAN), 0); //все коэффициенты равны 0
        printf("\n\n");

        test_counter += Solving_Tests(2, 0, 0, 3, 0 , INF_ROOTS, INF_ROOTS, INF_ROOTS); // коэффициенты при переменных равны 0
        printf("\n\n");

        test_counter += Solving_Tests(3, -4, 3, 8, 137, 1.838, -1.088, 2); //коэфф при x^2 отрицателен, остальные положительны
        printf("\n\n");

        test_counter += Solving_Tests(4, 1, 6, 9, 0, -3, isnan(NAN), 1);  //дискр == 0, 1 корень
        printf("\n\n");

        test_counter += Solving_Tests(5, 1, 0, -16, 64, -4, 4, 2);  // коэфф x отсутствует, 2 корня
        printf("\n\n");

        test_counter += Solving_Tests(6, 1.674, 673.5, -5, 453635.73, -402.337, 0.007, 2); // дробные коэффициенты
        printf("\n\n");

        test_counter += Solving_Tests(7, 16, 128, -872.7, 72236.8, -12.399, 4.399, 2); //отрицательный и дробный свободный коэфф
        printf("\n\n");

        test_counter += Solving_Tests(8, 10, -57, -672, 30129, -5.829, 11.529, 2); //отрицательные коэфф x и свободный коэфф
        printf("\n\n");

        test_counter += Solving_Tests(9, 10, -57, 672, -23631, isnan(NAN), isnan(NAN), 0); //дискриминант меньше 0
        printf("\n\n");

        test_counter += Solving_Tests(10, 0, 5, -45.72, 25, 9.144, isnan(NAN), 1); // линейное уравнение
        printf("\n\n");


        printf("%d out of 10 tests done correct ", test_counter);

    //}
    //printf("Спасибо за работу!\n\n");
    return 0;
}


bool is_zero(const double comparable)
{
    return (fabs(comparable) > EPSILON);
}


void equation_print(const NumRoots root_number, const double sqr_x_coef, const double x_coef, const double free_coef) //switch
{
    switch(root_number)
    {
        case(TWO_ROOTS):
        {
            printf("\nКоличество корней уравнения '%lgx^2%+lgx%+lg' = 2 \n\n", sqr_x_coef, x_coef, free_coef);
            break;
        }
        case(ONE_ROOT):
        {
            printf("\nКоличество корней уравнения '%lgx^2%+lgx%+lg' = 1 \n\n", sqr_x_coef, x_coef, free_coef);
            break;
        }
        case(INF_ROOTS):
        {
            printf("\nКоличество корней уравнения '%lgx^2%+lgx%+lg' = infinity \n\n", sqr_x_coef, x_coef, free_coef);
            break;
        }
        case(UNEXISTING_ROOTS):
        {
            printf("\nКоличество корней уравнения '%lgx^2%+lgx%+lg' = 0 \n\n", sqr_x_coef, x_coef, free_coef);
            break;
        }
        default:
        {
            assert(0 && " bububu");
            break;
        }
    }
}


void root_finder(NumRoots *root_num, const double sqr_x_coef, const double x_coef, const double free_coef,
                 double *discr, double *root_1, double *root_2)
{
    assert(root_num && "&root_num is 0");
    assert(discr && "&discr is 0");
    assert(root_1 && "&root_1 is 0");
    assert(root_2 && "&root_2 is 0");
    assert(isnan(*discr) && "discr is not NAN");
    assert(isnan(*root_1) && "root_1 is not NAN");
    assert(isnan(*root_2) && "root_2 is not NAN");

    if(is_zero(sqr_x_coef))
        {
            *discr = x_coef * x_coef - 4 * sqr_x_coef * free_coef;
            if(!is_zero(*discr))
            {
                *root_1 = -x_coef / (2 * sqr_x_coef);
                *root_num = ONE_ROOT;
            }
            else if(*discr > EPSILON)
            {
                assert( *discr > EPSILON && "discr is negative");//discr
                *root_1 = (-x_coef - sqrt(*discr)) / (2 * sqr_x_coef);
                *root_2 = (-x_coef + sqrt(*discr)) / (2 * sqr_x_coef);
                *root_num = TWO_ROOTS;
            }
            else
            {
                *root_num = UNEXISTING_ROOTS;
                *root_1 = isnan(NAN);
                *root_2 = isnan(NAN);
            }
        }
        else if(is_zero(x_coef))
        {
            lineal_equ_solver(free_coef, x_coef, root_1);
            *root_2 = isnan(NAN);
            *root_num = ONE_ROOT;
            *discr = x_coef * x_coef - 4 * sqr_x_coef * free_coef;
        }
        else
        {
            *root_num = (is_zero(free_coef)) ? INF_ROOTS : UNEXISTING_ROOTS;
            *discr = x_coef * x_coef - 4 * sqr_x_coef * free_coef;
            *root_1 = isnan(NAN);
            *root_2 = isnan(NAN);
        }
}


void result_print(const NumRoots root_counter, const double root_1, const double root_2)
{
    switch(root_counter)
    {
        case(TWO_ROOTS):
        {
            assert(!isnan(root_1) && "root_1 is NAN");
            assert(!isnan(root_2) && "root_2 is NAN");
            printf("Корни уравнения: x_1 = %.3lg, x_2 = %.3lg\n\n", fix_root_minus_zero(root_1), fix_root_minus_zero(root_2));
            break;
        }
        case(ONE_ROOT):
        {
            assert(!isnan(root_1) && "root_1 is NAN");
            printf("Корень уравнения x = %.3lg\n\n", fix_root_minus_zero(root_1));
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
            assert(0 && " bububu");
            break;
        }
    }
}

//assert(0 && "Abx")

void greetings()
{
    printf("Введи 3 коэффициента через пробел:\n\n"
           "_x^2 + _x + _\n\n"
           "Или введи любой нечисловой символ для окончания работы\n\n");
}


void lineal_equ_solver(const double free_coef, const double x_coef, double *root_1)
{
    assert(root_1 && "&root_1 is 0");
    assert(isnan(*root_1) && "root_1 is not NAN");
    *root_1 = -free_coef / x_coef;
}

void print_discriminant(const double discr)
{
    printf("Дискриминант = %lg\n\n", discr);
}

//to do
//структуры вход/выход в мейне и др.
//завершение работы q


double fix_root_minus_zero(double root)
{
    return !is_zero(root) ?  0 : root;
}

int read_nums(double *sqr_x_coef, double *x_coef, double *free_coef)
{
    int result = 0;
    result += for_input(sqr_x_coef, result);
    result += for_input(x_coef, result);
    result += for_input(free_coef, result);
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



int Solving_Tests(const int test_num, const double sqr_x_coef, const double x_coef, const double free_coef,
                   const double discr_exp, const double root_1_exp, const double root_2_exp,
                   const int root_num_exp)
{
    double root_1 = NAN;
    double root_2 = NAN;
    double discr = NAN;
    NumRoots root_num = UNEXISTING_ROOTS;
    root_finder(&root_num, sqr_x_coef, x_coef, free_coef,
                &discr, &root_1, &root_2);

    if(root_num_exp != root_num || fabs(discr - discr_exp) > EPSILON || (root_1 - root_1_exp) > EPSILON || (root_2 - root_2_exp) > EPSILON)
    {
        printf("Calculation error in test %d:\nwith sqr_x_coef = %lg\nx_coef = %lg\nfree_coef = %lg\n\nexpected:\n"
               "discriminant = %lg\nroot number = %d\nroot_1 = %lg\nroot_2 = %lg\n\n"
               "printed:\ndiscriminant = %lg\nroot_number = %d\nroot_1 = %lg\nroot_2 = %lg\n",
               test_num, sqr_x_coef, x_coef, free_coef, discr_exp, root_num_exp, root_1_exp, root_2_exp,
               discr, root_num, root_1, root_2);
        return 0;
    }
    else
    {
        printf("Test %d is done\n", test_num);
        return 1;
    }
}
