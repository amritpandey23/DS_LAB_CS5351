// author: Amrit Pandey, 207907
// date: 03-05-2021
// Write a program to implement a queue using two stacks such 
// that the enqueue operation runs in constant time and the dequeue 
// operation runs in linear time.

// Implement the following operations

// bool EnQueue(int v)
// int DeQueue()
// bool isEmpty()
// int size()
// void print()
// Use a menu in a loop, to call these operations.

#include <iostream>
using namespace std;

#define STACK_MAX 1000

int menu()
{
    int x;
    cout << "Enter your choice." << endl;
    cout << "1. enqueue" << endl;
    cout << "2. dequeue" << endl;
    cout << "3. isEmpty?" << endl;
    cout << "4. size" << endl;
    cout << "5. printlist" << endl;
    cout << "0. exit" << endl;
    cin >> x;
    return x;
}

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
    bool push(int x);
    int pop();
    int peek();
    bool isEmpty();
    void run();
    void printlist();
    int gettop();
};

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

int Stack::gettop()
{
    return top;
}

class Queue
{
private:
    Stack s1, s2;

public:
    bool enqueue(int);
    int dequeue();
    bool isEmpty();
    int size();
    void print();
    void run();
};

bool Queue::enqueue(int v)
{
    s1.push(v); // constant time
    return true;
}

int Queue::dequeue() // linear time
{
    if (isEmpty())
    {
        cout << "Queue is empty. Underflow occured." << endl;
        return -1;
    }
    int x;
    if (s2.isEmpty())
    {
        while (!s1.isEmpty())
        {
            x = s1.pop();
            s2.push(x);
        }
    }
    return s2.pop();
}

bool Queue::isEmpty()
{
    return s1.isEmpty() && s2.isEmpty();
}

int Queue::size()
{
    return s1.gettop() + s2.gettop() + 2;
}

void Queue::print()
{
    if (isEmpty())
    {
        cout << "LIST is empty. Nothing to print." << endl;
        return;
    }
    cout << "LIST: ";
    for (int i = s1.gettop(); i >= 0; i--)
    {
        cout << s1.a[i] << " ";
    }
    for (int i = s2.gettop(); i >= 0; i--)
    {
        cout << s2.a[i] << " ";
    }
    cout << endl;
}

void Queue::run()
{
    while (1)
    {
        cout << endl;
        switch (menu())
        {
        case 1:
        {
            int x;
            cout << "Enter value: ";
            cin >> x;
            enqueue(x);
            break;
        }
        case 2:
        {
            int x;
            if ((x = dequeue()) != -1)
            {
                cout << "successfully dequeud item " << x << endl;
            }
            break;
        }
        case 3:
        {
            isEmpty() ? cout << "Queue is empty" << endl : cout << "Queue is not empty" << endl;
            break;
        }
        case 4:
        {
            cout << "Size of queue = " << size() << endl;
            break;
        }
        case 5:
        {
            print();
            break;
        }
        case 0:
        {
            exit(0);
        }
        }
        cout << endl;
    }
}

int main()
{
    // code goes here
    Queue q;
    q.run();
}
