#include <bits/stdc++.h>
using namespace std;

bool check_prime(int n)
{
    if (n <= 1)
        return false;
    for (int i = 2; i <= sqrt(n); i++)
    {
        if (n % i == 0)
            return false;
    }
    return true;
}

void sieve(int n, vector<bool> arr)
{
    // loop till n*n
    for (int i = 2; i * i <= n; i++)
    {
        if (arr[i] == false)
        {
            for (int j = i * 2; j <= n; j += i)
            {
                arr[j] = true;
            }
        }
    }

    for (int i = 2; i <= n; i++)
    {
        if (arr[i] == false)
        {
            cout << i << " ";
        }
    }
}

int main()
{
    int n = 40;
    vector<bool> arr(n + 1, 0);
    // cout << check_prime(n);
    sieve(n, arr);
    return 0;
}