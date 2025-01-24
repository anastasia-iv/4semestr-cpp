#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>

using namespace std;
int main() 
{
    map <pair<unsigned long long int, unsigned long long int>, unsigned long long int> x;
    unsigned long long int i, j;
    unsigned long long int key;
    while (cin >> i >> j >> key) {
        if (i || j || key != 4294967161) {
            x[{i, j}] =  (x[{i, j}] + key % 4294967161)% 4294967161;
        }
    }
    for (const auto& it : x)  {
        if (it.second) {
            cout << it.first.first << " " << it.first.second << " " << it.second << endl;
        }
    }
    return 0;
}