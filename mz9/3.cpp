#include <iostream>
#include <cmath>
#include <string>
/*
S -> aKb
K -> aSb|T
T -> 0TM | 0M
Mb -> bM
bM -> b0
0M -> 00
*/
using namespace std;

int main() 
{
    string s;
    while (cin >> s){
        long int n = s.size(), i = 0, n_a = 0, n_b = 0, n_0 = 0, n_1 = 0;
        bool f = true;
        while (1) {
            while (i < n && s[i] == 'a') {
                n_a++;
                i++;
            }
            if (n_a == 0) {
                f = false;
                break;
            }
            while (i < n && s[i] == '0') {
                n_0++;
                i++;
            }
            if (n_0 == 0) {
                f = false;
                break;
            }
            while (i < n && s[i] == 'b') {
                n_b++;
                i++;
            }
            if (n_b != n_a) {
                f = false;
                break;
            }
            while (i < n && s[i] == '1') {
                n_1++;
                i++;
            }
            if (n_1 != n_0) {
                f = false;
                break;
            }
            break;
        }
        if (f && i == n) {
            cout << '1' << endl;
        } else {
            cout << '0' << endl;
        }
    }
    return 0;
}

