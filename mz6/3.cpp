#include <iostream>
#include <vector>
#include <string>
#include <list>
#include<algorithm>
#include<iterator>

template <class C, class P> 
void myapply (C begin, C end, P f) {
    while (begin != end) {
        f(*begin);
        ++begin;
    }
}
template <typename A, class B> 
auto myfilter2 (A begin, A end, B f) {
    std :: vector <std::reference_wrapper <typename std::iterator_traits<A> :: value_type>> v;
    while (begin != end) {
        if (f(*begin)) {
            v.push_back(*begin);
        }
        ++begin;
    }
    return v;
}

//ЛУЧШЕ ИСПОЛЬЗОВАТЬ TYPENAME