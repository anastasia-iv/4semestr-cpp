#include <iostream>
#include <cmath>
#include <cstdio>
#include <string>

namespace numbers {
    class complex { double r, i;
    public : 
        complex (double x = 0.0, double y = 0.0) : r(x), i(y){}
        explicit complex (std :: string s) : r(0), i(0) {
            sscanf(s.data(), "(%lf,%lf)", &r, &i);
        }
        double re() const {
            return r;
        }
        double im() const {
            return i;
        }
        double abs2() const{
            return r*r + i*i;
        }
        double abs() const{
            return sqrt(abs2());
        }
        std :: string to_string () const {
            char buffer[1000];
            std :: snprintf(buffer, 1000, "(%.10g,%.10g)", r, i);
            return buffer;
        }
        complex& operator +=( const complex& c) {
            r += c.re();
            i += c.im();
            return *this;
        }
        complex& operator -=( const complex& c) {
            r -= c.re();
            i -= c.im();
            return *this;
        }
        complex& operator *=( const complex& c) {
            double rr = r, ii = i;
            r = rr*c.re() - ii*c.im();
            i = rr*c.im() + c.re()*ii;
            return *this;
        }
        complex& operator /=( const complex& c) { //возвращаем ссылку, (ссылка когда стоит в правой части после равно синонимируется со значением )
            double rr = r, ii = i;
            r = (rr*c.re() + ii*c.im())/(c.re()*c.re() + c.im()*c.im());
            i = (ii*c.re() - rr*c.im())/(c.re()*c.re() + c.im()*c.im());
            return *this;
        }
        complex operator ~() const{
            return complex(r, -i);
        }
        complex operator -() const{
            return complex(-r, -i); //
        }
    };

    complex operator +( const complex& c1, const complex& c2) {
        complex c(c1.re(), c1.im());
        c += c2;
        return c;
    }
    complex operator -( const complex& c1, const complex& c2) {
        complex c(c1.re(), c1.im());
        c -= c2;
        return c;
    }
    complex operator *( const complex& c1, const complex& c2) {
        complex c(c1.re(), c1.im());
        c *= c2;
        return c;
    }
    complex operator /( const complex& c1, const complex& c2) {
        complex c(c1.re(), c1.im());
        c /= c2;
        return c;
    }
};

// const complex& x в параметре значит, что по ссылке x я значение на которое она ссылается
//изменить не могу
 
 //const T& operator[](int ind) const; - 
 //первый конст говорит о том что возвращаемое значение имеет типа ссылки на константу
 //то есть по этой ссылке я не могу изменять значение, на которое она ссылается

 //второй конст говорит о отом, что внутри не происходит изменений с элементом