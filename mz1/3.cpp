#include <iostream>
using namespace std;

int main()
{
    cin.tie(nullptr);
    char c;
    int flag_let = 1, flag_null = 0;
    while (cin >> std::noskipws >> c){
        if (c < '0' || c > '9') {
            if (flag_null == 1) {
                cout << '0';
            }
            cout << c;
            flag_null = 0;
            flag_let = 1;
        } else {
            if (flag_let == 1 && c == '0'){
                flag_null = 1;
            } else {
                cout << c;
                flag_null = 0;
                flag_let = 0;
            }
        }
    }
    if (flag_null == 1) {
        cout << '0';
    }
    return 0;
}