#include <iostream>
#include <vector>

void process (const std :: vector <uint64_t>& v_const, std :: vector <uint64_t>& v, ssize_t x)
{
    std :: vector <uint64_t> :: const_iterator i = v_const.begin();
    std :: vector <uint64_t> :: iterator j = v.end();
    ssize_t flag = 0;
    while (i != v_const.end() && j != v.begin()) {
        if (flag % x == 0) {
            j--;
            *j += *i;
        }
        flag++;
        i++;
    }
}

/*
int main() 
{
    const std :: vector <uint64_t> v_const = { 1, 2, 3, 4 };
    std :: vector <uint64_t> v = { 1, 2, 3 };
    process(v_const, v, 2);
    for (long unsigned int i = 0; i < v.size(); i++) std :: cout << v[i] << " ";
    return 0;
}
*/