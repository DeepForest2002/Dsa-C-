#include <iostream>
#include <string>
using namespace std;

bool check_palindrome(string name, int left, int right)
{
    if (left > right)
        return true;
    if (name[left] != name[right])
        return false;
    return check_palindrome(name, left += 1, right -= 1);
}

int main()
{
    string name = "aaaaa";
    int size = name.length();
    bool check = check_palindrome(name, 0, size - 1);
    cout << check << endl;
    return 0;
}