#include <iostream>
#include <vector>
#include <cstring>
#include <string.h>
#include <list>
#include <sstream>
#include <cmath>
#include <algorithm> 

/*
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
*/
bool cmp(const Figure * f1, const Figure * f2){
    return ((f1 -> get_square()) < (f2 -> get_square()));
}
int main()
{
    std :: vector <Figure *> fub;
    std :: string line;
    std :: string TYPE;
    std :: string PARAMS;
    while (std :: getline(std :: cin, line)) {
        std :: istringstream line_stream(line);
        line_stream >> TYPE;
        //cout << TYPE << PARAMS;
        getline(line_stream, PARAMS);
        if (line[0] == 'R') {
            fub.push_back(Rectangle :: make(PARAMS));
        }
        if (line[0] == 'S') {
            fub.push_back(Square :: make(PARAMS));
        }
        if (line[0] == 'C') {
            fub.push_back(Circle :: make(PARAMS));
        }
    }
    std :: stable_sort(fub.begin(), fub.end(), cmp);

    for (std :: vector <Figure *> :: iterator it = fub.begin(); it != fub.end(); ++it) {
        std :: cout << (*it) -> to_string() << std :: endl;
        //std :: cout << (*it) -> get_square() << std :: endl;
        delete (*it);
    }
    return 0;
}
// static - относятся ко всем объектам класса
/*
R       1
S     1
C 1
C 1
S       1
R 2
*/