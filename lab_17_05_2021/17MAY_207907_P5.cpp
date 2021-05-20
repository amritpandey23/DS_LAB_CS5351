// author: Amrit Pandey, 207907
// date: 17-05-2021
// Write a program to implement a stack using linked list. The operations to be implemented are

// bool Push(int v)
// int Pop()
// int Peek()
// void Print()
// int Size()
// bool isEmpty()
// Use a menu in a loop, to call these operations.

// (Here, the data type of the objects is int)

#include <iostream>
using namespace std;

int menu()
{
    int res;
    cout << "1. Push" << endl;
    cout << "2. Pop" << endl;
    cout << "3. Print" << endl;
    cout << "4. Size" << endl;
    cout << "5. Is Empty?" << endl;
    cout << "0. Exit" << endl;
    cout << "YOUR CHOICE >> ";
    cin >> res;
    return res;
}

struct ListNode
{
    int val;
    struct ListNode *next;
};

class Stack
{
private:
    struct ListNode *top;
    int ssize;

public:
    Stack()
    {
        top = NULL;
        ssize = 0;
    }
    bool push(int);
    int pop();
    int peek();
    void print();
    int size();
    bool isEmpty();
    void runwizard();
};

bool Stack::isEmpty()
{
    return ssize == 0;
}

bool Stack::push(int v)
{
    struct ListNode *ptr = new struct ListNode;
    ptr->val = v;
    if (isEmpty())
    {
        ptr->next = NULL;
        top = ptr;
        ++ssize;
        return true;
    }
    ptr->next = top;
    top = ptr;
    ++ssize;
    return true;
}

int Stack::pop()
{
    if (isEmpty())
    {
        cout << "Stack is emtpy. Underflow." << endl;
        return -1;
    }
    int res;
    struct ListNode *ptr = top;
    top = top->next;
    --ssize;
    res = ptr->val;
    delete ptr;
    return res;
}

int Stack::peek()
{
    if (isEmpty())
    {
        cout << "Stack is empty." << endl;
        return -1;
    }
    return top->val;
}

int Stack::size()
{
    return ssize;
}

void Stack::print()
{
    if (isEmpty())
    {
        cout << "Stack is empty." << endl;
        return;
    }
    struct ListNode *ptr = top;
    cout << "TOP -> ";
    while (ptr)
    {
        cout << ptr->val << " ";
        ptr = ptr->next;
    }
    cout << endl;
}

void Stack::runwizard()
{
    while (true)
    {
        int x;
        switch (menu())
        {
        case 1:
        {
            cout << "Enter value: ";
            cin >> x;
            push(x) ? cout << x << " was successfully pushed." << endl : cout << "error while popping" << endl;
            break;
        }
        case 2:
        {
            x = pop();
            if (x != -1)
            {
                cout << x << " was popped out." << endl;
            }
            break;
        }
        case 3:
        {
            print();
            break;
        }
        case 4:
        {
            cout << "Size = " << size() << endl;
            break;
        }
        case 5:
        {
            isEmpty() ? cout << "Stack is empty" << endl : cout << "Stack is not empty" << endl;
            break;
        }
        case 0:
        {
            cout << "Exiting program" << endl;
            exit(0);
            break;
        }
        default:
        {
            cout << "Invalid choice, try again." << endl;
            break;
        }
        }
    }
}

int main()
{
    // code goes here
    Stack s;
    s.runwizard();
}
