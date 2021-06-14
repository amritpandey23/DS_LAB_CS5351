// author: Amrit Pandey, 207907
// date: 07-06-2021
// DS MID LAB EXAM, Question 2

#include <iostream>
using namespace std;


struct ListNode
{
    int val;
    struct ListNode *next;
};

struct ListNode *reverseList(struct ListNode *head)
{
    struct ListNode *prev, *cur, *ptr;
    prev = NULL;
    cur = head;

    while (cur)
    {
        ptr = cur->next;
        cur->next = prev;
        prev = cur;
        cur = ptr;
    }
    return prev;
}

class LinkedList
{
private:
    struct ListNode *head;
    size_t size;

public:
    LinkedList()
    {
        this->head = NULL;
        this->size = 0;
    }
    size_t getsize();
    bool append(int);
    void print();
    void reverseSection(int, int);
    void reverseBlockIter(int);
    void run();
};

size_t LinkedList::getsize()
{
    return size;
}

bool LinkedList::append(int v)
{
    struct ListNode *newNode, *ptr;
    newNode = new struct ListNode;
    newNode->val = v;
    newNode->next = NULL;
    if (getsize() == 0)
    {
        head = newNode;
        size++;
        return true;
    }
    ptr = head;
    while (ptr->next != NULL)
    {
        ptr = ptr->next;
    }
    ptr->next = newNode;
    size++;
    return true;
}

void LinkedList::print()
{
    if (getsize() == 0)
    {
        cout << "List is empty." << endl;
        return;
    }
    struct ListNode *ptr = head;
    while (ptr->next != NULL)
    {
        cout << ptr->val << "->";
        ptr = ptr->next;
    }
    cout << ptr->val << endl;
}

void LinkedList::reverseSection(int start, int end)
{
    if (start == end)
    {
        return;
    }

    ListNode *revs, *revsPrev, *revend, *revendNext, *ptr;
    revs = revsPrev = revend = revendNext = NULL;
    int i;

    i = 1;
    ptr = head;
    while (ptr && i <= end)
    {
        if (i < start)
        {
            revsPrev = ptr;
        }
        if (i == start)
        {
            revs = ptr;
        }
        if (i == end)
        {
            revend = ptr;
            revendNext = ptr->next;
        }
        ptr = ptr->next;
        i++;
    }
    revend->next = NULL;
    revend = reverseList(revs);
    if (revsPrev)
    {
        revsPrev->next = revend;
    }
    else
    {
        head = revend;
    }
    revs->next = revendNext;
}

void LinkedList::reverseBlockIter(int n)
{
    int start, end;
    start = 1;
    end = n;
    while (end <= getsize())
    {
        reverseSection(start, end);
        start += n;
        end += n;
    }
}

void LinkedList::run()
{
    int n, k, x;
    char c;
    cout << "Enter n: ";
    cin >> n;
    cout << "Do you want to autofill linkedlist? (y/n): ";
    cin >> c;
    if (c == 'y')
    {
        for (int i = 1; i <= n; i++)
        {
            append(i);
        }
    }
    else
    {
        for (int i = 0; i < n; i++)
        {
            cout << "Enter value(" << (i + 1) << "): ";
            cin >> x;
            append(x);
        }
    }
    cout << "Enter k: ";
    cin >> k;
    cout << "ORIGINAL LIST: ";
    print();
    reverseBlockIter(k);
    cout << "FINAL LIST: ";
    print();
}

int main()
{
    LinkedList l;
    l.run();
    return 0;
}
