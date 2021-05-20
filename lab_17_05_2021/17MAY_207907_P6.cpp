// author: Amrit Pandey, 207907
// date: 17-05-2021
// Write a program to implement a circular queue using linked list. The operations to be implemented are

// bool EnQueue(int v)
// int DeQueue()
// int Peek()
// void Print()
// int Size()
// bool isEmpty()
// Use a menu in a loop, to call these operations.
// (Here, the data type of the objects is int)

#include <iostream>
using namespace std;

#define INT_MIN -2147483648

int menu()
{
    int res;
    cout << "1. Enqueue" << endl;
    cout << "2. Dequeue" << endl;
    cout << "3. Peek" << endl;
    cout << "4. Print" << endl;
    cout << "5. Size" << endl;
    cout << "0. Exit" << endl;
    cout << "YOUR CHOICE >> ";
    cin >> res;
    return res;
}

struct ListNode
{
    int data;
    struct ListNode *link;
};

class CircularQueue
{
private:
    struct ListNode *front, *rear;
    int qsize;

public:
    CircularQueue()
    {
        qsize = 0;
        front = rear = NULL;
    }
    bool enqueue(int);
    int dequeue();
    int peek();
    void print();
    int size();
    bool isEmpty();
    void runwizard();
};

bool CircularQueue::isEmpty()
{
    return front == NULL;
}

bool CircularQueue::enqueue(int v)
{
    struct ListNode *tmp = new struct ListNode;
    tmp->data = v;
    if (isEmpty())
    {
        front = tmp;
    }
    else
    {
        rear->link = tmp;
    }
    rear = tmp;
    rear->link = front;
    ++qsize;
    return true;
}

int CircularQueue::dequeue()
{
    if (isEmpty())
    {
        cout << "Queue is empty. Underflow." << endl;
        return INT_MIN;
    }
    int res;
    if (front == rear)
    {
        res = front->data;
        delete front;
        front = NULL;
        rear = NULL;
    }
    else
    {
        struct ListNode *tmp = front;
        res = tmp->data;
        front = front->link;
        rear->link = front;
        delete tmp;
    }
    ++qsize;
    return res;
}

void CircularQueue::print()
{
    if (isEmpty())
    {
        cout << "List empty." << endl;
        return;
    }
    struct ListNode *tmp;
    tmp = front;
    cout << "FRONT -> ";
    while (tmp->link != front)
    {
        cout << tmp->data << " ";
        tmp = tmp->link;
    }
    cout << tmp->data << " <- REAR" << endl;
}

int CircularQueue::size()
{
    return qsize;
}

int CircularQueue::peek()
{
    if (isEmpty())
    {
        cout << "Queue is empty." << endl;
        return INT_MIN;
    }
    return rear->data;
}

void CircularQueue::runwizard()
{
    int x, y;
    while (true)
    {
        print();
        switch (menu())
        {
        case 1:
        {
            cout << "Enter value: ";
            cin >> x;
            enqueue(x) ? cout << x << " was enqueued successfully." << endl : cout << "enqueue failed." << endl;
            break;
        }
        case 2:
        {
            x = dequeue();
            if (x != INT_MIN)
            {
                cout << x << " was dequeued successfully." << endl;
            }
            break;
        }
        case 3:
        {
            x = peek();
            if (x != INT_MIN)
            {
                cout << "PEEK = " << x << endl;
            }
            break;
        }
        case 4:
        {
            print();
            break;
        }
        case 5:
        {
            cout << "SIZE = " << size() << endl;
            break;
        }
        case 0:
        {
            cout << "Exiting program." << endl;
            exit(0);
            break;
        }
        default:
        {
            cout << "Invalid Choice, Try again." << endl;
            break;
        }
        }
    }
}

int main()
{
    CircularQueue q;
    q.runwizard();
    return 0;
}
