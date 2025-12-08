#include <iostream>
#include <string>
using namespace std;

string remove_duplicates(string &str)
{
    int i = 0;
    while (i < str.length())
    {
        if (str[i] == str[i + 1])
        {
            str.erase(i, 2);
            i = 0;
        }
        else
        {
            i++;
        }
    }
    return str;
}

int main()
{
    string str = "azxxzy";
    str = remove_duplicates(str);
    cout << str << endl;
    return 0;
}