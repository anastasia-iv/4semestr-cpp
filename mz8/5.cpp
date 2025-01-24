#include <iostream>
#include <cmath>
#include <sstream>
#include <string.h>
#include <list>
#include <chrono>


int main()
{
    std :: string date;
    using namespace std::chrono;
    int y, m, d;
    std :: cin >> date;
    std :: istringstream ss(date);
    char h;
    ss >> y >> h >> m >> h >> d;
    auto y1 = sys_days{year{y}/m/d};
    int sum = 0;
    //std :: cout << "OIJIN";
    while (std :: cin >> date) {
        //std :: cout << "OIJIN";
        std :: istringstream ss(date);
        ss >> y >> h >> m >> h >> d;
        auto y2 = sys_days{year{y}/m/d};
        const auto res = (y2 -y1).count();
        sum += abs(res);
        //std :: cout << sum;
        y1 = y2;
    }
    std :: cout << sum;
}