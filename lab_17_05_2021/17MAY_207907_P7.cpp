// author: Amrit Pandey, 207907
// date: 17-05-2021
// Write a program to Implement a double linked list with the following operations

// bool insertBegin(int v)
// bool insertEnd(int v)
// bool insertAtPos(int v, int pos)
// bool insertAfterValue(int v, int sv)
// int find(int sv)           - returns the location of the node in the linked list with sv value.
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
    cout << "1. Insert at beginning" << endl;
    cout << "2. Insert at end" << endl;
    cout << "3. Insert at Position" << endl;
    cout << "4. Insert after value" << endl;
    cout << "5. Find" << endl;
    cout << "6. Delete by value" << endl;
    cout << "7. Delete Begin" << endl;
    cout << "8. Delete End" << endl;
    cout << "9. Delete at Position" << endl;
    cout << "10. Print" << endl;
    cout << "0. Exit" << endl;
    cout << "YOUR CHOICE >> ";
    cin >> res;
    return res;
}

struct ListNode
{
    int val;
    struct ListNode *next;
    struct ListNode *prev;
};

class DLL
{
private:
    struct ListNode *head;
    struct ListNode *tail;
    int lsize;

public:
    DLL()
    {
        head = tail = NULL;
        lsize = 0;
    }
    bool insertBegin(int);
    bool insertEnd(int);
    bool insertAtPos(int, int);
    bool insertAfterValue(int, int);
    int find(int);
    bool deleteByValue(int);
    int deleteBegin();
    int deleteEnd();
    int deleteAtPos(int);
    bool isEmpty();
    int size();
    void print();
    int getTail();
    int getHead();
    void runwizard();
};

int DLL::getTail()
{
    return tail != NULL ? tail->val : INT_MIN;
}

int DLL::getHead()
{
    return head != NULL ? head->val : INT_MIN;
}

int DLL::size()
{
    return lsize;
}

bool DLL::isEmpty()
{
    return head == NULL;
}

bool DLL::insertBegin(int v)
{
    struct ListNode *ptr = new struct ListNode;
    ptr->val = v;
    if (isEmpty())
    {
        ptr->next = NULL;
        ptr->prev = NULL;
        head = tail = ptr;
        ++lsize;
        return true;
    }
    ptr->prev = NULL;
    head->prev = ptr;
    ptr->next = head;
    head = ptr;
    ++lsize;
    return true;
}

bool DLL::insertEnd(int v)
{
    struct ListNode *ptr = new struct ListNode;
    ptr->val = v;
    if (isEmpty())
    {
        ptr->next = NULL;
        ptr->prev = NULL;
        head = tail = ptr;
        ++lsize;
        return true;
    }
    ptr->next = NULL;
    ptr->prev = tail;
    tail->next = ptr;
    tail = ptr;
    ++lsize;
    return true;
}

bool DLL::insertAfterValue(int v, int sv)
{
    if (isEmpty())
    {
        cout << "\t\t" << "List is empty." << endl;
        return false;
    }
    int pos, i;
    struct ListNode *ptr, *newNode;
    pos = find(sv);
    if (pos == size() - 1)
    {
        return insertEnd(v);
    }
    return insertAtPos(v, pos + 1);
}

bool DLL::insertAtPos(int v, int pos)
{
    int i;
    i = 0;
    if (isEmpty())
    {
        cout << "\t\tList is empty, cannot insert." << endl;
        return false;
    }
    if (pos >= size())
    {
        cout << "\t\tInvalid position." << endl;
        return false;
    }
    struct ListNode *ptr, *newNode;
    ptr = head;
    newNode = new struct ListNode;
    newNode->val = v;
    if (pos == 0)
    {
        newNode->prev = NULL;
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
        ++lsize;
        return true;
    }
    while (i != pos)
    {
        ptr = ptr->next;
        ++i;
    }
    newNode->prev = ptr->prev;
    newNode->next = ptr;
    ptr->prev->next = newNode;
    ptr->prev = newNode;
    ++lsize;
    return true;
}

int DLL::deleteBegin()
{
    if (isEmpty())
    {
        cout << "\t\t" << "List is empty. Underflow." << endl;
        return -1;
    }
    int res;
    if (size() == 1)
    {
        res = head->val;
        delete head;
        head = NULL;
        tail = NULL;
        --lsize;
        return res;
    }
    struct ListNode *ptr = head;
    head = head->next;
    head->prev = NULL;
    res = ptr->val;
    delete ptr;
    --lsize;
    return res;
}

