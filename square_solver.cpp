#include <TXLiB.h>
#include <stdio.h>
#include <math.h>
#include <inttypes.h>


#define EPSILON 0.001

enum NumRoots
{
    UNEXISTING_ROOTS = 0,
    ONE_ROOT         = 1,
    TWO_ROOTS        = 2,
    INF_ROOTS        = 3,
};

struct Unit_Test_Data
{
    int test_num;
    double sqr_x_coef;
    double x_coef;
    double free_coef;
    double discr_exp;
    double root_1_exp;
    double root_2_exp;
    int root_num_exp;
};

struct Equation_Coefficients_Data
{
    double sqr_x_coef;
    double x_coef;
    double free_coef;
};

struct Equation_Attributes_Data
{
    double discr;
    double root_1;
    double root_2;
    NumRoots root_number;
};



bool is_zero(const double comparable);

void equation_print(const Equation_Coefficients_Data coefficients, const Equation_Attributes_Data equation_parts);

void result_print (Equation_Attributes_Data equation_parts);

void square_equ_solver(const Equation_Coefficients_Data coefficients, Equation_Attributes_Data *equation_parts);

void greetings();

void lineal_equ_solver(const double free_coef, const double x_coef, double *root_1, Equation_Attributes_Data *equation_parts);

double fix_root_minus_zero(double root);

int read_nums(Equation_Coefficients_Data *coefficients);

bool buff_clean_and_check();

int for_input(double *coef, int counter);

bool continue_or_finish();

int Solving_Tests(Unit_Test_Data test);

void Unit_Tests();

void is_min(double *root_1, double *root_2);

void my_swap(void* var_1, void* var_2, int size);


int main(void)
{

    //Unit_Tests();

    greetings(); //вывод просьбы ввести коэффициенты

    struct Equation_Coefficients_Data coefficients =
        {
          .sqr_x_coef = NAN,
          .x_coef = NAN,
          .free_coef = NAN
        };

    while (read_nums(&coefficients) == 3)  //считывание коэффициентов
    {

        struct Equation_Attributes_Data equation_parts =
            {
              .discr = NAN,
              .root_1 = NAN,
              .root_2 = NAN,
              .root_number = UNEXISTING_ROOTS
            };

        square_equ_solver(coefficients, &equation_parts);

        equation_print(coefficients, equation_parts);   //вывод уравнения

        result_print(equation_parts);                 //вывод ответа
    }

    printf("Спасибо за работу!\n\n");
    return 0;
}


bool is_zero(const double comparable)
{
    return (fabs(comparable) > EPSILON);
}


void equation_print(const Equation_Coefficients_Data coefficients, const Equation_Attributes_Data equation_parts) //switch
{
    switch(equation_parts.root_number)
    {
        case(TWO_ROOTS):
        {
            printf("\nКоличество корней уравнения '%lgx^2%+lgx%+lg' = 2 \n\n", coefficients.sqr_x_coef, coefficients.x_coef, coefficients.free_coef);
            break;
        }
        case(ONE_ROOT):
        {
            printf("\nКоличество корней уравнения '%lgx^2%+lgx%+lg' = 1 \n\n", coefficients.sqr_x_coef, coefficients.x_coef, coefficients.free_coef);
            break;
        }
        case(INF_ROOTS):
        {
            printf("\nКоличество корней уравнения '%lgx^2%+lgx%+lg' = infinity \n\n", coefficients.sqr_x_coef, coefficients.x_coef, coefficients.free_coef);
            break;
        }
        case(UNEXISTING_ROOTS):
        {
            printf("\nКоличество корней уравнения '%lgx^2%+lgx%+lg' = 0 \n\n", coefficients.sqr_x_coef, coefficients.x_coef, coefficients.free_coef);
            break;
        }
        default:
        {
            assert(0 && "equation_print crashed");
            break;
        }
    }
}


void square_equ_solver(const Equation_Coefficients_Data coefficients, Equation_Attributes_Data *equation_parts)
{
    assert((&(*equation_parts).root_number) && "&root_num is 0");
    assert((&(*equation_parts).discr) && "&discr is 0");
    assert((&(*equation_parts).root_1) && "&root_1 is 0");
    assert((&(*equation_parts).root_2) && "&root_2 is 0");
    assert(isnan(equation_parts->discr) && "discr is not NAN");
    assert(isnan(equation_parts->root_1) && "root_1 is not NAN");
    assert(isnan(equation_parts->root_2) && "root_2 is not NAN");

    if(is_zero(coefficients.sqr_x_coef))
        {
            equation_parts->discr = coefficients.x_coef * coefficients.x_coef - 4 * coefficients.sqr_x_coef * coefficients.free_coef;
            if(!is_zero(equation_parts->discr))
            {
                equation_parts->root_1 = -(coefficients.x_coef) / (2 * coefficients.sqr_x_coef);
                equation_parts->root_number = ONE_ROOT;
            }
            else if(equation_parts->discr > EPSILON)
            {
                assert(equation_parts->discr > EPSILON && "discr is negative");//discr
                equation_parts->root_1 = (-(coefficients.x_coef) - sqrt(equation_parts->discr)) / (2 * coefficients.sqr_x_coef);
                equation_parts->root_2 = (-(coefficients.x_coef) + sqrt(equation_parts->discr)) / (2 * coefficients.sqr_x_coef);
                is_min(&(equation_parts->root_1), &(equation_parts->root_2));
                equation_parts->root_number = TWO_ROOTS;
            }
            else
            {
                equation_parts->root_number = UNEXISTING_ROOTS;
            }
        }
        else if(is_zero(coefficients.x_coef))
        {
            lineal_equ_solver(coefficients.free_coef, coefficients.x_coef, &(equation_parts->root_1), equation_parts);
        }
        else
        {
            equation_parts->root_number = (is_zero(coefficients.free_coef)) ? UNEXISTING_ROOTS : INF_ROOTS;
        }
}


