#include <iostream>
#include <sstream>
#include <bitset>
using namespace std;

int main()
{
    char c, prev = '#';
    long long int cur = 1, i, n = 0;
    while (cin >> std::noskipws >> c){
        n++;
        if (n > 1) {
            if (c == prev){
                cur++;
            } else {
                if (cur <= 4 && prev != '#') {
                    for (i = 1; i <= cur; i++) {
                        cout << prev;
                    }
                } else {
                    cout << '#' << prev;
                    cout << std::hex << cur;
                    cout << '#';
                }
                cur = 1;
            }
        }
        prev = c;
    }
    if (n != 0) {
        if (cur <= 4 && prev != '#') {
            for (i = 1; i <= cur; i++) {
                cout << prev;
            }
        } else {
            cout << '#' << prev;
            cout << std::hex << cur;
            cout << '#';
        }
    }
    return 0;
}