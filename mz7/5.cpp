#include <iostream>
#include <vector>
#include <cstring>
#include <string.h>
#include <list>
#include <cmath>

using namespace std;
class  Figure {
    public: 
    virtual bool equals (const Figure *x) const{
        return 0;
    }
    virtual ~Figure() {};
};

class Rectangle : public Figure{
public :
    int a, b;
    Rectangle (int aa, int bb) : a(aa), b(bb) {}
    virtual bool equals (const Figure *f) const {
        const Rectangle* x = dynamic_cast <const Rectangle *>(f);
        if (x) {
            if (x->a == a && x->b == b) {
                return true;
            } else return false;
        } else {
            return false;
        }
    }
    
};
class Triangle : public Figure {
public :
    int a, b, c;
    Triangle (int aa, int bb, int cc) : a(aa), b(bb), c(cc) {}
    virtual bool equals (const Figure *f) const{
        const Triangle* x = dynamic_cast <const Triangle *>(f);
        if (x) {
            if (x->a == a && x->b == b && x->c == c) {
                return true;
            } else return false;
        } else {
            return false;
        }
    }
};
