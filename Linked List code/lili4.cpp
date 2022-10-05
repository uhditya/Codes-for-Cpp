#include <bits/stdc++.h>

using namespace std;

struct Node
{
    int data;
    struct Node *next;
    Node(int x)
    {
        data = x;
        next = NULL;
    }
};

int seachrec(Node *head, int x)
{
    if (head == NULL)
    {
        return -1;
    }
    if (head->data == x)
    {
        return 1;
    }
    else
    {
        int res = seachrec(head->next, x);
        if (res == -1)
        {
            return -1;
        }
        else
        {
            return (res + 1);
        }
    }
}

int seachLL(Node *head, int x) // this is the iterative sol to search for a
// specific value in a lili.
{
    int pos = 1;
    Node *curr = head;
    while (curr != NULL)
    {
        if (curr->data == x)
        {
            return pos;
        }
        else
        {
            pos++;
            curr = curr->next;
        }
        // int i = 0;
        // Node *curr = head;
        // while (curr->data != x && curr != NULL)
        // {
        //     curr = curr->next;
        //     i++;
        // }
        // if (curr->data == x)
        // {
        //     cout << i << endl;
        // }
        // else
        // {
        //     cout << -1 << endl;
        // }
    }
    return -1;
}

// time complexity for both iterative and recursive is O(n)
// auxiliary space for iterative is O(1) or constant space
// auxillary space for recursive is O(n) space.

int main()
{
    Node *head = new Node(10);
    head->next = new Node(5);
    head->next->next = new Node(20);
    head->next->next->next = new Node(15);
    cout << seachrec(head, 15);
}