#include <bits/stdc++.h>
using namespace std;
int size = 5;
void push(list<int> &arr, int element)
{
    if (arr.size() >= size)
    {
        cout << "Queue is full" << endl;
        return;
    }
    arr.push_back(element);
    cout << "Push is done";
}

void pop(list<int> &arr)
{
    if (arr.size() == 0)
    {
        cout << "Underflow" << endl;
        return;
    }
    int el = arr.front();
    arr.pop_front();
}

int main()
{
    list<int> arr;
    vector<int> ls;
    return 0;
}