// Basically implementing a stack using a queue
#include <bits/stdc++.h>
using namespace std;

class St_queue
{
public:
    queue<int> q;
    void push(int data)
    {
        int size = q.size();
        q.push(data);
        for (int i = 0; i < size; i++)
        {
            q.push(q.front());
            q.pop();
        }
    }

    int get_top_ele()
    {
        return q.front();
    }
};

// Implement a queue using a stack but this approach takes a lot time to implement
class Queue_stack
{
public:
    stack<int> s1, s2;
    void push(int data)
    {
        // empty the s1
        while (s1.size())
        {
            s2.push(s1.top());
            s1.pop();
        }
        s1.push(data);
        while (s2.size())
        {
            s1.push(s2.top());
            s2.pop();
        }
    }
    int get_top_element()
    {
        return s1.top();
    }
};

int main()
{
    St_queue q;
    q.push(7);
    q.push(8);
    cout << q.get_top_ele() << endl;
    Queue_stack q1;
    q1.push(2);
    q1.push(3);
    cout << q1.get_top_element() << endl;
    return 0;
}