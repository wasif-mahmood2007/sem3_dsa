#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node* next;
};

Node* front = NULL;
Node* rear = NULL;

void enqueue(int v)
{
    Node* tmp = new Node{v, NULL};

    if(front == NULL)
    {
        front = rear = tmp;
        return;
    }

    rear->next = tmp;
    rear = tmp;
}

void dequeue()
{
    if(front == NULL)
    {
        cout << "Queue Underflow.\n";
        return;
    }

    Node* tmp = front;
    front = front->next;
    delete tmp;
    if(front == NULL) rear = NULL;
}

int peek()
{
    if(front == NULL)
    {
        cout << "Queue is empty.\n";
        return -1;
    }

    return front->data;
}

void display()
{
    if(front == NULL)
    {
        cout << "Queue is empty.\n";
        return;
    }

    for(Node* cur = front; cur != NULL; cur = cur->next)
    {
        cout << cur->data << " ";
    }
    cout << endl;
}

int main()
{
    //Enqueue
    enqueue(10);
    enqueue(20);
    enqueue(30);
    display();

    //Dequeue
    dequeue();

    //Peek
    cout << peek() << endl;

    dequeue();
    dequeue();
    dequeue(); //Dequeue empty queue
}
