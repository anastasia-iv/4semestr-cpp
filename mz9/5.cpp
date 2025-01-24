#include <iostream>
#include <cmath>
#include <string>

/*
-1 не содержит правил, содержит только терминалы в
левой части какого-либо правила,
не содержит правила с единственным нетерминалом 'S'
в левой части.
2 если грамматика является контекстно-свободной,
но не неукорачивающей контекстно-свободной.
23 если грамматика является неукорачивающей
контестно-свободной.
10 в противном случае*/
using namespace std;
int main() 
{
    string s1, s2;
    bool f_has_rules_in_left = true;
    bool f_kc = true;
    bool f_neukor = true;
    bool f_empty = false;
    int s_inright = 0;
    int f_neukorcheck1 = 0;
    bool s_inleft = false;

    while (cin >> s1 >> s2){
        long int len1 = s1.size();
        long int len2 = s2.size();

        if (len1 == 0 || len2 == 0) f_empty = true;
        
        if (len1 <= len2) {
            if (s2[0] == '_') {
                if (s1[0] == 'S') {
                    f_neukorcheck1++;
                } else {
                    f_neukor = false;
                }
            }
        } else {
            f_neukor = false;
        }
        if (len1 == 1 && isupper(s1[0])) {
            //KC
        } else {
            f_kc = false;
        }
        if (len1 == 1 && s1[0] == 'S') s_inleft = true;
        bool help = false;
        for (auto i = 0; i < len1; i++) {
            if (isupper(s1[i])) {
                help = true;
                break;
            }
        }
        if (help == false) {
            f_has_rules_in_left = false;
        }
        for (auto i = 0; i < len2; i++) {
            if (s2[i] == 'S') {
                s_inright++;
                break;
            }
        }
    }
    if (f_neukorcheck1 > 1) f_neukor = false;
    if (f_neukorcheck1 == 1 && s_inright > 0) f_neukor = false;
    if (f_empty || !s_inleft || !f_has_rules_in_left) {
        cout << "-1\n";
    } else {
        if (f_kc) {
            if (f_neukor) cout << "23";
            else cout << "2";
        } else cout << "10";
    }
    cout << endl;
    return 0;
}