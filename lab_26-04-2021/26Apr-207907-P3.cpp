// author: Amrit Pandey, 207907
// date: 26-04-2021
// implement a queue

#include <iostream>
using namespace std;

#define QUEUE_MAX 10

int menu()
{
    int n;
    cout << "Choose Option: " << endl;
    cout << "1. Enqueue" << endl;
    cout << "2. Dequeue" << endl;
    cout << "3. isEmpty?" << endl;
    cout << "4. isFull?" << endl;
    cout << "5. peek last" << endl;
    cout << "6. size" << endl;
    cout << "7. prinlist" << endl;
    cout << "0. exit" << endl;
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
    bool enqueue(int);
    int dequeue();
    int size();
    int peek();
    bool isEmpty();
    bool isFull();
    void printlist();
    void runwizard();
};

bool Queue::enqueue(int v)
{
    if (isFull())
    {
        cout << "ERROR: overflow, queue if full." << endl;
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
        cout << "ERROR: underflow, queue is empty." << endl;
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
    cout << "LIST: ";
    for (int i = front; i <= rear; i++)
    {
        cout << list[i] << " ";
    }
    cout << endl;
}

void Queue::runwizard()
{
    while (true)
    {
        if (!isEmpty())
        {
            printlist();
        }
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
            if (dequeue() != -1)
            {
                cout << "Dequeue success.";
            }
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
            printlist();
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
    // code goes here
    Queue q;
    q.runwizard();
}
