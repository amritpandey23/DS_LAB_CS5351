// author: Amrit Pandey, 207907
// date: 17-05-2021
// Write a program to implement a stack using two queues such that the push operation runs in constant time and the pop operation runs in linear time.

// Implement the following operations

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

#define QUEUE_MAX 10

int menu()
{
    int n;
    cout << "1. Push" << endl;
    cout << "2. Pop" << endl;
    cout << "3. Peek" << endl;
    cout << "4. Print" << endl;
    cout << "5. Size" << endl;
    cout << "6. Is Empty?" << endl;
    cout << "0. Exit" << endl;
    cout << "YOUR CHOICE >>> ";
    cin >> n;
    return n;
}

class Queue
{
private:
    int front, rear;
    int list[QUEUE_MAX];

public:
    Queue()
    {
        front = rear = -1;
    }
    int getfront();
    bool enqueue(int);
    int dequeue();
    int size();
    int peek();
    bool isEmpty();
    bool isFull();
    void printlist();
    void runwizard();
    void clean();
};

int Queue::getfront()
{
    return list[front];
}

bool Queue::enqueue(int v)
{
    if (isFull())
    {
        // cout << "ERROR: overflow, queue if full." << endl;
        return false;
    }
    if (isEmpty())
    {
        front++;
    }
    list[++rear] = v;
    return true;
}

int Queue::dequeue()
{
    if (isEmpty())
    {
        // cout << "ERROR: underflow, queue is empty." << endl;
        return -1;
    }
    int res;
    if (front == rear)
    {
        res = list[front];
        front = rear = -1;
        return res;
    }
    return list[front++];
}

int Queue::size()
{
    if (front == rear == -1)
    {
        return 0;
    }
    return rear - front + 1;
}

int Queue::peek()
{
    if (isEmpty())
    {
        cout << "ERROR: list is empty." << endl;
        return -1;
    }
    return list[rear];
}

bool Queue::isEmpty()
{
    return front == -1 && rear == -1;
}

bool Queue::isFull()
{
    return (rear == QUEUE_MAX - 1);
}

void Queue::printlist()
{
    if (isEmpty())
    {
        cout << "LIST is empty." << endl;
        return;
    }
    for (int i = front; i <= rear; i++)
    {
        cout << list[i] << " ";
    }
    cout << endl;
}

void Queue::clean()
{
    rear = front = -1;
}

class Stack
{
private:
    Queue q0, q1;
    int ssize = 0;

public:
    bool push(int);
    int pop();
    int peek();
    void print();
    int size();
    bool isEmpty();
    void run();
};

bool Stack::push(int v)
{
    int tmp;
    if (ssize + 1 >= QUEUE_MAX)
    {
        cout << "Stack is full." << endl;
        return false;
    }
    if (q0.isEmpty())
    {
        q0.enqueue(v);
        while ((tmp = q1.dequeue()) != -1)
        {
            q0.enqueue(tmp);
        }
    }
    else
    {
        q1.enqueue(v);
        while ((tmp = q0.dequeue()) != -1)
        {
            q1.enqueue(tmp);
        }
    }
    ssize++;
    return true;
}

int Stack::pop()
{
    int res;
    if (ssize == 0)
    {
        cout << "Stack is empty." << endl;
        return -1;
    }
    if (q0.isEmpty())
    {
        res = q1.dequeue();
    }
    else
    {
        res = q0.dequeue();
    }
    ssize--;
    return res;
}

int Stack::size()
{
    return ssize;
}

bool Stack::isEmpty()
{
    return size() == 0;
}

int Stack::peek()
{
    if (isEmpty())
    {
        cout << "Stack is empty." << endl;
        return -1;
    }
    if (q0.isEmpty())
    {
        return q1.getfront();
    }
    return q0.getfront();
}

void Stack::print()
{
    if (ssize == 0)
    {
        cout << "Stack is empty." << endl;
        return;
    }
    cout << "TOP -> ";
    if (q0.isEmpty())
    {
        q1.printlist();
    }
    else
    {
        q0.printlist();
    }
}

void Stack::run()
{
    while (true)
    {
        int a, b, c;
        switch (menu())
        {
        case 1:
        {
            cout << "Enter value: ";
            cin >> a;
            push(a) ? cout << a << " was pushed successfully" << endl : cout << "error encountered while pushing " << a << endl;
            break;
        }
        case 2:
        {
            a = pop();
            a == -1 ? cout << "Error while popping." << endl : cout << "Successfully popped " << a << endl;
            break;
        }
        case 3:
        {
            a = peek();
            a == -1 ? cout << "Error while peeking." << endl : cout << "PEEK = " << a << endl;
            break;
        }
        case 4:
        {
            print();
            break;
        }
        case 5:
        {
            cout << "Size of stack = " << size() << endl;
            break;
        }
        case 6:
        {
            isEmpty() ? cout << "Stack is empty." << endl : cout << "Stack is not empty" << endl;
            break;
        }
        case 0:
        {
            cout << "Exiting application." << endl;
            exit(0);
            break;
        }
        defaut:
        {
            cout << "Invalid option inserted. Try again." << endl;
            break;
        }
        }
    }
}

int main()
{
    Stack s;
    s.run();
    return 0;
}