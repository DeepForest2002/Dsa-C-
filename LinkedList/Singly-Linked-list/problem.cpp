#include <iostream>
#include <vector>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

public:
    Node(int data)
    {
        this->data = data;
        this->next = nullptr;
    }
};

Node *ConvertLL(vector<int> arr)
{
    Node *head = new Node(arr[0]);
    Node *mover = head;
    for (int i = 1; i < arr.size(); i++)
    {
        Node *new_node = new Node(arr[i]);
        mover->next = new_node;
        mover = new_node;
    }
    return head;
}

void traverse_list(Node *head)
{
    Node *temp = head;
    while (temp)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int find_len(Node *head)
{
    Node *temp = head;
    int count = 0;
    while (temp)
    {
        count += 1;
        temp = temp->next;
    }
    return count;
}

Node *reverse_list(Node *head)
{
    Node *temp = head;
    Node *front = nullptr;
    Node *prev = nullptr;
    while (temp != nullptr)
    {
        front = temp->next;
        temp->next = prev;
        prev = temp;
        temp = front;
    }
    return prev;
}

Node *addition(Node *large, Node *small)
{
    Node *temp1 = large;
    Node *temp2 = small;
    int carry = 0;
    while (temp2 != nullptr)
    {
        int sum = temp1->data + temp2->data + carry;
        temp1->data = sum % 10;
        carry = sum / 10;
        temp1 = temp1->next;
        temp2 = temp2->next;
    }
    while (temp1 != nullptr)
    {
        int sum = temp1->data + carry;
        temp1->data = sum % 10;
        carry = sum / 10;
        if (carry == 0)
            break;
        if (temp1->next == nullptr && carry > 0)
        {
            temp1->next = new Node(0);
        }
        temp1 = temp1->next;
    }
    large = reverse_list(large);
    return large;
}

Node *addLists(Node *head1, Node *head2)
{
    int len1 = find_len(head1);
    int len2 = find_len(head2);

    if (len1 > len2 && len1 == len2)
    {
        head1 = addition(head1, head2);
        return head1;
    }
    else
    {
        head2 = addition(head2, head1);
        return head2;
    }
}

int main()
{
    vector<int> arr = {9, 9, 9, 9, 9, 9, 9};
    vector<int> arr2 = {9, 9, 9, 9};
    Node *head1 = ConvertLL(arr);
    Node *head2 = ConvertLL(arr2);

    head1 = addLists(head1, head2);
    traverse_list(head1);
    return 0;
}