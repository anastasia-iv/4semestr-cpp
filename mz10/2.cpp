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
каждый раз проходим только по грамматикам
 и если левая часть находится в достижимых символах проходимся 
то для этого символа проходлим по строке справа и добавляем в сет
если символа не было раньше 
если за весь проход добавили 


S _
S A
A Az
A cyyy
такой вывод?
S _
S A
*/

int main() {
    bool nestop = true;
    char s1;
    string s2;
    vector <pair <char, string>> s; // записываем грамматику 
    set <char> prev, next; //длостижимые символы
    prev.insert('S');
    while (cin >> s1 >> s2){
        s.push_back(make_pair(s1, s2));
    }
    while (nestop) {
        next = prev;
        nestop = false;
        std::vector<pair<char, string>>::iterator k;
        for (k = s.begin(); k != s.end(); ++k) {
            const bool is = (prev.find(k->first) != prev.end());
            string s = k->second;
            if (is) {
                for (long int i = 0; i < (long int)s.length(); i++){
                    if (isupper(s[i])) {
                        //если нет в предыдущем, то значит изменяем
                        if (prev.find(s[i]) == prev.end()) {
                            nestop = true;
                            next.insert(s[i]);
                        } 
                    }
                }
            }
        }
        prev = next;
    }
    std::vector<pair<char, string>>::iterator it;
    for (it = s.begin(); it != s.end(); ++it) {
        const bool is_in = (prev.find(it->first) != prev.end());
        if (is_in) {
            cout << it->first << " " << it->second << endl;
        }
    }
    return 0;
}
