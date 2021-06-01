// author: Amrit Pandey, 207907
// date: 31-05-2021
// Write a program to Implement a circular single linked list with the following operations

// bool insertBegin(int v)
// bool insertEnd(int v)
// bool insertAtPos(int v, int pos)
// bool insertAfterValue(int v, int sv)
// int find(int sv)           - returns the location of the node in the linked list with sv value.
// bool search(int sv)    - returns true if there is an node in the linked list with sv value.
// bool deleteByValue(int sv)
// int deleteBegin()
// int deleteEnd()
// int deleteAtPos(int pos)
// bool isEmpty()
// int size()
// void print()
// Use a menu in a loop, to call these operations.
// (Here, the data type of the objects is int)

#include <iostream>
using namespace std;

#define INT_MIN -2147483648

int menu()
{
    int res;
    cout << "1. Insert Beginning" << endl;
    cout << "2. Insert End" << endl;
    cout << "3. Insert at Position" << endl;
    cout << "4. Insert after Value" << endl;
    cout << "5. Find" << endl;
    cout << "6. Search" << endl;
    cout << "7. Delete by Value" << endl;
    cout << "8. Delete Begin" << endl;
    cout << "9. Delete End" << endl;
    cout << "10. Delete at Position" << endl;
    cout << "11. Is Empty?" << endl;
    cout << "12. Size" << endl;
    cout << "13. Print" << endl;
    cout << "0. Exit" << endl;
    cout << "\tYOUR CHOICE >>> ";
    cin >> res;
    return res;
}

struct ListNode
{
    int val;
    struct ListNode *next;
};

class CLL
{
private:
    struct ListNode *tail;
    int llsize;

public:
    CLL()
    {
        this->tail = NULL;
        this->llsize = 0;
    }

    bool insertBegin(int v);
    bool insertEnd(int v);
    bool insertAtPos(int v, int pos);
    bool insertAfterValue(int v, int sv);
    int find(int sv);
    bool search(int sv);
    bool deleteByValue(int sv);
    int deleteBegin();
    int deleteEnd();
    int deleteAtPos(int pos);
    bool isEmpty();
    int size();
    void print();
    void runwizard();

    ~CLL()
    {
        delete this->tail;
    }
};

bool CLL::isEmpty()
{
    return llsize == 0;
}

int CLL::size()
{
    return llsize;
}

void CLL::print()
{
    if (!tail)
    {
        return;
    }

    struct ListNode *tmp;
    tmp = tail->next;

    while (tmp != tail)
    {
        cout << tmp->val << " ";
        tmp = tmp->next;
    }
    cout << tmp->val << endl;
}

int CLL::find(int sv)
{
    if (!tail)
    {
        return INT_MIN;
    }
    if (llsize == 1 && tail->val == sv)
    {
        return 0;
    }
    struct ListNode *tmp;
    int i;
    tmp = tail->next;
    i = 0;
    while (tmp->val != sv)
    {
        ++i;
    }
    return i;
}

bool CLL::search(int sv)
{
    return find(sv) != INT_MIN;
}

bool CLL::insertAtPos(int v, int pos)
{
    if (!isEmpty() && pos >= size())
    {
        cout << "\tERROR: Invalid Position." << endl;
        return false;
    }
    struct ListNode *tmp, *ptr;
    tmp = new struct ListNode;
    tmp->val = v;
    if (pos == 0)
    {
        if (isEmpty())
        {
            tmp->next = tmp;
            tail = tmp;
            ++llsize;
            return true;
        }
        tmp->next = tail->next;
        tail->next = tmp;
        ++llsize;
        return true;
    }
    int i;
    i = 0;
    ptr = tail->next;
    while (i != pos)
    {
        ptr = ptr->next;
        ++i;
    }
    tmp->next = ptr->next;
    ptr->next = tmp;
    ++llsize;
    return true;
}

int CLL::deleteAtPos(int pos)
{
    if (pos >= size())
    {
        cout << "\tERROR: Invalid Position." << endl;
        return INT_MIN;
    }
    if (isEmpty())
    {
        cout << "\tERROR: Underflow occured." << endl;
        return INT_MIN;
    }
    struct ListNode *ptr, *s;
    int i, tmp;
    ptr = tail->next;
    if (pos == 0)
    {
        if (size() > 1)
        {
            tail->next = ptr->next;
            tmp = ptr->val;
            delete ptr;
            --llsize;
            return tmp;
        }
        tmp = tail->val;
        delete ptr;
        tail = NULL;
        --llsize;
        return tmp;
    }
    i = 0;
    while (i != pos - 1)
    {
        ptr = ptr->next;
        ++i;
    }
    s = ptr->next;
    ptr->next = s->next;
    tmp = s->val;
    delete s;
    --llsize;
    return tmp;
}

