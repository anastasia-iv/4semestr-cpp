#include <iostream>
#include <vector>
#include <string>
#include <list>
#include<algorithm>
#include<iterator>

template <typename Iterator> 
void selection_sort (Iterator begin, Iterator end) {
    auto min = begin;
    while (begin != end) {
        min = begin;
        auto it = begin;
        it++;
        while (it != end) {
            if (*it < *min) min = it;
            it++; 
        }
        auto help = *begin;
        *begin = *min;
        *min = help;
        ++begin;
    }
}

template <typename Iterator, typename Comp> 
void selection_sort (Iterator begin, Iterator end, Comp f) {
    while (begin != end) {
        auto min = begin;
        auto it = begin;
        it++;
        while (it != end) {
            if (f(*it, *min)) min = it;
            it++; 
        }
        auto help = *begin;
        *begin = *min;
        *min = help;
        ++begin;
    }
}
