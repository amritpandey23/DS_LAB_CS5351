// author: Amrit Pandey, 207907
// date: 28-06-2021

#include <iostream>
using namespace std;

int menu()
{
    int r;
    cout << "[1] Insert\n";
    cout << "[2] Delete\n";
    cout << "[3] Search\n";
    cout << "[4] Print\n";
    cout << "[0] Exit\n";
    cout << "YOUR CHOICE >>> ";
    cin >> r;
    return r;
}

struct ListNode
{
    int val;
    struct ListNode *next;
};

class LinkedList
{
private:
    struct ListNode *head;

public:
    LinkedList()
    {
        head = NULL;
    }

    struct ListNode *createNewNode(int v, struct ListNode *next)
    {
        struct ListNode *ptr = new struct ListNode;
        ptr->val = v;
        ptr->next = next;
        return ptr;
    }

    struct ListNode *createNewNode(int v)
    {
        return createNewNode(v, NULL);
    }

    void sortedInsert(struct ListNode **head, struct ListNode *node)
    {
        if (*head == NULL || (*head)->val >= node->val)
        {
            node->next = *head;
            *head = node;
            return;
        }

        struct ListNode *current = *head;
        while (current->next != NULL && current->next->val < node->val)
        {
            current = current->next;
        }

        node->next = current->next;
        current->next = node;
    }

    void sortedInsert(int k)
    {
        sortedInsert(&head, createNewNode(k));
    }

    void printList()
    {
        struct ListNode *tmp;
        tmp = head;
        while (tmp != NULL)
        {
            cout << tmp->val << "->";
            tmp = tmp->next;
        }
        cout << "NULL\b\b\n";
    }

    bool searchKey(int k)
    {
        struct ListNode *tmp;
        tmp = head;
        while (tmp != NULL && tmp->val <= k)
        {
            if (tmp->val == k)
            {
                return true;
            }
            tmp = tmp->next;
        }
        return false;
    }

    void deleteKey(struct ListNode *head, int k)
    {
        struct ListNode *tmp;
        if (head->val == k)
        {
            tmp = head;
            head = head->next;
            delete tmp;
        }
        else
        {
            struct ListNode *cur = head;
            while (cur->next != NULL)
            {
                if (cur->next->val == k)
                {
                    tmp = cur->next;
                    cur->next = cur->next->next;
                    delete tmp;
                    break;
                }
                else
                {
                    cur = cur->next;
                }
            }
        }
    }

    void deleteKey(int k)
    {
        deleteKey(head, k);
    }

    ~LinkedList()
    {
        struct ListNode *tmp;
        while (head != NULL)
        {
            tmp = head;
            head = head->next;
            delete tmp;
        }
    }
};

class HashTable
{
private:
    LinkedList *table;
    int n;

public:
    HashTable(int n)
    {
        this->n = n;
        this->table = new LinkedList[n];
    }
    int hash(int k)
    {
        return k % n;
    }

    void insertVal(int k)
    {
        int idx;
        idx = hash(k);
        table[idx].sortedInsert(k);
        // table[idx].printList();
    }

    bool searchVal(int k)
    {
        int idx;
        idx = hash(k);
        return table[idx].searchKey(k);
    }

    void deleteVal(int k)
    {
        int idx;
        idx = hash(idx);
        // table[idx].printList();
        table[idx].deleteKey(k);
    }

    void printTable()
    {
        for (int i = 0; i < n; i++)
        {
            cout << i << ": ";
            table[i].printList();
        }
    }
};

void wizard()
{
    int s, t;
    cout << "Enter the size of Hash Table: ";
    cin >> s;
    if (s <= 0)
    {
        cout << "[OUT] : Invalid Size!\n";
        return;
    }
    HashTable ht(s);

    while (true)
    {
        cout << endl;
        switch (menu())
        {
        case 1:
        {
            cout << "Enter value: ";
            cin >> t;
            ht.insertVal(t);
            break;
        }
        case 2:
        {
            cout << "Enter key: ";
            cin >> t;
            ht.deleteVal(t);
            break;
        }
        case 3:
        {
            cout << "Enter key: ";
            cin >> t;
            cout << "[OUT] :: ";
            ht.searchVal(t) ? cout << t << " exist.\n" : cout << t << " does not exist.\n";
            break;
        }
        case 4:
        {
            ht.printTable();
            break;
        }
        case 0:
        {
            exit(0);
        }
        default:
        {
            cout << "[OUT] :: ";
            cout << "Invalid Choice, try again.\n";
            break;
        }
        }
    }
}

int main()
{
    wizard();
}
