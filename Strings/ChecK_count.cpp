#include <iostream>
#include <string>
using namespace std;

bool check_count(int count1[], int count2[])
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

bool check_permutation(string s1, string s2)
{
    // First store the count of s1 string elements
    int count1[26] = {0};
    for (int i = 0; i < s1.length(); i++)
    {
        int index = s1[i] - 'a';
        count1[index]++;
    }

    int count2[26] = {0};
    int i = 0;
    int windowSize = s1.length();
    while (i < windowSize && i < s2.length())
    {
        // store the count of s2 string upto the length of s1 string
        int index = s2[i] - 'a';
        count2[index]++;
        i++;
    }

    // check if permutation is present or not
    if (check_count(count1, count2))
    {
        return true;
    }

    // Now do a sliding window and check if permutation is present or not
    while (i < s2.length())
    {
        int index = s2[i] - 'a';
        count2[index]++;

        index = s2[i - windowSize] - 'a';
        count2[index]--;
        i++;
        if (check_count(count1, count2))
        {
            return true;
        }
    }
    return false;
}

int main()
{

    string s1 = "ab", s2 = "eidbaooo";

    bool ans = check_permutation(s1, s2);
    cout << ans;

    return 0;
}