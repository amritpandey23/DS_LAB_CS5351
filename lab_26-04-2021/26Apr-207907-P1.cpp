// author: Amrit Pandey, 207907
// date: 26-04-2021
// given a postfix expression, evaluate it using stack.
// supported operators: * - + / %

#include <iostream>
using namespace std;

#define STACK_MAX 1000

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

bool postfixValidChecker(string str) // postfix expression validator
{
    
    // 1. Initialize the counter to 0.
    // 1.1 If found a space, return false.
    // 2. When you see a literal, increment the counter.
    // 3. When you see a binary operator, decrement the counter twice, then increment it.
    // 4. At the end of the string, if the counter is 1, and if it never went below 0, the string is valid.

    int ctr, i;
    i = ctr = 0;
    while (str[i] != '\0')
    {
        if (str[i] == ' ')
        {
            cout << "ERROR: found space at index " << i << endl;
            return false;
        }
        if (str[i] >= 48 && str[i] <= 57)
        {
            ctr++;
        }
        if (str[i] == '*' ||
            str[i] == '+' ||
            str[i] == '-' ||
            str[i] == '%' ||
            str[i] == '/')
        {
            ctr -= 2;
            if (ctr < 0)
            {
                return false;
            }
            ctr++;
        }
        i++;
    }
    return ctr == 1 ? true : false;
}

int evaluate(string str)
{
    if (!postfixValidChecker(str))
    {
        cout << "ERROR: invalid expression" << endl;
        return -1;
    }
    Stack s;
    int i, x, y, z;
    i = 0;
    while (str[i] != '\0')
    {
        if (str[i] >= 48 && str[i] <= 57)
        {
            s.push(str[i] - 48);
            i++;
            continue;
        }
        if (str[i] == '*' ||
            str[i] == '+' ||
            str[i] == '-' ||
            str[i] == '%' ||
            str[i] == '/')
        {
            switch (str[i])
            {
            case '*':
            {
                x = s.pop();
                y = s.pop();
                z = x * y;
                s.push(z);
                break;
            }
            case '+':
            {
                x = s.pop();
                y = s.pop();
                z = x + y;
                s.push(z);
                break;
            }
            case '-':
            {
                x = s.pop();
                y = s.pop();
                z = y - x;
                s.push(z);
                break;
            }
            case '%':
            {
                x = s.pop();
                y = s.pop();
                z = y % x;
                s.push(z);
                break;
            }
            case '/':
            {
                x = s.pop();
                y = s.pop();
                z = y / x;
                s.push(z);
                break;
            }
            }
            i++;
        }
    }
    return s.pop();
}

int main()
{
    /*
    test case                   output
    12+34*+                     15
    473/*4-92/+                 8
    */

    string tc;
    getline(cin, tc);
    cout << "result = " << evaluate(tc) << endl;
    // cout << tc;
    return 0;
}
