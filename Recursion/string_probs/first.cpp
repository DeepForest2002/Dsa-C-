#include <iostream>
#include <string>
using namespace std;
string ans = "";
string find_ans(string str, int i)
{
    if (i == str.length() - 1)
        return ans;
    if (str[i] != 'a')
        ans += str[i];
    return find_ans(str, i += 1);
}

int main()
{
    string str = "abcdefgaaadf";
    cout << find_ans(str, 0);
    return 0;
}