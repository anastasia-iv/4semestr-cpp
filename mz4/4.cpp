#include <iostream>
#include <vector>
#include <string>
#include<algorithm>

class accumulation {
    public:
        double sum = 0.0, k = 0.0;
        void operator() (double i) { sum += i; k++; }

};
using namespace std;
int main() 
{
    double x;
    vector <double> v;
    while (cin >> x) v.push_back(x);
    size_t n = v.size();

    std :: sort (std :: next (v.begin(),  n/10), std :: next (v.end(), -(n/10)));
    //for (i = 0; i < v.size(); i++) cout << v[i] << " ";
    accumulation C = for_each(std :: next (v.begin(), n/10 + (8 * n)/100), std :: next (v.end(), - (n/10) - (8 * n)/100), accumulation());
    if (C.k) {
        std :: cout << C.sum/C.k;
    } else std :: cout << C.k;
    return 0;
}
/*
20 19 18 17 16 15 14 13 12 11 10 9 8 7 6 5 4 3 2 1
    for (i = 0; i < v.size(); i++) cout << v[i] << endl;

*/