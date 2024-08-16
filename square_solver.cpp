#include <TXLiB.h>


double finder_Discriminant(double sqr_x, double x, double free_coef);
//double changer_Coefficient();
double finder_Root_bigger(double discr, double x_coef, double sqr_coef);
double finder_Root_smaller(double discr, double x_coef, double sqr_coef);
bool checker_Discriminant(double discrimiant);
//bool checker_Coefficient();




int main(void)
{

printf("Привет, я помогу решить квадратное уравнение)\n");
//printf("ВЫбери один из вариантов:\n");
printf("Введи коэфициенты через пробел:\n");

double sqr_x_coefficient = 0.0;
double x_coefficient = 0.0;
double free_coefficient = 0.0;
double discriminant = 0.0;

scanf("%lf %lf %lf", &sqr_x_coefficient, &x_coefficient, &free_coefficient );

//printf("Если хочешь поменять коэффициент, только скажи");








discriminant = finder_Discriminant(sqr_x_coefficient, x_coefficient, free_coefficient);


if(checker_Discriminant(discriminant))
{
    printf("X_1 = %.3lf, X_2 = %.3lf", finder_Root_bigger(discriminant,-x_coefficient, sqr_x_coefficient), finder_Root_smaller(discriminant,-x_coefficient, sqr_x_coefficient));

}
else
{
    printf("Дискриминант меньше нуля(");
}


return 0;
}




double finder_Discriminant(double sqr_x, double x, double free_coef)
{
    return pow(x ,2) - 4 * sqr_x * free_coef;
}


//double changer_Coefficient();


double finder_Root_bigger(double discr, double x_coef, double sqr_coef)
{
    return (x_coef+sqrt(discr))/(2*sqr_coef);
}

double finder_Root_smaller(double discr, double x_coef, double sqr_coef)
{
    return (x_coef-sqrt(discr))/(2*sqr_coef);
}


bool checker_Discriminant(double discr){
   return discr >= 0;
}

//bool checker_Coefficient();
