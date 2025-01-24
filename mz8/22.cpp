#include <iostream>
#include <cmath>
#include <sstream>
#include <string.h>
#include <list>
#include <chrono>


void func(long long a, long long b, unsigned k) {
    try {


        if (k == 0) {
            throw Result(a + b);
        } else {
            if (k > 0 && b == 1) {
                throw Result(a);
            } else if (k > 0 && b > 1) {
                try {
                    func(a, b - 1, k);
                }
                catch (const Result &r1) {
                    try {
                        long long int res = r1.pop();
                        func(a, res, k - 1);
                    }
                    catch (const Result &r2) {
                        throw r2;
                    }
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
    std :: string date;
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