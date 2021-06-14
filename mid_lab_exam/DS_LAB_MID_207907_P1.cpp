// author: Amrit Pandey, 207907
// date: 07-06-2021
// DS MID LAB EXAM

#include <iostream>
using namespace std;

#define STACK_MAX 100
#define INT_MAX 2147483647

int menu()
{
    int res;
    cout << "1. Enqueue Front" << endl;
    cout << "2. Enqueue Rear" << endl;
    cout << "3. Dequeue Front" << endl;
    cout << "4. Dequeue Rear" << endl;
    cout << "5. Print" << endl;
    cout << "YOUR CHOICE >>> ";
    cin >> res;
    return res;
}

class Stack
{
private:
    int top;
    size_t size;

public:
    int a[STACK_MAX];
    Stack()
    {
        top = -1;
        size = 0;
    }
    bool push(int x);
    int pop();
    int peek();
    bool isEmpty();
    void printlist();
    int gettop();
    size_t getsize()
    {
        return size;
    }
    int insert_at_bottom(int x)
    {

        if (size == 0)
            push(x);

        else
        {

            int a = this->a[top];
            pop();
            insert_at_bottom(x);

            push(a);
        }
    }

    int reverse()
    {
        if (size > 0)
        {
            int x = this->a[top];
            pop();
            reverse();
            insert_at_bottom(x);
        }
    }
};

bool Stack::push(int x)
{
    if (top >= (STACK_MAX - 1))
    {
        cout << "overflow" << endl;
        return false;
    }
    a[++top] = x;
    size++;
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
    size--;
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

Stack s; // global variable

class Dequeue
{
public:
    bool enqueueRear(int v)
    {
        s.push(v);
        return true;
    }

    int dequeueRear()
    {
        if (s.isEmpty())
        {
            return INT_MAX;
        }
        return s.pop();
    }

    bool enqueueFront(int v)
    {
        if (s.isEmpty())
        {
            s.push(v);
            return true;
        }

        int temp = s.pop();
        enqueueFront(v);
        s.push(temp);
        return true;
    }

    int dequeueFront()
    {
        if (s.isEmpty())
        {
            return INT_MAX;
        }
        if (s.getsize() == 1)
        {
            return s.pop();
        }
        int x, y;
        x = s.pop();
        y = dequeueFront();
        s.push(x);
        return y;
    }
    void print()
    {
        s.printlist();
    }

    void runwizard()
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
                enqueueFront(x) ? cout << x << " was enqueued at front successfully." << endl : cout << "Failed to enqueue " << x << endl;
                break;
            }
            case 2:
            {
                cout << "Enter value: ";
                cin >> y;
                enqueueRear(x) ? cout << x << " was enqueued at rear successfully." << endl : cout << "Failed to enqueue " << x << endl;
                break;
            }
            case 3:
            {
                y = dequeueFront();
                if (y != INT_MAX)
                {
                    cout << y << " was dequeued from front." << endl;
                }
                break;
            }
            case 4:
            {
                y = dequeueRear();
                if (y != INT_MAX)
                {
                    cout << y << " was dequeued from rear." << endl;
                }
                break;
            }
            case 5:
            {
                print();
                break;
            }
            case 0:
            {
                cout << "Closing Program ... BYE." << endl;
                exit(0);
                break;
            }
            default:
            {
                cout << "Invalid Option, try again." << endl;
                break;
            }
            }
        }
    }
};

int main()
{
    // code goes here
    Dequeue d;
    d.runwizard();
}
