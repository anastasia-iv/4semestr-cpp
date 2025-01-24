#include <iostream>
#include <string>
#include <list>
#include <cstring>
#include <vector>

using namespace std;

class Matrix
{
    std :: vector <std :: vector<int>> m = {
        {0, 0, 0},
        {0, 0, 0},
        {0, 0, 0}
    };
    public:
        int & operator [] (int x, int y) {
            return (m[x][y]);
        }
        std :: vector <std :: vector<int>> :: const_iterator begin() const {
            return m.cbegin();
        }
        std :: vector <std :: vector<int>> :: const_iterator end() const {
            return m.cend();
        }
        
};
