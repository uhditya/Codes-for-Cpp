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

int main() // creating a linked list here head=10 then 2nd node=20 and 3rd=30.
{
    Node *head = new Node(10);
    Node *temp1 = new Node(20); //there is a better method of doing this without
    Node *temp2 = new Node(30); //using temp variables,explained in lili2
    head->next = temp1;
    temp1->next = temp2;
    cout << temp1->data << " ";
}