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

int find_lcm(int a, int b)
{
    int gcd = find_gcd(a, b);
    int f = a / gcd;
    int g = b / gcd;
    return f * g * gcd;
}

int main()
{
    int a = 18, b = 9;
    cout << find_lcm(a, b);
    return 0;
}