#include <iostream>
#include <cmath>
#include <string>
//сначала максимальное n -> к макисмальному m
//n максимально, когда m = 1 -> n = k - 1 
// n = k - 1, m = 1;
// n = 1, k - 1;
using namespace std;

void S(int ad, int bc);
void X(int ad, int bc);
void P(int ad, int bc);
void f(int ad, int bc);

void X (int ad, int bc)
{
    if (ad > 0) {
        cout << 'a';
        X(ad - 1, bc);
        cout << 'd';
    } else {
        cout << 'b';
        P(ad, bc - 1);
        cout << 'c';
    }

}
void P (int ad, int bc)
{
    if (bc > 0) {
        cout << 'b';
        P(ad, bc - 1);
        cout << 'c';
    }
}
void S (int ad, int bc) 
{
    cout << 'a';
    X(ad - 1, bc);
    cout << 'd' << endl;
}
void f(int ad, int bc) {
    S(ad, bc);
    ad--;
    bc++;
    if (ad >= 1) {
        f(ad, bc);
    }
}
int main() 
{
    int k;
    cin >> k;
    if (k % 2 != 0) return 0;
    if (k == 0 || k == 2) return 0;
    k /= 2;  //n + m
    f(k - 1, 1);
    return 0;
}
/*
S -> aXd
X -> aXd|bPc
P -> bPc|e 
*/
