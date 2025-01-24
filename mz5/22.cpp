#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>

using namespace std;
int main() 
{
    string s;
    int mark;
    map <string, int> sum;
    map <string, int> num;
    while (cin >> s >> mark) {
        sum[s] += mark;
        sum[s]++;
    }
    map<string, int>::iterator i = sum.begin();
    map<string, int>::iterator j = num.begin();
    for (; j != num.end(), i != sum.end() ; j++, i++) {
        cout << i -> first << " " << (i -> second) / (j -> second) << endl;
    }
    return 0;
}