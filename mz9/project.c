#ifdef TEST
#define big 1
#else
#define big 0
#endif

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

double f1(double x);
double f2(double x);
double f3(double x);

char func[3][25] = {"f1(x) = 2^x + 1", "f2(x) = x^5", "f3(x) = (1 - x)/3"};
int number_of_iterations = 0;

double root(double (*f)(double), double (*g)(double), double a, double b, double eps1) //Вычисление с точностью ε1 корня x уравнения f(x) = g(x) на отрезке[a, b]
{
    double c;
    int flag;
    if (((f(a) - g(a) < 0) && (f((a+b)/2) - g((a+b)/2) <= (f(a) - g(a) + f(b) - g(b))/2)) || //возратает и выпукла вниз
        ((f(a) - g(a) > 0) && (f((a+b)/2) - g((a+b)/2) > (f(a) - g(a) + f(b) - g(b))/2))){   //убывает и выпукла вверх
        flag = 1;
    } //случай 1(приближение слева)
    else {
        flag = 0;
    } //случай 2(приближение справа)
    c = (a*(f(b) - g(b)) - b*(f(a) - g(a)))/((f(b) - g(b)) - (f(a) - g(a)));
    while (flag*(f(c) - g(c))*(f(c + eps1) - g(c + eps1)) + (1 - flag)*(f(c) - g(c))*(f(c - eps1) - g(c - eps1)) > 0){
         c = (a*(f(b) - g(b)) - b*(f(a) - g(a)))/((f(b) - g(b)) - (f(a) - g(a)));
         if (flag)
            a = c;
         else
            b = c;
         number_of_iterations++;
    }
    return c;
}

double integral(double (*f)(double), double a, double b, double eps2) //Вычисление с точностью ε2 величины определенного интеграла от функции f(x) на отрезке [a, b]
{
    double h = (b - a)/10;
    double i0 = 0.0, in, x = a; //значение I1
    int n = 10, i;
    double curr_sum = (f(a)+f(b))*0.5;
    for (i = 1; i <= 9; i++){
        curr_sum += f(x);
        x += h;
    }
    in = curr_sum * h;
    i0 = in - 3*eps2 - 1;
    while (((fabs(in - i0)/3) >= eps2)){
        //printf("%lf ", fabs(In - I0)/3);
        i0 = in; //значение на предыдущем шаге
        h = h * 0.5;
        x = a + h;
        n *= 2;
        for  (i = 1; i <= n/2; i++){
            curr_sum += f(x);
            x += 2.0*h;
        }
        in = curr_sum * h; // считаем новый член посл-ти
        //printf("%lf %lf sum %lf\n", in, i0, curr_sum);
    } // проверяем точность вычислений
    return in;
}

void help(void) // функция вывода на экран информации о всей программе
{
    printf("Выполняется вычисление площади фигуры, ограниченной заданными графиками: (1)%s, (2)%s, (3)%s.\n Ключи:\n"
           "-root (вывод абсцисс точек пересечения кривых)\n -iterations (вывод числа итераций, потребовавшихся на приближенное решение уравнений при поиске точек пересечения)\n"
           "--test-root (тестирование функции root)\n --test-integral (тестирование функции integral)\n", func[0], func[1], func[2]);
}

double r1 (double x)
{
    return x*x - 3*x + 3;
}
double r2 (double x)
{
    return x;
}
double r3 (double x)
{
    return 1/(x - 1);
}

void test_root(char **argv) // функция тестирования функции root
{
    int i1, i2;
    printf("Index of the function to find the root of:\n (1)y = x*x - 3x + 3 \n (2)y = x\n (3)y = 1/(x - 1)\n");
    double a, b, e, r;
    sscanf(argv[2], "%d:%d:%lf:%lf:%lf:%lf", &i1, &i2, &a, &b, &e, &r);
    double dx;
    double result;
    if ((i1 == 1 && i2 == 2) || (i1 == 2 && i2 == 1)){
        result = root(r2, r1, a, b, e);
        dx = fabs(r - result); //[0;1.25] 1
    }
    if ((i1 == 2 && i2 == 3) || (i1 == 3 && i2 == 2)){
        result = root(r3, r2, a, b, e);
        dx = fabs(r - result); //[1.5; 2] 1.618
    }
    if ((i1 == 1 && i2 == 3) || (i1 == 3 && i2 == 1)){
        result = root(r3, r1, a, b, e);
        dx = fabs(r - result); //[1.75; 3] 2
    }
    printf("%lf %lf %lf\n ", result, dx, dx/r);
}

double i1(double x)
{
    return sqrt(x) - 3; //[9;21]
}
double i2(double x)
{
    return 4*x-x*x; //[2;4]
}
double i3(double x)
{
    return 2 - x; //[0;2]
}

