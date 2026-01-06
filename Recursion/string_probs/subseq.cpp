#include <iostream>
#include <string>
using namespace std;

void check_sub(string upstring, string p)
{
    if (upstring.empty())
    {
        cout << p << endl;
        return;
    }

    char ch = upstring[0];
    check_sub(upstring.substr(1), p + ch);
    check_sub(upstring.substr(1), p);
}

int main()
{
    string upstring = "abc";
    string p = "";
    // check_sub(upstring, p);
    cout << upstring.substr(1);
    return 0;
}