// author: Amrit Pandey, 207907
// date: 19-04-2021

#include <iostream>
using namespace std;

#define STACK_MAX 1000

int menu()
{
    int x;
    cout << "Enter your choice." << endl;
    cout << "1. add item" << endl;
    cout << "2. pop" << endl;
    cout << "3. see last entered item" << endl;
    cout << "4. is the stack empty?" << endl;
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

void Stack::run()
{
    int tmp;
    while (1)
    {
        if (top != -1)
        {
            cout << "STACK: ";
            printlist();
        }
        switch (menu())
        {
        case 0:
            exit(0);
        case 1:
            cout << "Enter element: ";
            cin >> tmp;
            push(tmp);
            break;
        case 2:
            pop();
            break;
        case 3:
            cout << "Last entered item = " << peek() << endl;
            break;
        case 4:
            isEmpty() ? cout << "YES" << endl : cout << "NO" << endl;
            break;
        default:
            cout << "Invalid choice, try again." << endl;
            break;
        }
    }
}

int main()
{
    Stack s;
    s.run();
    return 0;
}
