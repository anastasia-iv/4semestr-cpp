#include <iostream>
#include <cmath>
#include <cstdio>
#include <map>
#include <vector>
#include <new>
#include <cmath>
#include <functional>
#include <string>
#include "cmc_complex.h"
#include "cmc_complex_stack.h"
#include "cmc_complex_eval.h"


int main (int argc, char *argv[]) 
{
    using namespace numbers;
    complex C(argv[1]);
    double R;
    int N;
    sscanf (argv[2], "%lf", &R);
    sscanf (argv[3], "%d", &N);   
    complex integral;
    for (int h = 0; h < N; h++)
    {
        double t = (2.0 * (double)h + 1.0) * M_PI/ (double)N;
        std::vector <std::string> args;
        for (int i = 4; i < argc; i++) args.push_back(argv[i]);
        complex z(C);
        integral += eval(args, z + complex(R*cos(t), R*sin(t))) * complex(-sin(t), cos(t));
    }
    std :: cout << (integral * (R * 2 * M_PI / N)).to_string();
    return 0;
}