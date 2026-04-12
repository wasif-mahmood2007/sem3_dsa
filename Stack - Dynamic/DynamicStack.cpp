#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node* next;
};

Node* top = NULL;

void push(int value)
{
    Node* tmp = new Node;
    tmp->data = value;
    tmp->next = top;

    top = tmp;
}

void pop()
{
    if(top == NULL)
    {
        cout << "Stack Underflow\n";
        return;
    }

    Node* tmp = top;
    top = top->next;
    delete tmp;
}

int peek()
{
    if(top == NULL)
    {
        cout << "Stack is Empty\n";
        return 0;
    }

    return top->data;
}

void display()
{
    if(top == NULL)
    {
        cout << "Stack is Empty\n";
        return;
    }

    Node* cur = top;
    while(cur != NULL)
    {
        cout << cur->data << " ";
        cur = cur->next;
    }
    cout << endl;
}

int main()
{
    push(3);
    push(6);
    push(9);
    push(12);
    display();

    pop();
    cout << peek() << endl;

    return 0;
}