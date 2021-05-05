// author: Amrit Pandey, 207907
// date: 03-05-2021
// Write a program to Implement a single linked list with the following operation

// bool insertBegin(int v)
// bool insertEnd(int v)
// bool insertAtPos(int v, int pos)
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

int menu()
{
    int res;
    cout << endl << "Choose one." << endl;
    cout << "1. insert at beginning" << endl;
    cout << "2. insert at end" << endl;
    cout << "3. insert at pos" << endl;
    cout << "4. delete beginning" << endl;
    cout << "5. delete end" << endl;
    cout << "6. delete at pos" << endl;
    cout << "7. is empty?" << endl;
    cout << "8. size" << endl;
    cout << "9. print" << endl;
    cout << "0. exit" << endl;
    cout << "YOUR CHOICE >>> ";
    cin >> res;
    return res;
}

struct ListNode
{
    int val;
    struct ListNode *next;
};

class LinkedList
{
private:
    ListNode *head;
    int size;

public:
    LinkedList()
    {
        head = NULL;
        size = 0;
    }
    bool insertBegin(int);
    bool insertEnd(int);
    bool insertAtPos(int, int);
    int deleteBegin();
    int deleteEnd();
    int deleteAtPos(int);
    bool isEmpty();
    int getsize();
    void print();
    void run();
};

bool LinkedList::insertBegin(int v)
{
    if (head == NULL)
    {
        struct ListNode *e = new struct ListNode;
        e->val = v;
        e->next = NULL;
        head = e;
        size++;
        return true;
    }
    struct ListNode *ptr = new struct ListNode;
    ptr->val = v;
    ptr->next = head;
    head = ptr;
    size++;
    return true;
}

bool LinkedList::insertEnd(int v)
{
    if (head == NULL)
    {
        struct ListNode *e = new struct ListNode;
        e->val = v;
        e->next = NULL;
        head = e;
        size++;
        return true;
    }
    struct ListNode *s = head;
    struct ListNode *ptr = new struct ListNode;
    ptr->val = v;
    ptr->next = NULL;
    while (s->next)
    {
        s = s->next;
    }
    s->next = ptr;
    size++;
    return true;
}

int LinkedList::getsize()
{
    return size;
}

bool LinkedList::insertAtPos(int v, int pos)
{
    struct ListNode *ptr = new struct ListNode;
    ptr->val = v;
    if (!getsize() && pos == 0)
    {
        ptr->next = NULL;
        head = ptr;
        size++;
        return true;
    }

    if (pos >= size - 1)
    {
        cout << "Invalid position." << endl;
        return false;
    }

    if (pos == 0)
    {
        ptr->next = head;
        head = ptr;
        size++;
        return true;
    }
    struct ListNode *s = head;
    for (int i = 0; i != pos - 1; i++)
    {
        s = s->next;
    }
    ptr->next = s->next;
    s->next = ptr;
    size++;
    return true;
}

int LinkedList::deleteBegin()
{
    if (!getsize())
    {
        cout << "LIST empty." << endl;
        return -1;
    }
    struct ListNode *s = head;
    head = head->next;
    int res = s->val;
    delete s;
    size--;
    return res;
}

int LinkedList::deleteEnd()
{
    if (isEmpty())
    {
        cout << "List is empty. Underflow." << endl;
        return -1;
    }
    if (head->next == NULL)
    {
        int res = head->val;
        delete head;
        head = NULL;
        size--;
        return res;
    }
    struct ListNode *s = head;
    while (s->next->next)
    {
        s = s->next;
    }
    int res = s->next->val;
    delete s->next;
    size--;
    return res;
}

int LinkedList::deleteAtPos(int pos)
{
    if (isEmpty())
    {
        cout << "Underflow occured. List is empty." << endl;
        return -1;
    }
    if (pos >= getsize() - 1)
    {
        cout << "Invalid postion." << endl;
        return -1;
    }
    struct ListNode *s, *p;
    int start, res;
    s = head;
    if (pos == 0)
    {
        res = s->val;
        delete s;
        head = NULL;
        size--;
        return res;
    }
    start = 0;
    while (start != pos - 1)
    {
        s = s->next;
    }
    p = s->next;
    s->next = p->next;
    res = p->val;
    delete p;
    size--;
    return res;
}

bool LinkedList::isEmpty()
{
    return head == NULL;
}

void LinkedList::print()
{
    struct ListNode *s = head;
    if (isEmpty())
    {
        cout << "List is empty." << endl;
        return;
    }
    cout << "LIST: ";
    while (s)
    {
        cout << s->val << " ";
        s = s->next;
    }
    cout << endl;
}

void LinkedList::run()
{
    int res, pos, tmp;
    while (true)
    {
        switch (menu())
        {
        case 1:
        {
            cout << "Enter val: ";
            cin >> tmp;
            insertBegin(tmp) ? cout << "Successfully entered item" : cout << "Entering item failed.";
            cout << endl;
            break;
        }
        case 2:
        {
            cout << "Enter val: ";
            cin >> tmp;
            insertEnd(tmp) ? cout << "Successfully entered item" : cout << "Entering item failed.";
            cout << endl;
            break;
        }
        case 3:
        {
            cout << "insert val, pos: ";
            cin >> tmp >> pos;
            insertAtPos(tmp, pos) ? cout << "Successfully entered item" : cout << "Entering item failed.";
            cout << endl;
            break;
        }
        case 4:
        {
            res = deleteBegin();
            if (res == -1)
            {
                cout << "Delete failed." << endl;
                break;
            }
            cout << "deleted item was " << res << endl;
            break;
        }
        case 5:
        {
            res = deleteEnd();
            if (res == -1)
            {
                cout << "Delete failed" << endl;
                break;
            }
            cout << "deleted item was " << res << endl;
            break;
        }
        case 6:
        {
            cout << "Enter position: ";
            cin >> pos;
            res = deleteAtPos(pos);
            if (res == -1)
            {
                cout << "delete failed." << endl;
                break;
            }
            cout << "delete item was " << res << endl;
            break;
        }
        case 7:
        {
            isEmpty() ? cout << "LIST is empty." : cout << "LIST is not empty.";
            cout << endl;
            break;
        }
        case 8:
        {
            cout << "Size of list = " << getsize() << endl;
            break;
        }
        case 9:
        {
            print();
            break;
        }
        case 0:
        {
            exit(0);
            break;
        }
        }
    }
}

int main()
{
    // code goes here
    LinkedList ll;
    ll.run();
}
