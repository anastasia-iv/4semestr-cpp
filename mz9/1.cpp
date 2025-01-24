#include <iostream>
#include <cmath>
#include <string>

using namespace std;
int main() 
{
    std :: string s;
    getline(cin, s);
    unsigned long long i = 0;
    while (i < s.length()) {
        bool f2 = false;
        bool f1 = false;
        //bool f = false;
        while (s[i] != ' ' && i < s.length() && (s[i] == '3' || s[i] == '4')) {
            i++;
            f1 = true;
        }
        while (s[i] != ' ' && i < s.length() && (s[i] == '1' || s[i] == '2')) {
            i++;
            f2 = true;
        }
        //либо на пробеле, либо на конце строки
        if (i == s.length() || s[i] == ' ') {
            cout << "1\n";
        } else {
            if (!f1 && !f2) {
                cout << "0\n";
            } else {
                if (f2 && s[i] != '1' && s[i] != '2') {
                    cout << "0\n";
                } else {
                    if (f1 && !f2) {
                        cout << "0\n";
                    }
                }
            }
        }
        while (i < s.length() && s[i] != ' ') {
            i++;
        }
        if (i < s.length() && s[i] == ' ') {
            i++;
        }
    }
    return 0;
}