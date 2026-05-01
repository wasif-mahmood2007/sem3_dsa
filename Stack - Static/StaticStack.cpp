#include <iostream>
using namespace std;

const int stackSize = 10;
int stackArr[stackSize];
int top = -1;

void push(int v)
{
    if(top == stackSize - 1)
    {
        cout << "Stack Overflow." << endl;
        return;
    }
    
    top++;
    stackArr[top] = v;
    cout << "Pushed: " << v << endl;
}

void pop()
{
    if(top == -1)
    {
        cout << "Stack Underflow." << endl;
        return;
    }
    
    cout << "Popped: " << stackArr[top] << endl;
    top--;
}

int peek()
{
    if(top == -1)
    {
        cout << "Stack is empty." << endl;
        return -1;
    }
    
    return stackArr[top];
}

void display()
{
    if(top == -1)
    {
        cout << "Stack is empty." << endl;
        return;
    }
    
    for(int i = top; i >= 0; i--)
    {
        cout << stackArr[i] << " ";
    }
    cout << endl;
}

int main() {
    push(3);
    push(6);
    push(9);
    push(12);
    display();

    pop();
    cout << peek() << endl;
    display();
}
