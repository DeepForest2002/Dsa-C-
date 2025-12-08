#include <iostream>
#include <vector>
using namespace std;
class Node
{
public:
    int data;
    Node *next;

public:
    Node(int data1)
    {
        this->data = data1;
        next = nullptr;
    }
};

Node *ConvertLL(vector<int> arr)
{
    Node *head = new Node(arr[0]);
    Node *mover = head;
    for (int i = 1; i < arr.size(); i++)
    {
        Node *temp = new Node(arr[i]);
        mover->next = temp;
        mover = temp;
    }
    return head;
}

int check_element(Node *head, int data)
{
    Node *temp = head;
    while (temp != nullptr)
    {
        if (temp->data == data)
            return true;
        temp = temp->next;
    }
    return false;
}

int main()
{
    vector<int> Arr = {1, 2, 4, 5, 6};
    Node *head = ConvertLL(Arr);
    // cout << head->data << endl;
    // Traverse the Linked List
    int ans = check_element(head, 9);
    cout << ans;
    return 0;
}