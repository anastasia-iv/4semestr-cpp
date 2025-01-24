#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

int main()
{
    double x, average = 0.0, sum2 = 0.0, sum1 = 0.0;
    int n = 0;
    while (cin >> x) {
        n++;
        sum2 += x*x;
        sum1 += x;
    }    
    average = sum1/n;
    cout << setprecision(10) << average << endl;
    cout << setprecision(10) << sqrt((sum2 - 2*sum1*(average) + n * (average)*(average))/n) << endl;    
}
 