#include <iostream>
#include <stack>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm> 
#include <string>
using namespace std;

int main() {
    char sym;
    int n = 0;
    //bool flag = false;
    stack <char> t;
    stack <string> ans;
    while (cin >> sym) {
        if (sym == '+' || sym == '-' || sym == '*' || sym == '/') {
            string s1, s2, s;
            s1 = ans.top();
            ans.pop();
            s2 = ans.top();
            ans.pop();

            string symm;
            stringstream m;
            m << sym;
            m >> symm;

            s = '(' + s2 + symm + s1 + ')';
            ans.push(s);
        } else {
            string s;
            stringstream m;
            m << sym;
            m >> s;
            ans.push(s);
        }
        n++;
    }
    cout << ans.top();
    return 0;
}
