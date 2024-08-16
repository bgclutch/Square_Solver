#include <TXLiB.h>


double finder_Discriminant(double sqr_x, double x, double free_coef);      //объявление функций
//double changer_Coefficient();
double finder_Root_bigger(double discr, double x_coef, double sqr_coef);
double finder_Root_smaller(double discr, double x_coef, double sqr_coef);
bool checker_Discriminant(double discrimiant);
//bool checker_Coefficient();




int main(void)
{

printf("Привет, я помогу решить квадратное уравнение)\n");    //вывод приветствия на экран
//printf("ВЫбери один из вариантов:\n");
printf("Введи коэфициенты через пробел:\n");
                                                      //вывод просьбы ввести коэффициенты
double sqr_x_coefficient = 0.0;                       //объявление переменныъ
double x_coefficient = 0.0;
double free_coefficient = 0.0;
double discriminant = 0.0;

scanf("%lf %lf %lf", &sqr_x_coefficient, &x_coefficient, &free_coefficient );  //считывание коэффициентов

printf("Ваше уравнение: %.3lfx^2%+.3lfx%+.3lf\n\n", sqr_x_coefficient, x_coefficient, free_coefficient);  //вывод уравнения на экран


discriminant = finder_Discriminant(sqr_x_coefficient, x_coefficient, free_coefficient);     //нахождение дискриминанта


if(checker_Discriminant(discriminant))    //вывод результата на экран
{
    printf("Корни уравнения: X_1 = %.3lf, X_2 = %.3lf", finder_Root_bigger(discriminant,-x_coefficient, sqr_x_coefficient), finder_Root_smaller(discriminant,-x_coefficient, sqr_x_coefficient));

}
else
{
    printf("Дискриминант меньше нуля(");
}


return 0;
}




double finder_Discriminant(double sqr_x, double x, double free_coef)    //  нахождения дискриминанта
{
    return pow(x ,2) - 4 * sqr_x * free_coef;
}


//double changer_Coefficient();


double finder_Root_bigger(double discr, double x_coef, double sqr_coef)  //  нахождение большего корня уравнения
{
    return (x_coef+sqrt(discr))/(2*sqr_coef);
}

double finder_Root_smaller(double discr, double x_coef, double sqr_coef) //  нахождение меньшего корня уравнения
{
    return (x_coef-sqrt(discr))/(2*sqr_coef);
}


bool checker_Discriminant(double discr){           //проверка дискриминанта на отрицательность
   return discr >= 0;
}

//bool checker_Coefficient();
