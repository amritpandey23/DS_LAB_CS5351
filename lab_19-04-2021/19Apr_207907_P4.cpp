// author: Amrit Pandey, 207907
// date: 19-04-2021

#include <iostream>
using namespace std;

#define STACK_MAX 1000

class Stack
{
private:
    int top;

public:
    int a[STACK_MAX];
    Stack()
    {
        top = -1;
    }
    int get_top();
    void set_top(int);
    bool push(int);
    int pop();
    int peek();
    bool isEmpty();
    void printlist();
};

int Stack::get_top()
{
    return top;
}

void Stack::set_top(int x)
{
    this->top = x;
}

bool Stack::push(int x)
{
    if (top >= (STACK_MAX - 1))
    {
        cout << "overflow" << endl;
        return false;
    }
    a[++top] = x;
    return true;
}

int Stack::pop()
{
    if (top < 0)
    {
        cout << "stack empty." << endl;
        return 0;
    }
    int x = a[top--];
    return x;
}
int Stack::peek()
{
    if (top == -1)
    {
        cout << "stack empty.";
        return -1;
    }
    return a[top];
}

bool Stack::isEmpty()
{
    return (top < 0);
}

void Stack::printlist()
{
    if (top == -1)
    {
        cout << "[stack empty.]" << endl;
        return;
    }
    for (int i = top; i >= 0; i--)
    {
        cout << a[i] << " ";
    }
    cout << endl;
}

void comparestacks(Stack &s1, Stack &s2)
{
    cout << "s1\ts2\tSAME?" << endl;
    for (int i = s1.get_top(); i >=0; i--)
    {
        cout << s1.a[i] << "\t" << s2.a[i];
        if (s1.a[i] == s2.a[i])
        {
            cout << "\tYES" << endl;
        }
        else
        {
            cout << "\tNO" << endl;
        }
    }
}

int main()
{
    Stack s1, s2;
    for (int i = 0; i < 10; i++)
    {
        s1.push(i*2);
        s2.push(i*3);
    }
    Stack &s11 = s1, &s22 = s2;
    comparestacks(s11, s22);
}
