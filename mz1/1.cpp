#include <iostream>
using namespace std;

class Sum {long long a, b; 
public: 
    Sum (const Sum &sum1, long long c) {a = sum1.a + sum1.b, b = c; } 
    Sum (long long d, long long c) { a = d, b = c; }
    long long get() const {return a + b; }
};
