// author: Amrit Pandey, 207907
// date: 31-05-2021

// Write a program to Implement a circular double linked list with the following operations
//     - bool insertBegin(int v)
//     - bool insertEnd(int v)
//     - bool insertAtPos(int v, int pos)
//     - bool insertAfterValue(int v, int sv)
//     - int find(int sv)           - returns the location of the node in the linked list with sv value.
//     - bool search(int sv)    - returns true if there is an node in the linked list with sv value.
//     - bool deleteByValue(int sv)
//     - int deleteBegin()
//     - int deleteEnd()
//     - int deleteAtPos(int pos)
//     - bool isEmpty()
//     - int size()
//     - void print()
// Use a menu in a loop, to call these operations.
// (Here, the data type of the objects is int)

#include <iostream>
using namespace std;

int menu()
{
    int res;
    cout << "0. Exit" << endl;
    cout << "1. Insert Begin" << endl;
    cout << "2. Insert End" << endl;
    cout << "3. Insert at Position" << endl;
    cout << "4. Insert after Value" << endl;
    cout << "5. Delete by Value" << endl;
    cout << "6. Delete Begin" << endl;
    cout << "7. Delete End" << endl;
    cout << "8. Delete at Position" << endl;
    cout << "9. Find" << endl;
    cout << "10. Search" << endl;
    cout << "11. Print" << endl;
    cout << "12. Size" << endl;
    cout << "\t YOUR CHOICE >>> ";
    cin >> res;
    return res;
}

struct ListNode
{
    int val;
    ListNode *next;
    ListNode *prev;
    ListNode(int val, ListNode *next = NULL, ListNode *prev = NULL)
    {
        this->val = val;
        this->next = next;
        this->prev = prev;
    }
};

class DCLL
{
private:
    ListNode *head;
    size_t size;

public:
    DCLL()
    {
        size = 0;
        head = NULL;
    }

    bool insertBegin(int);
    bool insertEnd(int);
    bool insertAtPos(size_t, int);
    bool insertAfterValue(int, int);
    int find(int);
    bool search(int);
    int deleteByVal(int);
    int deleteBegin();
    int deleteEnd();
    int deleteAtPos(int);
    bool isEmpty();
    size_t length();
    void print();
    void runwizard();

    ~DCLL()
    {
        if (size == 1)
        {
            delete head;
        }
        else if (size > 1)
        {
            ListNode *curr = head->next;
            while (curr->next != head)
            {
                curr = curr->next;
            }
            curr->next = nullptr;
            curr = head;
            while (curr)
            {
                ListNode *temp = curr;
                curr = curr->next;
                delete temp;
            }
            delete head;
        }
    }
};

size_t DCLL::length()
{
    return size;
}

bool DCLL::isEmpty()
{
    return size == 0 || head == nullptr;
}

bool DCLL::insertEnd(int v)
{
    if (head == NULL)
    {
        head = new ListNode(v);
        head->next = head;
    }
    else
    {
        ListNode *curr = head;
        while (curr->next != head)
        {
            curr = curr->next;
        }
        curr->next = new ListNode(v, head, curr);
    }
    size++;
    return true;
}

bool DCLL::insertBegin(int v)
{
    if (head == NULL)
    {
        head = new ListNode(v);
        head->next = head;
    }
    else
    {
        ListNode *newNode = new ListNode(v, head);
        ListNode *curr = head;
        while (curr->next != head)
        {
            curr = curr->next;
        }
        curr->next = newNode;
        head->prev = newNode;
        head = newNode;
    }
    size++;
    return true;
}

bool DCLL::insertAtPos(size_t index, int v)
{
    if (index <= 0 || index > size)
    {
        cout << "\tERROR: Invalid position" << endl;
        return false;
    }
    if (index == 1)
    {
        insertBegin(v);
    }
    else if (index == size)
    {
        insertEnd(v);
    }
    else
    {
        ListNode *prev = nullptr;
        ListNode *curr = head;
        for (int i = 1; i < index; i++)
        {
            prev = curr;
            curr = curr->next;
        }
        ListNode *newNode = new ListNode(v, curr, prev);
        prev->next = newNode;
        curr->prev = newNode;
        size++;
    }
    return true;
}

bool DCLL::insertAfterValue(int v, int sv)
{
    if (isEmpty())
    {
        cout << "\tCannot perform insert: List is empty." << endl;
        return false;
    }
    ListNode *curr = head->next;
    while (curr != head && curr->val != sv)
    {
        curr = curr->next;
    }
    if (curr->val != sv)
    {
        return false;
    }
    ListNode *newNode = new ListNode(v, curr->next, curr);
    curr->next = newNode;
    if (newNode->next != head)
    {
        newNode->next->prev = newNode;
    }
    return true;
}

int DCLL::find(int v)
{

    if (isEmpty())
    {
        cout << "\tCannot perform find: List is empty." << endl;
        return INT8_MIN;
    }
    ListNode *curr = head;
    int count{1};
    while (curr->val != v && curr->next != head)
    {
        curr = curr->next;
        count++;
    }
    if (curr->val != v)
    {
        return INT8_MIN;
    }
    return count;
}

