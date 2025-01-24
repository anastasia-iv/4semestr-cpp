#include <iostream>
#include <vector>
#include <string>
#include<algorithm>

int bits_sum (int x) {
    int sum = 0;
    while (x > 0) {
        sum += x % 2;
        x >>= 1;
    }
    return sum;
}
bool compare (int a, int b) {
    return (bits_sum(a) < bits_sum(b));
}
using namespace std;
int main() 
{
    long unsigned int i = 0;
    int x;
    vector <int> v;
    while (cin >> x) v.push_back(x);
    stable_sort(v.begin(), v.end(), compare);
    for (i = 0; i < v.size(); i++) cout << v[i] << endl;
    return 0;
}