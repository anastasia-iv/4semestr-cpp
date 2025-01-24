#include <iostream>
#include <vector>
#include <string>
#include <list>
#include<algorithm>
#include<iterator>

template <class C> 
typename C :: value_type process (const C &c) {
    typename C :: const_reverse_iterator i = c.crbegin();
    unsigned int k = 1;
    typename C :: value_type sum {};
    while (i != c.crend()) {
        if (k == 1 || k == 3 || k == 5) {
            sum += (*i);
            //std :: cout << sum << std :: endl;
        }
        k++;
        i++;
    }
    return sum;
} 
/*
int main() 
{
    using namespace std;
    list<int> st={ 10, 3, 6, 28, 2, 9 };
     cout<<process< list<int> >(st) << endl; // 28
    return 0;
}
*/