void result_print(const Equation_Attributes_Data equation_parts)
{
    switch(equation_parts.root_number)
    {
        case(TWO_ROOTS):
        {
            assert(!isnan(equation_parts.root_1) && "root_1 is NAN");
            assert(!isnan(equation_parts.root_2) && "root_2 is NAN");
            printf("Корни уравнения: x_1 = %.3lg, x_2 = %.3lg\n\n", fix_root_minus_zero(equation_parts.root_1),
                   fix_root_minus_zero(equation_parts.root_2));
            break;
        }
        case(ONE_ROOT):
        {
            assert(!isnan(equation_parts.root_1) && "root_1 is NAN");
            printf("Корень уравнения x = %.3lg\n\n", fix_root_minus_zero(equation_parts.root_1));
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
            assert(0 && "result_print crashed");
            break;
        }
    }
}


void greetings()
{
    printf("Введи 3 коэффициента через пробел:\n\n"
           "_x^2 + _x + _\n\n"
           "Или введи 'q' для окончания работы\n\n");
}


void lineal_equ_solver(const double free_coef, const double x_coef, double *root_1, Equation_Attributes_Data *equation_parts)
{
    assert(root_1 && "&root_1 is 0");
    assert(isnan(*root_1) && "root_1 is not NAN");
    *root_1 = -free_coef / x_coef;
    equation_parts->root_number = ONE_ROOT;
}


double fix_root_minus_zero(double root)
{
    return !is_zero(root) ?  0 : root;
}

