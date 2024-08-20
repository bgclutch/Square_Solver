#include <TXLiB.h>
#include <stdio.h>
#include <math.h>


#define EPSILON 0.0001

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


int main(void)
{

    greetings(); //����� ������� ������ ������������


    double sqr_x_coefficient = NAN;         //���������� ����������
    double x_coefficient = NAN;
    double free_coefficient = NAN;

    while (scanf("%lg %lg %lg", &sqr_x_coefficient, &x_coefficient, &free_coefficient) == 3)  //���������� �������������
    {

        double discriminant = NAN;
        double root_1 = NAN;
        double root_2 = NAN;
        NumRoots root_number = UNEXISTING_ROOTS;

        root_finder(&root_number, sqr_x_coefficient, x_coefficient, free_coefficient, &discriminant, &root_1, &root_2);

        equation_print(root_number, sqr_x_coefficient, x_coefficient, free_coefficient);   //����� ���������

        result_print(root_number, root_1, root_2);                 //����� ������

        greetings();
    }
    printf("������� �� ������!\n\n");
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
            printf("\n���������� ������ ��������� '%lgx^2%+lgx%+lg' = 2 \n\n", sqr_x_coef, x_coef, free_coef);
            break;
        }
        case(ONE_ROOT):
        {
            printf("\n���������� ������ ��������� '%lgx^2%+lgx%+lg' = 1 \n\n", sqr_x_coef, x_coef, free_coef);
            break;
        }
        case(INF_ROOTS):
        {
            printf("\n���������� ������ ��������� '%lgx^2%+lgx%+lg' = infinity \n\n", sqr_x_coef, x_coef, free_coef);
            break;
        }
        case(UNEXISTING_ROOTS):
        {
            printf("\n���������� ������ ��������� '%lgx^2%+lgx%+lg' = 0 \n\n", sqr_x_coef, x_coef, free_coef);
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
            }
        }
        else if(is_zero(x_coef))
        {
            lineal_equ_solver(free_coef, x_coef, root_1);
            *root_num = ONE_ROOT;
        }
        else
        {
            *root_num = (is_zero(free_coef)) ? INF_ROOTS : UNEXISTING_ROOTS;
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
            printf("����� ���������: x_1 = %.3lg, x_2 = %.3lg\n\n", root_1, root_2);
            break;
        }
        case(ONE_ROOT):
        {
            assert(!isnan(root_1) && "root_1 is NAN");
            printf("������ ��������� x = %.3lg\n\n", root_1);
            break;
        }
        case(UNEXISTING_ROOTS):
        {
            printf("��� ������\n\n");
            break;
        }
        case(INF_ROOTS):
        {
            printf("x - �����\n\n");
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
    printf("����� 3 ������������ ����� ������:\n\n"
           "_x^2 + _x + _\n\n"
           "��� ����� ����� ���������� ������ ��� ��������� ������\n\n");
}


void lineal_equ_solver(const double free_coef, const double x_coef, double *root_1)
{
    assert(root_1 && "&root_1 is 0");
    assert(isnan(*root_1) && "root_1 is not NAN");
    *root_1 = -free_coef / x_coef;
}

void print_discriminant(const double discr)
{
    printf("������������ = %lg\n\n", discr);
}

//to do
//fix_root check -0(return abs 0) else return root include to printf
// input function and validity check
