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

void recprint(Node *head) //do same thing as lili2 recursively
{
    Node *curr = head;
    if (curr != NULL)
    {
        cout << curr->data << " ";
        recprint(curr->next);
    }
    else
    {
        return;
    }
} //what i did can be more effiecient if i switch the if and else conditions
//i.e curr==null goes in the if condition therefore making the whole fuction
//tail recursive.hence more efficient.
//time ccomp=O(n)
//auxilary space=O(n)(for recursive funtion)
//auxillary space=O(1)(for iterative fuction)

int main()
{
    Node *head = new Node(10); //this is a better way to makeing a lili
    head->next = new Node(20); //without using temp variables
    head->next->next = new Node(30);
    head->next->next->next = new Node(40);
    recprint(head);
}