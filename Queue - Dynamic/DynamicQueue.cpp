#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node* next;
};

Node* front = NULL;
Node* rear = NULL;

void enqueue(int value)
{
    Node* tmp = new Node;
    tmp->data = value;
    tmp->next = NULL;

    if(front == NULL)
    {
        front = rear = tmp;
    }
    else
    {
        rear->next = tmp;
        rear = tmp;
    }
}

void dequeue()
{
    if(front == NULL)
    {
        cout << "Queue Underflow\n";
        return;
    }
    
    Node* tmp = front;
    front = front->next;
    delete tmp;

    if(front == NULL)
    {
            rear = NULL;
    }
    
}

int peek()
{
    if(front == NULL)
    {
        cout << "Queue is Empty\n";
        return 0;
    }
    
    return front->data;
}

void display()
{
    if(front == NULL)
    {
        cout << "Queue is Empty\n";
        return;
    }

    Node* cur = front;
    while(cur != NULL)
    {
        cout << cur->data << " ";
        cur = cur->next;
    }
    cout << endl;
}

int main()
{
    enqueue(10);
    enqueue(20);
    enqueue(30);
    display();

    dequeue();
    cout << peek() << endl;

    return 0;
}