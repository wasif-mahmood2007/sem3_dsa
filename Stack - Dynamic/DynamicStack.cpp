#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node* next;
};

Node* top = NULL;

void push(int v)
{
    Node* tmp = new Node{v, top};
    top = tmp;
}

void pop()
{
    if(top == NULL)
    {
        cout << "Stack Underflow.\n";
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
        cout << "Stack is empty.\n";
        return -1;
    }
    
    return top->data;
}

void display()
{
    if(top == NULL)
    {
        cout << "Stack is empty.\n";
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
    display();
}
