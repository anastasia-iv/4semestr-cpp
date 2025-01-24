#include <iostream>
#include <cmath>
#include <cstdio>
#include <new>
#include <string>

namespace numbers {

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
};

