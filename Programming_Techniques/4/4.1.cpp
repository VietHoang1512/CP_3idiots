#include <iostream>
using namespace std;
struct Node
{
    int data;
    Node *next;

    Node(int data)
    {
        this->data = data;
        next = NULL;
    }
};

// push a new element to the beginning of the list
Node *prepend(Node *head, int data)
{
    /*****************
    # YOUR CODE HERE #
    *****************/
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = head;
    return newNode;
}

// print the list content on a line
void print(Node *head)
{
    /*****************
    # YOUR CODE HERE #
    *****************/
    while (head)
    {
        cout << head->data << " ";
        head = head->next;
    }
}

// return the new head of the reversed list
Node *reverse(Node *head)
{
    /*****************
    # YOUR CODE HERE #
    *****************/
    // if (!head)
    //     return head;
    Node *prev = head, *next;
    cout << head->data << " ";
    head = head->next;
    
    while (head)
    {   
        cout << head->data << " ";
        next = head->next;
        head->next = prev;
        prev = head;
        head = next;
    }
    return prev;
}

int main()
{
    int n, u;
    cin >> n;
    Node *head = NULL;
    for (int i = 0; i < n; ++i)
    {
        cin >> u;
        head = prepend(head, u);
    }

    // cout << "Original list: ";
    // print(head);

    head = reverse(head);

    cout << "Reversed list: ";
    // print(head);

    return 0;
}