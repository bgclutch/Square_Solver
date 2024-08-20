#include <TXLiB.h>
#include <stdio.h>
#include <math.h>



enum constants
{
    epsilon = 0.0001,
    two_roots = 2,
    unexisting_roots = 0,
    one_root = 1,
    inf_roots = 3
};



bool pos_compare_to_zero(double comparable);
bool neg_compare_to_zero(double comparable);
int roots_counter(double sqr_x_coef, double x_coef, double free_coef);
int print_equation(int root_number, double sqr_x_coef, double x_coef, double free_coef);

int main(void)
{

    printf("������, � ������ ������ ���������� ���������)\n");  //����� �����������
    printf("_x^2 + _x + _\n\n");
    printf("����� 3 ������������ ����� ������:\n");      //����� ������� ������ ������������

    double sqr_x_coefficient = 0.0;         //���������� ����������
    double x_coefficient = 0.0;
    double free_coefficient = 0.0;
    double discriminant = 0.0;
    double root_1 = 0.0;
    double root_2 = 0.0;
    int root_number = 0;

    scanf("%lg %lg %lg", &sqr_x_coefficient, &x_coefficient, &free_coefficient );  //���������� �������������


    root_number = roots_counter(sqr_x_coefficient, x_coefficient, free_coefficient);

    print_equation(root_number, sqr_x_coefficient, x_coefficient, free_coefficient);

   /* if(root_number == )                                                      //���������� ����
    {
        discriminant = x_coefficient*x_coefficient - 4 * sqr_x_coefficient * free_coefficient;
        if(!neg_compare_to_zero(discriminant))         //�������� ����������������� �������������
        {
            if(pos_compare_to_zero(discriminant))                      //�������� ������������� �� "0"
            {
                root_counter = 2;
                root_1 = (-x_coefficient - sqrt(discriminant)) / (2 * sqr_x_coefficient);      //����������� ��� ������������� > 0
                root_2 = (-x_coefficient + sqrt(discriminant)) / (2 * sqr_x_coefficient);
                printf("���������� ������ ��������� %d\n", root_counter);
            }
            else
            {
                root_counter = 1;                                                     //����������� ��� ������������ == 0
                root_1 = -x_coefficient / (2 * sqr_x_coefficient);
                printf("���������� ������ ��������� %d\n", root_counter);
            }
        }
        else                                                             //����������� ��� ������������� < 0
        {
            printf("������������ ������ ����, x �����\n");
            return 0;
        }
    }
    else                                                                    //������� � ��������� ���������
    {
        root_1 = -free_coefficient / x_coefficient;
    }  */


    if(root_counter == 2)
        printf("����� ���������: x_1 = %.3lg, x_2 = %.3lg\n", root_1, root_2);  //����� ������� ����������� ���������
    else
    {
        printf("������ ��������� x = %.3lg\n", root_1);      //����� ������� ��������� ��������� ��� ����������� ��������� � ����� ������
    }

    return;
}


bool compare_to_zero(double comparable)
{
    return (fabs(comparable) > POS_EPSILON);
}

int roots_counter(double sqr_x_coef, double x_coef, double free_coef)
{
    if(compare_to_zero(sqr_x_coef))
    {
        return -1;
    }
    else if(compare_to_zero(x_coef)){
        return 1;
    }
    else
    {
        return (compare_to_zero(free_coef))? INF_ROOTS: NO_ROOTS;
    }
}

int print_equation(int root_number, double sqr_x_coef, double x_coef, double free_coef)
{
    switch(root_number)
    {
        case UNEXISTING_ROOTS:
        {
             printf("��������� %lgx^2 %+lgx %+lg �� ����� ������\n\n", sqr_x_coef, x_coef, free_coef);
        }
        case INF_ROOTS:
        {
            printf("��������� %lgx^2 %+lgx %+lg ����� ����������� ���������� ������\n\n", sqr_x_coef, x_coef, free_coef);
        }
        case ONE_ROOT:
        {
            printf("��������� %lgx %+lg ����� ���� ������\n\n", x_coef, free_coef);
        }
        case TWO_ROOTS:
        {
            printf("��������� %lgx^2 %+lgx %+lg ����� ��� �����\n\n", sqr_x_coef, x_coef, free_coef);
        }
        default:
        {
            printf("��� ������\n\n");
            return 0;
        }
    }
}

int root_finder(int root_num, double sqr_x_coef, double x_coef, double free_coef, double *discr, double *root_1, double *root_2)
{     if(root_num == two_roots)
      {
        discr = x_coef*x_coef - 4 * sqr_x_coef * free_coef;
        if(!compare_to_zero(discr))
        {
            if(compare_to_zero(discr))
            {
                *root_1 = -x_coef/ (2 * sqr_x_coef);
            }
            else
            {
                *root_1 = (-x_coef - sqrt(discr)) / (2 * sqr_x_coef);
                *root_2 = (-x_coef + sqrt(discr)) / (2 * sqr_x_coef);
            }
        }
        else
        {
            printf("������������ ������ ����, x �����\n");
            return 0;
        }
    }
    else
    {
        *root_1 = -free_coef / x_coef;
    }
}