void test_integral(char **argv) // функция тестирования функции integral
{
    int i;
    printf("Index of the function whose integral needs to be calculated:\n (1)y = sqrt(x) - 3 \n (2)y = 4*x - x*x \n (3)y = 2 - x \n");
    double a, b, e, r;
    sscanf(argv[2], "%d:%lf:%lf:%lf:%lf", &i, &a, &b, &e, &r);
    double dx;
    double result;
    if (i == 1){
        result = integral(i1, a, b, e);
        dx = fabs(r - result);
    }
    if (i == 2){
        result = integral(i2, a, b, e);
        dx = fabs(r - result);
    }
    if (i == 3){
        result = integral(i3, a, b, e);
        dx = fabs(r - result);
    }
    printf("%lf %lf %lf\n ", result, dx, dx/r);
}

void iterations(int number_of_iterations) //число итераций
{
    printf("%d\n", number_of_iterations);
}
void root_abs(double x1, double x2, double x3){ //функция вывода на экран абсцисс точек перечесения трех функций
    printf("Точки пересечения функций:\n");
    printf("%s и %s : %lf \n", func[0], func[1], x1);
    printf("%s и %s : %lf \n", func[1], func[2], x3);
    printf("%s и %s : %lf \n", func[2], func[0], x2);
}

void big_test(void)
{
    double r, result, dx;
    printf("functions to find the root of:\n (1)y = x*x - 3*x + 3 \n (2)y = x \n (3)y = 1/(x - 1) \n root:\n");
    printf("1:2:0.1:1.25:0.001:1.0\n");
    r = 1.0;
    result = root(r2, r1, 0.1, 1.25, 0.0001);
    dx = fabs(r - result); //[0;1.25] 1
    printf("%lf %lf %lf\n", result, dx, dx/r);

    printf("2:3:1.5:2.1:0.001:1.618\n");
    r = 1.618;
    result = root(r3, r2, 1.5, 2.1, 0.0001);
    dx = fabs(r - result); //[0; 2] 1.618
    printf("%lf %lf %lf\n", result, dx, dx/r);

    printf("1:3:1.75:3.1:0.001:2.0\n"); //[1.75; 3] 2
    r = 2.0;
    result = root(r3, r1, 1.75, 3.1, 0.0001);
    dx = fabs(r - result);
    printf("%lf %lf %lf\n", result, dx, dx/r);

    printf("functions whose integral needs to be calculated:\n (1)y = sqrt(x) - 3 \n (2)y = 4*x - x*x \n (3)y = cosx \n");
    printf("\nintegral:\n");

    printf("1:9.0:21.0:0.001:10.156\n");
    r = 10.156;
    result = integral(i1, 9.0, 21.0, 0.0001);
    dx = fabs(r - result);
    printf("%lf %lf %lf\n", result, dx, dx/r);

    printf("2:2.0:4.0:0.001:5.333\n");
    r = 5.333;
    result = integral(i2, 2.0, 4.0, 0.0001);
    dx = fabs(r - result);
    printf("%lf %lf %lf\n", result, dx, dx/r);

    printf("3:0.0:2.0:0.001:2.0\n");
    r = 2.0;
    result = integral(i3, 0.0, 2.0, 0.0001);
    dx = fabs(r - result);
    printf("%lf %lf %lf\n", result, dx, dx/r);
}

int main(int argc, char** argv)
{
     if(argc > 1) {
        if (!strcmp(argv[1], "--test-root") || !strcmp(argv[1], "-R")){
            test_root(argv);
            return 0;
        }
        if (!strcmp(argv[1], "--test-integral") || !strcmp(argv[1], "-I")){
            test_integral(argv);
            return 0;
        }
        if (!strcmp(argv[1], "--help") || !strcmp(argv[1], "-h")){
            help();
            return 0;
        }
    }
    if (big){
        big_test();
        return 0;
    }
    double eps = 0.00001, a, b, x1, x2, x3;
    int i;
    a = 0.0;
    b = 1.5;
    x1 = root(f1, f2, a, b, eps); // точка пересечения f1 и f2
    a = -4.0;
    b = -2.0;
    x2 = root(f1, f3, a, b, eps); // точка пересечения f1 и f3
    a = 0.0;
    b = 1.0;
    x3 = root(f2, f3, a, b, eps); // точка пересечения f2 и f3
    for (i = 1; i < argc; i++){
        if (!strcmp(argv[i], "-root") || !strcmp(argv[i], "-r")){
            root_abs(x1, x2, x3);
        }
        else if (!strcmp(argv[i], "--iterations") || !strcmp(argv[i], "-i")){
            iterations(number_of_iterations);
        }
    }
    double s = integral(f1, x2, x1, eps) - integral(f2, x3, x1, eps) - integral(f3, x2, x3, eps);
    printf("Площадь фигуры: %.4lf\n", s);
    return 0;
}