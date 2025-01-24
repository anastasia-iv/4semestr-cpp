#include <iostream>
#include <vector>
#include <cstring>
#include <map>
#include <set>
#include <algorithm>
using namespace std;

class Date {
        string all;
    public:
        Date(const string &s){
            all = s;
            if (all[6] == '/') {
                all.insert(5, "0");
            }
            if(all.size() != 10) {
                all.insert(8, "0");
            }
        }
        string str() const {
            return all;
        }
};

int main() 
{
    map <string, map <string, int >> m;
    set <string> d;
    string data, name;
    int mark;
    while (cin >> name >> data >> mark) {
        Date format(data);
        d.insert(format.str());
        m [name][format.str()] = mark;
    }
    cout << ". ";
    for (auto it : d) {
        cout << it << " ";
    }
    cout << endl;
    set <string> :: iterator itr;
    for(map <string, map<string, int>> :: const_iterator i = m.begin(); i != m.end(); i++) {
        itr = d.begin();
        cout << i -> first << " ";
        for(map <string, int> ::const_iterator j = i -> second.begin(); j != i -> second.end(); j++){
            while (j -> first != *itr && itr != d.end()) {
                cout << ". ";
                itr++;
            }
            cout << j -> second << " ";
            itr++;
            
        }
        while (itr != d.end()) {
            cout << ". ";
            itr++;
        }
        cout << endl;
    }
    return 0;
}