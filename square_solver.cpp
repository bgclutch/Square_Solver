#include <TXLiB.h>
#include <stdio.h>
#include <math.h>

#define POS_COMPARER 0.0001
#define NEG_COMPARER -0.0001

bool compare_to_zero(double comparable);

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
    int root_counter = 0;

    scanf("%lf %lf %lf", &sqr_x_coefficient, &x_coefficient, &free_coefficient );  //���������� �������������


    if(compare_to_zero(sqr_x_coefficient))
    {
        root_counter = 2;
        printf("���� ���������: %.3lfx^2%+.3lfx%+.3lf\n\n", sqr_x_coefficient, x_coefficient, free_coefficient);  //����� ����������� ���������
        printf("���������� ������ ��������� %d\n", root_counter);
    }
    else if(compare_to_zero(x_coefficient))
    {
        root_counter = 1;
        printf("���� ���������: %.3lfx%+.3lf\n\n", x_coefficient, free_coefficient);  //����� ��������� ���������
        printf("���������� ������ ��������� %d\n", root_counter);
    }
    else
    {
        printf("�������� ������������ �� ����� ���������� ���������(\n");
        return 0;
    }


    if(root_counter == 2)                                                      //���������� ����
    {
        discriminant = x_coefficient*x_coefficient - 4 * sqr_x_coefficient * free_coefficient;
        if(compare_to_zero(discriminant))
        {
            root_1 = (-x_coefficient - sqrt(discriminant)) / (2 * sqr_x_coefficient);
            root_2 = (-x_coefficient + sqrt(discriminant)) / (2 * sqr_x_coefficient);
        }
        else
        {
            printf("������������ ������ ����(\n");
            return 0;
        }
    }
    else
        root_1 = -free_coefficient / x_coefficient;





    if(root_counter == 2)
        printf("����� ����������� ���������: x_1 = %.3lf, x_2 = %.3lf\n", root_1, root_2);  //����� ������� ����������� ���������
    else
    {
        printf("������ ��������� ��������� = %.3lf\n", root_1);      //����� ������� ��������� ���������
    }

    return 0;
}


 bool compare_to_zero(double comparable)
 {
    return (comparable > POS_COMPARER || comparable < NEG_COMPARER);
 }
