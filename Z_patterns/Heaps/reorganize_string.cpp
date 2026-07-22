// leetcode -767
#include <bits/stdc++.h>
using namespace std;

struct cmp
{
    /* data */
    bool operator()(pair<int, char> &a, pair<int, char> &b)
    {
        if (a.first != b.first)
            return a.first < b.first;
        return a.second < b.second;
    }
};

string reOrganize(string &str)
{
    int index = 0;
    string res = "";
    priority_queue<pair<int, char>, vector<pair<int, char>>, cmp> mx_pq;
    unordered_map<char, int> mpp;
    for (auto el : str)
    {
        mpp[el]++;
    }
    for (auto el : mpp)
    {
        pair<int, char> pq = {el.second, el.first};
        mx_pq.push(pq);
    }
    while (!mx_pq.empty())
    {
        pair<int, char> p1 = mx_pq.top();
        mx_pq.pop();
        if (index == 0 || res[index - 1] != p1.second)
        {
            res.push_back(p1.second);
            index += 1;
            p1.first -= 1;
            if (p1.first > 0)
                mx_pq.push(p1);
        }
        else
        {
            if (mx_pq.empty())
                return "";
            pair<int, char> p2 = mx_pq.top();
            mx_pq.pop();
            res.push_back(p2.second);
            index += 1;
            p2.first -= 1;
            if (p2.first > 0)
                mx_pq.push(p2);
            mx_pq.push(p1);
        }
    }
    return res;
}

int main()
{
    string str = "aab";
    cout << reOrganize(str);
    return 0;
}