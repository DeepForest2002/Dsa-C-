#include <bits/stdc++.h>
using namespace std;
class QueueStack
{
public:
    queue<int> q;
    void push(int el)
    {
        int size = q.size();
        q.push(el);
        for (int i = 0; i < size; i++)
        {
            q.push(q.front());
            q.pop();
        }
    }
    void pop()
    {
        cout << q.front();
        q.pop();
    }
};
int main()
{
    return 0;
}