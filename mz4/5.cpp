#include <iostream>
#include <vector>
#include <string>
#include <list>
#include<algorithm>
#include<iterator>

int main() 
{
    long long int x;
    std :: list <long long int> l;
    while (std :: cin >> x) {
        if (!x) break;
        l.push_back(x);
    }
    long int k, m;
    unsigned long int c;
    while (std :: cin >> k) {
        if (k < 0) {
            c = -k;
            if (c <= l.size()) {
                l.erase(std :: next(l.begin(), c - 1));
            }
        } else {
            std :: cin >> m;
            c = k;
            if (c <= l.size()) {
                l.insert(std :: next(l.begin(), c - 1), m);
            } else {
                l.push_back(m);
            }
        }
    }
    std :: copy(l.begin(), l.end(), std :: ostream_iterator<long long int>(std :: cout, "\n"));
    l.clear();
    return 0;
}
/*
                std :: cout << " " << c - 1 << " " << m << " -m \n";

*/