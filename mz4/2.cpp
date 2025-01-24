#include <iostream>
#include <vector>

void process (std :: vector <int64_t>& v, int64_t x)
{
    std :: vector <int64_t> :: iterator p = v.begin();
    int64_t last = v.size() - 1;
    int64_t h = 0;
    while (h != last + 1) {
        p = v.begin() + last - h;
        if (*p >= x) {
            v.push_back(*p);
        }
        h++;
    }
}

int main() 
{
    std :: vector <int64_t> v = { 1, 4, 3, 2 } ;
    //{ 1, 4, 3, 2, 3, 4 };
    process(v, 3);
    for (long unsigned int i = 0; i < v.size(); i++) std :: cout << v[i] << " ";
    return 0;
}
