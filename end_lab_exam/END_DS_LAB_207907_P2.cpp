// author: Amrit Pandey, 207907
// date: 08/07/2021
// MCA II SEM Data Structure END LAB Exam

#include <iostream>
#include <limits.h>
using namespace std;

#define QUEUE_MAX 100

int menu()
{
    int r;
    cout << "Enter 1. Enque 2. Deque 3. Print 4. Exit : ";
    cin >> r;
    return r;
}

class int_Deque
{
    int arr[QUEUE_MAX];
    int front;
    int rear;
    int qsize;

public:
    int_Deque()
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
};

bool int_Deque::isFull()
{
    return ((front == 0 && rear == qsize - 1) || front == rear + 1);
}

bool int_Deque::isEmpty()
{
    return (front == -1);
}

int int_Deque::size()
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

bool int_Deque::enqueueFront(int v)
{
    if (isFull())
    {
        // cout << "Queue is full. Overflow." << endl;
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

bool int_Deque::enqueueRear(int v)
{
    if (isFull())
    {
        // cout << "Queue is full. Overflow." << endl;
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

int int_Deque::dequeueFront()
{
    int res;
    if (isEmpty())
    {
        // cout << "Queue is empty. Underflow." << endl;
        return INT_MIN;
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

int int_Deque::dequeueRear()
{
    int res;
    if (isEmpty())
    {
        // cout << "Queue is empty. Underflow." << endl;
        return INT_MIN;
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

int int_Deque::peekFront()
{
    if (isEmpty())
    {
        // cout << "Queue is empty." << endl;
        return INT_MIN;
    }
    return arr[front];
}

int int_Deque::peekRear()
{
    if (isEmpty() || rear < 0)
    {
        // cout << " Queue is empty." << endl;
        return INT_MIN;
    }
    return arr[rear];
}

void int_Deque::print()
{
    if (isEmpty())
    {
        // cout << "Queue is empty." << endl;
        return;
    }
    cout << "FRONT-> ";
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
    }
    cout << " <-REAR" << endl;
}

class priQueue
{
private:
    int_Deque dq;

public:
    bool enque(int);
    int deque();
    void print();
    void runwiz();
};

bool priQueue::enque(int v)
{
    if (dq.isFull())
    {
        return false;
    }

    int p = dq.dequeueRear();
    if (v < p || p == INT_MIN)
    {
        dq.enqueueRear(v);
    }
    else
    {
        enque(v);
    }
    dq.enqueueRear(p);
    return true;
}

int priQueue::deque()
{
    int res = dq.dequeueFront();
    return res;
}

void priQueue::print()
{
    dq.print();
}

void priQueue::runwiz()
{
    int x, y;
    while (true)
    {
        switch (menu())
        {
        case 1:
        {
            cout << "EnQue: ";
            cin >> x;
            enque(x);
            break;
        }
        case 2:
        {
            y = deque();
            cout << "Deque: " << y << endl;
            break;
        }
        case 3:
        {
            print();
            break;
        }
        case 4:
        {
            exit(0);
            break;
        }
        default:
        {
            cout << "[OUT] : Invalid operation, try again.";
            break;
        }
        }
    }
}

int main()
{
    priQueue pq;
    pq.runwiz();
}
