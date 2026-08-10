#include <bits/stdc++.h>
using namespace std;

bool palindrome(string str, int low, int high)
{
    if (str.length() == 0 || low > high)
    {
        return true;
    }
    if (str[low] != str[high])
        return false;
    return palindrome(str, low + 1, high - 1);
}

int main()
{
    string str = "aaaa";
    cout << palindrome(str, 0, str.length() - 1);
    return 0;
}