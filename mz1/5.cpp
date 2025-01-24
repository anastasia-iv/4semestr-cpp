#include <iostream>
#include <sstream>
#include <cstdlib>
#include <bitset>
using namespace std;

int main()
{
    cin.tie(nullptr);
    string s;
    char hex[9];
    hex[8] = '\0';
    long long int offset;
    while (cin >> std::hex >> offset){
        getline(cin, s);
        int i = 0, cur = 0;
        while (s[i] != '\0') {
            if (s[i] != ' ') {
                hex[cur++] = s[i];
                hex[cur++] = s[i+1];
                if (cur == 8) {
                    cout << strtol(hex, NULL, 16) << endl;
                    cur = 0;
                }
                i += 2;
            } else {
                i++;
            }
        }
    }
    return 0;
}