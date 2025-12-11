#include <iostream>
using namespace std;

int find_count(int n)
{
    int count = 0;
    while (n)
    {
        if (n & 1)
            count += 1;
        n = n >> 1;
    }
    return count;
}

int main()
{
    int n = 16;
    cout << find_count(n);
    return 0;
}