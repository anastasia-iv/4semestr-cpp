#include <iostream>
#include <sstream>
#include <cstdlib>
#include <bitset>
#include <iomanip>
#include <cmath>
using namespace std;

class point {
    public:
        double x;
        double y;
        point(double xx, double yy) {x = xx; y = yy; }
};

class line {
    public:
        double k = 0.0;
        double b = 0.0;
        double special_x = 0.0;
        int flag = 0;
        line(const point &p1, const point &p2) {
            if (p1.x == p2.x) {
                special_x = p1.x;
                flag = 1;
            } else {
                k = (p2.y - p1.y)/(p2.x - p1.x);
                b = (p1.x*p2.y - p1.y*p2.x)/(p1.x - p2.x);
            }
        }
};

point intercept (const line &l1, const line &l2) {
    double x, y;
    x = (l2.b - l1.b) / (l1.k - l2.k);
    y = l1.k * x + l1.b;
    point z(x, y);
    return z;
}

int main()
{
    cin.tie(nullptr);
    double x1, x2, y1, y2;
    double x3, x4, y3, y4;
    cin >> x1 >> y1 >> x2 >> y2;
    cin >> x3 >> y3 >> x4 >> y4;
    point a1(x1, y1);
    point a2(x2, y2);  
    point b1(x3, y3);  
    point b2(x4, y4);  
    line f1(a1, a2);
    line f2(b1, b2);
    if (f1.flag == 1 && f2.flag == 1) { // вертикальные 
        if (f1.special_x == f2.special_x ){
            std :: cout << '2';
        } else {
            std :: cout << '0';
        }
    } else if (f1.k == f2.k && f1.flag == 0 && f2.flag == 0) { 
        if (f1.b == f2.b ){
            std :: cout << '2';
        } else {
            std :: cout << '0';
        }
    } else {
        if (f1.flag == 1) {
            std :: cout << '1' << ' ';
            std :: cout << std :: fixed << std :: setprecision(5) << a1.x << ' ';
            std :: cout << std :: fixed << std :: setprecision(5) << f2.k * (a1.x) + f2.b << endl;
        } else if (f2.flag == 1) {
            std :: cout << '1' << ' ';
            std :: cout << std :: fixed << std :: setprecision(5)  << b1.x << ' ';
            std :: cout << std :: fixed << std :: setprecision(5)  << f1.k * (b1.x) + f1.b << endl;
        } else {
            std :: cout << '1' << ' ';
            std :: cout << std :: fixed << std :: setprecision(5) << intercept(f1, f2).x << ' ';
            std :: cout << std :: fixed << std :: setprecision(5) << intercept(f1, f2).y << endl;
        }
    }
    return 0;
}