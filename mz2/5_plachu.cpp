#include <iostream>
#include <string>
#include <cstring>
using namespace std;

class BinaryNumber
{
    unsigned long long int n = 0;
    string str;
public:
    BinaryNumber(const string &s){
        str = s;
        n = s.size();
    }
    operator string () const {
        return str;
    }
    const BinaryNumber &operator++(){
        if (str[n - 1] == '0') {
            str[n - 1] = '1';
            return *this;
        }
        //в конце 1
        //случай, когда пустая
        long long int i;
        bool m = true;
        for (i = n - 1; i >= 0; i--) {
            if (str[i] == '1') {
                str[i] = '0';
            } else {
                str[i] = '1';
                m = false;
                break;
            }
        }
        if (m) {
            str.insert(str.begin(), '1');
            n++;
        }
        //cout << endl << "this is num " << str << " and it`s length is " << n << endl;
        return *this;
    }
};
