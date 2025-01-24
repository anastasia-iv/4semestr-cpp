#include <iostream>
#include <vector>

using namespace std;

template < class T >
typename T :: value_type  sum(const T&t) {
    typename T :: value_type zero = typename T :: value_type() ;
    auto p = t.end();  
    if (t.size() < 5) return zero;
    for(typename T :: size_type i = 0; i < 5; i++) {
        --p;
        zero += *p;
    }
    return zero;
}
 int main()
 {
    vector <int> v {1, 2, 3, 4, 8, 0,  9};
    cout << sum(v);
 }