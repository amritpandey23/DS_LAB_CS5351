// author: Amrit Pandey, 207907
// date: 17-05-2021
// Write a program to implement a circular double ended queue (Deque) using array, with the following operations

// bool EnQueueRear(int v)
// bool EnQueueFront(int v)
// int DeQueueFront()
// int DeQueueRear()
// int Peek()
// void Print()
// int size()
// bool isEmpty()
// bool isFull()
// Use a menu in a loop, to call these operations.

// (Here, the data type of the objects is int)

#include <iostream>
using namespace std;

#define MAX 100

int menu()
{
    int res;
    cout << "1. Enqueue Front" << endl;
    cout << "2. Enqueue Rear" << endl;
    cout << "3. Dequeue Front" << endl;
    cout << "4. Dequeue Rear" << endl;
    cout << "5. Peek Front" << endl;
    cout << "6. Peek Rear" << endl;
    cout << "7. Size" << endl;
    cout << "8. Print" << endl;
    cout << "0. Exit" << endl;
    cout << "YOUR CHOICE >>> ";
    cin >> res;
    return res;
}

class Deque
{
    int arr[MAX];
    int front;
    int rear;
    int qsize;

public:
    Deque()
    {
        front = -1;
        rear = 0;
        qsize = 10;
    }

    bool enqueueFront(int);
    bool enqueueRear(int);
    int dequeueFront();
    int dequeueRear();
    bool isFull();
    bool isEmpty();
    int peekFront();
    int peekRear();
    void print();
    int size();
    void runwizard();
};

bool Deque::isFull()
{
    return ((front == 0 && rear == qsize - 1) || front == rear + 1);
}

bool Deque::isEmpty()
{
    return (front == -1);
}

int Deque::size()
{
    if (isEmpty())
    {
        return 0;
    }
    int curr = 0;
    while (front != rear)
    {
        curr++;
        front = (front + 1) % qsize;
    }
    return curr + 1;
}

bool Deque::enqueueFront(int v)
{
    if (isFull())
    {
        cout << "Queue is full. Overflow." << endl;
        return false;
    }

    if (front == -1)
    {
        front = 0;
        rear = 0;
    }
    else if (front == 0)
    {
        front = qsize - 1;
    }
    else
    {
        front = front - 1;
    }

    arr[front] = v;
    return true;
}

bool Deque ::enqueueRear(int v)
{
    if (isFull())
    {
        cout << "Queue is full. Overflow." << endl;
        return false;
    }

    if (front == -1)
    {
        front = 0;
        rear = 0;
    }
    else if (rear == qsize - 1)
    {
        rear = 0;
    }
    else
    {
        rear = rear + 1;
    }

    arr[rear] = v;
    return true;
}

int Deque::dequeueFront()
{
    int res;
    if (isEmpty())
    {
        cout << "Queue is empty. Underflow." << endl;
        return -1;
    }
    res = arr[front];

    if (front == rear)
    {
        front = -1;
        rear = -1;
    }
    else
    {
        if (front == qsize - 1)
        {
            front = 0;
        }
        else
        {
            front = front + 1;
        }
    }

    return res;
}

int Deque::dequeueRear()
{
    int res;
    if (isEmpty())
    {
        cout << "Queue is empty. Underflow." << endl;
        return -1;
    }
    res = arr[rear];

    if (front == rear)
    {
        front = -1;
        rear = -1;
    }
    else if (rear == 0)
    {
        rear = qsize - 1;
    }
    else
    {
        rear = rear - 1;
    }

    return res;
}

int Deque::peekFront()
{
    if (isEmpty())
    {
        cout << "Queue is empty." << endl;
        return -1;
    }
    return arr[front];
}

int Deque::peekRear()
{
    if (isEmpty() || rear < 0)
    {
        cout << " Queue is empty." << endl;
        return -1;
    }
    return arr[rear];
}

void Deque::print()
{
    if (isEmpty())
    {
        cout << "Queue is empty." << endl;
        return;
    }
    if (front == rear)
    {
        cout << arr[front] << " ";
    }
    else
    {
        for (int i = front; i != rear; i = (i + 1) % qsize)
        {
            cout << arr[i] << " ";
        }
        cout << arr[rear] << " ";
    }
    cout << endl;
}

void Deque::runwizard()
{
    int x, y;
    while (true)
    {
        switch (menu())
        {
        case 1:
        {
            cout << "Enter value: ";
            cin >> x;
            enqueueFront(x);
            break;
        }
        case 2:
        {
            cout << "Enter value: ";
            cin >> x;
            enqueueRear(x);
            break;
        }
        case 3:
        {
            x = dequeueFront();
            x == -1 ? cout << "Error while dequeue" << endl : cout << x << " was dequeued from front" << endl;
            break;
        }
        case 4:
        {
            x = dequeueRear();
            x == -1 ? cout << "Error while dequeue" << endl : cout << x << " was dequeued from rear" << endl;
            break;
        }
        case 5:
        {
            x = peekFront();
            if (x != -1)
            {
                cout << "PEEK FRONT = " << x << endl;
            }
            break;
        }
        case 6:
        {
            x = peekRear();
            if (x != -1)
            {
                cout << "PEEK REAR = " << x << endl;
            }
            break;
        }
        case 7:
        {
            cout << "SIZE = " << size() << endl;
            break;
        }
        case 8:
        {
            print();
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
            cout << "Invalid Option. Try again." << endl;
            break;
        }
        }
    }
}

int main()
{
    Deque q;
    q.runwizard();
}
