#include <iostream>
using namespace std;

int findPower(int x, int n)
{
    if (n == 0)
        return 1;
    else
        return x * findPower(x, n - 1);
}

int main()
{
    int ans = findPower(2, 5);
    cout << ans;
    return 0;
}