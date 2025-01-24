#include <iostream>
#include <cmath>
#include <sstream>
#include <string.h>
#include <list>
#include <chrono>

class Result {
    long long x;
    public :
    Result (long long x_x): x(x_x) {};
    long long int pop () const {
        return x;
    }
};

void func(long long a, long long b, unsigned k) {
    try {


        if (k == 0) {
            throw Result(a + b);
        } 
        if (k > 0 && b == 1) {
            throw Result(a);
        }
        if (k > 0 && b > 1) {
            try {
                func(a, b - 1, k);
            }
            catch (const Result &r1) {
                try {
                    long long int res = r1.pop();
                    func(a, res, k - 1);
                }
                catch (const Result &r2) {
                    throw;
                }
            }
        }
    }
    catch(const Result &r) {
        throw;
    }


}

int main()
{
    //std :: string date;
    long long a, b;
    unsigned k;
    while (std :: cin >> a >> b >> k) {
        try {
            func(a, b, k);
        }
        catch(const Result &r) {
            std :: cout << r.pop() << std :: endl;
        }
    }
}