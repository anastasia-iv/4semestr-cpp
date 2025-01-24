#include <iostream>
#include <cmath>
#include <string>

using namespace std;
int main() 
{
    std :: string s;
    while (cin >> s) {
        bool f = true;
        unsigned long long int i = 0;
        if (s.length() == 0) {
            cout << "1\n";
        } else {
            while (i < s.length() && (s[i] == '3' || s[i] == '4')) {
                i++;
            }
            if (i < s.length() && (s[i] != '1' && s[i] != '2')) {
                f = false;
            }
            while (i < s.length() && (s[i] == '2' || s[i] == '1')) {
                i++;
            }
            if (i < s.length()) {
                f = false;
            }
            if (f) {
                cout << "1\n";
            } else {
                cout << "0\n";
            }
        }
    }
    return 0;
}