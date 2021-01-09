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
    if (head == NULL)
    {
        head = new Node(data);
        return head;
    }
    Node *tmp = new Node(data);
    tmp->next = head;
    return tmp;
}

// print the list content on a line
void print(Node *head)
{
    /*****************
    # YOUR CODE HERE #
    *****************/
    if (head == NULL)
    {
        cout << endl;
        return;
    }
    Node *tmp = head;
    while (tmp != NULL)
    {
        cout << tmp->data << " ";
        tmp = tmp->next;
    }
    cout << endl;
    return;
}

// return the new head of the reversed list
Node *reverse(Node *head)
{
    /*****************
    # YOUR CODE HERE #
    *****************/
    if ((head == NULL) || (head->next == NULL))
    {
        return head;
    }
    Node *tmp1, *tmp2, *tmp3;
    tmp1 = head;
    tmp2 = head->next;
    tmp1->next = NULL;
    while (tmp2->next)
    {
        tmp3 = tmp2->next;
        tmp2->next = tmp1;
        tmp1 = tmp2;
        tmp2 = tmp3;
    }
    tmp2->next = tmp1;
    return tmp2;
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

    cout << "Original list: ";
    print(head);

    head = reverse(head);

    cout << "Reversed list: ";
    print(head);

    return 0;
}