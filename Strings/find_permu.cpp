#include <iostream>
#include <string>
using namespace std;

bool check(int count1[], int count2[])
{
    for (int i = 0; i < 26; i++)
    {
        if (count1[i] != count2[i])
        {
            return false;
        }
    }
    return true;
}

bool find_permutation(string s1, string s2)
{
    int count1[26] = {0};
    int count2[26] = {0};

    for (int i = 0; i < s1.length(); i++)
    {
        int index = s1[i] - 'a';
        count1[index]++;
    }

    int j = 0;
    int windowSize = s1.length();
    while (j < windowSize && j < s2.length())
    {
        int index = s2[j] - 'a';
        count2[index]++;
        j++;
    }

    // check if they are equal or not
    if (check(count1, count2))
    {
        return true;
    }

    while (j < s2.length())
    {
        int newIndex = s2[j] - 'a';
        count2[newIndex]++;
        int oldInedex = s2[j - windowSize] - 'a';
        count2[oldInedex]--;
        j++;
        if (check(count1, count2))
        {
            return true;
        }
    }
    return false;
}

int main()
{
    string s1 = "cba";
    string s2 = "ababbcabbcd";
    bool ans = find_permutation(s1, s2);
    cout << ans;
    return 0;
}