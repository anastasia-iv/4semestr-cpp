#include <iostream>
#include <vector>
#include <complex>
#include <array>

namespace Equations {

    using namespace std;
    template <typename C>
    bool eps_checker(complex<C> hlper) {
        if ((norm(hlper)) < ((numeric_limits<C>::epsilon()) * 32)){
            return true;
        } else {
            return false;
        }
    }
    template <typename C>
    pair <bool, vector <C>> quadratic (const array <C, 3> &v) 
    {
        bool fc = false, fb = false, fa = false;
        C c(v[0]);
        if (eps_checker(c)) fc = true;
        C b(v[1]);
        if (eps_checker(b)) fb = true;
        C a(v[2]);
        if (eps_checker(a))fa = true;
        if (fa && fb && fc) return make_pair(false, vector<C> {});
        if (fa && !fb && !fc) return make_pair(true, vector<C> {-(c/b)});
        if (fa && !fb && fc) return make_pair(true, vector<C> {C(0.0)});
        if (!fa && fb && fc) return make_pair(true, vector<C> {C(0.0)});
        if (fa && fb && !fc) return make_pair(true, vector<C> {}); //no solves
        C d = sqrt(b*b - C(4.0)*a*c);
        C x1 = (-b + d) / (C(2.0)*a);
        C x2 = (-b - d) / (C(2.0)*a);
        return make_pair(true, vector<C>{x1, x2});
    }
};
/*
int main()
{
    std::array<std::complex<int>, 3> v1{
        std::complex<double>(1),
        std::complex<double>(2),
        std::complex<double>(1)
    };

    auto res = Equations::quadratic(v1);
    std::cout << res.first;
}
*/