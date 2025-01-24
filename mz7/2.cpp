#include <iostream>
#include <vector>
#include <cstring>
#include <string.h>
#include <list>
#include <cmath>

using namespace std;
class  Figure {
    public: virtual double get_square() const { return 0;} ;
    virtual ~Figure() {};
};
class Rectangle : public Figure{
public :
    double a, b;
    double get_square () const {
        return a*b;
    }
    static Rectangle * make (std :: string s) {
        double x, y;
        sscanf(s.c_str(), "%lf %lf", &x, &y);
        Rectangle * ret;
        ret = new Rectangle;
        ret -> a = x;
        ret -> b = y;
        return ret;
    }
};
class Square : public Figure {
public :
    double a;
    double get_square () const {
        return a*a;
    }
    static Square * make (std :: string s) {
        double x;
        sscanf(s.c_str(), "%lf", &x);
        Square * ret;
        ret = new Square;
        ret -> a = x;
        return ret;
    }
};
class Circle : public Figure{
public :
    double r;
    double get_square () const {
        return M_PI * r * r;
    }
    static Circle * make (std :: string s) {
        double x;
        sscanf(s.c_str(), "%lf", &x);
        Circle * ret;
        ret = new Circle;
        ret -> r = x;
        return ret;
    }
};
// static - относятся ко всем объектам класса