int read_nums(Equation_Coefficients_Data *coefficients)
{
    if(continue_or_finish())
    {

    }
    else
    {
        break;
    }
    int result = 0;
    result += for_input(&(coefficients->sqr_x_coef), result);
    result += for_input(&(coefficients->x_coef), result);
    result += for_input(&(coefficients->free_coef), result);
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



int Solving_Tests(Unit_Test_Data test)
{
    struct Equation_Coefficients_Data coefficients =
        {
          .sqr_x_coef = test.sqr_x_coef,
          .x_coef = test.x_coef,
          .free_coef = test.free_coef
        };

    struct Equation_Attributes_Data equation_parts =
        {
          .discr = NAN,
          .root_1 = NAN,
          .root_2 = NAN,
          .root_number = UNEXISTING_ROOTS
        };

    square_equ_solver(coefficients, &equation_parts);

    if(test.root_num_exp != equation_parts.root_number || fabs(equation_parts.discr - test.discr_exp) > EPSILON || (equation_parts.root_1 - test.root_1_exp) > EPSILON ||
      (equation_parts.root_2 - test.root_2_exp) > EPSILON)
    {
        printf("Calculation error in test %d:\nwith sqr_x_coef = %lg\nx_coef = %lg\nfree_coef = %lg\n\nexpected:\n"
               "discriminant = %lg\nroot number = %d\nroot_1 = %lg\nroot_2 = %lg\n\n"
               "printed:\ndiscriminant = %lg\nroot_number = %d\nroot_1 = %lg\nroot_2 = %lg\n",
               test.test_num, test.sqr_x_coef, test.x_coef, test.free_coef, test.discr_exp, test.root_num_exp,
               test.root_1_exp, test.root_2_exp,
               equation_parts.discr, equation_parts.root_number, equation_parts.root_1, equation_parts.root_2);
        return 0;
    }
    else
    {
        printf("Test %d is done\n", test.test_num);
        return 1;
    }
}


void Unit_Tests()
{
    struct Unit_Test_Data testing_data_array[] =
    {  //  #,    x^2,    x,  fr_co,         D,        x1,        x2,         root_num
         { 1,     0,     0,      0,       NAN,       NAN,       NAN,        INF_ROOTS},
         { 2,     0,     0,      3,       NAN, INF_ROOTS, INF_ROOTS, UNEXISTING_ROOTS},
         { 3,    -4,     3,      8,       137,    -1.088,     1.388,                2},
         { 4,     1,     6,      9,         0,        -3,       NAN,                1},
         { 5,     1,     0,    -16,        64,        -4,         4,                2},
         { 6, 1.674, 673.5,     -5, 453635.73,  -402.337,     0.007,                2},
         { 7,    16,   128, -872.7,   72236.8, -  12.399,     4.399,                2},
         { 8,    10,   -57,   -672,     30129,    -5.829,    11.529,                2},
         { 9,    10,   -57,    672,    -23631,       NAN,       NAN,                0},
         {10,     0,     5, -45.72,       NAN,     9.144,       NAN,                1}
    };

    printf("result %lg means not existing root\n\n"         //unit tests
           "result %d means ifinity of roots\n\n", NAN, INF_ROOTS);
    int test_counter = 0;

    for(unsigned int array_index = 0; array_index < sizeof(testing_data_array) / sizeof(testing_data_array[0]); array_index++)
    {
        test_counter += Solving_Tests(testing_data_array[array_index]);
        printf("\n");
    }


    printf("%d out of %d tests done correct ", test_counter, sizeof(testing_data_array)/sizeof(testing_data_array[0]));
}

bool continue_or_finish()
{
    printf("Введи 1 для продолжения или 'q', чтобы закончить:\n\n");

    for(int tries = 6; char var_char = getchar(); tries--)
    {
        char var_char = getchar();
        if(var_char == 'q')
        {
            return 0;
        }
        else if(var_char == '1')
        {
            return 1;
        }
        else
        {
         printf("Попробуй еще раз, осталось %d попыток", tries - 1);
        }
        if (tries == 1)
            return 0;
    }
}

void is_min(double *root_1, double *root_2)
{
    if(*root_1 > *root_2)
    {
        my_swap(root_1, root_2, sizeof(*root_1));
    }
}

void my_swap(void* var_1, void* var_2, int size)//побайтовый свап
{
    int add_bytes = 0;

    uint64_t *ptr_var_long_1 = (uint64_t*)var_1;
    uint64_t *ptr_var_long_2 = (uint64_t*)var_2;
    printf("start swapping: %p %p\n", ptr_var_long_1, ptr_var_long_2);

    for(; size >= sizeof(uint64_t); ptr_var_long_1++, ptr_var_long_2++, size -= sizeof(uint64_t), add_bytes += sizeof(uint64_t))
    {
        uint64_t imba = *ptr_var_long_1;
        *ptr_var_long_1 = *ptr_var_long_2;
        *ptr_var_long_2 = imba;
        //printf("swap in long start: %p %p %d\n", ptr_var_long_1, ptr_var_long_2, size);
    }
    //printf("swap in long finish: %p %p\n\n", ptr_var_long_1 + add_bytes, ptr_var_long_2 + add_bytes);

    uint32_t *ptr_var_int_1 = (uint32_t*)(var_1) + add_bytes;
    uint32_t *ptr_var_int_2 = (uint32_t*)(var_2) + add_bytes;

    if(size / sizeof(uint32_t) == 1)
    {
        uint32_t imba = *ptr_var_int_1;
        *ptr_var_int_1 = *ptr_var_int_2;
        *ptr_var_int_2 = imba;
        size %= sizeof(uint32_t);
        add_bytes += sizeof(uint32_t);
        //printf("swap in int start: %p %p\n", ptr_var_int_1, ptr_var_int_2);
        //printf("swap in int finish: %p %p\n\n", ptr_var_int_1 + add_bytes,
               // ptr_var_int_2 + add_bytes);
    }

    uint16_t *ptr_var_short_1 = (uint16_t*)(var_1) + add_bytes;
    uint16_t *ptr_var_short_2 = (uint16_t*)(var_2) + add_bytes;

    if(size / sizeof(uint16_t) == 1)
    {
        uint16_t imba = *ptr_var_short_1;
        *ptr_var_short_1 = *ptr_var_short_2;
        *ptr_var_short_2 = imba;
        size %= sizeof(uint16_t);
        add_bytes += sizeof(uint16_t);
        //printf("swap in short start: %p %p\n", ptr_var_short_1, ptr_var_short_2);
        //printf("swap in int finish: %p %p\n\n", ptr_var_short_1 + add_bytes,
                //ptr_var_short_2 + add_bytes);
    }

    uint8_t *ptr_var_char_1 = (uint8_t*)var_1 + add_bytes;
    uint8_t *ptr_var_char_2 = (uint8_t*)var_2 + add_bytes;

    if(size / sizeof(uint8_t) == 1)
    {
        uint8_t imba = *ptr_var_char_1;
        *ptr_var_char_1 = *ptr_var_char_2;
        *ptr_var_char_2 = imba;
        size %= sizeof(uint8_t);
        add_bytes += sizeof(uint8_t);
        //printf("swap in char start: %p %p\n", ptr_var_char_1, ptr_var_char_2);
        //printf("swap in int finish: %p %p\n\n", ptr_var_char_1 + add_bytes,
               // ptr_var_char_2 + add_bytes);
    }
}
