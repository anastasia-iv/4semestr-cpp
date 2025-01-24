#include <iostream>
#include <vector>
#include <algorithm>

void process (const std :: vector <int>& v1, std :: vector <int>& v2)
{
    std :: vector <int> vhelp = v1;
    std :: vector <int> :: iterator ip;
    std :: vector <int> :: iterator i;
    std :: sort (vhelp.begin(), vhelp.end());
    ip = std :: unique (vhelp.begin(), vhelp.end()); // указывает на первый удаленный


    std :: vector <int> :: iterator p = vhelp.begin();


    int n = v2.size();
    int x = 0;

    while (p != ip && *p < n){
        if (*p >= 0) {
            v2.erase(std :: next (v2.begin(), *p - x));
            x++;
        }
        p++;
    }
}

// игнорировать отрицательные числа

/*
int main() 
{
    std :: vector <int> v1 = {  } ;
    std :: vector <int> v2 = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 10, 10, 0, -4, -7} ;
    process(v1, v2);
    for (long unsigned int i = 0; i < v2.size(); i++) std :: cout << v2[i] << " ";
    return 0;
}
*/