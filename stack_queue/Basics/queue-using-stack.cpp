#include <iostream>
#include <stack>
using namespace std;

// push operation using 2 queues
class Queue_using_stack
{
public:
    stack<int> input, output;
    void push(int x)
    {
        input.push(x);
    }
    int pop()
    {
        if (output.empty())
        {
            if (input.empty())
                return -1;
            else
            {
                while (!input.empty())
                {
                    output.push(input.top());
                    input.pop();
                }
            }
        }
        if (output.empty())
            return -1;
        int el = output.top();
        output.pop();
        return el;
    }
    int top()
    {
        if (output.empty())
        {
            if (input.empty())
                return -1;
            while (!input.empty())
            {
                output.push(input.top());
                input.top();
                
            }
        }
        return output.top();
    }
};

int main()
{
    return 0;
}