bool CLL::insertBegin(int v)
{
    return insertAtPos(v, 0);
}

bool CLL::insertEnd(int v)
{
    return insertAtPos(v, size() - 1);
}

bool CLL::insertAfterValue(int v, int sv)
{
    int index = find(sv);
    if (index == INT_MIN)
    {
        cout << "\t ERROR: Value not found." << endl;
        return false;
    }
    return insertAtPos(v, index + 1);
}

int CLL::deleteBegin()
{
    return deleteAtPos(0);
}

int CLL::deleteEnd()
{
    return deleteAtPos(size() - 1);
}

bool CLL::deleteByValue(int sv)
{
    int index = find(sv);
    if (index == INT_MIN)
    {
        cout << "\t ERROR: Value not found." << endl;
        return false;
    }
    return deleteAtPos(index) != INT_MIN;
}

void CLL::runwizard()
{
    int x, y;

    while (true)
    {
        switch (menu())
        {
        case 0:
        {
            cout << "\tExiting Program ... Bye." << endl;
            exit(0);
        }
        case 1:
        {
            cout << "\tEnter value: ";
            cin >> x;
            insertBegin(x) ? cout << "\t" << x << " was successfully inserted at beginning." << endl : cout << "\tFailed to insert " << x << endl;
            break;
        }
        case 2:
        {
            cout << "\tEnter value: ";
            cin >> x;
            insertEnd(x) ? cout << "\t" << x << " was successfully inserted at the end." << endl : cout << "\tFailed to insert " << x << endl;
            break;
        }
        case 3:
        {
            cout << "\tEnter value: ";
            cin >> x;
            cout << "\tEnter position: ";
            cin >> y;
            insertAtPos(x, y) ? cout << "\t" << x << " was successfully inserted at position " << y << endl : cout << "\tFailed to insert " << x << endl;
            break;
        }
        case 4:
        {
            cout << "\tEnter value: ";
            cin >> x;
            cout << "\tEnter search value: ";
            cin >> y;
            insertAfterValue(x, y) ? cout << "\t" << x << " was successfully inserted after " << y << endl : cout << "\tFailed to insert " << x << endl;
            break;
        }
        case 5:
        {
            cout << "\tEnter value to find: ";
            cin >> x;
            y = find(x);
            if (y != INT_MIN)
            {
                cout << "\t" << x << " is located at " << y << " position in the list." << endl;
            }
            break;
        }
        case 6:
        {
            cout << "\tEnter value to search: ";
            cin >> x;
            search(x) ? cout << "\t" << x << " was found in the list." << endl : cout << x << " was not found in the list." << endl;
            break;
        }
        case 7:
        {
            cout << "\tEnter value to delete: ";
            cin >> x;
            deleteByValue(x) ? cout << "\t" << x << " was successfully deleted from the list." << endl : cout << "\tFailed to delete " << x << endl;
            break;
        }
        case 8:
        {
            x = deleteBegin();
            if (x != INT_MIN)
            {
                cout << "\t" << x << " was successfully deleted from list" << endl;
            }
            break;
        }
        case 9:
        {
            x = deleteEnd();
            if (x != INT_MIN)
            {
                cout << "\t" << x << " was successfully deleted from list" << endl;
            }
            break;
        }
        case 10:
        {
            cout << "\tEnter postion: ";
            cin >> y;
            x = deleteAtPos(y);
            if (x != INT_MIN)
            {
                cout << "\t" << x << " was successfully deleted from list" << endl;
            }
            break;
        }
        case 11:
        {
            isEmpty() ? cout << "\t"
                             << "List is empty." << endl
                      : cout << "\tList is not empty." << endl;
            break;
        }
        case 12:
        {
            cout << "\tSize = " << size() << endl;
            break;
        }
        case 13:
        {
            print();
            break;
        }
        default:
        {
            cout << "\tInvalid choice, try again." << endl;
            break;
        }
        }
    }
}

int main()
{
    CLL ll;
    ll.runwizard();
}
