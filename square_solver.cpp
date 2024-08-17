#include <TXLiB.h>
#include <stdio.h>
#include <math.h>

#define POS_COMPARER 0.0001
#define NEG_COMPARER -0.0001

bool compare_to_zero(double comparable);

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
    int root_counter = 0;

    scanf("%lf %lf %lf", &sqr_x_coefficient, &x_coefficient, &free_coefficient );  //считывание коэффициентов


    if(compare_to_zero(sqr_x_coefficient))
    {
        root_counter = 2;
        printf("Ваше уравнение: %.3lfx^2%+.3lfx%+.3lf\n\n", sqr_x_coefficient, x_coefficient, free_coefficient);  //вывод квадратного уравнения
        printf("Количество корней уравнения %d\n", root_counter);
    }
    else if(compare_to_zero(x_coefficient))
    {
        root_counter = 1;
        printf("Ваше уравнение: %.3lfx%+.3lf\n\n", x_coefficient, free_coefficient);  //вывод линейного уравнения
        printf("Количество корней уравнения %d\n", root_counter);
    }
    else
    {
        printf("Введеные коэффициенты не могут образовать уравнение(\n");
        return 0;
    }


    if(root_counter == 2)                                                      //рассчетный блок
    {
        discriminant = x_coefficient*x_coefficient - 4 * sqr_x_coefficient * free_coefficient;
        if(compare_to_zero(discriminant))
        {
            root_1 = (-x_coefficient - sqrt(discriminant)) / (2 * sqr_x_coefficient);
            root_2 = (-x_coefficient + sqrt(discriminant)) / (2 * sqr_x_coefficient);
        }
        else
        {
            printf("Дискриминант меньше нуля(\n");
            return 0;
        }
    }
    else
        root_1 = -free_coefficient / x_coefficient;





    if(root_counter == 2)
        printf("Корни квадратного уравнения: x_1 = %.3lf, x_2 = %.3lf\n", root_1, root_2);  //вывод решения квадратного уравнения
    else
    {
        printf("Корень линейного уравнения = %.3lf\n", root_1);      //вывод решения линейного уравнения
    }

    return 0;
}


 bool compare_to_zero(double comparable)
 {
    return (comparable > POS_COMPARER || comparable < NEG_COMPARER);
 }
