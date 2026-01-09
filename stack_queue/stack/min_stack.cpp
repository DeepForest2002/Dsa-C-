#include <bits/stdc++.h>
using namespace std;

class Min_stack
{
public:
    stack<pair<int, int>> st;

    int find_min(int data, int min)
    {
        if (min > data)
            return data;
        return min;
    }

    void push(int data)
    {
        if (st.empty())
            st.push({data, data});
        else
            int min_element = find_min(data, st.top().second());
    }
};

int main()
{

    return 0;
}