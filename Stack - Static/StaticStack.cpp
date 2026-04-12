#include <iostream>
using namespace std;

int stackArr[10];
int top = -1;

void push(int value)
{
    if(top == 9)
    {
        cout << "Stack Overflow\n";
        return;
    }
    
    top++;
    stackArr[top] = value;
}

void pop()
{
    if(top == -1)
    {
        cout << "Stack Underflow\n";
        return;
    }
    
    top--;
}

int peek()
{
    if(top == -1)
    {
        cout << "Stack is empty\n";
        return -1;
    }
    
    return stackArr[top];
}

void display()
{
    if(top == -1)
    {
        cout << "Stack is empty\n";
        return;
    }
    
    for(int i = top; i >= 0; i--)
    {
        cout << stackArr[i] << " ";
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

    return 0;
}