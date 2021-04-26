// author: Amrit Pandey, 207907
// date: 26-04-2021
// given an infix expression, convert it into postfix expression

#include <iostream>
using namespace std;
#define STACK_MAX 1000

class Stack
{
private:
    int top;

public:
    char a[STACK_MAX];
    Stack()
    {
        top = -1;
    }
    int gettopval();
    bool push(char x);
    char pop();
    char peek();
    bool isEmpty();
    void run();
    void printlist();
};

int Stack::gettopval()
{
    return top;
}

bool Stack::push(char x)
{
    if (top >= (STACK_MAX - 1))
    {
        cout << "overflow" << endl;
        return false;
    }
    a[++top] = x;
    return true;
}

char Stack::pop()
{
    if (top < 0)
    {
        cout << "stack empty." << endl;
        return 0;
    }
    char x = a[top--];
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

char Stack::peek()
{
    if (isEmpty())
    {
        cout << "Stack is empty." << endl;
        return '\0';
    }
    return a[top];
}

int getPrecedenceOperator(char c)
{
    int res = -1;
    switch (c)
    {
    case '^':
        res = 2;
        break;
    case '*':
    case '/':
    case '%':
        res = 1;
        break;
    case '+':
    case '-':
        res = 0;
        break;
    }
    return res;
}

bool isOperator(char t)
{
    return (t == '+' || t == '-' || t == '*' || t == '/' || t == '%' || t == '^');
}

string *tokenize(string str)
{
    int i, z;
    i = z = 0;
    string *tokens = new string[str.length()];
    string tmp = "";
    char t;
    while ((t = str[i]) != '\0')
    {
        if (t == ' ' || t == '\t')
        {
            tokens[z++] = tmp;
            tmp = "";
            i += 2;
            continue;
        }
        else
        {
            tmp += t;
            i++;
        }
    }
    return tokens;
}

string infixToPostfix(string str)
{
    Stack s;
    string res;
    int i;
    char t;
    i = 0;
    res = "";
    while ((t = str[i]) != '\0')
    {
        if (t == '(' || t == '[' || t == '{')
        {
            s.push(t);
        }
        else if (t == ')' || t == ']' || t == '}')
        {
            if (t == ')')
            {
                while (s.peek() != '(')
                {
                    res += s.pop();
                }
            }
            if (t == ']')
            {
                while (s.peek() != '[')
                {
                    res += s.pop();
                }
            }
            if (t == '}')
            {
                while (s.peek() != '{')
                {
                    res += s.pop();
                }
            }
            s.pop();
        }
        else if (isOperator(t))
        {
            if (s.isEmpty())
            {
                s.push(t);
            }
            else
            {
                if (getPrecedenceOperator(s.peek()) >= getPrecedenceOperator(t))
                {
                    res += s.pop();
                    s.push(t);
                }
                else
                {
                    s.push(t);
                }
            }
        }
        else
        {
            res += t;
        }
        i++;
    }

    if (!s.isEmpty())
    {
        while (!s.isEmpty())
        {
            res += s.pop();
        }
    }
    return res;
}

int main()
{
    // code goes here
    cout << infixToPostfix("1+2*3/9-6") << endl;
    cout << infixToPostfix("(9+8)*5^4/4") << endl;
    // string *tokens = tokenize("1 + 2 * 3 / 9 - 6");
    // for (int i = 0; i < 18; i++)
    // {                                                            -- effort to solve spaced expression failed.
    //     cout << tokens[i] << endl;
    // }
}
