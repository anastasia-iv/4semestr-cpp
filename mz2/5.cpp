#include <iostream>
#include <string>
#include <cstring>
using namespace std;

class BinaryNumber
{
    unsigned long long int bin = 0;
    unsigned long long int n;
public:
    BinaryNumber(const string &s){
        n = s.size();
        unsigned long long int k = 1;
        for (long long int i = n - 1; i >= 0; i--) {
            if (s[i] == '1') {
                bin += k;
            }
            k *= 2;
        }
    }
    operator string () const {
        char ss[n + 1]; //+1, т.к. может добавиться символ
        if (n == 1 && bin == 0){
            return "0\0";
        }
        unsigned long long int i = 0;
        unsigned long long int bbin = bin;
        while (bbin > 0){
            ss[i++] = (bbin%2) + '0';
            bbin /= 2;
        }
        unsigned long long int nn = i; ///длина без \0
        char s_new[nn + 1];
        for (i = 0; i < nn; i++){
            s_new[i] = ss[nn - i - 1];
        }
        s_new[nn] = '\0';
        return s_new;
    }
    const BinaryNumber &operator++(){
        bin++;
        bool x = true;
        unsigned long long int bbin = bin;
        while (bbin > 1) {
            if (bbin % 2 != 0) {
                x = false;
                break;
            }
            bbin /= 2;
        }
        if (x && (bin != 0 || n != 1)) {
            n++;
        }
        return *this;
    }
};

int main()
{
    18446744073709551615
    9223372036854775808
    BinaryNumber b("
    10000000000
    0000000000
    0000000000
    0000000000
    0000000000
    0000000000
    0001");
    10000000000
    0000000000
    0000000000
    0000000000
    0000000000
    0001
    10000000000
    0000000000
    0000000000
    0000000000
    0000000000
    000000
    1000000000000000000000000000000000000000000000000000001
    1000000000000000000000000000000000000000000000000000001
    std::cout << std::string(b) << std::endl;
    std::cout << std::string(++b) << std::endl;
    std::cout << std::string(++b) << std::endl;
    std::cout << std::string(++b) << std::endl;
    std::cout << std::string(++b) << std::endl; 
    std::cout << std::string(++b) << std::endl;
    std::cout << std::string(++b) << std::endl;
    std::cout << std::string(++b) << std::endl;
    std::cout << std::string(++b) << std::endl;
    std::cout << std::string(++b) << std::endl; 
    std::cout << std::string(++b) << std::endl;
    std::cout << std::string(++b) << std::endl;
    std::cout << std::string(++b) << std::endl;
    std::cout << std::string(++b) << std::endl;
    std::cout << std::string(++b) << std::endl; 
    std::cout << std::string(++b) << std::endl;
    std::cout << std::string(++b) << std::endl;
    std::cout << std::string(++b) << std::endl;
    std::cout << std::string(++b) << std::endl;
    std::cout << std::string(++b) << std::endl; 
    std::cout << std::string(++b) << std::endl;
    std::cout << std::string(++b) << std::endl;
    std::cout << std::string(++b) << std::endl;
    std::cout << std::string(++b) << std::endl;
    std::cout << std::string(++b) << std::endl; 
    std::cout << std::string(++b) << std::endl;
    std::cout << std::string(++b) << std::endl;
    std::cout << std::string(++b) << std::endl;
    std::cout << std::string(++b) << std::endl;
    std::cout << std::string(++b) << std::endl; 
    std::cout << std::string(++b) << std::endl;
    std::cout << std::string(++b) << std::endl;
    return 0;
}