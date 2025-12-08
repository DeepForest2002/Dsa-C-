#include <iostream>
#include <string>
using namespace std;

string replace_spaces(string &str)
{
    string replace_word = "@40";
    for (int i = 0; i < str.length(); i++)
    {
        if (str[i] == ' ')
        {
            str.replace(i, 1, replace_word);
        }
    }
    return str;
}

int main()
{
    // Replace the spaces with the word @40 by not taking new string
    string str = "This is an ad of Shampoo";
    str = replace_spaces(str);
    cout << str << endl;
    return 0;
}