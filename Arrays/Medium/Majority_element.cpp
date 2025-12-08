// This problem is to found an element which appears more than >n/2 times
#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

// Optimal Solutuion- Moores voting algo
int Optimal_solution(vector<int> v, int size)
{
    int ma_ele;
    int count1 = 0;

    // The first loop indicates the moores voting algo to get the majority element

    for (int i = 0; i < size; i++)
    {
        if (count1 == 0)
        {
            count1 = 1;
            ma_ele = v[i];
        }
        else if (ma_ele == v[i])
        {
            count1++;
        }
        else
        {
            count1--;
        }
    }

    int count2 = 0;

    // And this loop indicates if the count of majority element is greater than n/2 or not

    for (int i = 0; i < size; i++)
    {
        if (ma_ele == v[i])
            count2++;
    }
    if (count2 > (size / 2))
    {
        return ma_ele;
    }
    return -1;
}

// Better Solution- Store occurrences of each array element in a map
int Majority_element(vector<int> v, int size)
{
    unordered_map<int, int> map;
    // loop to store the occurrences of the elements
    for (int i = 0; i < size; i++)
    {
        map[v[i]]++;
    }

    // Iterate through the map
    for (const auto &pair : map)
    {
        if (pair.second > (size / 2))
            return pair.first;
    }
    return -1;
}

int main()
{
    vector<int> v = {4, 4, 2, 4, 3, 4, 4, 3, 2, 4};
    int size = v.size();

    int ans = Optimal_solution(v, size);
    cout << ans;
    return 0;
}