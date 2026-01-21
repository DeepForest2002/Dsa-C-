#include <bits/stdc++.h>
using namespace std;

class LRU
{
    class Node
    {
    public:
        int val;
        int key;
        Node *next;
        Node *prev;
        Node(int key, int val)
        {
            this->key = key;
            this->val = val;
            next = nullptr;
            prev = nullptr;
        }
    };

public:
    // create two nodes
    Node *head = new Node(-1, -1);
    Node *tail = new Node(-1, -1);

    unordered_map<int, Node *> mpp;
    int capacity;
    LRU(int capacity)
    {
        this->capacity = capacity;
        head->next = tail;
        tail->prev = head;
    }

    void addNode(Node *newNode)
    {
        Node *nextNode = head->next;
        newNode->next = nextNode;
        nextNode->prev = newNode;
        newNode->prev = head;
        head->next = newNode;
    }

    void deleteNode(Node *delNode)
    {
        Node *delPrev = delNode->prev;
        Node *delNext = delNode->next;
        delPrev->next = delNext;
        delNext->prev = delPrev;
    }

    int get(int key)
    {
        // if the key is present then return the val otherwise -1
        if (mpp.find(key) != mpp.end())
        {
            Node *resNode = mpp[key];
            int ans = resNode->val;
            mpp.erase(key);
            deleteNode(resNode);
            addNode(resNode);
            mpp[key] = head->next;
            return ans;
        }
        return -1;
    }

    void put(int key, int val)
    {
        // if the key is present
        if (mpp.find(key) != mpp.end())
        {
            mpp.erase(key);
            deleteNode(mpp[key]);
        }
        if (mpp.size() == capacity)
        {
            // delete the prev node of tail
            mpp.erase(tail->prev->key);
            deleteNode(tail->prev);
        }
        addNode(new Node(key, val));
        mpp[key] = head->next;
    }
};

int main()
{
    LRU cache(2);

    // Put values in cache
    cache.put(1, 1);
    cache.put(2, 2);

    // Get value for key 1
    cout << cache.get(1) << endl;

    // Insert another key (evicts key 2)
    cache.put(3, 3);

    // Key 2 should be evicted
    cout << cache.get(2) << endl;

    // Insert another key (evicts key 1)
    cache.put(4, 4);

    // Key 1 should be evicted
    cout << cache.get(1) << endl;

    // Key 3 should be present
    cout << cache.get(3) << endl;

    // Key 4 should be present
    cout << cache.get(4) << endl;

    return 0;
}