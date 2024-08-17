#include <TXLiB.h>

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
bool sqr_x_coef_exists = true;

scanf("%lf %lf %lf", &sqr_x_coefficient, &x_coefficient, &free_coefficient );  //���������� �������������


if(fabs(sqr_x_coefficient-0) > 0.0001)
{
    discriminant = pow(x_coefficient, 2) - 4 * sqr_x_coefficient * free_coefficient;     //���������� �������������
    printf("���� ���������: %.3lfx^2%+.3lfx%+.3lf\n\n", sqr_x_coefficient, x_coefficient, free_coefficient);  //����� ����������� ���������
    printf("��� ������������ ����� %.3lf\n", discriminant);
}
else if(fabs(x_coefficient-0) > 0.0001)
{
    printf("���� ���������: %.3lfx%+.3lf\n\n", x_coefficient, free_coefficient);  //����� ��������� ���������
    sqr_x_coef_exists = false;
}
else
{
    printf("�������� ������������ �� ����� ���������� ���������(");
    return 0;
}



if(sqr_x_coef_exists && discriminant >= 0)
{
    root_1 = (-x_coefficient - sqrt(discriminant)) / (2 * sqr_x_coefficient);
    root_2 = (-x_coefficient + sqrt(discriminant)) / (2 * sqr_x_coefficient);
    printf("����� ����������� ���������: x_1 = %.3lf, x_2 = %.3lf", root_1, root_2);  //����� ������� ����������� ���������

}
else if(sqr_x_coef_exists && discriminant < 0)
{
    printf("������������ ������ ����(");
}
else
{
    root_1 = -free_coefficient / x_coefficient;
    printf("������ ��������� ��������� = %.3lf", root_1);      //����� ������� ��������� ���������
}


return 0;
}
