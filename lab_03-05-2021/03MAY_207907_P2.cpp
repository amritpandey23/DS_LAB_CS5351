// author: Amrit Pandey, 207907
// date: 03-05-2021
// Write a program to implement a queue using two stacks such that the enqueue operation runs in linear time and the dequeue operation runs in constant time.

// Implement the following operations

// bool EnQueue(int v)
// int DeQueue()
// bool isEmpty()
// int size()
// void print()
// Use a menu in a loop, to call these operations.
// (Here, the data type of the objects is int)

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
    void clear();
    bool isFull();
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

bool Stack::isFull()
{
    return (top + 1) >= STACK_MAX;
}

void Stack::clear()
{
    top = -1;
}

class Queue
{
private:
    Stack s1, s2;
    int sizeq = 0;

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
    if (s1.isFull() || s2.isFull())
    {
        cout << "Queue is full. Overflow occured." << endl;
        return false;
    }
    while (!s1.isEmpty())
    {
        s2.push(s1.pop());
    }
    s1.push(v);
    while (!s2.isEmpty())
    {
        s1.push(s2.pop());
    }
    sizeq++;
    return true;
}

int Queue::dequeue()
{
    if (isEmpty())
    {
        cout << "Queue is empty. Underflow occured." << endl;
        return -1;
    }
    int ele = s1.pop();
    sizeq--;
    return ele;
}

bool Queue::isEmpty()
{
    return sizeq == 0;
}

int Queue::size()
{
    return sizeq;
}

void Queue::print()
{
    if (isEmpty())
    {
        cout << "LIST is empty." << endl;
        return;
    }
    cout << "LIST: ";
    while (!s1.isEmpty())
    {
        int temp = s1.peek();
        s2.push(s1.peek());
        s1.pop();
        cout << temp << " ";
    }
    cout << endl;
    while (!s2.isEmpty())
    {
        s1.push(s2.pop());
    }
}

void Queue::run()
{
    while (true)
    {
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
    }
}

int main()
{
    Queue q;
    q.run();
    return 0;
}