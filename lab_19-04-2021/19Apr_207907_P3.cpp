// author: Amrit Pandey, 207907
// date: 19-04-2021

#include <iostream>
using namespace std;

#define MAX 1000

int menu()
{
    int ch;
    cout << endl
         << "Choose one option" << endl;
    cout << "1. enter new name" << endl;
    cout << "2. delete last name" << endl;
    cout << "3. see last name" << endl;
    cout << "4. size of stack" << endl;
    cout << "5. is stack empty?" << endl;
    cout << "6. is stack full?" << endl;
    cout << "7. exit" << endl;
    cout << "enter choice: ";
    cin >> ch;
    return ch;
}

class Stack
{
private:
    int size;
    int top{-1};
    string a[MAX];

public:
    Stack() : size{MAX}, top{-1} {}
    Stack(int n) : size{n}, top{-1} {}

    bool push(string);
    string pop();
    string peek();
    int getSize();
    bool isEmpty();
    bool isFull();
};

bool Stack::push(string ele)
{
    if (!isFull())
    {
        a[++top] = ele;
        return true;
    }
    cout << "overflow." << endl;
    return false;
}

string Stack::pop()
{
    if (!isEmpty())
    {
        string x = a[top];
        top--;
        return x;
    }

    cout << "stack empty." << endl;
    return "NULL";
}

string Stack::peek()
{
    if (top == -1 || top >= size)
    {
        cout << "stack empty." << endl;
        return "NULL";
    }
    return a[top];
}

int Stack::getSize()
{
    return size;
}

bool Stack::isEmpty()
{
    return (top == -1);
}

bool Stack::isFull()
{
    return (size - 1 == top);
}

int main()
{
    int n;
    cout << "Enter total number of students : ";
    cin >> n;
    Stack st(n);

    while (1)
    {
        switch (menu())
        {
        case 1:
        {
            cin.ignore();
            string name;
            cout << "Enter name: ";
            getline(cin, name);
            st.push(name);
            break;
        }

        case 2:
        {
            st.pop();
            break;
        }

        case 3:
        {
            cout << "Last entered name = " << st.peek() << endl;
            break;
        }

        case 4:
        {
            cout << "Current number of names = " << st.getSize() << endl;
            break;
        }

        case 5:
        {
            st.isEmpty() ? cout << "No names in the stack." << endl : cout << "Stack is not empty." << endl;
            break;
        }

        case 6:
        {
            st.isFull() ? cout << "Yes, stack is full." << endl : cout << "No, stack is not full." << endl;
            break;
        }

        case 7:
        {
            exit(0);
        }

        default:
        {
            cout << "Invalid Choice, try again." << endl;
            break;
        }
        }
    }
    return 0;
}