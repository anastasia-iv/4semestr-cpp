#include <iostream>
#include <string>

using namespace std;

int main()
{
    int c;
    int prev = 0;
    string s = "";
    while (1) {
        c = getchar();
        if (c == '1' || c == '0') {
            if (prev) {
                while (c != ' ' && c != '\n' && c != EOF){
                    c = getchar();
                }
                cout << 0 << endl;
                if (c == EOF) {
                    break;
                }
                prev = 0;
            } else {
                s += c;
            }
        } else if (c == ' ' || c == '\n' || c == EOF){
            if (prev) {
                cout << 0 << endl;
                prev = 0;
                s = "";
            }
            int i = 0, len = s.length(), c0 = 0, c1 = 0;
            string curs;
            if (len == 0) {
                if (c == EOF) {
                    break;
                }
                else {
                    continue;
                }
            }
            while (s[i] == '0' && i < len) {
                c0++;
                i++;
                curs += '0';
            }
            if (c0 == 0) {
                cout << '0' << endl;
                s = "";
                continue;
            }
            if (i == len) {
                cout << '0' << endl;
                s = "";
                continue;
            }
            while (s[i] == '1' && i < len) {
                c1++;
                i++;
                curs += '1';
            }
            if (c1 == 0) {
                cout << '0' << endl;
                s = "";
                continue;
            }
            if (i == len) {
                cout << '1' << endl;
                s = "";
                continue;
            }
            
            int f = 0;
            while (i < len) {
                f = 0;
                for (unsigned int j = 0; j < curs.length(); j++) {
                    if (i < len) {
                        if (s[i] != curs[j]) {
                            f = 1;
                            cout << '0' << endl;
                            break;
                        }
                        i++;
                    } else {
                        cout << '0' << endl;
                        f = 1;
                        break;
                    }
                }
                if (f) {
                    break;
                }
            }
            if (!f) {
                cout << '1' << endl;
            }
            s = "";
            if (c == EOF) {
                break;
            }
        } else {
            prev = 1;
            s = "";
        }
    }
    return 0;
}
