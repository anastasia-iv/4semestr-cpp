#include <iostream>
#include <vector>
#include <cstring>
#include <string.h>
#include <list>
#include <cmath>

class S { 
        int sum;
        bool b;
        int f = 0;
    public : 
        S () {
            int a;
            f = 0;
            if (std :: cin >> a) {
                b = true;
                sum = a;
                f = 1;
            } else {
                f = 0;
                b = false;
                sum = 0;
            }
        }
        S (S && rval) {
            int a = 0;
            f = 1;
            if (std :: cin >> a) {
                b = true;
                sum = a;
            } else {
                b = false;
                sum = 0;
            }
            sum += rval.sum;
            rval.f = 0;

        }
        operator bool () const {
            return b;
        }
        ~S() {
            if (f) std :: cout << sum << std :: endl;
        }
};

using namespace std;
void func(S v)
{
    if (v) {
        func(move(v));
    }
}

int main()
{
    func(S());
}