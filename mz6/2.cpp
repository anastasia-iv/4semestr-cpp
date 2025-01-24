#include <iostream>
#include <vector>
#include <string>
#include <list>
#include<algorithm>
#include<iterator>

template <class C, class P> 
C  myfilter (const C &c, P p) {
    typename C :: const_iterator i = c.cbegin();
    C x;
    while (i != c.end()) {
        if (p(*i)) {
            x.insert(x.end(), *i);   
        }
        i++;
    }
    return x;
} 