#include <iostream>
#include <stdio.h>
using namespace std;

#define QUEUE_MAX 100

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

class Graph
{
private:
    int **mat;
    int start;
    int n;

public:
    Graph(int **mat, int start, int n)
    {
        this->mat = mat;
        this->start = start;
        this->n = n;
    }

    Graph(int **mat, int n)
    {
        Graph(mat, 0, n);
    }

    void BFS()
    {
        int i = start;
        Queue q;
        int visited[7] = {0};
        cout << i;
        visited[i] = 1;
        q.enqueue(i);

        while (!q.isEmpty())
        {
            i = q.dequeue();
            for (int j = 1; j < n; j++)
            {
                if (mat[i][j] == 1 && visited[j] == 0)
                {
                    cout << j;
                    visited[j] = 1;
                    q.enqueue(j);
                }
            }
        }
    }
};

int main()
{
    // int g_mat[][] = {
    //     {0, 0, 0, 0, 0, 0, 0},
    //     {0, 0, 1, 1, 0, 0, 0},
    //     {0, 1, 0, 0, 1, 0, 0},
    //     {0, 1, 0, 0, 1, 0, 0},
    //     {0, 0, 1, 1, 0, 1, 1},
    //     {0, 0, 0, 0, 1, 0, 0},
    //     {0, 0, 0, 0, 1, 0, 0}};
    /*
7
0 0 0 0 0 0 0
0 0 1 1 0 0 0
0 1 0 0 1 0 0
0 1 0 0 1 0 0
0 0 1 1 0 1 1
0 0 0 0 1 0 0
0 0 0 0 1 0 0
        */

    int n;
    cout << "Enter nodes in graph: ";
    cin >> n;
    int *arr[n];
    for (int i = 0; i < n; i++)
    {
        int x[n];
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &x[j]);
        }
        arr[i] = x;
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << arr[i][j] << " ";
        }
    }
    Graph g(arr, 1, n);
    g.BFS();
    return 0;
}
