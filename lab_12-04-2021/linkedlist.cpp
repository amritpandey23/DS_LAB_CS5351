#include <iostream>
using namespace std;

struct Node
{
    int item;
    Node *next;
};

class LinkedList
{
private:
    struct Node *head;

public:
    LinkedList()
    {
        head = NULL;
    }

    void append(int item)
    {
        if (head == NULL)
        {
            this->head = new struct Node;
            head->item = item;
            head->next = NULL;
            return;
        }
        struct Node *s;
        s = head;
        while (s->next != NULL)
        {
            s = s->next;
        }
        struct Node *ele = new struct Node;
        ele->item = item;
        ele->next = NULL;
        s->next = ele;
    }

    void prepend(int item)
    {
        if (head == NULL)
        {
            this->head = new struct Node;
            head->item = item;
            head->next = NULL;
            return;
        }
        struct Node *ele = new struct Node;
        ele->item = item;
        ele->next = head;
        head = ele;
    }

    void printlist()
    {
        struct Node *s;
        s = head;
        while (s != NULL)
        {
            cout << s->item << " ";
            s = s->next;
        }
        cout << endl;
    }

    int pop()
    {
        int item = -1;
        if (head)
        {
            struct Node *s, *l;

            s = head;
            while (s->next != NULL)
            {
                l = s;
                s = s->next;
            }
            l->next = NULL;
            item = s->item;
            delete s;
            return item;
        }
        cout << "List is empty." << endl;
        return item;
    }

    int shift()
    {
        int item = -1;
        if (head)
        {
            struct Node *s = head;
            head = head->next;
            item = s->item;
            delete s;
            return item;
        }
        cout << "List is empty." << endl;
        return item;
    }

    ~LinkedList()
    {
        struct Node *s;
        while (head != NULL)
        {
            s = head;
            head = head->next;
            delete s;
        }
    }
};

int main()
{
    LinkedList stack;
    for (int i = 0; i < 45; i += 2)
    {
        stack.prepend(i);
    }
    stack.printlist();
    for (int i = 0; i < 5; i++)
    {
        stack.shift();
    }
    stack.printlist();
    return 0;
}
