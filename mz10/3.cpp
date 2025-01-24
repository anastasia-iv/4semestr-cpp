#include <iostream>
#include <stack>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm> 
#include <string>
#include <set>
#include <map>
#include <map>
using namespace std;

/* 
CUR -> (CHAR) NEW
...
CUR -> (CHAR) END
Начальная строка
проверяемое слово

1/0 - допускает/не допускает
кол-во символов проитанных во входной  цепочке к моменту принятия решения
идентификатор состояния, в котором в данный момент находился автомат(CUR)
*/

int main() {
    string cur, neww;
    char charr;
    map < pair <string, char>, string> s; // записываем грамматику 
    while (cin >> cur) {
        if (cur == "END"){
            break;
        }
        cin >> charr >> neww;
        s[{cur, charr}] = neww;
    }
    //конечнsе состояния
    set <string> ends;
    while (cin >> cur) {
        if (cur == "END") break;
        else ends.insert(cur);
    }

    //начальное состояние
    string begin;
    cin >> begin;

    //строка для проверки
    string str;
    cin >> str;

    long int len = str.size();

    long int i = 0;
    bool flag = false;
    cur = begin;

    while (i <= len) {
        flag = false;
        if (i == len) {
            //проверяем на конечное состояние 
            for (auto j : ends) {
                if (cur == j) {
                    cout << "1" << endl;
                    cout << i << endl;
                    cout << j << endl;
                    return 0;
                }
            }
            cout << "0" << endl;
            cout << i << endl;
            cout << cur << endl;
            return 0;
        } else {
            pair <string, char> p = {cur, str[i]};
            if (s.find(p) != s.end()) {
                flag = true;
                cur = s[p];
            }
        }
        //cout << i << " " << str << endl;
        if (!flag) {
            break;
        }
        i++;
    }
    cout << "0" << endl;
    cout << i << endl;
    cout << cur << endl;
    return 0;
}