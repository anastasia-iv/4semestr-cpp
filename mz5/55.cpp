#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <algorithm>

using namespace std;
int main() 
{
    map <pair<unsigned long long int, unsigned long long int>, unsigned long long int> a;
    map <pair<unsigned long long int, unsigned long long int>, unsigned long long int> c;
    map <unsigned long long int, map <unsigned long long int, unsigned long long int>> b;
    unsigned long long int i, j;
    unsigned long long int key, m = 0;
    while (cin >> i >> j >> key) {
        if (!i && !j && key == 4294967161) {
            break;
        } else {
            a[{i, j}] = key;
        }
        if (j > m) m = j;
    }
    while (cin >> i >> j >> key) {
        if (b.find(j) == b.end()) {
            b[j].resize(m + 1);
        }
        b[j][i] = key;
    }
    for (const auto& row : a) {
         for (const auto& column : b) {
            c[{row.first.first, column.first}] = (c[{row.first.first, column.first}] + (a[{row.first.first, row.first.second}] * b[column.first][row.first.first])% 4294967161) %  4294967161;
        }
    }
    ///*
    for (const auto& it : c)  {
        if (it.second) {
            cout << it.first.first << " " << it.first.second << " " << it.second << endl;
        }
    }
    //*/
    return 0;
}