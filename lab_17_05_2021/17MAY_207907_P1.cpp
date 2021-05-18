// author: Amrit Pandey, 207907
// date: 17-05-2021
// Write a program to implement circular queue using array, with the following operations

// bool EnQueue(int v)
// int DeQueue()
// int Peek()
// void Print()
// int Size()
// bool isEmpty()
// bool isFull()
// Use a menu in a loop, to call these operations.

// (Here, the data type of the objects is int)

#include <iostream>
using namespace std;

#define QUEUE_MAX 10

int menu()
{
    int n;
    cout << "1. Enqueue" << endl;
    cout << "2. Dequeue" << endl;
    cout << "3. isEmpty?" << endl;
    cout << "4. isFull?" << endl;
    cout << "5. Peek" << endl;
    cout << "6. size" << endl;
    cout << "7. print" << endl;
    cout << "0. exit" << endl;
    cout << "YOUR CHOICE >>> ";
    cin >> n;
    return n;
}

class CircularQueue
{
private:
    int list[QUEUE_MAX], front, rear, n;

public:
    CircularQueue()
    {
        front = rear = -1;
    }
    bool enqueue(int);
    int dequeue();
    int peek();
    void print();
    bool isEmpty();
    bool isFull();
    void runwizard();
    int size();
};

int CircularQueue::size()
{
    if (isEmpty())
    {
        return 0;
    }
    return abs(front - rear + 1);
}

bool CircularQueue::isEmpty()
{
    return front == -1 && rear == -1;
}

bool CircularQueue::isFull()
{
    return ((rear + 1) % n) == front;
}

bool CircularQueue::enqueue(int e)
{
    if (isFull())
    {
        cout << "overflow" << endl;
        return false;
    }
    if (isEmpty())
    {
        front = rear = 0;
    }
    else
    {
        rear = (rear + 1) % n;
    }
    list[rear] = e;
    return true;
}

int CircularQueue::dequeue()
{
    int res;
    if (front == rear == -1)
    {
        cout << "underflow" << endl;
        return -1;
    }
    if (isFull())
    {
        res = this->list[front];
        front = rear = -1;
    }
    else
    {
        res = list[front];
        front = (++front) % n;
    }
    return res;
}

int CircularQueue::peek()
{
    if (isEmpty())
    {
        cout << "Queue is empty." << endl;
        return -1;
    }
    return list[rear];
}

void CircularQueue::print()
{
    if (isEmpty())
    {
        cout << "Queue is empty." << endl;
        return;
    }
    for (int i = front; i <= rear; i++)
    {
        cout << list[i] << " ";
    }
    cout << endl;
}

void CircularQueue::runwizard()
{
    int x, y;
    while (true)
    {
        switch (menu())
        {
        case 1:
        {
            int n;
            cout << "Enter value: ";
            cin >> n;
            if (enqueue(n))
            {
                cout << "Enqueue success." << endl;
            }
            break;
        }
        case 2:
        {
            x = dequeue();
            break;
        }
        case 3:
        {
            isEmpty() ? cout << "Yes, queue is empty." << endl : cout << "No, queue is not empty." << endl;
            break;
        }
        case 4:
        {
            isFull() ? cout << "Yes, queue is full." << endl : cout << "No, queue is not full." << endl;
            break;
        }
        case 5:
        {
            cout << "PEEK: " << peek() << endl;
            break;
        }
        case 6:
        {
            cout << "SIZE: " << size() << endl;
            break;
        }
        case 7:
        {
            print();
            break;
        }
        case 0:
        {
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
    CircularQueue q;
    q.runwizard();
}