bool DCLL::search(int v)
{

    if (isEmpty())
    {
        cout << "\tCannot perform search: List is empty." << endl;
        return false;
    }
    ListNode *curr = head;
    while (curr->val != v && curr->next != head)
        curr = curr->next;
    if (curr->val != v)
        return false;
    return true;
}

int DCLL::deleteByVal(int v)
{
    if (isEmpty())
    {
        cout << "\tCannot perform delete operation: List is empty." << endl;
        return INT8_MIN;
    }
    ListNode *curr = head->next;
    ListNode *prev = head;
    while (curr != head && curr->val != v)
    {
        prev = curr;
        curr = curr->next;
    }
    if (curr->val != v)
    {
        cout << "\tERROR: Cannot find element." << endl;
        return INT8_MIN;
    }
    ListNode *temp = curr;
    int delete_val = temp->val;
    if (prev->next != curr->next)
    {
        prev->next = curr->next;
        curr->next->prev = prev;
    }
    size--;
    if (temp == head && size > 0)
    {
        head = head->next;
        head->prev = nullptr;
    }
    if (size == 0)
        head = nullptr;
    delete temp;
    return delete_val;
}

int DCLL::deleteBegin()
{
    if (isEmpty())
    {
        cout << "\tCannot perform delete operation: List is empty." << endl;
        return INT8_MIN;
    }
    return deleteByVal(head->val);
}

int DCLL::deleteEnd()
{
    if (isEmpty())
    {
        cout << "\tCannot perform delete: List is empty." << endl;
        return INT8_MIN;
    }
    ListNode *curr = head->next;
    ListNode *prev = head;
    while (curr->next != head)
    {
        prev = curr;
        curr = curr->next;
    }
    ListNode *deletePtr = curr;
    int delete_val = curr->val;
    if (prev == curr)
    {
        head = NULL;
    }
    else
    {
        prev->next = curr->next;
    }
    size--;
    delete deletePtr;
    return delete_val;
}

int DCLL::deleteAtPos(int pos)
{
    if (isEmpty())
    {
        cout << "\tCannot perform delete: List is empty." << endl;
        return INT8_MIN;
    }
    ListNode *curr = head;
    int i;
    for (i = 1; i < pos && curr->next != head; i++, curr = curr->next)
        ;
    return i == pos ? deleteByVal(curr->val) : INT8_MIN;
}

void DCLL::print()
{
    if (isEmpty())
    {
        cout << "\tList is empty." << endl;
        return;
    }
    ListNode *curr = head;
    if (size == 1)
    {
        cout << curr->val;
    }
    else
    {
        while (curr->next != head)
        {
            cout << curr->val << " ";
            curr = curr->next;
        }
        cout << curr->val;
    }
    cout << endl;
}

void DCLL::runwizard()
{
    int x, y;
    size_t index;
    while (true)
    {
        switch (menu())
        {
        case 0:
        {
            exit(0);
            break;
        }
        case 1:
        {
            cout << "\tEnter value: ";
            cin >> x;
            insertBegin(x) ? cout << "\t" << x << " was inserted successfully." << endl : cout << "\tFailed to insert " << x << endl;
            break;
        }
        case 2:
        {
            cout << "\tEnter value: ";
            cin >> x;
            insertEnd(x) ? cout << "\t" << x << " was inserted successfully." << endl : cout << "\tFailed to insert " << x << endl;
            break;
        }
        case 3:
        {
            cout << "\tEnter position: ";
            cin >> index;
            cout << "\tEnter value: ";
            cin >> x;
            insertAtPos(index, x) ? cout << "\t" << x << " was inserted successfully at position " << index << endl : cout << "\tFailed to insert " << x << endl;
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
            cout << "\tEnter value: ";
            cin >> x;
            y = deleteByVal(x);
            y == x ? cout << "\t" << x << " was deleted sucessfully." << endl : cout << "\tFailed to delete " << x << endl;
            break;
        }
        case 6:
        {
            y = deleteBegin();
            y != INT8_MIN ? cout << "\t" << x << " was deleted successfully from beginning." << endl : cout << "\tFailed to delete." << endl;
            break;
        }
        case 7:
        {
            y = deleteEnd();
            y != INT8_MIN ? cout << "\t" << x << " was deleted successfully from end." << endl : cout << "\tFailed to delete." << endl;
            break;
        }
        case 8:
        {
            cout << "\tEnter position: ";
            cin >> x;
            y = deleteAtPos(x);
            y != INT8_MIN ? cout << "\t" << x << " was deleted successfully." << endl : cout << "\tFailed to delete." << endl;
            break;
        }
        case 9:
        {
            cout << "\tEnter value: ";
            cin >> x;
            y = find(x);
            y != INT8_MIN ? cout << "\t" << x << " is located at position " << y << " in the list." : cout << "\tFailed to find " << x << endl;
            break;
        }
        case 10:
        {
            cout << "\tEnter value: ";
            cin >> x;
            search(x) ? cout << "\t" << x << " was found in the list." << endl : cout << "\tCannot find " << x << " in the list." << endl;
            break;
        }
        case 11:
        {
            print();
            break;
        }
        case 12:
        {
            cout << "\tSize = " << length() << endl;
            break;
        }
        default:
            cout << "\tInvalid option, try again." << endl;
            break;
        }
    }
}

int main()
{
    DCLL ll;
    ll.runwizard();
}