#include <iostream>
#include <vector>
#include <cstring>
#include <string.h>
#include <list>
#include <cmath>

class my { 
        std :: string s; 
    public : 
        my (const std :: string &str) : s(str) {}
        ~my() {
            std :: cout << s << std :: endl;
        }
};
void f() 
{
    std :: string s;
    if (std :: cin >> s) {
        my str(s);
        f();
    } else {
        throw 0;
    }
}
int main() 
{
    try {
        f();
    } 
    catch (int x) {

    }
    return 0;
}
// static - относятся ко всем объектам класса