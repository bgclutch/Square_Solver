#include <TXLiB.h>

int main(void)
{

printf("Привет, я помогу решить квадратное уравнение)\n");  //вывод приветствия
printf("_x^2 + _x + _\n\n");
printf("Введи 3 коэффициента через пробел:\n");      //вывод просьбы ввести коэффициенты

double sqr_x_coefficient = 0.0;         //объявление переменных
double x_coefficient = 0.0;
double free_coefficient = 0.0;
double discriminant = 0.0;
double root_1 = 0.0;
double root_2 = 0.0;
bool sqr_x_coef_exists = true;

scanf("%lf %lf %lf", &sqr_x_coefficient, &x_coefficient, &free_coefficient );  //считывание коэффициентов


if(fabs(sqr_x_coefficient-0) > 0.0001)
{
    discriminant = pow(x_coefficient, 2) - 4 * sqr_x_coefficient * free_coefficient;     //нахождение дискриминанта
    printf("Ваше уравнение: %.3lfx^2%+.3lfx%+.3lf\n\n", sqr_x_coefficient, x_coefficient, free_coefficient);  //вывод квадратного уравнения
    printf("Ваш дискриминант равен %.3lf\n", discriminant);
}
else if(fabs(x_coefficient-0) > 0.0001)
{
    printf("Ваше уравнение: %.3lfx%+.3lf\n\n", x_coefficient, free_coefficient);  //вывод линейного уравнения
    sqr_x_coef_exists = false;
}
else
{
    printf("Введеные коэффициенты не могут образовать уравнение(");
    return 0;
}



if(sqr_x_coef_exists && discriminant >= 0)
{
    root_1 = (-x_coefficient - sqrt(discriminant)) / (2 * sqr_x_coefficient);
    root_2 = (-x_coefficient + sqrt(discriminant)) / (2 * sqr_x_coefficient);
    printf("Корни квадратного уравнения: x_1 = %.3lf, x_2 = %.3lf", root_1, root_2);  //вывод решения квадратного уравнения

}
else if(sqr_x_coef_exists && discriminant < 0)
{
    printf("Дискриминант меньше нуля(");
}
else
{
    root_1 = -free_coefficient / x_coefficient;
    printf("Корень линейного уравнения = %.3lf", root_1);      //вывод решения линейного уравнения
}


return 0;
}