int DLL::deleteAtPos(int pos)
{
    if (isEmpty())
    {
        cout << "\t\t" << "List is empty." << endl;
        return -1;
    }
    if (pos >= size())
    {
        cout << "\t\t" << "Invalid postion." << endl;
        return -1;
    }
    int i, res;
    struct ListNode *ptr;
    ptr = head;
    i = 0;
    if (pos == 0)
    {
        head = head->next;
        head->prev = NULL;
        res = ptr->val;
        delete ptr;
        --lsize;
        return res;
    }
    else if (pos == size() - 1)
    {
        ptr = tail;
        tail = tail->prev;
        tail->next = NULL;
        res = ptr->val;
        delete ptr;
        --lsize;
        return res;
    }
    while (i != pos)
    {
        ptr = ptr->next;
        ++i;
    }
    ptr->prev->next = ptr->next;
    ptr->next->prev = ptr->prev;
    res = ptr->val;
    --lsize;
    return res;
}

int DLL::deleteEnd()
{
    if (isEmpty())
    {
        cout << "\t\t" << "List is empty." << endl;
        return -1;
    }
    int res;
    if (size() == 1)
    {
        res = head->val;
        delete head;
        head = tail = NULL;
        --lsize;
        return res;
    }
    struct ListNode *ptr;
    ptr = tail;
    tail = tail->prev;
    tail->next = NULL;
    res = ptr->val;
    delete ptr;
    --lsize;
    return res;
}

bool DLL::deleteByValue(int sv)
{
    int pos, i;
    struct ListNode *ptr;
    pos = find(sv);
    if (pos == INT_MIN)
    {
        cout << "\t\t" << "ERROR: Search value was not found." << endl;
        return false;
    }
    return deleteAtPos(pos);
}

int DLL::find(int sv)
{
    int i;
    struct ListNode *ptr;
    ptr = head;
    i = 0;
    while (ptr)
    {
        if (ptr->val == sv)
        {
            return i;
        }
        ptr = ptr->next;
        ++i;
    }
    return INT_MIN;
}

void DLL::print()
{
    if (isEmpty())
    {
        cout << "\t\t" << "List is empty." << endl;
        return;
    }
    struct ListNode *ptr = head;
    cout << "\t\t" << "HEAD -> ";
    while (ptr)
    {
        cout << ptr->val << " ";
        ptr = ptr->next;
    }
    cout << "<- TAIL";
    cout << endl;
}

void DLL::runwizard()
{
    while (true)
    {
        // system("cls");
        print();
        cout << "HEAD: " << getHead() << endl;
        cout << "TAIL: " << getTail() << endl;
        cout << "SIZE: " << size() << endl;
        int x, y;
        switch (menu())
        {
        case 1:
        {
            cout << "\t\tEnter value: ";
            cin >> x;
            insertBegin(x);
            break;
        }
        case 2:
        {
            cout << "\t\tEnter value: ";
            cin >> x;
            insertEnd(x);
            break;
        }
        case 3:
        {
            cout << "\t\tEnter val, pos: ";
            cin >> x >> y;
            insertAtPos(x, y);
            break;
        }
        case 4:
        {
            cout << "\t\tEnter value, search value: ";
            cin >> x >> y;
            insertAfterValue(x, y) ? cout << "\t\t" << x << " was successfully entered after " << y << endl : cout << "\t\t" << "insertion failed." << endl;
            break;
        }
        case 5:
        {
            cout << "\t\tEnter search value: ";
            cin >> x;
            y = find(x);
            if (y != INT_MIN)
            {
                cout << "\t\t" << x << " is located at position " << y << "." << endl;
            }
            else
            {
                cout << "\t\t" << x << " was not found." << endl;
            }
            break;
        }
        case 6:
        {
            cout << "\t\tEnter value: ";
            cin >> x;
            deleteByValue(x) ? cout << "\t\t" << x << " was successfully deleted." << endl : cout << "\t\t" << "deletion failed." << endl;
            break;
        }
        case 7:
        {
            x = deleteBegin();
            if (x != -1)
            {
                cout << "\t\t" << x << " was deleted from beginning." << endl;
            }
            break;
        }
        case 8:
        {
            x = deleteEnd();
            if (x != -1)
            {
                cout << "\t\t" << x << " was deleted from end." << endl;
            }
            break;
        }
        case 9:
        {
            cout << "\t\tEnter postion: ";
            cin >> x;
            x = deleteAtPos(x);
            if (x != -1)
            {
                cout << "\t\t" << x << " was delete successfully." << endl;
            }
            break;
        }
        case 10:
        {
            print();
            break;
        }
        case 0:
        {
            cout << "\t\tExiting program" << endl;
            exit(0);
            break;
        }
        default:
        {
            cout << "\t\tInvalid choice, try again." << endl;
            break;
        }
        }
    }
}

int main()
{
    // code goes here
    DLL d;
    d.runwizard();
    // d.insertBegin(23);
    // d.insertBegin(3);
    // d.insertEnd(60);
    // d.insertBegin(45);
    // d.insertAtPos(45, 2);
    // d.deleteEnd();
    // d.deleteEnd();
}
