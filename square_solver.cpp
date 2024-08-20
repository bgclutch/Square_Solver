#include <TXLiB.h>
#include <stdio.h>
#include <math.h>


#define EPSILON 0.0001

enum Constant
{
    TWO_ROOTS = 2,
    UNEXISTING_ROOTS = 0,
    ONE_ROOT = 1,
    INF_ROOTS = 3
};


bool compare_to_zero(double comparable);

int roots_counter(double sqr_x_coef, double x_coef, double free_coef);

void equation_print(int root_number, double sqr_x_coef, double x_coef, double free_coef);

void result_print(int root_counter, double root_1, double root_2, double discr);

void root_finder(int *root_num, double sqr_x_coef, double x_coef, double free_coef,
 double *discr, double *root_1, double *root_2);


int main(void)
{

    printf("������, � ������ ������ ���������� ���������)\n");  //����� �����������
    printf("_x^2 + _x + _\n\n");
    printf("����� 3 ������������ ����� ������:\n\n");      //����� ������� ������ ������������

    double sqr_x_coefficient = 0.0;         //���������� ����������
    double x_coefficient = 0.0;
    double free_coefficient = 0.0;

    while (scanf("%lg %lg %lg", &sqr_x_coefficient, &x_coefficient, &free_coefficient) == 3)  //���������� �������������
    {

    int root_number = 0;

    root_number = roots_counter(sqr_x_coefficient, x_coefficient, free_coefficient);   //���������� ���������� ������

    double discriminant = 0.0;
    double root_1 = 0.0;
    double root_2 = 0.0;

    root_finder(&root_number, sqr_x_coefficient, x_coefficient, free_coefficient, &discriminant,  //���������� ������
    &root_1, &root_2);

    equation_print(root_number, sqr_x_coefficient, x_coefficient, free_coefficient);   //����� ���������

    result_print(root_number, root_1, root_2, discriminant);                 //����� ������

    printf("����� 3 ������������ ����� ������:\n\n");
    printf("_x^2 + _x + _\n\n");
    printf("��� ����� ����� ���������� ������ ��� ��������� ������\n\n");
    }
    printf("������� �� ������!\n\n");
    return 0;
}


bool compare_to_zero(double comparable)
{
    return (fabs(comparable) > EPSILON);
}


int roots_counter(double sqr_x_coef, double x_coef, double free_coef)
{
    if(compare_to_zero(sqr_x_coef))
    {
        return TWO_ROOTS;
    }
    else if(compare_to_zero(x_coef)){
        return ONE_ROOT;
    }
    else
    {
        return (compare_to_zero(free_coef))? INF_ROOTS: UNEXISTING_ROOTS;
    }
}


void equation_print(int root_number, double sqr_x_coef, double x_coef, double free_coef)
{
    printf("\n���������� ������ ��������� %lgx^2%+lgx%+lg = %d \n\n", sqr_x_coef, x_coef, free_coef, root_number);
}


void root_finder(int *root_num, double sqr_x_coef, double x_coef, double free_coef, double *discr, double *root_1, double *root_2)
{
    if(*root_num == TWO_ROOTS)
    {
        *discr = x_coef * x_coef - 4 * sqr_x_coef * free_coef;
        if(!compare_to_zero(*discr))
        {
            *root_1 = -x_coef / (2 * sqr_x_coef);
            *root_num = ONE_ROOT;
        }
        else if(!(*discr < EPSILON))
        {
            *root_1 = (-x_coef - sqrt(*discr)) / (2 * sqr_x_coef);
            *root_2 = (-x_coef + sqrt(*discr)) / (2 * sqr_x_coef);
        }
        else
        {
            *root_num = UNEXISTING_ROOTS;
        }
    }
    else if(*root_num == ONE_ROOT)
    {
        *root_1 = -free_coef / x_coef;
    }
}


void result_print(int root_counter, double root_1, double root_2, double discr)
{
    printf("������������ = %lg\n\n",discr);
    if(root_counter == TWO_ROOTS)
        printf("����� ���������: x_1 = %.3lg, x_2 = %.3lg\n\n", root_1, root_2);
    else if(root_counter == ONE_ROOT)
    {
        printf("������ ��������� x = %.3lg\n\n", root_1);
    }
    else
    {
        printf("��� ������\n\n");
    }
}
