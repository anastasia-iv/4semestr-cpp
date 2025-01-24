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
    map <string, vector<int>> m;
    while (cin >> s >> mark) {
        m[s].push_back(mark);
    }
    map<string, vector <int> >::iterator i = m.begin();
    
    for (; i != m.end(); i++) {
        double sum = 0;
        double num = 0;
        for (long unsigned int j = 0; j < i -> second.size(); j++) {
            sum += i -> second[j];
            num++;
        } 
        cout << i -> first << " " << sum/num << endl;
    }
    return 0;
}