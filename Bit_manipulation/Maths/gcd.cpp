#include <iostream>
using namespace std;

int find_gcd(int a, int b)
{
    if (a == 0)
        return b;
    if (b == 0)
        return a;
    if (a == b)
        return a;
    if (a > b)
        return find_gcd(a - b, b);
    return find_gcd(a, b - a);
}

int main()
{
    int a = 5, b = 11;
    cout << find_gcd(a, b);
    return 0;
}