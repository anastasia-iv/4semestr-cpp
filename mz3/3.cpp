#include <iostream>
#include <cmath>
#include <cstdio>
#include <map>
#include <vector>
#include <new>
#include <functional>
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
    //                     COMPLEX STACK
    class complex_stack { 
        complex *mas; 
        unsigned long long used; 
        unsigned long long n; 
    public : 
        complex_stack(size_t u = 0, size_t s = 4) : used(), n(s) {
            mas = static_cast <complex*> (:: operator new (s * sizeof(complex)));
        };
        complex_stack(const complex_stack& st) : used(st.used), n(st.n){
            mas = static_cast <complex*> (:: operator new (n * sizeof(complex)));
            for (size_t i = 0; i < used; i++) {
                new(mas + i) complex(st.mas[i]);
            }
        }
        unsigned long long size() const {
            return used;
        }
        complex operator [] (unsigned long long ind) const {
            return mas[ind];
        }
        complex operator +() const{
            return mas[used - 1];
        }
        complex_stack& operator = (const complex_stack& st){
            if (&st == this) {
                return *this;
            }
            for (size_t i = 0; i < used; i++) {
                mas[i].~complex();
            }
            :: operator delete(mas);
            used = st.used;
            n = st.n;
            mas = static_cast <complex*> (:: operator new (n * sizeof(complex)));
            for (size_t i = 0; i < used; i++) {
                new(mas + i) complex(st.mas[i]);
            }
            return *this;
        }
        complex_stack operator ~() const {
            unsigned long long int f = 0;
            if (used != 0) f = used - 1;
            complex_stack new_stack(f,n);
            unsigned long long int i = 0;
            for (; i < f; i++) {
                new(new_stack.mas + i) complex(mas[i]);
            }

            return new_stack;
        }
        ~complex_stack() {
            for (size_t i = 0; i < used; i++) {
                mas[i].~complex();
            }
            used = 0;
            if (mas) {
                :: operator delete(mas);
            }
        }
        friend complex_stack operator << (const complex_stack& st, const complex& c);

    };
    complex_stack operator << (const complex_stack& st, const complex& c){
          if (st.used == st.n) {
               complex_stack new_stack(st.used + 1, st.n * 2);
               size_t i = 0;
               for (i = 0; i < st.used; i++) {
               new(new_stack.mas + i) complex(st.mas[i]);
               }
               new(new_stack.mas + i) complex(c);
               return new_stack;
          } else {
               complex_stack new_stack(st.used + 1, st.n);
               size_t i = 0;
               for (i = 0; i < st.used; i++) {
               new(new_stack.mas + i) complex(st.mas[i]);
               }
               new(new_stack.mas + st.used) complex(c);
               return new_stack;
          }
     }
     complex eval(const std::vector <std::string> &args, const complex &z)
     {    
          complex_stack st;
          std :: map <std :: string, std :: function<void()>> mp 
          {
               {"z", [&st, &z]() {st = st << z;}}, //добавляем z в стек
               {";", [&st]() {st = ~st;}}, // удаляет элемент с верхушки стека
               {"!", [&st]() {st = st << +st;}}, //заносит в стек элемент, находящийся на верхушке стека
               {"~", [&st]() {
                    complex x = ~(+st);
                    st = ~st;
                    st = st << x;
               }}, //которая вычисляет комплексно-сопряженное число
               {"#", [&st]() {
                    complex x = -(+st);
                    st = ~st;
                    st = st << x;
               }}, //меняет знак у числа
               {"+", [&st]() {
                    complex x2 = +st;
                    st = ~st;
                    complex x1 = +st;
                    st = ~st;
                    st = st << (x1 + x2);
               }},
               {"-", [&st]() {
                    complex x2 = +st;
                    st = ~st;
                    complex x1 = +st;
                    st = ~st;
                    st = st << (x1 - x2);
               }},
               {"*", [&st]() {
                    complex x2 = +st;
                    st = ~st;
                    complex x1 = +st;
                    st = ~st;
                    st = st << (x1 * x2);
               }},
               {"/", [&st]() {
                    complex x2 = +st;
                    st = ~st;
                    complex x1 = +st;
                    st = ~st;
                    st = st << (x1 / x2);
               }},

          };
          for (const auto &s : args) {
               if (s[0] != '(') mp[s]();
               else {
                    //новый комплексный элемент 
                    st = st << complex(s);
               }
          }
          return +st;
     }
};